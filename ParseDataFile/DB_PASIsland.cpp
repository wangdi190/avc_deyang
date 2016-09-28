// DB_PASIsland.cpp: implementation of the DB_PASIsland class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_PASIsland.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_PASIsland::DB_PASIsland()
{

}

DB_PASIsland::~DB_PASIsland()
{

}

void DB_PASIsland::RefreshModel(char *pData, int bufSize)
{
	LSI_EmptyTable("ScadaAVC.PasIsland", false);
	DIILND_COMM_EMS_Model *pRec = (DIILND_COMM_EMS_Model*)pData;
	ScadaAVC_PasIsland DBrec;
	int m_recn=0;
	CTime ctm = CTime::GetCurrentTime();

	for (int i=0; i<bufSize/sizeof(DIILND_COMM_EMS_Model); i++)
	{
		DIILND_COMM_EMS_Model* pnew = new DIILND_COMM_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(DIILND_COMM_EMS_Model));

		ZeroMemory(&DBrec, sizeof(DBrec));

		DBrec.NU=pnew->keyno;							//���
		if(MatchKeyNo(pnew->keyno, DIILND_COMM_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		DBrec.IslandID=pnew->isrec;					//����
		DBrec.Station=pnew->stid;						//ƽ�������
		strcat(DBrec.StaName, pnew->chst);					//ƽ�������
		DBrec.GenID=pnew->unid;						//ƽ���ID
		strcat(DBrec.GenName, pnew->un);					//ƽ�����
		DBrec.NodeNum=pnew->bus;						//�ڵ���
		DBrec.State=pnew->stat;						//������
		DBrec.Obisle=pnew->obisle;						//�ɹ۲���
		DBrec.BadDataP=pnew->lvbadp;						//�й�������
		DBrec.BadDataQ=pnew->lvbadq;						//�޹�������
		DBrec.SERunTime=ctm;					//����ʱ��
		DBrec.LogTime = g_TimeFile;
		

		LSI_AppendRec("ScadaAVC.PasIsland", &DBrec);
		delete pnew;
	}
}
