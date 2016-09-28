// DB_AvcRunParam.cpp: implementation of the DB_AvcRunParam class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AvcRunParam.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AvcRunParam::DB_AvcRunParam()
{

}

DB_AvcRunParam::~DB_AvcRunParam()
{

}

void DB_AvcRunParam::RefreshModel(char *pData, int bufSize)
{
	RUNPLT_AVC_EMS_Model *pRec = (RUNPLT_AVC_EMS_Model*)pData;
	refavc_Avc_RunParam DBrec;
	ZeroMemory(&DBrec, sizeof(refavc_Avc_RunParam));

	CString m_szTmp;
	int m_recn=0;

	LSI_EmptyTable("refavc.Avc_RunParam", false);

	for (int i=0; i<bufSize/sizeof(RUNPLT_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		RUNPLT_AVC_EMS_Model* pnew = new RUNPLT_AVC_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(RUNPLT_AVC_EMS_Model));

		
		ZeroMemory(&DBrec, sizeof(refavc_Avc_RunParam));
		DBrec.NU=i+1;
		DBrec.type=pnew->type;						//0�߷� 1�͹�
		DBrec.starttime=CTime(2000,1,1,0,0,0);//pnew->strtm;
		DBrec.starttime+=CTimeSpan(0,0,0,pnew->strtm);
		DBrec.endtime=CTime(2000,1,1,0,0,0);
		DBrec.endtime+=CTimeSpan(0,0,0,pnew->endtm);
		DBrec.GateCosup=pnew->cosfup;
		DBrec.GateCosdn=pnew->cosfdn;
		DBrec.FacCosup=pnew->scosfup;
		DBrec.FacCosdn=pnew->scosfdn;
		DBrec.capnum=pnew->cpnum;
		DBrec.tfmnum=pnew->xfnum;

		if(pnew->v6up>0)
		{
			DBrec.BaseVol=6.0;
			DBrec.Volup=pnew->v6up;
			DBrec.Voldn=pnew->v6dn;
			LSI_AppendRec("refavc.Avc_RunParam", &DBrec);
		}
		if(pnew->v10up>0)
		{
			DBrec.BaseVol=10.0;
			DBrec.Volup=pnew->v10up;
			DBrec.Voldn=pnew->v10dn;
			LSI_AppendRec("refavc.Avc_RunParam", &DBrec);
		}
		if(pnew->v35up>0)
		{
			DBrec.BaseVol=35.0;
			DBrec.Volup=pnew->v35up;
			DBrec.Voldn=pnew->v35dn;
			LSI_AppendRec("refavc.Avc_RunParam", &DBrec);
		}
		if(pnew->v110up>0)
		{
			DBrec.BaseVol=110.0;
			DBrec.Volup=pnew->v110up;
			DBrec.Voldn=pnew->v110dn;
			LSI_AppendRec("refavc.Avc_RunParam", &DBrec);
		}
		if(pnew->v220up>0)
		{
			DBrec.BaseVol=220.0;
			DBrec.Volup=pnew->v220up;
			DBrec.Voldn=pnew->v220dn;
			LSI_AppendRec("refavc.Avc_RunParam", &DBrec);
		}
	/*	if(pnew->v500up>0)
		{
			DBrec.BaseVol=500.0;
			DBrec.Volup=pnew->v500up;
			DBrec.Voldn=pnew->v500dn;
			LSI_AppendRec("refavc.Avc_RunParam", &DBrec);
		}*/

		//���AVC������Ϣ
		ScadaAVC_AVCRunParam AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.ID=pnew->keyno;							//���

		if(MatchKeyNo(pnew->keyno, RUNPLT_AVC_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}


		AVCRec.srttm=CTime(2000,1,1,0,0,0)+CTimeSpan(0,0,0,pnew->strtm);						//��ʼʱ��
		AVCRec.endtm=CTime(2000,1,1,0,0,0)+CTimeSpan(0,0,0,pnew->endtm);						//����ʱ��
		AVCRec.Type=pnew->type;							//ʱ������
		//AVCRec.Msg[32]=pnew->;						//ʱ������
		AVCRec.CPNum=pnew->cpnum;						//���ݿ��ô���
		AVCRec.XfrNum=pnew->xfnum;						//��ѹ�����ô���
		AVCRec.CosUp=pnew->cosfup;						//�ؿڹ�����������
		AVCRec.CosDn=pnew->cosfdn;						//�ؿڹ�����������
		AVCRec.SCosUp=pnew->scosfup;						//��վ������������
		AVCRec.SCosDn=pnew->scosfdn;						//��վ������������
		AVCRec.V6Up=pnew->v6up;						//6KV����
		AVCRec.V6Dn=pnew->v6dn;						//6KV����
		AVCRec.V10Up=pnew->v10up;						//10KV����
		AVCRec.V10Dn=pnew->v10dn;						//10KV����
		AVCRec.V35Up=pnew->v35up;						//35KV����
		AVCRec.V35Dn=pnew->v35dn;						//35KV����
		AVCRec.V110Up=pnew->v110up;						//110KV����
		AVCRec.V110Dn=pnew->v110dn;						//110KV����
		AVCRec.V220Up=pnew->v220up;						//220KV����
		AVCRec.V220Dn=pnew->v220dn;						//220KV����
		AVCRec.V330Up=pnew->v330up;						//330KV����
		AVCRec.V330Dn=pnew->v330dn;						//330KV����

		AVCRec.LogTime = g_TimeFile;

		m_szTmp.Format("TABLE(ScadaAVC.AVCRunParam),WHERE(ID=%d)", pnew->keyno);
		ScadaAVC_AVCRunParam* pAvcRec = (ScadaAVC_AVCRunParam*)g_DB.QueryRecord("AVCRunParam",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCRunParam", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCRunParam", &AVCRec);
		}

		delete pnew;
	}
}