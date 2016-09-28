// DB_pwStation.cpp: implementation of the DB_pwStation class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_pwStation.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_pwStation::DB_pwStation()
{
//	m_fac.RemoveAll();
}

DB_pwStation::~DB_pwStation()
{

}



bool SortByNu(PositionStation a, PositionStation b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool DB_pwStation::InitParam()
{
	m_nTableID = g_DB.GetTableID("visualpw", "Station");
	m_VecStation.clear();
	
	visualpw_Station *pDBRec = (visualpw_Station*)g_DB.QueryRecord(m_nTableID,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	PositionStation posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionStation));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBRec[i], sizeof(visualpw_Station));
		posRec.nu = pDBRec[i].NU;
		
		m_VecStation.push_back(posRec);
	}
	
	std::sort(m_VecStation.begin(), m_VecStation.end(), SortByNu);
	return true;
}

int DB_pwStation::BinaryFindStationByNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecStation.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecStation.at(lMid).nu;
			if (lid<nu)
				lMin = lMid+1;
			else if(lid>nu)
				lMax = lMid-1;
			else
				return lMid;
		}
		else
			break;
	}
	return -1;
}


void DB_pwStation::RefreshModel(char *pData, int bufSize)
{
	FAC_INFO_Model *pRec = (FAC_INFO_Model*)pData;
	visualpw_Station DBrec, *pDBrec;
	bool bAddNew = false;

	for (int i=0; i<bufSize/sizeof(FAC_INFO_Model); i++)
	{
		if(MatchKeyNo(pRec[i].fac_id, FAC_INFO_MODEL) == false)
		{
			break;
		}

		ZeroMemory(&DBrec, sizeof(DBrec));
		m_nRet = BinaryFindStationByNu(pRec[i].fac_id);
		if (m_nRet == -1)
		{
			DBrec.NU = pRec[i].fac_id;
			strcpy(DBrec.Name, pRec[i].fac_name);
			DBrec.zoneNU = pRec[i].area_id;
			sprintf(DBrec.ID, "%d", pRec[i].fac_id);
			
			DBrec.Type = pRec[i].fac_type;
			DBrec.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			LSI_AppendRec("visualpw.Station", &DBrec);
			bAddNew = true;
		}
		else
		{
			pDBrec = &m_VecStation.at(m_nRet).rec;
			strcpy(pDBrec->Name, pRec[i].fac_name);
			pDBrec->zoneNU = pRec[i].area_id;
			sprintf(pDBrec->ID, "%d", pRec[i].fac_id);
			
			pDBrec->Type = pRec[i].fac_type;
			pDBrec->VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			pDBrec->LogTime=g_TimeFile;

			g_DB.UpdateRealRecord("Station", m_VecStation.at(m_nRet).nPos, &m_VecStation.at(m_nRet).rec, "visualpw");
		}
		
	/*	m_szTmp.Format("TABLE(visualpw.Station),WHERE(NU=%d)", pRec[i].fac_id);
		pDBrec = (visualpw_Station*)g_DB.QueryRecord("Station",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		if(pDBrec == NULL)
		{
			DBrec.NU = pRec[i].fac_id;
			strcpy(DBrec.Name, pRec[i].fac_name);
			DBrec.zoneNU = pRec[i].area_id;
			sprintf(DBrec.ID, "%d", pRec[i].fac_id);

			DBrec.Type = pRec[i].fac_type;
			DBrec.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			LSI_AppendRec("visualpw.Station", &DBrec);
		}
		else
		{
			memcpy(&DBrec, pDBrec, sizeof(DBrec));
			strcpy(DBrec.Name, pRec[i].fac_name);
			DBrec.zoneNU = pRec[i].area_id;
			sprintf(DBrec.ID, "%d", pRec[i].fac_id);
			
			DBrec.Type = pRec[i].fac_type;
			DBrec.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			DBrec.LogTime=g_TimeFile;
			g_DB.UpdateRecord("Station", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}*/
	}
	if(bAddNew)
		InitParam();
}

visualpw_Station* DB_pwStation::GetSubStationNameByID(int nu)
{
	m_nRet = BinaryFindStationByNu(nu);
	if(m_nRet != -1)
		return &m_VecStation.at(m_nRet).rec;
	else
		return NULL;

/*	memset(&pwsta, 0, sizeof(pwsta));
	m_szTmp.Format("TABLE(visualpw.Station),WHERE(NU=%d)", nu);
	visualpw_Station *pDBrec = (visualpw_Station*)g_DB.QueryRecord("Station",m_szTmp.GetBuffer(0),m_recn,"visualpw");
	if(pDBrec != NULL)
	{
		memcpy(&pwsta, pDBrec, sizeof(pwsta));
		return &pwsta;
	}
	
	return NULL;*/
}
