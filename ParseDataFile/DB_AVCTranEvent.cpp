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
		
		//���AVC������Ϣ
		ScadaAVC_AVCTransEvent AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//���
		if(MatchKeyNo(pnew->keyno, XFACT_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.StationID=pnew->facid;					//��վID
		CString sztext(pnew->stm);
		sztext.TrimRight();
		strcat(AVCRec.StationName, sztext);				//��վ����
		AVCRec.TransID=pnew->sub;						//��ѹ��ID
		sztext=pnew->chid;
		sztext.TrimRight();
		strcat(AVCRec.TransName, sztext);				//��ѹ������
		AVCRec.WindID=pnew->id;						//��������ID
		AVCRec.Optime=pnew->optime-CTimeSpan(0, 8, 0, 0);						//����ʱ��
	//	TRACE("%d %s\n", AVCRec.KeyID, AVCRec.Optime.Format("%Y-%m-%d %H:%M:%S"));

		AVCRec.pretap=pnew->pretap;						//����ǰ��λ
		AVCRec.afttap=pnew->afttap;						//������λ
		AVCRec.preVol=pnew->prekv;						//����ǰ��ѹ
		AVCRec.aftVol=pnew->val;						//�������ѹ
		sztext=pnew->optype;
		sztext.TrimRight();
		strcat(AVCRec.opttype, sztext);					//��������
		AVCRec.qAVC=pnew->qavc;							//AVC�����־
		AVCRec.preHVol=pnew->prevh;						//����ǰ��ѹ��ѹ
		AVCRec.preHP=pnew->prewh;						//����ǰ��ѹ�й�
		AVCRec.preHQ=pnew->prerh;						//����ǰ��ѹ�޹�
		AVCRec.preMVol=pnew->prevm;						//����ǰ��ѹ��ѹ
		AVCRec.preMP=pnew->prewm;						//����ǰ��ѹ�й�
		AVCRec.preMQ=pnew->prerm;						//����ǰ��ѹ�޹�
		AVCRec.preLVol=pnew->prevl;						//����ǰ��ѹ��ѹ
		AVCRec.preLP=pnew->prewl;						//����ǰ��ѹ�й�
		AVCRec.preLQ=pnew->prerl;						//����ǰ��ѹ�޹�
		AVCRec.aftHVol=pnew->aftvh;						//���ƺ��ѹ��ѹ
		AVCRec.aftHP=pnew->aftwh;						//���ƺ��ѹ�й�
		AVCRec.aftHQ=pnew->aftrh;						//���ƺ��ѹ�޹�
		AVCRec.aftMVol=pnew->aftvm;						//���ƺ���ѹ��ѹ
		AVCRec.aftMP=pnew->aftwm;						//���ƺ���ѹ�й�
		AVCRec.aftMQ=pnew->aftrm;						//���ƺ���ѹ�޹�
		AVCRec.aftLVol=pnew->aftvl;						//���ƺ��ѹ��ѹ
		AVCRec.aftLP=pnew->aftwl;						//���ƺ��ѹ�й�
		AVCRec.aftLQ=pnew->aftrl;						//���ƺ��ѹ�޹�
		AVCRec.EventTime=g_TimeFile;//CTime::GetCurrentTime();					//�¼�ʱ��

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
