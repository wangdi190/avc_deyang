// DB_PASRuninfo.cpp: implementation of the DB_PASRuninfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_PASRuninfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_PASRuninfo::DB_PASRuninfo()
{

}

DB_PASRuninfo::~DB_PASRuninfo()
{

}

void DB_PASRuninfo::RefreshModel(char *pData, int bufSize)
{
	LSI_EmptyTable("ScadaAVC.PasRunInfo", false);

	RECENTMSG_COMM_EMS_Model *pRec = (RECENTMSG_COMM_EMS_Model*)pData;
	ScadaAVC_PasRunInfo DBrec;

	for (int i=0; i<bufSize/sizeof(RECENTMSG_COMM_EMS_Model); i++)
	{
		RECENTMSG_COMM_EMS_Model* pnew = new RECENTMSG_COMM_EMS_Model();
		memcpy(pnew, &pRec[i], sizeof(RECENTMSG_COMM_EMS_Model));

		ZeroMemory(&DBrec, sizeof(DBrec));

		DBrec.RunTime=pnew->time-CTimeSpan(0, 8, 0, 0);						//运行时间
		DBrec.LogTime=g_TimeFile;
		strcat(DBrec.RunInfo, pnew->msg);					//运行信息

		LSI_AppendRec("ScadaAVC.PasRunInfo", &DBrec);
		delete pnew;
	}
}
