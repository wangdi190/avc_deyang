// DB_AVCStatInfo.cpp: implementation of the DB_AVCStatInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCStatInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCStatInfo::DB_AVCStatInfo()
{

}

DB_AVCStatInfo::~DB_AVCStatInfo()
{

}
void DB_AVCStatInfo::RefreshModel(char* pData, int bufSize)
{
	STAT_AVC_EMS_Model *pRec = (STAT_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;


	for (int i=0; i<bufSize/sizeof(STAT_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		STAT_AVC_EMS_Model* pnew = new STAT_AVC_EMS_Model();
		memcpy(pnew, (pRec+i), sizeof(STAT_AVC_EMS_Model));
		
		//添加AVC配置信息
		ScadaAVC_AVCStateInfo AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//序号
		if(MatchKeyNo(pnew->keyno, STAT_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.DevID=pnew->devid;						//设备ID
		AVCRec.StationID=pnew->fac_id;					//厂站ID
		strcat(AVCRec.Name, pnew->devname);						//设备名称
		AVCRec.numall=pnew->numall;						//日动作次数
		AVCRec.numavc=pnew->numavc;						//日成功次数
		AVCRec.numorder=pnew->numorder;					//日下令次数
		AVCRec.numfail=pnew->numfail;						//日失败次数
		AVCRec.sucrate=pnew->sucrate;						//日成功数
		AVCRec.timelog=g_TimeFile;//CTime::GetCurrentTime();						//日期时标

		m_szTmp.Format("TABLE(ScadaAVC.AVCStateInfo),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCStateInfo* pAvcRec = (ScadaAVC_AVCStateInfo*)g_DB.QueryRecord("AVCStateInfo",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCStateInfo", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCStateInfo", &AVCRec);
		}
		delete pnew;
	}
}
