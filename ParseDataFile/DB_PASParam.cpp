// DB_PASParam.cpp: implementation of the DB_PASParam class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_PASParam.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_PASParam::DB_PASParam()
{

}

DB_PASParam::~DB_PASParam()
{

}

void DB_PASParam::RefreshModel(char *pData, int bufSize)
{
	
	PARA_RTNET_EMS_Model *pRec = (PARA_RTNET_EMS_Model*)pData;
	ScadaAVC_PasSEParam DBrec;
	int m_recn;
	LSI_EmptyTable("ScadaAVC.PasSEParam", false);

	for (int i=0; i<bufSize/sizeof(PARA_RTNET_EMS_Model); i++)
	{
		PARA_RTNET_EMS_Model* pnew = new PARA_RTNET_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(PARA_RTNET_EMS_Model));

		ZeroMemory(&DBrec, sizeof(DBrec));

		ScadaAVC_PasSEParam* pDBrec1 = (ScadaAVC_PasSEParam*)g_DB.QueryRecord("PasSEParam",NULL,m_recn,"ScadaAVC");

		DBrec.Run_State=pnew->run_flag;					//��ǰ����״̬
		DBrec.Pause_State=pnew->pause_flag;					//��ͣ����״̬
		DBrec.RunTime=pnew->hourmark;//+pnew->datemark;						//����ʱ��
		DBrec.Conv_State=pnew->conv_state;					//��ǰ����״̬
		DBrec.Measure_Rate=pnew->estimable_rate;				//ң�⸲����
		DBrec.CycleTime=pnew->conv_rate;					//��������(��)
		DBrec.MaxIter=pnew->iter_step_limit;						//����������
		DBrec.EpsP=pnew->epsp;						//�й���������
		DBrec.EpsQ1=pnew->epsq;						//�޹���������

		if(pDBrec1==NULL)
			LSI_AppendRec("ScadaAVC.PasSEParam", &DBrec);
		else
		{
			DBrec.SE_Rate=pDBrec1->SE_Rate;						//��ǰ״���ϸ���
			DBrec.SE_DayRate=pDBrec1->SE_DayRate;					//����״���ϸ���
			DBrec.SE_MonRate=pDBrec1->SE_MonRate;					//��״���ϸ���
			DBrec.SE_YearRate=pDBrec1->SE_YearRate;					//��״���ϸ���
			DBrec.LogTime=g_TimeFile;
			LSI_UpdateARecord("ScadaAVC.PasSEParam", &DBrec,0);
		}
		delete pnew;
	}
}
