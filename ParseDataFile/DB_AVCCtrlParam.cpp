// DB_AVCCtrlParam.cpp: implementation of the DB_AVCCtrlParam class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AVCCtrlParam.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AVCCtrlParam::DB_AVCCtrlParam()
{

}

DB_AVCCtrlParam::~DB_AVCCtrlParam()
{

}

void DB_AVCCtrlParam::RefreshModel(char *pData, int bufSize)
{
//	int n = sizeof(CTime);

	ITEM_AVC_EMS_Model *pRec = (ITEM_AVC_EMS_Model*)pData;
	ScadaAVC_AVCCtrRunParam DBrec;
	ZeroMemory(&DBrec, sizeof(ScadaAVC_AVCCtrRunParam));

	CTime lasttm=CTime(2000,1,1,0,0,0);
	ScadaAVC_AVCCtrRunParam* pparam=NULL;
	int datanum=0;
	CUIntArray posarray;
	if(SearchData("ScadaAVC", "AVCCtrRunParam", "", "StartTime", (void**)&pparam, datanum, posarray))
	{
		if(datanum>0)
			lasttm=(pparam+datanum-1)->StartTime;
	}
	
	if(pparam!=NULL)
	{
		delete []pparam;
	}

	CString m_szTmp;
	int m_recn=0;

	for (int i=0; i<bufSize/sizeof(ITEM_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		ITEM_AVC_EMS_Model* pnew = new ITEM_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(ITEM_AVC_EMS_Model));

		ZeroMemory(&DBrec, sizeof(ScadaAVC_AVCCtrRunParam));
		ScadaAVC_AVCCtrRunParam AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		CTime starttime=pnew->strtime-CTimeSpan(0, 8, 0, 0);
		if(starttime<=lasttm)
		{
			delete pnew;
			continue;
		}
		lasttm=starttime;

		AVCRec.DateLog=g_TimeFile;//CTime::GetCurrentTime();						//ϵͳ������־ʱ��
		strcat(AVCRec.SysInfo, pnew->sysinfo);					//ϵͳ��Ϣ
		strcat(AVCRec.RunMsg, pnew->avcmsg);					//������Ϣ
		AVCRec.RunNum=pnew->avcnum;						//���д���
		AVCRec.StartTime=pnew->strtime-CTimeSpan(0, 8, 0, 0);					//����ʱ��
		AVCRec.AvcTime=pnew->avctime-CTimeSpan(0, 8, 0, 0);						//AVC����ʱ��
		AVCRec.Run_Sta=pnew->run;						//����״̬
		AVCRec.Auto_Sta=pnew->aut;						//�Զ�����״̬
		AVCRec.Quit_Sta=pnew->abort;						//�����˳�״̬
		AVCRec.Cmd_Sta=pnew->cmd;						//�����·�״̬
		AVCRec.Remote_Sta=pnew->remote;					//Զ��״̬
		AVCRec.Enable_Sta=pnew->enable;					//AVC���ñ�־
		AVCRec.Cycvol=pnew->cycvol;						//��������
		AVCRec.Ctrlmtd=pnew->ctrlmtd;						//�����㷨
		AVCRec.Ctrl_CP=pnew->ctrlre;						//���ݿ���״̬
		AVCRec.Ctrl_Cos=pnew->ctrlcq;						//�����޹�����״̬
		AVCRec.Ctrl_Vol=pnew->ctrltcv;						//�����ѹ����״̬
		AVCRec.Xfre_space=pnew->xfregin;					//�������ʱ����
		AVCRec.CPOut_space=pnew->cpouin;					//����Ͷ���˳�ʱ����
		AVCRec.CPIn_space=pnew->cpinin;					//�����˳�Ͷ��ʱ����
		AVCRec.Zone_space=pnew->znctlin;					//�������ʱ����
		AVCRec.Xfr_overload=pnew->xfhvld;				//�������ϵ��
		AVCRec.AvcUse_Rate=pnew->avcuper;					//AVC������
		AVCRec.AvcClosedTime=pnew->avcautt;				//AVC�ջ�����ʱ��
		AVCRec.CtrlNum=pnew->ctrlnum;						//AVC����ָ����
		AVCRec.CtrlSucNum=pnew->ctrlsuc;					//AVC���Ƴɹ���
		AVCRec.CtrlSuc_Rate=pnew->sucper;				//AVC���Ƴɹ���
		AVCRec.MaxCtrlNum=pnew->mxopnum;					//���ɶ��豸��
		AVCRec.CP_RefuseNum=pnew->cpacfnm;				//�ݿ��ܶ�����
		AVCRec.XF_RefuseNum=pnew->xfacfnm;				//��ѹ���ܶ�����
		AVCRec.lossdec=pnew->lossdec;						//�ս�����

//		m_szTmp.Format("TABLE(ScadaAVC.AVCCtrRunParam),WHERE(StartTime=%d)", AVCRec.StartTime);
//		ScadaAVC_AVCCtrRunParam* pAvcRec = (ScadaAVC_AVCCtrRunParam*)g_DB.QueryRecord("AVCCtrRunParam",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");
//		if(pAvcRec == NULL)
			LSI_AppendRec("ScadaAVC.AVCCtrRunParam", &AVCRec);
		delete pnew;
	}
}