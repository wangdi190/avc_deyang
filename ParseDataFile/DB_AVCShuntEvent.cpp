// DB_AVCShuntEvent.cpp: implementation of the DB_AVCShuntEvent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCShuntEvent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCShuntEvent::DB_AVCShuntEvent()
{

}

DB_AVCShuntEvent::~DB_AVCShuntEvent()
{

}

void DB_AVCShuntEvent::RefreshModel(char* pData, int bufSize)
{
	CPACT_AVC_EMS_Model *pRec = (CPACT_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;


	for (int i=0; i<bufSize/sizeof(CPACT_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		CPACT_AVC_EMS_Model* pnew = new CPACT_AVC_EMS_Model();
		memcpy(pnew, (pRec+i), sizeof(CPACT_AVC_EMS_Model));
		
		//���AVC������Ϣ
		ScadaAVC_AVCShuntEvent AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//���
		if(MatchKeyNo(pnew->keyno, CPACT_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.StationID=pnew->facid;					//��վID
		CString sztext(pnew->stm);
		sztext.TrimRight();
		strcat(AVCRec.StationName, sztext);				//��վ����
		AVCRec.ShuntID=pnew->id;						//����ID
		sztext=pnew->chid;
		sztext.TrimRight();
		strcat(AVCRec.ShuntName, sztext);				//��������
		AVCRec.opttime=pnew->optime-CTimeSpan(0, 8, 0, 0);						//����ʱ��
		sztext=pnew->optype;
		sztext.TrimRight();
		strcat(AVCRec.opttype, sztext);					//��������
		AVCRec.qavc=pnew->qavc;							//AVCָ���־
		AVCRec.qopen=pnew->qopen;						//����������״̬
		AVCRec.preVol=pnew->prekv;						//����ǰ��ѹ
		AVCRec.aftVol=pnew->val;						//�������ѹ
		AVCRec.EventTime=g_TimeFile;//CTime::GetCurrentTime();					//�¼�ʱ��

		m_szTmp.Format("TABLE(ScadaAVC.AVCShuntEvent),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCShuntEvent* pAvcRec = (ScadaAVC_AVCShuntEvent*)g_DB.QueryRecord("AVCShuntEvent",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		/*if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCShuntEvent", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCShuntEvent", &AVCRec);
		}*/
		if(pAvcRec == NULL)
			LSI_AppendRec("ScadaAVC.AVCShuntEvent", &AVCRec);
		delete pnew;
	}
}
