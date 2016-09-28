// DB_AVCTranEvent.cpp: implementation of the DB_AVCTranEvent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCTranEvent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCTranEvent::DB_AVCTranEvent()
{

}

DB_AVCTranEvent::~DB_AVCTranEvent()
{

}

void DB_AVCTranEvent::RefreshModel(char* pData, int bufSize)
{
	XFACT_AVC_EMS_Model *pRec = (XFACT_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;

	for (int i=0; i<bufSize/sizeof(XFACT_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		XFACT_AVC_EMS_Model* pnew = new XFACT_AVC_EMS_Model();
		memcpy(pnew, (pRec+i), sizeof(XFACT_AVC_EMS_Model));
		
		//添加AVC配置信息
		ScadaAVC_AVCTransEvent AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//序号
		if(MatchKeyNo(pnew->keyno, XFACT_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.StationID=pnew->facid;					//厂站ID
		CString sztext(pnew->stm);
		sztext.TrimRight();
		strcat(AVCRec.StationName, sztext);				//厂站名称
		AVCRec.TransID=pnew->sub;						//变压器ID
		sztext=pnew->chid;
		sztext.TrimRight();
		strcat(AVCRec.TransName, sztext);				//变压器名称
		AVCRec.WindID=pnew->id;						//控制绕组ID
		AVCRec.Optime=pnew->optime-CTimeSpan(0, 8, 0, 0);						//操作时间
	//	TRACE("%d %s\n", AVCRec.KeyID, AVCRec.Optime.Format("%Y-%m-%d %H:%M:%S"));

		AVCRec.pretap=pnew->pretap;						//操作前档位
		AVCRec.afttap=pnew->afttap;						//操作后档位
		AVCRec.preVol=pnew->prekv;						//操作前电压
		AVCRec.aftVol=pnew->val;						//操作后电压
		sztext=pnew->optype;
		sztext.TrimRight();
		strcat(AVCRec.opttype, sztext);					//命令类型
		AVCRec.qAVC=pnew->qavc;							//AVC命令标志
		AVCRec.preHVol=pnew->prevh;						//控制前高压电压
		AVCRec.preHP=pnew->prewh;						//控制前高压有功
		AVCRec.preHQ=pnew->prerh;						//控制前高压无功
		AVCRec.preMVol=pnew->prevm;						//控制前中压电压
		AVCRec.preMP=pnew->prewm;						//控制前中压有功
		AVCRec.preMQ=pnew->prerm;						//控制前中压无功
		AVCRec.preLVol=pnew->prevl;						//控制前低压电压
		AVCRec.preLP=pnew->prewl;						//控制前低压有功
		AVCRec.preLQ=pnew->prerl;						//控制前低压无功
		AVCRec.aftHVol=pnew->aftvh;						//控制后高压电压
		AVCRec.aftHP=pnew->aftwh;						//控制后高压有功
		AVCRec.aftHQ=pnew->aftrh;						//控制后高压无功
		AVCRec.aftMVol=pnew->aftvm;						//控制后中压电压
		AVCRec.aftMP=pnew->aftwm;						//控制后中压有功
		AVCRec.aftMQ=pnew->aftrm;						//控制后中压无功
		AVCRec.aftLVol=pnew->aftvl;						//控制后低压电压
		AVCRec.aftLP=pnew->aftwl;						//控制后低压有功
		AVCRec.aftLQ=pnew->aftrl;						//控制后低压无功
		AVCRec.EventTime=g_TimeFile;//CTime::GetCurrentTime();					//事件时间

		m_szTmp.Format("TABLE(ScadaAVC.AVCTransEvent),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCTransEvent* pAvcRec = (ScadaAVC_AVCTransEvent*)g_DB.QueryRecord("AVCTransEvent",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		/*if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCTransEvent", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCTransEvent", &AVCRec);
		}*/
		if(pAvcRec == NULL)
			LSI_AppendRec("ScadaAVC.AVCTransEvent", &AVCRec);
		delete pnew;
	}
}
