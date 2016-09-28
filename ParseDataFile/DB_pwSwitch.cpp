// DB_pwSwitch.cpp: implementation of the DB_pwSwitch class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_pwSwitch.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_pwSwitch::DB_pwSwitch()
{

}

DB_pwSwitch::~DB_pwSwitch()
{

}

bool SortBySwitchNu(PositionSwitch a, PositionSwitch b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool SortByGNDNu(PositionGND a, PositionGND b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool DB_pwSwitch::InitParam()
{
	InitParam_Switch();
	InitParam_GND();
	return true;
}

bool DB_pwSwitch::InitParam_Switch()
{
	m_nTableID_Switch = g_DB.GetTableID("visualpw", "Switch");
	
	visualpw_Switch *pDBrec = (visualpw_Switch*)g_DB.QueryRecord(m_nTableID_Switch,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	m_VecSwitch.clear();
	
	PositionSwitch posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionSwitch));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBrec[i], sizeof(visualpw_Switch));
		posRec.nu = pDBrec[i].NU;
		
		m_VecSwitch.push_back(posRec);
	}
	
	std::sort(m_VecSwitch.begin(), m_VecSwitch.end(), SortBySwitchNu);
	return true;
}

bool DB_pwSwitch::InitParam_GND()
{
	m_nTableID_GND = g_DB.GetTableID("visualpw", "GND");
	
	visualpw_GND *pDBrec = (visualpw_GND*)g_DB.QueryRecord(m_nTableID_GND,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	m_VecGND.clear();
	
	PositionGND posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionGND));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBrec[i], sizeof(visualpw_GND));
		posRec.nu = pDBrec[i].NU;
		
		m_VecGND.push_back(posRec);
	}
	std::sort(m_VecGND.begin(), m_VecGND.end(), SortByGNDNu);
	return true;
}

/*void DB_pwSwitch::RefreshModel_Brk(char *pData, int bufSize)
{
	BRK_DEVICE_Model *pRec = (BRK_DEVICE_Model*)pData;
	visualpw_Switch DBrec, *pDBrec;
	visualpw_Station *pSta;
	bool bNew=false;
	
	for (int i=0; i<bufSize/sizeof(BRK_DEVICE_Model); i++)
	{
		if(MatchKeyNo(pRec[i].brk_id, BRK_DEVICE_MODEL) == false)
		{
			break;
		}

		ZeroMemory(&DBrec, sizeof(DBrec));
		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);
		
		m_szTmp.Format("TABLE(visualpw.Switch),WHERE(NU=%d)", pRec[i].brk_id);
		pDBrec = (visualpw_Switch*)g_DB.QueryRecord("Switch",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		if(pDBrec == NULL)
		{
			DBrec.NU = pRec[i].brk_id;
			sprintf(DBrec.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].brk_name);
			DBrec.Station = pRec[i].fac_id;
			DBrec.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			DBrec.sta = pRec[i].run_state;
			DBrec.ele = 1;//1-pRec[i].run_state;
			sprintf(DBrec.ID, "%d", pRec[i].brk_id);

			if(pRec[i].nd1_no<0)
				pRec[i].nd1_no = 0;
			if(pRec[i].nd2_no<0)
				pRec[i].nd2_no = 0;

			DBrec.Node1 = pRec[i].nd1_no;
			DBrec.Node2 = pRec[i].nd2_no;
			DBrec.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			LSI_AppendRec("visualpw.Switch", &DBrec);
			bNew=true;
		}
		else
		{
			memcpy(&DBrec, pDBrec, sizeof(DBrec));
			sprintf(DBrec.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].brk_name);
			DBrec.Station = pRec[i].fac_id;
			DBrec.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			DBrec.ele = 1;//-pRec[i].run_state;
			//DBrec.sta = pRec[i].run_state;
			sprintf(DBrec.ID, "%d", pRec[i].brk_id);

			if(pRec[i].nd1_no<0)
				pRec[i].nd1_no = 0;
			if(pRec[i].nd2_no<0)
				pRec[i].nd2_no = 0;
			
			DBrec.Node1 = pRec[i].nd1_no;
			DBrec.Node2 = pRec[i].nd2_no;
			DBrec.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			g_DB.UpdateRecord("Switch", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
	}

	if(bNew == true)
	{
		InitParam();
	}
}*/

int DB_pwSwitch::BinaryFindSwitchNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecSwitch.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecSwitch.at(lMid).nu;
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

int DB_pwSwitch::BinaryFindGNDNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecGND.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecGND.at(lMid).nu;
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

void DB_pwSwitch::RefreshModel_Brk(char *pData, int bufSize)
{
	BRK_DEVICE_Model *pRec = (BRK_DEVICE_Model*)pData;
	visualpw_Switch DBrec, *pDBrec;
	visualpw_Station *pSta;
	bool bAddNew=false;
	
	for (int i=0; i<bufSize/sizeof(BRK_DEVICE_Model); i++)
	{
		if(MatchKeyNo(pRec[i].brk_id, BRK_DEVICE_MODEL) == false)
		{
			break;
		}
		
		ZeroMemory(&DBrec, sizeof(DBrec));
		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);
		
		//m_szTmp.Format("TABLE(visualpw.Switch),WHERE(NU=%d)", pRec[i].brk_id);
		//pDBrec = (visualpw_Switch*)g_DB.QueryRecord("Switch",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet= BinaryFindSwitchNu(pRec[i].brk_id);
		if(m_nRet == -1)
		{
			DBrec.NU = pRec[i].brk_id;
			sprintf(DBrec.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].brk_name);
			DBrec.Station = pRec[i].fac_id;
			DBrec.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			DBrec.sta = pRec[i].run_state;
			DBrec.ele = 1;//1-pRec[i].run_state;
			sprintf(DBrec.ID, "%d", pRec[i].brk_id);
			
			if(pRec[i].nd1_no<0)
				pRec[i].nd1_no = 0;
			if(pRec[i].nd2_no<0)
				pRec[i].nd2_no = 0;
			
			DBrec.Node1 = pRec[i].nd1_no;
			DBrec.Node2 = pRec[i].nd2_no;
			DBrec.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			LSI_AppendRec("visualpw.Switch", &DBrec);
			bAddNew=true;
		}
		else
		{
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			pDBrec = &m_VecSwitch.at(m_nRet).rec;
			sprintf(pDBrec->Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].brk_name);
			pDBrec->Station = pRec[i].fac_id;
			pDBrec->ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			pDBrec->ele = 1;//-pRec[i].run_state;
			//DBrec.sta = pRec[i].run_state;
			sprintf(pDBrec->ID, "%d", pRec[i].brk_id);
			
			if(pRec[i].nd1_no<0)
				pRec[i].nd1_no = 0;
			if(pRec[i].nd2_no<0)
				pRec[i].nd2_no = 0;
			
			pDBrec->Node1 = pRec[i].nd1_no;
			pDBrec->Node2 = pRec[i].nd2_no;
			pDBrec->VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			g_DB.UpdateRealRecord("Switch", m_VecSwitch.at(m_nRet).nPos, &m_VecSwitch.at(m_nRet).rec, "visualpw");
			//g_DB.UpdateRecord("Switch", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
	}
	
	if(bAddNew)
		InitParam();
}


void DB_pwSwitch::RefreshModel_Discr(char *pData, int bufSize)
{
	
	DISCR_DEVICE_Model *pRec = (DISCR_DEVICE_Model*)pData;
	visualpw_Switch DBrec, *pDBrec;
	visualpw_Station *pSta=NULL;
	bool bAddNew=false;
	
	for (int i=0; i<bufSize/sizeof(DISCR_DEVICE_Model); i++)
	{
		if(MatchKeyNo(pRec[i].discr_id, DISCR_DEVICE_MODEL) == false)
		{
			break;
		}

		ZeroMemory(&DBrec, sizeof(DBrec));
		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);
		
		//m_szTmp.Format("TABLE(visualpw.Switch),WHERE(NU=%d)", pRec[i].discr_id);
		//pDBrec = (visualpw_Switch*)g_DB.QueryRecord("Switch",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindSwitchNu(pRec[i].discr_id);
		if(m_nRet == -1)
		{
			DBrec.NU = pRec[i].discr_id;
			sprintf(DBrec.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].discr_name);
			DBrec.Station = pRec[i].fac_id;
			DBrec.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			DBrec.sta = pRec[i].run_state;
			DBrec.ele = 1;//-pRec[i].run_state;
			sprintf(DBrec.ID, "%d", pRec[i].discr_id);

			if(pRec[i].nd1_no<0)
				pRec[i].nd1_no = 0;
			if(pRec[i].nd2_no<0)
				pRec[i].nd2_no = 0;
			
			DBrec.Node1 = pRec[i].nd1_no;
			DBrec.Node2 = pRec[i].nd2_no;
			DBrec.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			LSI_AppendRec("visualpw.Switch", &DBrec);
			bAddNew=true;
		}
		else
		{
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			pDBrec = &m_VecSwitch.at(m_nRet).rec;
			sprintf(pDBrec->Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].discr_name);
			pDBrec->Station = pRec[i].fac_id;
			pDBrec->ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			//DBrec.sta = pRec[i].run_state;
			pDBrec->ele = 1;//-pRec[i].run_state;
			sprintf(pDBrec->ID, "%d", pRec[i].discr_id);

			if(pRec[i].nd1_no<0)
				pRec[i].nd1_no = 0;
			if(pRec[i].nd2_no<0)
				pRec[i].nd2_no = 0;
			
			pDBrec->Node1 = pRec[i].nd1_no;
			pDBrec->Node2 = pRec[i].nd2_no;
			pDBrec->VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			g_DB.UpdateRealRecord("Switch", m_VecSwitch.at(m_nRet).nPos, &m_VecSwitch.at(m_nRet).rec, "visualpw");
			//g_DB.UpdateRecord("Switch", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
	}
	if(bAddNew)
		InitParam();
}

void DB_pwSwitch::RefreshModel_Gddiscr(char *pData, int bufSize)
{
	
	GDDISCR_DEVICE_Model *pRec = (GDDISCR_DEVICE_Model*)pData;
	visualpw_GND DBrec, *pDBrec;
	visualpw_Station *pSta=NULL;
	bool bAddNew = false;
	
	for (int i=0; i<bufSize/sizeof(GDDISCR_DEVICE_Model); i++)
	{
		if(MatchKeyNo(pRec[i].gddiscr_id, GDDISCR_DEVICE_MODEL) == false)
		{
			break;
		}

		ZeroMemory(&DBrec, sizeof(DBrec));
		
		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);

		//m_szTmp.Format("TABLE(visualpw.GND),WHERE(NU=%d)", pRec[i].gddiscr_id);
		//pDBrec = (visualpw_GND*)g_DB.QueryRecord("GND",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindGNDNu(pRec[i].gddiscr_id);
		if(m_nRet == -1)
		{
			DBrec.NU = pRec[i].gddiscr_id;
			strcpy(DBrec.Name, pRec[i].gddiscr_name);
			DBrec.Station = pRec[i].fac_id;
			DBrec.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			DBrec.sta = 1;
			if(pRec[i].nd_no<0)
				pRec[i].nd_no = 0;

			DBrec.Node = pRec[i].nd_no;
			LSI_AppendRec("visualpw.GND", &DBrec);
			bAddNew = true;
		}
		else
		{
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			pDBrec = &m_VecGND.at(m_nRet).rec;
			strcpy(pDBrec->Name, pRec[i].gddiscr_name);
			pDBrec->Station = pRec[i].fac_id;
			pDBrec->ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec.Station);
			//DBrec.sta = 1;
			if(pRec[i].nd_no<0)
				pRec[i].nd_no = 0;
			
			pDBrec->Node = pRec[i].nd_no;
			pDBrec->LogTime=g_TimeFile;
			g_DB.UpdateRealRecord("GND", m_VecGND.at(m_nRet).nPos, &m_VecGND.at(m_nRet).rec, "visualpw");
			//g_DB.UpdateRecord("GND", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
	}
	if(bAddNew)
		InitParam_GND();
}


void DB_pwSwitch::RefreshRealTime_Discr(char *pData, int bufSize)
{
	DISCR_DEVICE_Real *pRec = (DISCR_DEVICE_Real*)pData;
//	visualpw_Switch *pDBrec;
	for (int i=0; i<bufSize/sizeof(DISCR_DEVICE_Real); i++)
	{
		/*m_szTmp.Format("TABLE(visualpw.Switch),WHERE(NU=%d)", pRec[i].discr_id);
		pDBrec = (visualpw_Switch*)g_DB.QueryRecord("Switch",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		if(pDBrec != NULL)
		{
			if (pDBrec->sta != pRec[i].yx_value)
				g_DB.ModifyRecord(m_nTableID_Switch, m_szTmp.GetBuffer(0), "sta", (void*)&pRec[i].yx_value);
		//	if (pDBrec->ele != pRec[i].run_state)
		//		g_DB.ModifyRecord(m_nTableID_Switch, m_szTmp.GetBuffer(0), "ele", (void*)&pRec[i].run_state);

			g_DB.ModifyRecord(m_nTableID_Switch, m_szTmp.GetBuffer(0), "LogTime", (void*)&g_TimeFile);
		}*/
		
		m_nRet = BinaryFindSwitchNu(pRec[i].discr_id);
		if (m_nRet != -1)
		{
			m_pPosSwitch = &m_VecSwitch.at(m_nRet);
			
			if(m_pPosSwitch->rec.sta != pRec[i].yx_value)
			{
				LSI_PutColVal(m_nTableID_Switch, m_pPosSwitch->nPos, "sta", &pRec[i].yx_value);	
				m_pPosSwitch->rec.sta = pRec[i].yx_value;
			}
			if (m_pPosSwitch->rec.LogTime != g_TimeFile)
			{
				LSI_PutColVal(m_nTableID_Switch, m_pPosSwitch->nPos, "LogTime", (void*)&g_TimeFile);
				m_pPosSwitch->rec.LogTime = g_TimeFile;
			}
		}

	}
}

void DB_pwSwitch::RefreshRealTime_Brk(char *pData, int bufSize)
{
//	InitParam();
	
	
	BRK_DEVICE_Real *pRec = (BRK_DEVICE_Real*)pData;
//	visualpw_Switch *pDBrec;
	for (int i=0; i<bufSize/sizeof(BRK_DEVICE_Real); i++)
	{
		/*m_szTmp.Format("TABLE(visualpw.Switch),WHERE(NU=%d)", pRec[i].brk_id);
		pDBrec = (visualpw_Switch*)g_DB.QueryRecord("Switch",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		if(pDBrec != NULL)
		{
			if (pDBrec->sta != pRec[i].yx_value)
				g_DB.ModifyRecord(m_nTableID_Switch, m_szTmp.GetBuffer(0), "sta", (void*)&pRec[i].yx_value);
		//	if (pDBrec->ele != pRec[i].run_state)
		//		g_DB.ModifyRecord(m_nTableID_Switch, m_szTmp.GetBuffer(0), "ele", (void*)&pRec[i].run_state);
			g_DB.ModifyRecord(m_nTableID_Switch, m_szTmp.GetBuffer(0), "LogTime", (void*)&g_TimeFile);
		}*/

		m_nRet = BinaryFindSwitchNu(pRec[i].brk_id);
		if (m_nRet != -1)
		{
			m_pPosSwitch = &m_VecSwitch.at(m_nRet);
			
			if(m_pPosSwitch->rec.sta != pRec[i].yx_value)
			{
				LSI_PutColVal(m_nTableID_Switch, m_pPosSwitch->nPos, "sta", &pRec[i].yx_value);
				m_pPosSwitch->rec.sta = pRec[i].yx_value;
			}
			if (m_pPosSwitch->rec.LogTime != g_TimeFile)
			{
				LSI_PutColVal(m_nTableID_Switch, m_pPosSwitch->nPos, "LogTime", (void*)&g_TimeFile);
				m_pPosSwitch->rec.LogTime = g_TimeFile;
			}
		}
	}
}
