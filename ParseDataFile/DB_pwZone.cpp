// DB_pwZone.cpp: implementation of the DB_pwZone class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_pwZone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_pwZone::DB_pwZone()
{

}

DB_pwZone::~DB_pwZone()
{

}

void DB_pwZone::RefreshModel(char *pData, int bufSize)
{
	
	DIV_INFO_Model *pRec = (DIV_INFO_Model*)pData;
	visualpw_Zone DBrec, *pDBrec;
	
	for (int i=0; i<bufSize/sizeof(DIV_INFO_Model); i++)
	{
		if(MatchKeyNo(pRec[i].area_id, DIV_INFO_MODEL) == false)
		{
			break;
		}

		ZeroMemory(&DBrec, sizeof(DBrec));
		
		m_szTmp.Format("TABLE(visualpw.Zone),WHERE(NU=%d)", pRec[i].area_id);
		pDBrec = (visualpw_Zone*)g_DB.QueryRecord("Zone",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		if(pDBrec == NULL)
		{
			DBrec.NU = pRec[i].area_id;
			strcpy(DBrec.Name, pRec[i].area_name);
			DBrec.LogTime=g_TimeFile;
			LSI_AppendRec("visualpw.Zone", &DBrec);
			
		}
	/*	else
		{
			memcpy(&DBrec, pDBrec, sizeof(DBrec));
			g_DB.UpdateRecord("Zone", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}*/
	}
}