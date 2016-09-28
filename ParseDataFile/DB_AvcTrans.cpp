// DB_AvcTrans.cpp: implementation of the DB_AvcTrans class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AvcTrans.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AvcTrans::DB_AvcTrans()
{

}

DB_AvcTrans::~DB_AvcTrans()
{

}

void DB_AvcTrans::RefreshModel(char *pData, int bufSize)
{
	XFM_AVC_EMS_Model *pRec = (XFM_AVC_EMS_Model*)pData;
	visualpw_Tfm1 DBrec1, *pDBrec1;
	visualpw_Tfm2 DBrec2, *pDBrec2;
	CString m_szTmp;
	int m_recn=0;
	CPtrArray syslimit;
	LoadSystemLimit(syslimit);

	for (int i=0; i<bufSize/sizeof(XFM_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		XFM_AVC_EMS_Model* pnew = new XFM_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(XFM_AVC_EMS_Model));
		ZeroMemory(&DBrec1, sizeof(DBrec1));

		BYTE AVCCtrl = GetStationAVCSta(pnew->fac_id);

		float limit[4];
		
		m_szTmp.Format("TABLE(visualpw.Tfm1),WHERE(NU=%d)", pRec[i].trid);
		pDBrec1 = (visualpw_Tfm1*)g_DB.QueryRecord("Tfm1",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		if(pDBrec1 != NULL)
		{
			memcpy(&DBrec1, pDBrec1, sizeof(DBrec1));

			DBrec1.CtrlType=pnew->pltyp;

			GetVolLimit(syslimit, pnew->pltyp, limit, 0.0, g_TimeFile, pnew->qgate);
			float fCosdn=limit[3];						//��������
			float fCosup=limit[2];						//��������

			if(pnew->offavr!=0)
				DBrec1.status|=STATION_LOCKED;
			else
				DBrec1.status&=!STATION_LOCKED;

			if(AVCCtrl==1)							//����״̬
				DBrec1.status|=STUS_DEVOPFED;
			else
				DBrec1.status&=!STUS_DEVOPFED;

			if(pnew->upykno>=0&&pnew->dnykno>=0)		//�ɿ���
				DBrec1.status|=STUS_CTRL_HI;
			else
				DBrec1.status&=!STUS_CTRL_HI;

			DBrec1.CosDn=fCosdn;
			DBrec1.CosUp=fCosup;
			//DBrec1.status|=STUS_DEVOPFED;
			
			g_DB.UpdateRecord("Tfm1", m_szTmp.GetBuffer(0), &DBrec1, "visualpw");
		}
		else
		{
			m_szTmp.Format("TABLE(visualpw.Tfm2),WHERE(NU=%d)", pRec[i].trid);
			pDBrec2 = (visualpw_Tfm2*)g_DB.QueryRecord("Tfm2",m_szTmp.GetBuffer(0),m_recn,"visualpw");
			if(pDBrec2 != NULL)
			{
				memcpy(&DBrec2, pDBrec2, sizeof(DBrec2));

				DBrec2.CtrlType=pnew->pltyp;
				GetVolLimit(syslimit, pnew->pltyp, limit, 0.0, g_TimeFile, pnew->qgate);
				float fCosdn=limit[3];						//��������
				float fCosup=limit[2];						//��������

				if(pnew->offavr!=0)						//����״̬
					DBrec2.status|=STATION_LOCKED;
				else
					DBrec2.status&=!STATION_LOCKED;

				if(AVCCtrl==1)							//����״̬
					DBrec2.status|=STUS_DEVOPFED;
				else
					DBrec2.status&=!STUS_DEVOPFED;

				if(pnew->upykno>=0&&pnew->dnykno>=0)		//�ɿ���
					DBrec2.status|=STUS_CTRL_HI;
				else
					DBrec2.status&=!STUS_CTRL_HI;

				DBrec2.status|=STUS_DEVOPFED;
				DBrec2.CosDn=fCosdn;
				DBrec2.CosUp=fCosup;
				
				g_DB.UpdateRecord("Tfm2", m_szTmp.GetBuffer(0), &DBrec2, "visualpw");
			}
		}

		//����AVCͳ����Ϣ
		ScadaAVC_AVCTrans AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.ID=pnew->trid;						//��ѹ��ID
		if(MatchKeyNo(pnew->trid, TR_DEVICE_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.StationID=pnew->fac_id;					//��վID
		GetDevName(AVCRec.ID, EQUIP_TYPE_BITRS, AVCRec.Name);								//��ѹ������
		AVCRec.CtrlID=pnew->pltyp;						//����ʱ��ID
//		AVCRec.Cal_Sta=pnew->qavr;						//��������ʶ
		AVCRec.Cal_Sta=AVCCtrl;						//�Ƿ�AVC����
		AVCRec.Lock_Sta=pnew->offavr;					//������ʶ
		AVCRec.IsGate=pnew->qgate;						//�ؿڱ�ѹ��
		AVCRec.LimitNumber=pnew->limtnum;					//���ƴ�������
		AVCRec.UpYXID=pnew->upyxid;						//����ң��ID
		AVCRec.UpYKNO=pnew->upykno;						//����ң�ص��
		AVCRec.DnYXID=pnew->dnyxid;						//����ң��ID
		AVCRec.DnYKNO=pnew->dnykno;						//����ң�ص��
		AVCRec.LinkBusID=pnew->isbsid;					//����ĸ��ID
		AVCRec.DCtrlNum=pnew->numday;					//�տ��ƴ���
		AVCRec.DAVCCtrlNum=pnew->tnumday;					//��AVC���ƴ���
		AVCRec.DAVCActNum=pnew->cnumday;					//��AVC��������
		AVCRec.MCtrlNum=pnew->nummon;					//�¿��ƴ���
		AVCRec.MAVCCtrlNum=pnew->tnummon;					//��AVC���ƴ���
		AVCRec.MAVCActNum=pnew->cnummon;					//��AVC��������
		AVCRec.YCtrlNum=pnew->numyea;					//����ƴ���
		AVCRec.YAVCCtrlNum=pnew->tnumyea;					//��AVC���ƴ���
		AVCRec.YAVCActNum=pnew->cnumyea;					//��AVC��������

		AVCRec.LogTime = g_TimeFile;

		m_szTmp.Format("TABLE(ScadaAVC.AVCTrans),WHERE(ID=%d)", AVCRec.ID);
		ScadaAVC_AVCTrans* pAvcRec = (ScadaAVC_AVCTrans*)g_DB.QueryRecord("AVCTrans",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			AVCRec.H24CtrlNum=pAvcRec->H24CtrlNum;					//24Сʱ���ƴ���
			AVCRec.H24AVCCtrlNum=pAvcRec->H24AVCCtrlNum;				//24СʱAVC���ƴ���
			AVCRec.H24AVCActNum=pAvcRec->H24AVCActNum;				//24СʱAVC��������
			g_DB.UpdateRecord("AVCTrans", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCTrans", &AVCRec);
		}
		
		delete pnew;
	}
	ClearSysLimit(syslimit);
}