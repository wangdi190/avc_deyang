// DB_pwLoad.cpp: implementation of the DB_pwLoad class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_pwLoad.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_pwLoad::DB_pwLoad()
{

}

DB_pwLoad::~DB_pwLoad()
{

}

bool SortByNu(PositionLoad a, PositionLoad b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool DB_pwLoad::InitParam()
{
	m_nTableID_Load = g_DB.GetTableID("visualpw", "Load");
	m_VecLoad.clear();
	
	visualpw_Load *pDBRec = (visualpw_Load*)g_DB.QueryRecord(m_nTableID_Load,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	PositionLoad posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionLoad));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBRec[i], sizeof(visualpw_Load));
		posRec.nu = pDBRec[i].NU;
		
		m_VecLoad.push_back(posRec);
	}
	
	std::sort(m_VecLoad.begin(), m_VecLoad.end(), SortByNu);
	return true;
}

int DB_pwLoad::BinaryFindLoadByNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecLoad.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecLoad.at(lMid).nu;
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

void DB_pwLoad::RefreshModel(char *pData, int bufSize)
{
	
	LD_DEVICE_Model *pRec = (LD_DEVICE_Model*)pData;
	visualpw_Load DBrec, *pDBrec;
	visualpw_Station *pSta;
	bool bAddNew = false;

	for (int i=0; i<bufSize/sizeof(LD_DEVICE_Model); i++)
	{
		ZeroMemory(&DBrec, sizeof(DBrec));
		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);

		if(MatchKeyNo(pRec[i].ld_id, LD_DEVICE_MODEL) == false)
		{
			break;
		}


		//m_szTmp.Format("TABLE(visualpw.Load),WHERE(NU=%d)", pRec[i].ld_id);
		//pDBrec = (visualpw_Load*)g_DB.QueryRecord("Load",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindLoadByNu(pRec[i].ld_id);
		if(m_nRet == -1)
		{
			DBrec.NU = pRec[i].ld_id;
			sprintf(DBrec.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].ld_name);
			DBrec.Station = pRec[i].fac_id;
			DBrec.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			sprintf(DBrec.ID, "%d", pRec[i].ld_id);
			DBrec.sta = 1;
			DBrec.ele = 1-pRec[i].run_state;
			if(pRec[i].nd_no<0)
					DBrec.Node = 0;
			else
				DBrec.Node = pRec[i].nd_no; 
			DBrec.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			LSI_AppendRec("visualpw.Load", &DBrec);
			bAddNew = true;
		}
		else
		{
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			pDBrec = &m_VecLoad.at(m_nRet).rec;
			sprintf(pDBrec->Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].ld_name);
			pDBrec->Station = pRec[i].fac_id;
			pDBrec->ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			sprintf(pDBrec->ID, "%d", pRec[i].ld_id);
			pDBrec->ele = 1-pRec[i].run_state;

			if(pRec[i].nd_no<0)
				pDBrec->Node = 0;
			else
				pDBrec->Node = pRec[i].nd_no; 
			pDBrec->VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			g_DB.UpdateRealRecord("Load", m_VecLoad.at(m_nRet).nPos, &m_VecLoad.at(m_nRet).rec, "visualpw");
			//g_DB.UpdateRecord("Load", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}

	}
	if(bAddNew)
		InitParam();
}


void DB_pwLoad::RefreshRealTime(char *pData, int bufSize)
{
//	InitParam();
	
	LD_DEVICE_Real *pRec = (LD_DEVICE_Real*)pData;
	visualpw_Load *pDBrec;
	
	for (int i=0; i<bufSize/sizeof(LD_DEVICE_Real); i++)
	{
		//m_szTmp.Format("TABLE(visualpw.Load),WHERE(NU=%d)", pRec[i].ld_id);
		//pDBrec = (visualpw_Load*)g_DB.QueryRecord("Load",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindLoadByNu(pRec[i].ld_id);
		if(m_nRet != -1)
		{
			m_pPosLoad = &m_VecLoad.at(m_nRet);
			pDBrec = &m_VecLoad.at(m_nRet).rec;
			if (fabs(pDBrec->P - pRec[i].p_value)>0.01)
			{
				LSI_PutColVal(m_nTableID_Load, m_pPosLoad->nPos, "P", (void*)&pRec[i].p_value);
				pDBrec->P = pRec[i].p_value;
				//g_DB.ModifyRecord(m_nTableID_Load, m_szTmp.GetBuffer(0), "P", (void*)&pRec[i].p_value);
			}
			if (fabs(pDBrec->Q - pRec[i].q_value)>0.01)
			{
				LSI_PutColVal(m_nTableID_Load, m_pPosLoad->nPos, "Q", (void*)&pRec[i].q_value);
				pDBrec->Q = pRec[i].q_value;
				//g_DB.ModifyRecord(m_nTableID_Load, m_szTmp.GetBuffer(0), "Q", (void*)&pRec[i].q_value);
			}
			if (fabs(pDBrec->I - pRec[i].i_value)>0.01)
			{
				LSI_PutColVal(m_nTableID_Load, m_pPosLoad->nPos, "I", (void*)&pRec[i].i_value);
				pDBrec->I = pRec[i].i_value;
				//g_DB.ModifyRecord(m_nTableID_Load, m_szTmp.GetBuffer(0), "I", (void*)&pRec[i].i_value);
			}
			BYTE sta=0;
			if(fabs(pRec[i].i_value)>0.1||fabs(pRec[i].p_value)>0.1||fabs(pRec[i].q_value)>0.1)
				sta=1;
			if (pDBrec->sta != sta)
			{
				LSI_PutColVal(m_nTableID_Load, m_pPosLoad->nPos, "sta", (void*)&sta);
				pDBrec->sta = sta;
			}
			//g_DB.ModifyRecord(m_nTableID_Load, m_szTmp.GetBuffer(0), "sta", (void*)&sta);
			if(pDBrec->LogTime != g_TimeFile)
			{
				LSI_PutColVal(m_nTableID_Load, m_pPosLoad->nPos, "LogTime", (void*)&g_TimeFile);
				pDBrec->LogTime = g_TimeFile;
			}

			//g_DB.ModifyRecord(m_nTableID_Load, m_szTmp.GetBuffer(0), "LogTime", (void*)&g_TimeFile);
		}
	}
}