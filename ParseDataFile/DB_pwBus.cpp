// DB_pwBus.cpp: implementation of the DB_pwBus class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_pwBus.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_pwBus::DB_pwBus()
{

}

DB_pwBus::~DB_pwBus()
{

}

bool SortByBusNu(PositionBus a, PositionBus b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool DB_pwBus::InitParam()
{
	m_nTableID_Bus = g_DB.GetTableID("visualpw", "Bus");
	m_VecBus.clear();
	
	visualpw_Bus *pDBRec = (visualpw_Bus*)g_DB.QueryRecord(m_nTableID_Bus,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	PositionBus posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionBus));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBRec[i], sizeof(visualpw_Bus));
		posRec.nu = pDBRec[i].NU;
		
		m_VecBus.push_back(posRec);
	}
	
	std::sort(m_VecBus.begin(), m_VecBus.end(), SortByBusNu);
	return true;
}

int DB_pwBus::BinaryFindBusByNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecBus.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecBus.at(lMid).nu;
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

void DB_pwBus::RefreshModel(char *pData, int bufSize)
{
	BS_DEVICE_Model *pRec = (BS_DEVICE_Model*)pData;
	visualpw_Bus DBrec, *pDBrec;
	visualpw_Station *pSta;
	bool bAddNew = false;

	for (int i=0; i<bufSize/sizeof(BS_DEVICE_Model); i++)
	{
		ZeroMemory(&DBrec, sizeof(DBrec));
		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);
		

		if(MatchKeyNo(pRec[i].bs_id, BS_DEVICE_MODEL) == false)
		{
			break;
		}

	//	m_szTmp.Format("TABLE(visualpw.Bus),WHERE(NU=%d)", pRec[i].bs_id);
	//	pDBrec = (visualpw_Bus*)g_DB.QueryRecord("Bus",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindBusByNu(pRec[i].bs_id);
		if(m_nRet == -1)
		{
			DBrec.NU = pRec[i].bs_id;
			sprintf(DBrec.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].bs_name);
			DBrec.Station = pRec[i].fac_id;
			DBrec.ZoneNU = pSta!=NULL?pSta->zoneNU:0;  //GetZoneNU(DBrec.Station);
			DBrec.MaxV = pRec[i].vmax;
			DBrec.MinV = pRec[i].vmin;
			sprintf(DBrec.ID, "%d", pRec[i].bs_id);
			DBrec.sta = 1;
			DBrec.ele = 1-pRec[i].run_state;

			if(pRec[i].nd_no<0)
				pRec[i].nd_no = 0;
			DBrec.Node = pRec[i].nd_no;
			DBrec.Vl = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			LSI_AppendRec("visualpw.Bus", &DBrec);
			bAddNew = true;
		}
		else
		{
		//	memcpy(&DBrec, pDBrec, sizeof(DBrec));
			pDBrec = &m_VecBus.at(m_nRet).rec;
			sprintf(pDBrec->Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].bs_name);
			pDBrec->Station = pRec[i].fac_id;
			pDBrec->ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			pDBrec->MaxV = pRec[i].vmax;
			pDBrec->MinV = pRec[i].vmin;
			sprintf(pDBrec->ID, "%d", pRec[i].bs_id);
			pDBrec->ele = 1-pRec[i].run_state;
			if(pRec[i].nd_no<0)
				pRec[i].nd_no = 0;
			pDBrec->Node = pRec[i].nd_no;
			pDBrec->Vl = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			g_DB.UpdateRealRecord("Bus", m_VecBus.at(m_nRet).nPos, &m_VecBus.at(m_nRet).rec, "visualpw");
			//g_DB.UpdateRecord("Bus", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
	}
	if(bAddNew)
		InitParam();
}


void DB_pwBus::RefreshRealTime(char *pData, int bufSize)
{
//	InitParam();
	
	BS_DEVICE_Real *pRec = (BS_DEVICE_Real*)pData;
	visualpw_Bus *pDBrec;
	
	for (int i=0; i<bufSize/sizeof(BS_DEVICE_Real); i++)
	{
		//m_szTmp.Format("TABLE(visualpw.Bus),WHERE(NU=%d)", pRec[i].bs_id);
		//pDBrec = (visualpw_Bus*)g_DB.QueryRecord("Bus",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindBusByNu(pRec[i].bs_id);
		if(m_nRet != -1)
		{
			pDBrec = &m_VecBus.at(m_nRet).rec;
			m_pPosBus = &m_VecBus.at(m_nRet);

			if (fabs(pDBrec->V - pRec[i].v_value)>0.01)
			{
				LSI_PutColVal(m_nTableID_Bus, m_pPosBus->nPos, "Vb", (void*)&pRec[i].v_value);
				float fpu = pRec[i].v_value/pDBrec->Vl;
				LSI_PutColVal(m_nTableID_Bus, m_pPosBus->nPos, "V", (void*)&fpu);
				pDBrec->V = pRec[i].v_value;
			}
			if (fabs(pDBrec->deg - pRec[i].c_value)>0.01)
			{
				//g_DB.ModifyRecord(m_nTableID_Bus, m_szTmp.GetBuffer(0), "deg", (void*)&pRec[i].c_value);
				LSI_PutColVal(m_nTableID_Bus, m_pPosBus->nPos, "deg", (void*)&pRec[i].c_value);
				pDBrec->deg = pRec[i].c_value;

			}
			BYTE sta=0;
			if(fabs(pRec[i].v_value)>1)
				sta=1;

			if(pDBrec->sta != sta)
			{

				LSI_PutColVal(m_nTableID_Bus, m_pPosBus->nPos, "sta", (void*)&sta);
				pDBrec->sta = sta;
			}
			if(pDBrec->LogTime != g_TimeFile)
			{
				LSI_PutColVal(m_nTableID_Bus, m_pPosBus->nPos, "LogTime", (void*)&g_TimeFile);
				pDBrec->LogTime = g_TimeFile;
			}

			//g_DB.ModifyRecord(m_nTableID_Bus, m_szTmp.GetBuffer(0), "sta", (void*)&sta);

//			g_DB.ModifyRecord(m_nTableID_Bus, m_szTmp.GetBuffer(0), "LogTime", (void*)&g_TimeFile);

		}
	}
}

