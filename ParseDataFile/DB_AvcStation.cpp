// DB_AvcStation.cpp: implementation of the DB_AvcStation class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AvcStation.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AvcStation::DB_AvcStation()
{

}

DB_AvcStation::~DB_AvcStation()
{

}

void DB_AvcStation::RefreshModel(char *pData, int bufSize)
{
	STM_AVC_EMS_Model *pRec = (STM_AVC_EMS_Model*)pData;
	visualpw_Station DBrec, *pDBrec;
	PositionStation *pPosSta;
	CString m_szTmp;
	int m_recn=0, m_nRet;

	for (int i=0; i<bufSize/sizeof(STM_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		STM_AVC_EMS_Model* pnew = new STM_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(STM_AVC_EMS_Model));

		ZeroMemory(&DBrec, sizeof(DBrec));
		
		//m_szTmp.Format("TABLE(visualpw.Station),WHERE(NU=%d)", pRec[i].fac_id);
		//pDBrec = (visualpw_Station*)g_DB.QueryRecord("Station",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = g_DataBase.m_pwStation.BinaryFindStationByNu(pRec[i].fac_id);
		if(m_nRet != -1)
		{
			pDBrec = &g_DataBase.m_pwStation.m_VecStation.at(m_nRet).rec;
			pPosSta = &g_DataBase.m_pwStation.m_VecStation.at(m_nRet);
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			//DBrec.CtrlType=pRec[i].pltyp;
			if(pRec[i].remove==1)					//优化控制标志
				DBrec.status&=!STUS_DEVOPFED;
			else
				DBrec.status|=STUS_DEVOPFED;

			g_ComFunc.PutCol(&pDBrec->CtrlType, pRec[i].pltyp, g_DataBase.m_pwStation.m_nTableID, pPosSta->nPos, "CtrlType");
			g_ComFunc.PutCol(&pDBrec->status, DBrec.status, g_DataBase.m_pwStation.m_nTableID, pPosSta->nPos, "status");

			//g_DB.UpdateRecord("Station", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
		else	
		{
			delete pnew;
			continue;
		}

		//加载AVC统计信息
		ScadaAVC_AVCStation AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.ID=pnew->fac_id;							//厂站ID
		if(MatchKeyNo(pnew->fac_id, FAC_INFO_MODEL) == false)
		{
			delete pnew;
			break;
		}

		strcat(AVCRec.Name, pDBrec->Name);						//厂站名称
		AVCRec.Zone=pnew->respar;						//区域ID
		AVCRec.CtrlOut=pnew->remove;						//控制退出
		AVCRec.AVCCtrl=pnew->qaut;						//AVC自动控制
		AVCRec.CtrlID=pnew->pltyp;						//控制时段编号
		AVCRec.DevLock_Sta=pnew->qdevlck;					//厂站设备闭锁状态
		AVCRec.LogTime = g_TimeFile;


		m_szTmp.Format("TABLE(ScadaAVC.AVCStation),WHERE(ID=%d)", pRec[i].fac_id);
		ScadaAVC_AVCStation* pAvcRec = (ScadaAVC_AVCStation*)g_DB.QueryRecord("AVCStation",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			AVCRec.Lock_Sta=pAvcRec->Lock_Sta;						//厂站闭锁状态
			AVCRec.Vol_rate=pAvcRec->Vol_rate;					//电压合格率
			AVCRec.Loss_P=pAvcRec->Loss_P;						//有功网损
			AVCRec.Loss_Q=pAvcRec->Loss_Q;						//无功网损
			AVCRec.Bachup_Q=pAvcRec->Bachup_Q;					//无功备用
			AVCRec.DCtrlNum=pAvcRec->DCtrlNum;					//日动作数
			AVCRec.H24CtrlNum=pAvcRec->H24CtrlNum;					//24小时动作数
			AVCRec.MCtrlNum=pAvcRec->MCtrlNum;					//月动作数
			//AVCRec.LogTime = g_TimeFile;

			g_DB.UpdateRecord("AVCStation", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCStation", &AVCRec);
		}
		
		delete pnew;
	}
}