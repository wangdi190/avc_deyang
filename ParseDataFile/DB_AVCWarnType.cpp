// DB_AVCWarnType.cpp: implementation of the DB_AVCWarnType class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCWarnType.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCWarnType::DB_AVCWarnType()
{

}

DB_AVCWarnType::~DB_AVCWarnType()
{

}

void DB_AVCWarnType::RefreshModel(char *pData, int bufSize)
{
	
	ALMTYP_AVC_EMS_Model *pRec = (ALMTYP_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;

	for (int i=0; i<bufSize/sizeof(ALMTYP_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		ALMTYP_AVC_EMS_Model* pnew = new ALMTYP_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(ALMTYP_AVC_EMS_Model));

		ScadaAVC_AVCWarnType AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//序号
		if(MatchKeyNo(pnew->keyno, ALMTYP_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.ID=pnew->id;							//告警ID
		strcat(AVCRec.TypeName, AVCALARM_NAME[pnew->id]);					//告警名称
		AVCRec.ot=pnew->ot;							//告警设备类型
		strcat(AVCRec.txt, pnew->txt);						//告警内容
		AVCRec.qskip=pnew->qskip;						//抑止告警标志
		AVCRec.qlock=pnew->qlock;						//闭锁复归方式
		AVCRec.qsend=pnew->qsend;						//告警发送标志
		AVCRec.deltm=pnew->deltm;							//复归延时时间

		m_szTmp.Format("TABLE(ScadaAVC.AVCWarnType),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCWarnType* pAvcRec = (ScadaAVC_AVCWarnType*)g_DB.QueryRecord("AVCWarnType",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCWarnType", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCWarnType", &AVCRec);
		}

		delete pnew;
	}
}
