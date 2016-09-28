// DB_AvcTrans.cpp: implementation of the DB_AvcTrans class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AvcTrans.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AvcTrans::DB_AvcTrans()
{

}

DB_AvcTrans::~DB_AvcTrans()
{

}

void DB_AvcTrans::RefreshModel(char *pData, int bufSize)
{
	XFM_AVC_EMS_Model *pRec = (XFM_AVC_EMS_Model*)pData;
	visualpw_Tfm1 DBrec1, *pDBrec1;
	visualpw_Tfm2 DBrec2, *pDBrec2;
	CString m_szTmp;
	int m_recn=0;
	CPtrArray syslimit;
	LoadSystemLimit(syslimit);

	for (int i=0; i<bufSize/sizeof(XFM_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		XFM_AVC_EMS_Model* pnew = new XFM_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(XFM_AVC_EMS_Model));
		ZeroMemory(&DBrec1, sizeof(DBrec1));

		BYTE AVCCtrl = GetStationAVCSta(pnew->fac_id);

		float limit[4];
		
		m_szTmp.Format("TABLE(visualpw.Tfm1),WHERE(NU=%d)", pRec[i].trid);
		pDBrec1 = (visualpw_Tfm1*)g_DB.QueryRecord("Tfm1",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		if(pDBrec1 != NULL)
		{
			memcpy(&DBrec1, pDBrec1, sizeof(DBrec1));

			DBrec1.CtrlType=pnew->pltyp;

			GetVolLimit(syslimit, pnew->pltyp, limit, 0.0, g_TimeFile, pnew->qgate);
			float fCosdn=limit[3];						//功率下限
			float fCosup=limit[2];						//功率上限

			if(pnew->offavr!=0)
				DBrec1.status|=STATION_LOCKED;
			else
				DBrec1.status&=!STATION_LOCKED;

			if(AVCCtrl==1)							//控制状态
				DBrec1.status|=STUS_DEVOPFED;
			else
				DBrec1.status&=!STUS_DEVOPFED;

			if(pnew->upykno>=0&&pnew->dnykno>=0)		//可控制
				DBrec1.status|=STUS_CTRL_HI;
			else
				DBrec1.status&=!STUS_CTRL_HI;

			DBrec1.CosDn=fCosdn;
			DBrec1.CosUp=fCosup;
			//DBrec1.status|=STUS_DEVOPFED;
			
			g_DB.UpdateRecord("Tfm1", m_szTmp.GetBuffer(0), &DBrec1, "visualpw");
		}
		else
		{
			m_szTmp.Format("TABLE(visualpw.Tfm2),WHERE(NU=%d)", pRec[i].trid);
			pDBrec2 = (visualpw_Tfm2*)g_DB.QueryRecord("Tfm2",m_szTmp.GetBuffer(0),m_recn,"visualpw");
			if(pDBrec2 != NULL)
			{
				memcpy(&DBrec2, pDBrec2, sizeof(DBrec2));

				DBrec2.CtrlType=pnew->pltyp;
				GetVolLimit(syslimit, pnew->pltyp, limit, 0.0, g_TimeFile, pnew->qgate);
				float fCosdn=limit[3];						//功率下限
				float fCosup=limit[2];						//功率上限

				if(pnew->offavr!=0)						//闭锁状态
					DBrec2.status|=STATION_LOCKED;
				else
					DBrec2.status&=!STATION_LOCKED;

				if(AVCCtrl==1)							//控制状态
					DBrec2.status|=STUS_DEVOPFED;
				else
					DBrec2.status&=!STUS_DEVOPFED;

				if(pnew->upykno>=0&&pnew->dnykno>=0)		//可控制
					DBrec2.status|=STUS_CTRL_HI;
				else
					DBrec2.status&=!STUS_CTRL_HI;

				DBrec2.status|=STUS_DEVOPFED;
				DBrec2.CosDn=fCosdn;
				DBrec2.CosUp=fCosup;
				
				g_DB.UpdateRecord("Tfm2", m_szTmp.GetBuffer(0), &DBrec2, "visualpw");
			}
		}

		//加载AVC统计信息
		ScadaAVC_AVCTrans AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.ID=pnew->trid;						//变压器ID
		if(MatchKeyNo(pnew->trid, TR_DEVICE_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.StationID=pnew->fac_id;					//厂站ID
		GetDevName(AVCRec.ID, EQUIP_TYPE_BITRS, AVCRec.Name);								//变压器名称
		AVCRec.CtrlID=pnew->pltyp;						//控制时段ID
//		AVCRec.Cal_Sta=pnew->qavr;						//参与计算标识
		AVCRec.Cal_Sta=AVCCtrl;						//是否AVC控制
		AVCRec.Lock_Sta=pnew->offavr;					//闭锁标识
		AVCRec.IsGate=pnew->qgate;						//关口变压器
		AVCRec.LimitNumber=pnew->limtnum;					//控制次数限制
		AVCRec.UpYXID=pnew->upyxid;						//升档遥信ID
		AVCRec.UpYKNO=pnew->upykno;						//升档遥控点号
		AVCRec.DnYXID=pnew->dnyxid;						//降档遥信ID
		AVCRec.DnYKNO=pnew->dnykno;						//降档遥控点号
		AVCRec.LinkBusID=pnew->isbsid;					//关联母线ID
		AVCRec.DCtrlNum=pnew->numday;					//日控制次数
		AVCRec.DAVCCtrlNum=pnew->tnumday;					//日AVC控制次数
		AVCRec.DAVCActNum=pnew->cnumday;					//日AVC动作次数
		AVCRec.MCtrlNum=pnew->nummon;					//月控制次数
		AVCRec.MAVCCtrlNum=pnew->tnummon;					//月AVC控制次数
		AVCRec.MAVCActNum=pnew->cnummon;					//月AVC动作次数
		AVCRec.YCtrlNum=pnew->numyea;					//年控制次数
		AVCRec.YAVCCtrlNum=pnew->tnumyea;					//年AVC控制次数
		AVCRec.YAVCActNum=pnew->cnumyea;					//年AVC动作次数

		AVCRec.LogTime = g_TimeFile;

		m_szTmp.Format("TABLE(ScadaAVC.AVCTrans),WHERE(ID=%d)", AVCRec.ID);
		ScadaAVC_AVCTrans* pAvcRec = (ScadaAVC_AVCTrans*)g_DB.QueryRecord("AVCTrans",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			AVCRec.H24CtrlNum=pAvcRec->H24CtrlNum;					//24小时控制次数
			AVCRec.H24AVCCtrlNum=pAvcRec->H24AVCCtrlNum;				//24小时AVC控制次数
			AVCRec.H24AVCActNum=pAvcRec->H24AVCActNum;				//24小时AVC动作次数
			g_DB.UpdateRecord("AVCTrans", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCTrans", &AVCRec);
		}
		
		delete pnew;
	}
	ClearSysLimit(syslimit);
}