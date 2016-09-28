// DB_pwGen.cpp: implementation of the DB_pwGen class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_pwGen.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_pwGen::DB_pwGen()
{

}

DB_pwGen::~DB_pwGen()
{

}

bool SortByGenNu(PositionGen a, PositionGen b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool DB_pwGen::InitParam()
{
	m_nTableID_Gen = g_DB.GetTableID("visualpw", "Gen");
	m_VecGen.clear();
	
	visualpw_Gen *pDBRec = (visualpw_Gen*)g_DB.QueryRecord(m_nTableID_Gen,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	PositionGen posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionGen));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBRec[i], sizeof(visualpw_Gen));
		posRec.nu = pDBRec[i].NU;
		
		m_VecGen.push_back(posRec);
	}
	
	std::sort(m_VecGen.begin(), m_VecGen.end(), SortByGenNu);
	return true;
}

int DB_pwGen::BinaryFindGenByNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecGen.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecGen.at(lMid).nu;
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

void DB_pwGen::RefreshModel(char *pData, int bufSize)
{
	
	GN_DEVICE_Model *pRec = (GN_DEVICE_Model*)pData;
	visualpw_Gen DBrec, *pDBrec;
	bool bAddNew = false;
	visualpw_Station *pSta=NULL;
	for (int i=0; i<bufSize/sizeof(GN_DEVICE_Model); i++)
	{
	//	TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].gn_name, pRec[i].vlty_id, pRec[i].pmax, pRec[i].nd_no);
		ZeroMemory(&DBrec, sizeof(DBrec));
		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);

		if(MatchKeyNo(pRec[i].gn_id, GN_DEVICE_MODEL) == false)
		{
			break;
		}

	//	m_szTmp.Format("TABLE(visualpw.Gen),WHERE(NU=%d)", pRec[i].gn_id);
	//	pDBrec = (visualpw_Gen*)g_DB.QueryRecord("Gen",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindGenByNu(pRec[i].gn_id);
		if(m_nRet == -1)
		{
			DBrec.NU = pRec[i].gn_id;
			sprintf(DBrec.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].gn_name);
			DBrec.MaxP = pRec[i].snom;
			DBrec.Station = pRec[i].fac_id;
			DBrec.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			DBrec.ele = 1-pRec[i].run_state;
			DBrec.sta = 1;  //运行状态都为1
			
			if(pRec[i].nd_no<0)
				DBrec.Node = 0;
			else
				DBrec.Node = pRec[i].nd_no;

			sprintf(DBrec.ID, "%d", pRec[i].gn_id);
			DBrec.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			LSI_AppendRec("visualpw.Gen", &DBrec);
			bAddNew = true;
		}
		else
		{
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			pDBrec = &m_VecGen.at(m_nRet).rec;
			sprintf(pDBrec->Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].gn_name);
			pDBrec->MaxP = pRec[i].snom;
			pDBrec->Station = pRec[i].fac_id;
			pDBrec->ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			pDBrec->ele = 1-pRec[i].run_state;
			pDBrec->sta = 1;  //运行状态都为1

			if(pRec[i].nd_no<0)
				pDBrec->Node = 0;
			else
				pDBrec->Node = pRec[i].nd_no;

			sprintf(pDBrec->ID, "%d", pRec[i].gn_id);
			pDBrec->VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);

			g_DB.UpdateRealRecord("Gen", m_VecGen.at(m_nRet).nPos, &m_VecGen.at(m_nRet).rec, "visualpw");
			//g_DB.UpdateRecord("Gen", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
	}
	if(bAddNew)
		InitParam();
}


void DB_pwGen::RefreshRealTime(char *pData, int bufSize)
{
//	InitParam();
	
	GN_DEVICE_Real *pRec = (GN_DEVICE_Real*)pData;
	visualpw_Gen *pDBrec;
	
	for (int i=0; i<bufSize/sizeof(GN_DEVICE_Real); i++)
	{
		//m_szTmp.Format("TABLE(visualpw.Gen),WHERE(NU=%d)", pRec[i].gn_id);
		//pDBrec = (visualpw_Gen*)g_DB.QueryRecord("Gen",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindGenByNu(pRec[i].gn_id);
		if(m_nRet != -1)
		{
			pDBrec = &m_VecGen.at(m_nRet).rec;
			m_pPosGen = &m_VecGen.at(m_nRet);

			if (fabs(pDBrec->P - pRec[i].p_value)>0.01)
			{
				LSI_PutColVal(m_nTableID_Gen, m_pPosGen->nPos, "P", (void*)&pRec[i].p_value);
				pDBrec->P = pRec[i].p_value;
				//g_DB.ModifyRecord(m_nTableID_Gen, m_szTmp.GetBuffer(0), "P", (void*)&pRec[i].p_value);
			}
			if (fabs(pDBrec->Q - pRec[i].q_value)>0.01)
			{
				LSI_PutColVal(m_nTableID_Gen, m_pPosGen->nPos, "Q", (void*)&pRec[i].q_value);
				pDBrec->Q = pRec[i].q_value;
				//g_DB.ModifyRecord(m_nTableID_Gen, m_szTmp.GetBuffer(0), "Q", (void*)&pRec[i].q_value);
			}
			if (fabs(pDBrec->V - pRec[i].v_value)>0.01)
			{
				LSI_PutColVal(m_nTableID_Gen, m_pPosGen->nPos, "V", (void*)&pRec[i].v_value);
				pDBrec->V = pRec[i].v_value;
				//g_DB.ModifyRecord(m_nTableID_Gen, m_szTmp.GetBuffer(0), "V", (void*)&pRec[i].v_value);
			}
//			if (fabs(pDBrec->angle - pRec[i].gn_angle)>0.01)
//				g_DB.ModifyRecord(m_nTableID_Gen, m_szTmp.GetBuffer(0), "angle", (void*)&pRec[i].gn_angle);

			BYTE sta=0;
			if(fabs(pRec[i].p_value)>0.1||fabs(pRec[i].q_value)>0.1)
				sta=1;
			if(pDBrec->sta != sta)
			{
				LSI_PutColVal(m_nTableID_Gen, m_pPosGen->nPos, "sta", (void*)&sta);
				pDBrec->sta = sta;
			}
		//	g_DB.ModifyRecord(m_nTableID_Gen, m_szTmp.GetBuffer(0), "sta", (void*)&sta);

			if(pDBrec->LogTime != g_TimeFile)
			{
				LSI_PutColVal(m_nTableID_Gen, m_pPosGen->nPos, "LogTime", (void*)&g_TimeFile);
				pDBrec->LogTime = g_TimeFile;
			}
		//	g_DB.ModifyRecord(m_nTableID_Gen, m_szTmp.GetBuffer(0), "LogTime", (void*)&g_TimeFile);
		}
	}
}