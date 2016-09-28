// DB_AVCCtrlZone.cpp: implementation of the DB_AVCCtrlZone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCCtrlZone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCCtrlZone::DB_AVCCtrlZone()
{

}

DB_AVCCtrlZone::~DB_AVCCtrlZone()
{

}
void DB_AVCCtrlZone::RefreshModel(char* pData, int bufSize)
{
	ZONE_AVC_EMS_Model *pRec = (ZONE_AVC_EMS_Model*)pData;

	CString m_szTmp;
	int m_recn=0;


	for (int i=0; i<bufSize/sizeof(ZONE_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		ZONE_AVC_EMS_Model* pnew = new ZONE_AVC_EMS_Model();
		memcpy(pnew, (pRec+i), sizeof(ZONE_AVC_EMS_Model));
		
		//���AVC������Ϣ
		ScadaAVC_AVCCtrlZone AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.KeyID=pnew->keyno;						//���
		if(MatchKeyNo(pnew->keyno, ZONE_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		strcat(AVCRec.Name, pnew->chid);						//��������
		AVCRec.VovNum=pnew->vovnum;						//��ѹ����Խ����
		AVCRec.QovNum=pnew->qovnum;						//�޹�����Խ����
		AVCRec.wloss=pnew->wloss;						//��������ֵ
		AVCRec.NormCp=pnew->normcp;						//�ɿص�����
		AVCRec.NormXf=pnew->normxf;						//�ɿر�ѹ����
		AVCRec.LockCp=pnew->lockcp;						//����������
		AVCRec.LockXf=pnew->lockxf;						//������ѹ����
		AVCRec.VarIn=pnew->varin;						//��Ͷ���޹�������
		AVCRec.VarOff=pnew->varoff;						//δͶ���޹�������
		AVCRec.Cosfi=pnew->cosfi;						//�ؿڹ�������
		AVCRec.score=pnew->score;						//����״̬�÷�

		AVCRec.LogTime = g_TimeFile;

		m_szTmp.Format("TABLE(ScadaAVC.AVCCtrlZone),WHERE(KeyID=%d)", pnew->keyno);
		ScadaAVC_AVCCtrlZone* pAvcRec = (ScadaAVC_AVCCtrlZone*)g_DB.QueryRecord("AVCCtrlZone",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCCtrlZone", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCCtrlZone", &AVCRec);
		}
		delete pnew;
	}
}
