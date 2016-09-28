// DB_PASMeasure.cpp: implementation of the DB_PASMeasure class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_PASMeasure.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_PASMeasure::DB_PASMeasure()
{

}

DB_PASMeasure::~DB_PASMeasure()
{

}

void DB_PASMeasure::RefreshModel(char *pData, int bufSize)
{
	
	SEMEAS_RTNET_EMS_Model *pRec = (SEMEAS_RTNET_EMS_Model*)pData;
	ScadaAVC_PasSEMeasure DBrec;
	int m_recn;
	LSI_EmptyTable("ScadaAVC.PasSEMeasure", false);
	return;

	for (int i=0; i<bufSize/sizeof(SEMEAS_RTNET_EMS_Model); i++)
	{
		SEMEAS_RTNET_EMS_Model* pnew = new SEMEAS_RTNET_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(SEMEAS_RTNET_EMS_Model));

		ZeroMemory(&DBrec, sizeof(DBrec));

		ScadaAVC_PasSEMeasure* pDBrec1 = (ScadaAVC_PasSEMeasure*)g_DB.QueryRecord("PasSEMeasure",NULL,m_recn,"ScadaAVC");

		DBrec.Station=pnew->keyno;						//��վ��
		if(MatchKeyNo(pnew->keyno, SEMEAS_RTNET_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		DBrec.DevID=pnew->devid;						//�豸ID
		DBrec.DevType=pnew->devmtyp;						//�豸����
		DBrec.MeasType=pnew->devmtyp;						//��������
		DBrec.MeasPos=pnew->meassub;						//����λ��
		GetDevMeasureName(pnew,DBrec.MeasInfo);
		DBrec.Island=0;//pnew->island;						//����
		DBrec.Meas_value=pnew->measval;					//����ֵ
		DBrec.SE_value=pnew->seval;					//״̬����ֵ
		DBrec.Err_value=pnew->err;					//���ٷ���
		DBrec.Error=pnew->qbigerr;						//���ϸ�����
		DBrec.BadData=pnew->qbad;						//������

//		if(pDBrec1==NULL)
			LSI_AppendRec("ScadaAVC.PasSEMeasure", &DBrec);
/*		else
		{
			DBrec.DHisRate=pDBrec1->DHisRate;						//�պϸ�ͳ����
			DBrec.MHisRate=pDBrec1->MHisRate;					//�ºϸ�ͳ����
			LSI_UpdateARecord("ScadaAVC.PasSEMeasure", &DBrec,0);
		}*/
		delete pnew;
	}
}
