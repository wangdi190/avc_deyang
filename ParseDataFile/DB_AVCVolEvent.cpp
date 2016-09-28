// DB_AVCVolEvent.cpp: implementation of the DB_AVCVolEvent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCVolEvent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCVolEvent::DB_AVCVolEvent()
{

}

DB_AVCVolEvent::~DB_AVCVolEvent()
{

}
void DB_AVCVolEvent::RefreshModel(char* pData, int bufSize)
{
	OVBUS_AVC_EMS_Model *pRec = (OVBUS_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;

//	LSI_EmptyTable("refavc.SetLim_table", false);

	for (int i=0; i<bufSize/sizeof(OVBUS_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		OVBUS_AVC_EMS_Model* pnew = new OVBUS_AVC_EMS_Model();
		memcpy(pnew, (pRec+i), sizeof(OVBUS_AVC_EMS_Model));
		
		//添加AVC配置信息
		ScadaAVC_AVCVoltEvent AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;											//序号
		if(MatchKeyNo(pnew->keyno, OVBUS_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		GetIDByName(pnew->st, EQUIP_TYPE_SUB, AVCRec.StationID);			//厂站ID	
		strcat(AVCRec.StationName, pnew->st);								//站名
		GetIDByName(pnew->id, EQUIP_TYPE_BUS, AVCRec.BusID);				//母线ID	
		strcat(AVCRec.BusName, pnew->id);								//母线名称
		AVCRec.val=pnew->val;											//电压值
		AVCRec.limit=pnew->lmt;											//电压限值
		AVCRec.EventTime=g_TimeFile;//CTime::GetCurrentTime();						//事件时间
	
		m_szTmp.Format("TABLE(ScadaAVC.AVCVoltEvent),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCVoltEvent* pAvcRec = (ScadaAVC_AVCVoltEvent*)g_DB.QueryRecord("AVCVoltEvent",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		/*if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCVoltEvent", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCVoltEvent", &AVCRec);
		}*/
		if(pAvcRec == NULL)
			LSI_AppendRec("ScadaAVC.AVCVoltEvent", &AVCRec);
		delete pnew;
	}
}
