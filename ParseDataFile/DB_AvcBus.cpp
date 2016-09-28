// DB_AvcBus.cpp: implementation of the DB_AvcBus class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AvcBus.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AvcBus::DB_AvcBus()
{

}

DB_AvcBus::~DB_AvcBus()
{

}

void DB_AvcBus::RefreshModel(char *pData, int bufSize)
{
	NDM_AVC_EMS_Model *pRec = (NDM_AVC_EMS_Model*)pData;
	visualpw_Bus DBrec, *pDBrec;
	CPtrArray syslimit;
	LoadSystemLimit(syslimit);

	CString m_szTmp;
	int m_recn=0;
	for (int i=0; i<bufSize/sizeof(NDM_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		NDM_AVC_EMS_Model* pnew = new NDM_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(NDM_AVC_EMS_Model));

		//����AVCͳ����Ϣ
		ScadaAVC_AVCBus AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		BYTE AVCCtrl = GetStationAVCSta(pnew->fac_id);

		AVCRec.BusID=pnew->bsid;						//ĸ��ID
		if(MatchKeyNo(pnew->bsid, BS_DEVICE_MODEL) == false)
		{
			delete pnew;
			break;
		}
		m_szTmp.Format("TABLE(visualpw.Bus),WHERE(NU=%d)", pRec[i].bsid);
		pDBrec = (visualpw_Bus*)g_DB.QueryRecord("Bus",m_szTmp.GetBuffer(0),m_recn,"visualpw");			//ȡ����ģ�Ͷ���
		ZeroMemory(&DBrec, sizeof(DBrec));
		if(pDBrec != NULL)
			memcpy(&DBrec, pDBrec, sizeof(DBrec));
		else
		{
			delete pnew;
			continue;
		}

		AVCRec.StationID=pnew->fac_id;					//��վID
		GetDevName(AVCRec.BusID, EQUIP_TYPE_BUS, AVCRec.Name);								//ĸ������
		AVCRec.CtrlID=pnew->pltyp;						//����ʱ�α��
		AVCRec.Ctr_Sta=AVCCtrl;						//�Ƿ�AVC����
		AVCRec.Cal_Sta=pnew->qavr;						//�Ƿ�������
		AVCRec.Lock_Sta=pnew->offavr;						//����״̬
		AVCRec.IsGate=pnew->qgate;						//�ؿڱ�ʶ

		float limit[4];
		if(GetVolLimit(syslimit, pnew->pltyp, limit, pDBrec->Vl, g_TimeFile, pnew->qgate))
		{
			AVCRec.Volup=limit[0];						//��ѹ����
			AVCRec.Voldn=limit[1];						//��ѹ����
			AVCRec.Cosup=limit[2];						//��������
			AVCRec.Cosdn=limit[3];						//��������
		}
		else
		{
			AVCRec.Volup=pnew->vup;						//��ѹ����
			AVCRec.Voldn=pnew->vdn;						//��ѹ����
			AVCRec.Cosup=1.0;							//��������
			AVCRec.Cosdn=0.9;							//��������
		}

		AVCRec.LogTime = g_TimeFile;

		m_szTmp.Format("TABLE(ScadaAVC.AVCBus),WHERE(BusID=%d)", pRec[i].bsid);
		ScadaAVC_AVCBus* pAvcRec = (ScadaAVC_AVCBus*)g_DB.QueryRecord("AVCBus",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			AVCRec.DVol_rate=pAvcRec->DVol_rate;					//�յ�ѹ�ϸ���
			AVCRec.H24Vol_rate=pAvcRec->H24Vol_rate;				//24Сʱ��ѹ�ϸ���
			AVCRec.MVol_rate=pAvcRec->MVol_rate;					//�µ�ѹ�ϸ���
			AVCRec.DCos_rate=pAvcRec->DCos_rate;					//���޹��ϸ���
			AVCRec.H24Cos_rate=pAvcRec->H24Cos_rate;				//24Сʱ�޹��ϸ���
			AVCRec.MCos_rate=pAvcRec->MCos_rate;					//���޹��ϸ���
			AVCRec.LogTime = g_TimeFile;

			g_DB.UpdateRecord("AVCBus", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCBus", &AVCRec);
		}

		//���»�����
		//ZeroMemory(&DBrec, sizeof(DBrec));
		
		m_szTmp.Format("TABLE(visualpw.Bus),WHERE(NU=%d)", pRec[i].bsid);
		pDBrec = (visualpw_Bus*)g_DB.QueryRecord("Bus",m_szTmp.GetBuffer(0),m_recn,"visualpw");			//ȡ����ģ�Ͷ���
		if(pDBrec != NULL)
		{
			memcpy(&DBrec, pDBrec, sizeof(DBrec));
			DBrec.CtrlType=pnew->pltyp;

			if(AVCRec.Lock_Sta!=0)						//����״̬
				DBrec.status|=STATION_LOCKED;
			else
				DBrec.status&=!STATION_LOCKED;

			DBrec.status|=STUS_DEVOPFED;

			if(AVCRec.IsGate==1)						//�ؿڱ�־
				DBrec.status|=STUS_GATEBUS;
			else
				DBrec.status&=!STUS_GATEBUS;

			if(AVCRec.Ctr_Sta==1)						//AVC���Ʊ�־
				DBrec.status|=STUS_DEVOPFED;
			else
				DBrec.status&=!STUS_DEVOPFED;

			DBrec.HiLimit=AVCRec.Volup;
			DBrec.LoLimit=AVCRec.Voldn;

			g_DB.UpdateRecord("Bus", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
		delete pnew;
	}

	ClearSysLimit(syslimit);
}

