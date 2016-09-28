// DB_AVCWarnInfo.cpp: implementation of the DB_AVCWarnInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCWarnInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCWarnInfo::DB_AVCWarnInfo()
{

}

DB_AVCWarnInfo::~DB_AVCWarnInfo()
{

}

void DB_AVCWarnInfo::RefreshModel(char *pData, int bufSize)
{
	ALMYX_AVC_EMS_Model *pRec = (ALMYX_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;

	for (int i=0; i<bufSize/sizeof(ALMYX_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		ALMYX_AVC_EMS_Model* pnew = new ALMYX_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(ALMYX_AVC_EMS_Model));

		ScadaAVC_AVCWarnInfo AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.StationID=pnew->fac_id;					//厂站ID
		if(MatchKeyNo(pnew->fac_id, FAC_INFO_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.DevID=pnew->devid;						//设备ID
		AVCRec.WarnID=pnew->atyid;						//告警类型ID
		AVCRec.qlock=pnew->qlock;						//闭锁复归方式
		AVCRec.stat=pnew->stat;							//闭锁状态
		AVCRec.almtype=pnew->almtyp;					//告警类型
		AVCRec.ontm=(CTime)pnew->ontm-CTimeSpan(0, 8, 0, 0);							//动作时间
		AVCRec.offtm=(CTime)pnew->offtm-CTimeSpan(0, 8, 0, 0);						//复归时间

		m_szTmp.Format("TABLE(ScadaAVC.AVCWarnInfo),WHERE(DevID=%d)", pnew->devid);
		ScadaAVC_AVCWarnInfo* pAvcRec = (ScadaAVC_AVCWarnInfo*)g_DB.QueryRecord("AVCWarnInfo",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCWarnInfo", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCWarnInfo", &AVCRec);
		}

		delete pnew;
	}
}
