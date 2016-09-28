// DB_AVCCtrlPloy.cpp: implementation of the DB_AVCCtrlPloy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCCtrlPloy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCCtrlPloy::DB_AVCCtrlPloy()
{

}

DB_AVCCtrlPloy::~DB_AVCCtrlPloy()
{

}

void DB_AVCCtrlPloy::RefreshModel(char *pData, int bufSize)
{
	OPBUFF_AVC_EMS_Model *pRec = (OPBUFF_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;

	for (int i=0; i<bufSize/sizeof(OPBUFF_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		OPBUFF_AVC_EMS_Model* pnew = new OPBUFF_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(OPBUFF_AVC_EMS_Model));

		ScadaAVC_AVCCtrlCmd AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//���
		if(MatchKeyNo(pnew->keyno, OPBUFF_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.LogTime=g_TimeFile;//CTime::GetCurrentTime();						//����ʱ��
		CString sztext=pnew->id;
		sztext.TrimRight();
		strcat(AVCRec.DevName, sztext);					//�豸����
		AVCRec.StationID=pnew->facid;					//��վID
		AVCRec.DevID=pnew->devid;						//�豸ID
		AVCRec.DevSub=pnew->devsub;						//�����豸�±�
		AVCRec.IssTm=pnew->isstm-CTimeSpan(0, 8, 0, 0);						//����ʱ��
		AVCRec.CmdTm=pnew->comtm-CTimeSpan(0, 8, 0, 0);						//ִ��ʱ��
		sztext=pnew->cause;
		sztext.TrimRight();
		strcat(AVCRec.cause_info, sztext);				//����ԭ��
		sztext=pnew->result;
		sztext.TrimRight();
		strcat(AVCRec.result_info, sztext);				//��ʩ
		sztext=pnew->text;
		sztext.TrimRight();
		strcat(AVCRec.Cmd_info, sztext);				//��������
		sztext=pnew->cmdtype;
		sztext.TrimRight();
		strcat(AVCRec.CmdType, sztext);					//��������
		AVCRec.CtrlType=pnew->optype;					//��������
		sztext=pnew->rslttyp;
		sztext.TrimRight();
		strcat(AVCRec.rslttype, sztext);					//����״̬
		AVCRec.qcheck=pnew->qcheck;						//����ȷ��
		AVCRec.qaut=pnew->qaut;							//�Կ�����
		AVCRec.seq=pnew->seq;							//������
		AVCRec.ZoneID=pnew->zone;						//������ID
		AVCRec.resp=pnew->resp;						//������

		m_szTmp.Format("TABLE(ScadaAVC.AVCCtrlCmd),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCCtrlCmd* pAvcRec = (ScadaAVC_AVCCtrlCmd*)g_DB.QueryRecord("AVCCtrlCmd",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCCtrlCmd", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCCtrlCmd", &AVCRec);
		}

		delete pnew;
	}
}
