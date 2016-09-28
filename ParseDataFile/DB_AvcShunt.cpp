// DB_AvcShunt.cpp: implementation of the DB_AvcShunt class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AvcShunt.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AvcShunt::DB_AvcShunt()
{

}

DB_AvcShunt::~DB_AvcShunt()
{

}

void DB_AvcShunt::RefreshModel(char *pData, int bufSize)
{
	CPM_AVC_EMS_Model *pRec = (CPM_AVC_EMS_Model*)pData;
	visualpw_Shunt DBrec, *pDBrec;
	PositionShunt *pPosShunt;
	CString m_szTmp;
	int m_recn=0, m_nRet;

	for (int i=0; i<bufSize/sizeof(CPM_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		CPM_AVC_EMS_Model* pnew = new CPM_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(CPM_AVC_EMS_Model));

		ZeroMemory(&DBrec, sizeof(DBrec));
		
		BYTE AVCCtrl = GetStationAVCSta(pnew->fac_id);

		//m_szTmp.Format("TABLE(visualpw.Shunt),WHERE(NU=%d)", pRec[i].cpid);
		//pDBrec = (visualpw_Shunt*)g_DB.QueryRecord("Shunt",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = g_DataBase.m_pwShuntSreact.BinaryFindShuntByNu(pRec[i].cpid);
		if(m_nRet != -1)
		{
			pDBrec = &g_DataBase.m_pwShuntSreact.m_VecShunt.at(m_nRet).rec;
			pPosShunt = &g_DataBase.m_pwShuntSreact.m_VecShunt.at(m_nRet);
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			DBrec.CtrlType=pnew->pltyp;
			if(pnew->offavr!=0)
				DBrec.status|=STATION_LOCKED;
			else
				DBrec.status&=!STATION_LOCKED;

			if(AVCCtrl==1)							//控制状态
				DBrec.status|=STUS_DEVOPFED;
			else
				DBrec.status&=!STUS_DEVOPFED;

			if(pnew->ykno>=0)		//可控制
				DBrec.status|=STUS_CTRL_HI;
			else
				DBrec.status&=!STUS_CTRL_HI;

			g_ComFunc.PutCol(&pDBrec->CtrlType, pRec[i].pltyp, g_DataBase.m_pwShuntSreact.m_nTableID_Shunt, pPosShunt->nPos, "CtrlType");
			g_ComFunc.PutCol(&pDBrec->status, DBrec.status, g_DataBase.m_pwShuntSreact.m_nTableID_Shunt, pPosShunt->nPos, "status");

			//g_DB.UpdateRecord("Shunt", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}


		//加载AVC统计信息
		ScadaAVC_AVCShunt AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.ID=pnew->cpid;							//电容ID
		if(MatchKeyNo(pnew->cpid, RC_DEVICE_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.StationID=pnew->fac_id;					//厂站ID
		GetDevName(AVCRec.ID, EQUIP_TYPE_SHUNT, AVCRec.Name);						//电容名称
		AVCRec.CtrlID=pnew->pltyp;						//控制时段ID
		AVCRec.Cal_Sta=AVCCtrl;						//是否AVC控制
//		AVCRec.Cal_Sta=pnew->qavr;						//参与计算
		AVCRec.Lock_Sta=pnew->offavr;						//闭锁状态
		AVCRec.LimitNum=pnew->limtnum;						//动作次数限制
		AVCRec.YXID=pnew->yxid;						//遥信ID
		AVCRec.YKNO=pnew->ykno;						//遥控点号
		AVCRec.BusID=pnew->isbsid;					//控制母线ID
		AVCRec.BreakID=pnew->yxid;						//控制开关ID
		AVCRec.DCtrlNum=pnew->tnumday;						//日动作数量
		AVCRec.DAVCCtrlNum=pnew->cnumday;					//日AVC控制数量
		AVCRec.DAVCActNum=pnew->numday;					//日AVC动作数量
		AVCRec.DRunTime=pnew->rtmday;					//日运行时长
		AVCRec.MRunTime=pnew->rtmmon;					//月运行时长
		AVCRec.YRunTime=pnew->rtmyea;					//年运行时长

		AVCRec.LogTime = g_TimeFile;

		m_szTmp.Format("TABLE(ScadaAVC.AVCShunt),WHERE(ID=%d)", pRec[i].cpid);
		ScadaAVC_AVCShunt* pAvcRec = (ScadaAVC_AVCShunt*)g_DB.QueryRecord("AVCShunt",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			AVCRec.H24CtrlNum=pAvcRec->H24CtrlNum;					//24小时动作数量
			AVCRec.H24AVCCtrlNum=pAvcRec->H24AVCCtrlNum;				//24小时AVC控制数量
			AVCRec.H24AVCActNum=pAvcRec->H24AVCActNum;				//24小时AVC动作数量
			AVCRec.MCtrlNum=pAvcRec->MCtrlNum;					//月动作数量
			AVCRec.MAVCCtrlNum=pAvcRec->MAVCCtrlNum;					//月AVC控制数量
			AVCRec.MAVCActNum=pAvcRec->MAVCActNum;					//月AVC动作数量
			AVCRec.YCtrlNum=pAvcRec->YCtrlNum;					//年动作数量
			AVCRec.YAVCCtrlNum=pAvcRec->YAVCCtrlNum;					//年AVC控制数量
			AVCRec.YAVCActNum=pAvcRec->YAVCActNum;					//年AVC动作数量
			AVCRec.H24RunTime=pAvcRec->H24RunTime;					//24小时运行时长

			g_DB.UpdateRecord("AVCShunt", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCShunt", &AVCRec);
		}

		delete pnew;
	}
}