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

		DBrec.NU=pnew->keyno;							//序号
		if(MatchKeyNo(pnew->keyno, DIILND_COMM_EMS_MODEL) == false)
		{
			delete pnew;
			break;
		}

		DBrec.IslandID=pnew->isrec;					//岛号
		DBrec.Station=pnew->stid;						//平衡机厂号
		strcat(DBrec.StaName, pnew->chst);					//平衡机厂名
		DBrec.GenID=pnew->unid;						//平衡机ID
		strcat(DBrec.GenName, pnew->un);					//平衡机名
		DBrec.NodeNum=pnew->bus;						//节点数
		DBrec.State=pnew->stat;						//收敛性
		DBrec.Obisle=pnew->obisle;						//可观测性
		DBrec.BadDataP=pnew->lvbadp;						//有功坏数据
		DBrec.BadDataQ=pnew->lvbadq;						//无功坏数据
		DBrec.SERunTime=ctm;					//运行时间
		DBrec.LogTime = g_TimeFile;
		

		LSI_AppendRec("ScadaAVC.PasIsland", &DBrec);
		delete pnew;
	}
}
