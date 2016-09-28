// DB_AvcStation.cpp: implementation of the DB_AvcStation class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AvcStation.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AvcStation::DB_AvcStation()
{

}

DB_AvcStation::~DB_AvcStation()
{

}

void DB_AvcStation::RefreshModel(char *pData, int bufSize)
{
	STM_AVC_EMS_Model *pRec = (STM_AVC_EMS_Model*)pData;
	visualpw_Station DBrec, *pDBrec;
	PositionStation *pPosSta;
	CString m_szTmp;
	int m_recn=0, m_nRet;

	for (int i=0; i<bufSize/sizeof(STM_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		STM_AVC_EMS_Model* pnew = new STM_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(STM_AVC_EMS_Model));

		ZeroMemory(&DBrec, sizeof(DBrec));
		
		//m_szTmp.Format("TABLE(visualpw.Station),WHERE(NU=%d)", pRec[i].fac_id);
		//pDBrec = (visualpw_Station*)g_DB.QueryRecord("Station",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = g_DataBase.m_pwStation.BinaryFindStationByNu(pRec[i].fac_id);
		if(m_nRet != -1)
		{
			pDBrec = &g_DataBase.m_pwStation.m_VecStation.at(m_nRet).rec;
			pPosSta = &g_DataBase.m_pwStation.m_VecStation.at(m_nRet);
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			//DBrec.CtrlType=pRec[i].pltyp;
			if(pRec[i].remove==1)					//�Ż����Ʊ�־
				DBrec.status&=!STUS_DEVOPFED;
			else
				DBrec.status|=STUS_DEVOPFED;

			g_ComFunc.PutCol(&pDBrec->CtrlType, pRec[i].pltyp, g_DataBase.m_pwStation.m_nTableID, pPosSta->nPos, "CtrlType");
			g_ComFunc.PutCol(&pDBrec->status, DBrec.status, g_DataBase.m_pwStation.m_nTableID, pPosSta->nPos, "status");

			//g_DB.UpdateRecord("Station", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
		else	
		{
			delete pnew;
			continue;
		}

		//����AVCͳ����Ϣ
		ScadaAVC_AVCStation AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.ID=pnew->fac_id;							//��վID
		if(MatchKeyNo(pnew->fac_id, FAC_INFO_MODEL) == false)
		{
			delete pnew;
			break;
		}

		strcat(AVCRec.Name, pDBrec->Name);						//��վ����
		AVCRec.Zone=pnew->respar;						//����ID
		AVCRec.CtrlOut=pnew->remove;						//�����˳�
		AVCRec.AVCCtrl=pnew->qaut;						//AVC�Զ�����
		AVCRec.CtrlID=pnew->pltyp;						//����ʱ�α��
		AVCRec.DevLock_Sta=pnew->qdevlck;					//��վ�豸����״̬
		AVCRec.LogTime = g_TimeFile;


		m_szTmp.Format("TABLE(ScadaAVC.AVCStation),WHERE(ID=%d)", pRec[i].fac_id);
		ScadaAVC_AVCStation* pAvcRec = (ScadaAVC_AVCStation*)g_DB.QueryRecord("AVCStation",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			AVCRec.Lock_Sta=pAvcRec->Lock_Sta;						//��վ����״̬
			AVCRec.Vol_rate=pAvcRec->Vol_rate;					//��ѹ�ϸ���
			AVCRec.Loss_P=pAvcRec->Loss_P;						//�й�����
			AVCRec.Loss_Q=pAvcRec->Loss_Q;						//�޹�����
			AVCRec.Bachup_Q=pAvcRec->Bachup_Q;					//�޹�����
			AVCRec.DCtrlNum=pAvcRec->DCtrlNum;					//�ն�����
			AVCRec.H24CtrlNum=pAvcRec->H24CtrlNum;					//24Сʱ������
			AVCRec.MCtrlNum=pAvcRec->MCtrlNum;					//�¶�����
			//AVCRec.LogTime = g_TimeFile;

			g_DB.UpdateRecord("AVCStation", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCStation", &AVCRec);
		}
		
		delete pnew;
	}
}