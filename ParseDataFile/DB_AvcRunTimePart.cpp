// DB_AvcRunTimePart.cpp: implementation of the DB_AvcRunTimePart class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_AvcRunTimePart.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_AvcRunTimePart::DB_AvcRunTimePart()
{

}

DB_AvcRunTimePart::~DB_AvcRunTimePart()
{

}

void DB_AvcRunTimePart::RefreshModel(char *pData, int bufSize)
{
	DEVPLT_AVC_EMS_Model *pRec = (DEVPLT_AVC_EMS_Model*)pData;
	refavc_SetLim_table DBrec;
	ZeroMemory(&DBrec, sizeof(refavc_SetLim_table));

	CString m_szTmp;
	int m_recn=0;

	LSI_EmptyTable("refavc.SetLim_table", false);

	for (int i=0; i<bufSize/sizeof(DEVPLT_AVC_EMS_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		DEVPLT_AVC_EMS_Model* pnew = new DEVPLT_AVC_EMS_Model();
		memcpy(pnew, (pRec+i), sizeof(DEVPLT_AVC_EMS_Model));
		
		ZeroMemory(&DBrec, sizeof(refavc_SetLim_table));
		DBrec.shLimitNo=pnew->keyno;
		strcat(DBrec.szName,pnew->id);
		int index=1;

		CTime tm(2000,1,1,0,0,0);
		CTime lasttm(2000,1,1,0,0,0);
		if(pnew->tm1>0)
		{
//			CTime tm = pnew->tm1;
			CTime startm=lasttm;
			DBrec.tStartTime=startm;
			DBrec.tEndTime=tm+CTimeSpan(0,0,0,pnew->tm1);
			lasttm = DBrec.tEndTime;

			DBrec.shOrderNo=index++;
			DBrec.fVolLow=pnew->vdn1;
			DBrec.fVolUp=pnew->vup1;
			DBrec.fVarDown=pnew->cosfdn1;
			DBrec.fVarUp=pnew->cosfup1;
			DBrec.fShuntNum=pnew->cpnum1;
			DBrec.fTransNum=pnew->xfnum1;
			LSI_AppendRec("refavc.SetLim_table", &DBrec);
		}

		if(pnew->tm2>0)
		{
			DBrec.tStartTime=lasttm;
			DBrec.tEndTime=tm+CTimeSpan(0,0,0,pnew->tm2);
			lasttm = DBrec.tEndTime;

			DBrec.shOrderNo=index++;
			DBrec.fVolLow=pnew->vdn2;
			DBrec.fVolUp=pnew->vup2;
			DBrec.fVarDown=pnew->cosfdn2;
			DBrec.fVarUp=pnew->cosfup2;
			DBrec.fShuntNum=pnew->cpnum2;
			DBrec.fTransNum=pnew->xfnum2;
			LSI_AppendRec("refavc.SetLim_table", &DBrec);
		}
		if(pnew->tm3>0)
		{
			DBrec.tStartTime=lasttm;
			DBrec.tEndTime=tm+CTimeSpan(0,0,0,pnew->tm3);
			lasttm = DBrec.tEndTime;

			DBrec.shOrderNo=index++;
			DBrec.fVolLow=pnew->vdn3;
			DBrec.fVolUp=pnew->vup3;
			DBrec.fVarDown=pnew->cosfdn3;
			DBrec.fVarUp=pnew->cosfup3;
			DBrec.fShuntNum=pnew->cpnum3;
			DBrec.fTransNum=pnew->xfnum3;
			LSI_AppendRec("refavc.SetLim_table", &DBrec);
		}

		if(pnew->tm4>0)
		{
			DBrec.tStartTime=lasttm;
			DBrec.tEndTime=tm+CTimeSpan(0,0,0,pnew->tm4);
			lasttm = DBrec.tEndTime;

			DBrec.shOrderNo=index++;
			DBrec.fVolLow=pnew->vdn4;
			DBrec.fVolUp=pnew->vup4;
			DBrec.fVarDown=pnew->cosfdn4;
			DBrec.fVarUp=pnew->cosfup4;
			DBrec.fShuntNum=pnew->cpnum4;
			DBrec.fTransNum=pnew->xfnum4;
			LSI_AppendRec("refavc.SetLim_table", &DBrec);
		}

		if(pnew->tm5>0)
		{
			DBrec.tStartTime=lasttm;
			DBrec.tEndTime=tm+CTimeSpan(0,0,0,pnew->tm5);
			lasttm = DBrec.tEndTime;

			DBrec.shOrderNo=index++;
			DBrec.fVolLow=pnew->vdn5;
			DBrec.fVolUp=pnew->vup5;
			DBrec.fVarDown=pnew->cosfdn5;
			DBrec.fVarUp=pnew->cosfup5;
			DBrec.fShuntNum=pnew->cpnum5;
			DBrec.fTransNum=pnew->xfnum5;
			LSI_AppendRec("refavc.SetLim_table", &DBrec);
		}

		if((lasttm+CTimeSpan(0,0,0,1)).GetDay()==lasttm.GetDay())
		{
			DBrec.tStartTime=lasttm;
			DBrec.tEndTime=tm+CTimeSpan(1,0,0,0)-CTimeSpan(0,0,0,1);
			lasttm = DBrec.tEndTime;

			DBrec.shOrderNo=index++;
			DBrec.fVolLow=pnew->vdn6;
			DBrec.fVolUp=pnew->vup6;
			DBrec.fVarDown=pnew->cosfdn6;
			DBrec.fVarUp=pnew->cosfup6;
			DBrec.fShuntNum=pnew->cpnum6;
			DBrec.fTransNum=pnew->xfnum6;
			LSI_AppendRec("refavc.SetLim_table", &DBrec);
		}


		//���AVC������Ϣ
		ScadaAVC_AVCTimePart AVCRec;
		ZeroMemory(&AVCRec, sizeof(AVCRec));

		AVCRec.ID=pnew->keyno;							//���
		strcat(AVCRec.Name,pnew->id);						//ʱ������
		AVCRec.VUp1=pnew->vup1;						//��ѹ����1
		AVCRec.VDn1=pnew->vdn1;						//��ѹ����1
		AVCRec.CP_Num1=pnew->cpnum1;						//���ݿɿش���1
		AVCRec.XF_Num1=pnew->xfnum1;						//��ѹ���ɿش���1
		AVCRec.CosUp1=pnew->cosfup1;						//������������1
		AVCRec.CosDn1=pnew->cosfdn1;						//������������1
		AVCRec.Tm1=tm+CTimeSpan(0,0,0,pnew->tm1);							//ʱ��1�ָ��
		AVCRec.VUp2=pnew->vup2;						//��ѹ����2
		AVCRec.VDn2=pnew->vdn2;						//��ѹ����2
		AVCRec.CP_Num2=pnew->cpnum2;						//���ݿɿش���2
		AVCRec.XF_Num2=pnew->xfnum2;						//��ѹ���ɿش���2
		AVCRec.CosUp2=pnew->cosfup2;						//������������2
		AVCRec.CosDn2=pnew->cosfdn2;						//������������2
		AVCRec.Tm2=tm+CTimeSpan(0,0,0,pnew->tm2);							//ʱ��2�ָ��
		AVCRec.VUp3=pnew->vup3;						//��ѹ����3
		AVCRec.VDn3=pnew->vdn3;						//��ѹ����3
		AVCRec.CP_Num3=pnew->cpnum3;						//���ݿɿش���3
		AVCRec.XF_Num3=pnew->xfnum3;						//��ѹ���ɿش���3
		AVCRec.CosUp3=pnew->cosfup3;						//������������3
		AVCRec.CosDn3=pnew->cosfdn3;						//������������3
		AVCRec.Tm3=tm+CTimeSpan(0,0,0,pnew->tm3);							//ʱ��3�ָ��
		AVCRec.VUp4=pnew->vup4;						//��ѹ����4
		AVCRec.VDn4=pnew->vdn4;						//��ѹ����4
		AVCRec.CP_Num4=pnew->cpnum4;						//���ݿɿش���4
		AVCRec.XF_Num4=pnew->xfnum4;						//��ѹ���ɿش���4
		AVCRec.CosUp4=pnew->cosfup4;						//������������4
		AVCRec.CosDn4=pnew->cosfdn4;						//������������4
		AVCRec.Tm4=tm+CTimeSpan(0,0,0,pnew->tm4);							//ʱ��4�ָ��
		AVCRec.VUp5=pnew->vup5;						//��ѹ����5
		AVCRec.VDn5=pnew->vdn5;						//��ѹ����5
		AVCRec.CP_Num5=pnew->cpnum5;						//���ݿɿش���5
		AVCRec.XF_Num5=pnew->xfnum5;						//��ѹ���ɿش���5
		AVCRec.CosUp5=pnew->cosfup5;						//������������5
		AVCRec.CosDn5=pnew->cosfdn5;						//������������5
		AVCRec.Tm5=tm+CTimeSpan(0,0,0,pnew->tm5);							//ʱ��1�ָ��
		AVCRec.VUp6=pnew->vup6;						//��ѹ����6
		AVCRec.VDn6=pnew->vdn6;						//��ѹ����6
		AVCRec.CP_Num6=pnew->cpnum6;						//���ݿɿش���6
		AVCRec.XF_Num6=pnew->xfnum6;						//��ѹ���ɿش���6
		AVCRec.CosUp6=pnew->cosfup6;						//������������6
		AVCRec.CosDn6=pnew->cosfdn6;						//������������6

		AVCRec.LogTime = g_TimeFile;
	
		m_szTmp.Format("TABLE(ScadaAVC.AVCTimePart),WHERE(ID=%d)", pnew->keyno);
		ScadaAVC_AVCTimePart* pAvcRec = (ScadaAVC_AVCTimePart*)g_DB.QueryRecord("AVCTimePart",m_szTmp.GetBuffer(0),m_recn,"ScadaAVC");

		if(pAvcRec != NULL)
		{
			g_DB.UpdateRecord("AVCTimePart", m_szTmp.GetBuffer(0), &AVCRec, "ScadaAVC");
		}
		else
		{
			LSI_AppendRec("ScadaAVC.AVCTimePart", &AVCRec);
		}
		delete pnew;
	}
}