// DB_AvcShunt.cpp: implementation of the DB_AvcShunt class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AvcShunt.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AvcShunt::DB_AvcShunt()
{

}

DB_AvcShunt::~DB_AvcShunt()
{

}

void DB_AvcShunt::RefreshModel(char *pData, int bufSize)
{
	CPM_AVC_EMS_Model *pRec = (CPM_AVC_EMS_Model*)pData;
	visualpw_Shunt DBrec, *pDBrec;
	PositionShunt *pPosShunt;
	CString m_szTmp;
	int m_recn=0, m_nRet;

	for (int i=0; i<bufSize/sizeof(CPM_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		CPM_AVC_EMS_Model* pnew = new CPM_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(CPM_AVC_EMS_Model));

		ZeroMemory(&DBrec, sizeof(DBrec));
		
		BYTE AVCCtrl = GetStationAVCSta(pnew->fac_id);

		//m_szTmp.Format("TABLE(visualpw.Shunt),WHERE(NU=%d)", pRec[i].cpid);
		//pDBrec = (visualpw_Shunt*)g_DB.QueryRecord("Shunt",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = g_DataBase.m_pwShuntSreact.BinaryFindShuntByNu(pRec[i].cpid);
		if(m_nRet != -1)
		{
			pDBrec = &g_DataBase.m_pwShuntSreact.m_VecShunt.at(m_nRet).rec;
			pPosShunt = &g_DataBase.m_pwShuntSreact.m_VecShunt.at(m_nRet);
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			DBrec.CtrlType=pnew->pltyp;
			if(pnew->offavr!=0)
				DBrec.status|=STATION_LOCKED;
			else
				DBrec.status&=!STATION_LOCKED;

			if(AVCCtrl==1)							//����״̬
				DBrec.status|=STUS_DEVOPFED;
			else
				DBrec.status&=!STUS_DEVOPFED;

			if(pnew->ykno>=0)		//�ɿ���
				DBrec.status|=STUS_CTRL_HI;
			else
				DBrec.status&=!STUS_CTRL_HI;

			g_ComFunc.PutCol(&pDBrec->CtrlType, pRec[i].pltyp, g_DataBase.m_pwShuntSreact.m_nTableID_Shunt, pPosShunt->nPos, "CtrlType");
			g_ComFunc.PutCol(&pDBrec->status, DBrec.status, g_DataBase.m_pwShuntSreact.m_nTableID_Shunt, pPosShunt->nPos, "status");

			//g_DB.UpdateRecord("Shunt", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}


		//����AVCͳ����Ϣ
		ScadaAVC_AVCShunt AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.ID=pnew->cpid;							//����ID
		if(MatchKeyNo(pnew->cpid, RC_DEVICE_MODEL) == false)
		{
			delete pnew;
			break;
		}

		AVCRec.StationID=pnew->fac_id;					//��վID
		GetDevName(AVCRec.ID, EQUIP_TYPE_SHUNT, AVCRec.Name);						//��������
		AVCRec.CtrlID=pnew->pltyp;						//����ʱ��ID
		AVCRec.Cal_Sta=AVCCtrl;						//�Ƿ�AVC����
//		AVCRec.Cal_Sta=pnew->qavr;						//�������
		AVCRec.Lock_Sta=pnew->offavr;						//����״̬
		AVCRec.LimitNum=pnew->limtnum;						//������������
		AVCRec.YXID=pnew->yxid;						//ң��ID
		AVCRec.YKNO=pnew->ykno;						//ң�ص��
		AVCRec.BusID=pnew->isbsid;					//����ĸ��ID
		AVCRec.BreakID=pnew->yxid;						//���ƿ���ID
		AVCRec.DCtrlNum=pnew->tnumday;						//�ն�������
		AVCRec.DAVCCtrlNum=pnew->cnumday;					//��AVC��������
		AVCRec.DAVCActNum=pnew->numday;					//��AVC��������
		AVCRec.DRunTime=pnew->rtmday;					//������ʱ��
		AVCRec.MRunTime=pnew->rtmmon;					//������ʱ��
		AVCRec.YRunTime=pnew->rtmyea;					//������ʱ��

		AVCRec.LogTime = g_TimeFile;

		m_szTmp.Format("TABLE(ScadaAVC.AVCShunt),WHERE(ID=%d)", pRec[i].cpid);
		ScadaAVC_AVCShunt* pAvcRec = (ScadaAVC_AVCShunt*)g_DB.QueryRecord("AVCShunt",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			AVCRec.H24CtrlNum=pAvcRec->H24CtrlNum;					//24Сʱ��������
			AVCRec.H24AVCCtrlNum=pAvcRec->H24AVCCtrlNum;				//24СʱAVC��������
			AVCRec.H24AVCActNum=pAvcRec->H24AVCActNum;				//24СʱAVC��������
			AVCRec.MCtrlNum=pAvcRec->MCtrlNum;					//�¶�������
			AVCRec.MAVCCtrlNum=pAvcRec->MAVCCtrlNum;					//��AVC��������
			AVCRec.MAVCActNum=pAvcRec->MAVCActNum;					//��AVC��������
			AVCRec.YCtrlNum=pAvcRec->YCtrlNum;					//�궯������
			AVCRec.YAVCCtrlNum=pAvcRec->YAVCCtrlNum;					//��AVC��������
			AVCRec.YAVCActNum=pAvcRec->YAVCActNum;					//��AVC��������
			AVCRec.H24RunTime=pAvcRec->H24RunTime;					//24Сʱ����ʱ��

			g_DB.UpdateRecord("AVCShunt", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCShunt", &AVCRec);
		}

		delete pnew;
	}
}