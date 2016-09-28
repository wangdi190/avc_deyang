// DB_AVCCtrlEvent.cpp: implementation of the DB_AVCCtrlEvent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCCtrlEvent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCCtrlEvent::DB_AVCCtrlEvent()
{

}

DB_AVCCtrlEvent::~DB_AVCCtrlEvent()
{

}

void DB_AVCCtrlEvent::RefreshModel(char* pData, int bufSize)
{
	AOPMSG_AVC_EMS_Model *pRec = (AOPMSG_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;

//	LSI_EmptyTable("refavc.SetLim_table", false);

	for (int i=0; i<bufSize/sizeof(AOPMSG_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		AOPMSG_AVC_EMS_Model* pnew = new AOPMSG_AVC_EMS_Model();
		memcpy(pnew, (pRec+i), sizeof(AOPMSG_AVC_EMS_Model));
		
		//添加AVC配置信息
		ScadaAVC_AVCCtrlEvent AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//序号
		if(MatchKeyNo(pnew->keyno, AOPMSG_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		CString sztext(pnew->usr);
		sztext.TrimRight();
		strcat(AVCRec.user, sztext);					//用户名
		AVCRec.CmdTime=pnew->time-CTimeSpan(0, 8, 0, 0);						//操作时刻
		sztext=pnew->opefunc;
		sztext.TrimRight();
		strcat(AVCRec.opefunc, sztext);			//操作项
		sztext=pnew->text;
		sztext.TrimRight();
		strcat(AVCRec.text, sztext);				//操作内容

		m_szTmp.Format("TABLE(ScadaAVC.AVCCtrlEvent),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCCtrlEvent* pAvcRec = (ScadaAVC_AVCCtrlEvent*)g_DB.QueryRecord("AVCCtrlEvent",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		/*if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCCtrlEvent", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCCtrlEvent", &AVCRec);
		}*/
		if(pAvcRec == NULL)
			LSI_AppendRec("ScadaAVC.AVCCtrlEvent", &AVCRec);

		delete pnew;
	}
}
