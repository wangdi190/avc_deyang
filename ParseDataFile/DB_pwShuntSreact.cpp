// DB_pwShuntSreact.cpp: implementation of the DB_pwShuntSreact class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_pwShuntSreact.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern bool g_firstrun;

DB_pwShuntSreact::DB_pwShuntSreact()
{

}

DB_pwShuntSreact::~DB_pwShuntSreact()
{

}

bool SortByShuntNu(PositionShunt a, PositionShunt b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool SortBySreactNu(PositionSreact a, PositionSreact b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool DB_pwShuntSreact::InitParam()
{
	InitParam_Shunt();
	InitParam_Sreact();

	return true;
}

bool DB_pwShuntSreact::InitParam_Shunt()
{
	m_nTableID_Shunt = g_DB.GetTableID("visualpw", "Shunt");
	m_VecShunt.clear();
	
	visualpw_Shunt *pDBShunt = (visualpw_Shunt*)g_DB.QueryRecord(m_nTableID_Shunt,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	PositionShunt posShunt;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posShunt, 0 , sizeof(PositionShunt));
		posShunt.nPos = i;
		memcpy(&posShunt.rec, &pDBShunt[i], sizeof(visualpw_Shunt));
		posShunt.nu = pDBShunt[i].NU;
		
		m_VecShunt.push_back(posShunt);
	}
	std::sort(m_VecShunt.begin(), m_VecShunt.end(), SortByShuntNu);
	
	return true;
}

bool DB_pwShuntSreact::InitParam_Sreact()
{
	m_nTableID_Sreact = g_DB.GetTableID("visualpw", "Sreact");
	m_VecSreact.clear();
	
	visualpw_Sreact *pDBSreact = (visualpw_Sreact*)g_DB.QueryRecord(m_nTableID_Sreact,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	PositionSreact posSreact;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posSreact, 0 , sizeof(PositionSreact));
		posSreact.nPos = i;
		memcpy(&posSreact.rec, &pDBSreact[i], sizeof(visualpw_Sreact));
		posSreact.nu = pDBSreact[i].NU;
		
		m_VecSreact.push_back(posSreact);
	}
	std::sort(m_VecSreact.begin(), m_VecSreact.end(), SortBySreactNu);
	
	return true;
}

int DB_pwShuntSreact::BinaryFindShuntByNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecShunt.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecShunt.at(lMid).nu;
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

int DB_pwShuntSreact::BinaryFindSreactByNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecSreact.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecSreact.at(lMid).nu;
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

void DB_pwShuntSreact::RefreshModel(char *pData, int bufSize)
{
	RC_DEVICE_Model *pRec = (RC_DEVICE_Model*)pData;
	visualpw_Shunt DBrec1, *pDBrec1;
	visualpw_Sreact DBrec2, *pDBrec2;
	visualpw_Station *pSta;
	bool bAddNew_Shunt = false, bAddNew_Sreact = false;
	
	for (int i=0; i<bufSize/sizeof(RC_DEVICE_Model); i++)
	{
		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);
		
		if(MatchKeyNo(pRec[i].rc_id, RC_DEVICE_MODEL) == false)
		{
			break;
		}
		
		if (pRec[i].rc_type == 1 || pRec[i].rc_type == 3)   //电容
		{
			ZeroMemory(&DBrec1, sizeof(DBrec1));
			m_nRet = BinaryFindShuntByNu(pRec[i].rc_id);
			if (m_nRet == -1)
			{
				DBrec1.NU = pRec[i].rc_id;
				sprintf(DBrec1.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].rc_name);
				DBrec1.Station = pRec[i].fac_id;
				DBrec1.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec1.Station);
				sprintf(DBrec1.ID, "%d", pRec[i].rc_id);
				DBrec1.ele = 1-pRec[i].run_state;
				DBrec1.sta = 0;
				
				
				if (pRec[i].nd1_no<0)
					DBrec1.Node = 0;
				else
					DBrec1.Node = pRec[i].nd1_no; 
				DBrec1.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
				DBrec1.Qmax=pRec[i].qnom;
				DBrec1.RVol=pRec[i].vnom;
				//DBrec1.CtrlType=pRec[i].q_status;
				LSI_AppendRec("visualpw.Shunt", &DBrec1);
				bAddNew_Shunt = true;
			}
			else
			{
				pDBrec1 = &m_VecShunt.at(m_nRet).rec;

				sprintf(pDBrec1->Name, "%s.%s", pSta!=NULL?pSta->Name:"", pRec[i].rc_name);
				pDBrec1->Station = pRec[i].fac_id;
				pDBrec1->ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec1.Station);
				sprintf(pDBrec1->ID, "%d", pRec[i].rc_id);
				pDBrec1->ele = 1-pRec[i].run_state;
				
				if (pRec[i].nd1_no<0)
					pDBrec1->Node = 0;
				else
					pDBrec1->Node = pRec[i].nd1_no; 
				pDBrec1->VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
				pDBrec1->Qmax=pRec[i].qnom;
				pDBrec1->RVol=pRec[i].vnom;

				g_DB.UpdateRealRecord("Shunt", m_VecShunt.at(m_nRet).nPos, &m_VecShunt.at(m_nRet).rec, "visualpw");
			}
		}

		else if (pRec[i].rc_type == 2 ||    //电抗
			pRec[i].rc_type == 4 ||
			pRec[i].rc_type == 5)
		{
			m_nRet = BinaryFindSreactByNu(pRec[i].rc_id);
			if (m_nRet == -1)
			{
				DBrec2.NU = pRec[i].rc_id;
				sprintf(DBrec2.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].rc_name);
				DBrec2.Station = pRec[i].fac_id;
				DBrec2.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec2.Station);
				sprintf(DBrec2.ID, "%d", pRec[i].rc_id);
				DBrec2.ele = 1-pRec[i].run_state;
				DBrec2.sta = 1;
				
				if (pRec[i].nd1_no<0)
					DBrec2.Node1 = 0;
				else
					DBrec2.Node1 = pRec[i].nd1_no; 
				
				if (pRec[i].nd2_no<0)
					DBrec2.Node2 = 0;
				else
					DBrec2.Node2 = pRec[i].nd2_no; 
				
				DBrec2.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
				DBrec2.Qmax=pRec[i].qnom;
				DBrec2.RVol=pRec[i].vnom;
				//DBrec2.CtrlType=pRec[i].q_status;
				LSI_AppendRec("visualpw.Sreact", &DBrec2);
				bAddNew_Sreact = true;
			}
			else
			{
				pDBrec2 = &m_VecSreact.at(m_nRet).rec;

				sprintf(pDBrec2->Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].rc_name);
				pDBrec2->Station = pRec[i].fac_id;
				pDBrec2->ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec2.Station);
				sprintf(pDBrec2->ID, "%d", pRec[i].rc_id);
				pDBrec2->ele = 1-pRec[i].run_state;
				pDBrec2->sta = 1;
				
				if (pRec[i].nd1_no<0)
					pDBrec2->Node1 = 0;
				else
					pDBrec2->Node1 = pRec[i].nd1_no; 
				
				if (pRec[i].nd2_no<0)
					pDBrec2->Node2 = 0;
				else
					pDBrec2->Node2 = pRec[i].nd2_no; 
				pDBrec2->VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
				pDBrec2->Qmax=pRec[i].qnom;
				pDBrec2->RVol=pRec[i].vnom;
				//DBrec2.CtrlType=pRec[i].q_status;
				g_DB.UpdateRealRecord("Sreact", m_VecSreact.at(m_nRet).nPos, &m_VecSreact.at(m_nRet).rec, "visualpw");
			}
		}
	}

	if(bAddNew_Shunt)
		InitParam_Shunt();
	if(bAddNew_Sreact)
		InitParam_Sreact();

}

/*void DB_pwShuntSreact::RefreshModel(char *pData, int bufSize)
{
	
	RC_DEVICE_Model *pRec = (RC_DEVICE_Model*)pData;
	visualpw_Shunt DBrec1, *pDBrec1;
	visualpw_Sreact DBrec2, *pDBrec2;
	visualpw_Station *pSta;
	
	for (int i=0; i<bufSize/sizeof(RC_DEVICE_Model); i++)
	{
		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);

		if(MatchKeyNo(pRec[i].rc_id, RC_DEVICE_MODEL) == false)
		{
			break;
		}

		if (pRec[i].rc_type == 1 || pRec[i].rc_type == 3)   //电容
		{
			ZeroMemory(&DBrec1, sizeof(DBrec1));

			m_szTmp.Format("TABLE(visualpw.Shunt),WHERE(NU=%d)", pRec[i].rc_id);
			pDBrec1 = (visualpw_Shunt*)g_DB.QueryRecord("Shunt",m_szTmp.GetBuffer(0),m_recn,"visualpw");
			if(pDBrec1 == NULL)
			{
				DBrec1.NU = pRec[i].rc_id;
				sprintf(DBrec1.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].rc_name);
				DBrec1.Station = pRec[i].fac_id;
				DBrec1.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec1.Station);
				sprintf(DBrec1.ID, "%d", pRec[i].rc_id);
				DBrec1.ele = 1-pRec[i].run_state;
				DBrec1.sta = 0;


				if (pRec[i].nd1_no<0)
					DBrec1.Node = 0;
				else
					DBrec1.Node = pRec[i].nd1_no; 
				DBrec1.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
				DBrec1.Qmax=pRec[i].qnom;
				DBrec1.RVol=pRec[i].vnom;
				//DBrec1.CtrlType=pRec[i].q_status;
				LSI_AppendRec("visualpw.Shunt", &DBrec1);
			}
			else
			{
				memcpy(&DBrec1, pDBrec1, sizeof(DBrec1));
				sprintf(DBrec1.Name, "%s.%s", pSta!=NULL?pSta->Name:"", pRec[i].rc_name);
				DBrec1.Station = pRec[i].fac_id;
				DBrec1.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec1.Station);
				sprintf(DBrec1.ID, "%d", pRec[i].rc_id);
				DBrec1.ele = 1-pRec[i].run_state;

				if (pRec[i].nd1_no<0)
					DBrec1.Node = 0;
				else
					DBrec1.Node = pRec[i].nd1_no; 
				DBrec1.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
				DBrec1.Qmax=pRec[i].qnom;
				DBrec1.RVol=pRec[i].vnom;
				//DBrec1.CtrlType=pRec[i].q_status;
				g_DB.UpdateRecord("Shunt", m_szTmp.GetBuffer(0), &DBrec1, "visualpw");
			}

		}
		else if (pRec[i].rc_type == 2 ||    //电抗
				 pRec[i].rc_type == 4 ||
				 pRec[i].rc_type == 5)
		{
			ZeroMemory(&DBrec2, sizeof(DBrec2));
			m_szTmp.Format("TABLE(visualpw.Sreact),WHERE(NU=%d)", pRec[i].rc_id);
			pDBrec2 = (visualpw_Sreact*)g_DB.QueryRecord("Sreact",m_szTmp.GetBuffer(0),m_recn,"visualpw");
			if(pDBrec2 == NULL)
			{
				DBrec2.NU = pRec[i].rc_id;
				sprintf(DBrec2.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].rc_name);
				DBrec2.Station = pRec[i].fac_id;
				DBrec2.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec2.Station);
				sprintf(DBrec2.ID, "%d", pRec[i].rc_id);
				DBrec2.ele = 1-pRec[i].run_state;
				DBrec2.sta = 1;

				if (pRec[i].nd1_no<0)
					DBrec2.Node1 = 0;
				else
					DBrec2.Node1 = pRec[i].nd1_no; 

				if (pRec[i].nd2_no<0)
					DBrec2.Node2 = 0;
				else
					DBrec2.Node2 = pRec[i].nd2_no; 

				DBrec2.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
				DBrec2.Qmax=pRec[i].qnom;
				DBrec2.RVol=pRec[i].vnom;
				//DBrec2.CtrlType=pRec[i].q_status;
				LSI_AppendRec("visualpw.Sreact", &DBrec2);
			}
			else
			{
				memcpy(&DBrec2, pDBrec2, sizeof(DBrec2));
				sprintf(DBrec2.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].rc_name);
				DBrec2.Station = pRec[i].fac_id;
				DBrec2.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec2.Station);
				sprintf(DBrec2.ID, "%d", pRec[i].rc_id);
				DBrec2.ele = 1-pRec[i].run_state;
				DBrec2.sta = 1;

				if (pRec[i].nd1_no<0)
					DBrec2.Node1 = 0;
				else
					DBrec2.Node1 = pRec[i].nd1_no; 
				
				if (pRec[i].nd2_no<0)
					DBrec2.Node2 = 0;
				else
					DBrec2.Node2 = pRec[i].nd2_no; 
				DBrec2.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
				DBrec2.Qmax=pRec[i].qnom;
				DBrec2.RVol=pRec[i].vnom;
				//DBrec2.CtrlType=pRec[i].q_status;
				g_DB.UpdateRecord("Sreact", m_szTmp.GetBuffer(0), &DBrec2, "visualpw");
			}
		}
	}
}*/

void DB_pwShuntSreact::RefreshRealTime(char *pData, int bufSize)
{
	RC_DEVICE_Real *pRec = (RC_DEVICE_Real*)pData;
	PositionShunt *pPos1;
	PositionSreact *pPos2;
	visualpw_Shunt  *pDBrec1;
	visualpw_Sreact  *pDBrec2;
	for (int i=0; i<bufSize/sizeof(RC_DEVICE_Real); i++)
	{
		if (pRec[i].rc_type == RC_SHUNT || pRec[i].rc_type == RC_SERIESSHUNT)   //电容
		{
			m_nRet = BinaryFindShuntByNu(pRec[i].rc_id);
			if(m_nRet != -1)
			{
				pPos1 = &m_VecShunt.at(m_nRet);
				pDBrec1 = &m_VecShunt.at(m_nRet).rec;
				if (fabs(pDBrec1->Q - pRec[i].q_value)>0.01)
				{
					LSI_PutColVal(m_nTableID_Shunt, pPos1->nPos, "Q", (void*)&pRec[i].q_value);
					pDBrec1->Q = pRec[i].q_value;
				}

				BYTE Tsta=pDBrec1->Tsta;
				if(g_TimeFile.GetDay()!=pDBrec1->LogTime.GetDay())		//复位
					Tsta=0;
				if(fabs((pDBrec1->Q - pRec[i].q_value)/pDBrec1->Qmax)>0.5)
				{
					if(g_firstrun==false)
						Tsta++;
				}
				if(Tsta!=pDBrec1->Tsta)					//变位计数
				{
					//g_DB.ModifyRecord(m_nTableID_Shunt, m_szTmp.GetBuffer(0), "Tsta", (void*)&Tsta);
					LSI_PutColVal(m_nTableID_Shunt, pPos1->nPos, "Tsta", (void*)&Tsta);
					pDBrec1->Tsta = Tsta;
				}
				
				BYTE sta=0;
				if(fabs(pDBrec1->Q)>0.1||fabs(pDBrec1->I)>0.1)
					sta=1;
				
				if (pDBrec1->sta != sta)
				{
					LSI_PutColVal(m_nTableID_Shunt, pPos1->nPos, "sta", (void*)&sta);
					pDBrec1->sta = sta;

				}

				if (pDBrec1->LogTime != g_TimeFile)
				{
					LSI_PutColVal(m_nTableID_Shunt, pPos1->nPos, "LogTime", (void*)&g_TimeFile);
					pDBrec1->LogTime = g_TimeFile;
				}
			}
		}
		else if (pRec[i].rc_type == 2 ||    //电抗
			pRec[i].rc_type == 4 ||
			pRec[i].rc_type == 5)
		{

			m_nRet = BinaryFindSreactByNu(pRec[i].rc_id);
			if (m_nRet == -1)
			{
				pPos2 = &m_VecSreact.at(m_nRet);
				pDBrec2 = &m_VecSreact.at(m_nRet).rec;
				if (fabs(pDBrec2->Zx - pRec[i].q_value)>0.01)
				{
					LSI_PutColVal(m_nTableID_Sreact, pPos2->nPos, "Zx", (void*)&pRec[i].q_value);
					pDBrec2->Zx = pRec[i].q_value;
				}

			
				BYTE sta=0;
				if(fabs(pDBrec2->Zx)>0.1||fabs(pDBrec2->I)>0.1)
					sta=1;

				if (sta != pDBrec2->sta)
				{
					LSI_PutColVal(m_nTableID_Sreact, pPos2->nPos, "sta", (void*)&sta);
					pDBrec2->sta = sta;
				}

				if (pDBrec2->LogTime != g_TimeFile)
				{
					LSI_PutColVal(m_nTableID_Sreact, pPos2->nPos, "LogTime", (void*)&g_TimeFile);
					pDBrec2->LogTime = g_TimeFile;
				}
			}
		}
	}
}

/*
void DB_pwShuntSreact::RefreshRealTime(char *pData, int bufSize)
{
//	InitParam();
	
	RC_DEVICE_Real *pRec = (RC_DEVICE_Real*)pData;
	visualpw_Shunt  *pDBrec1;
	visualpw_Sreact  *pDBrec2;
	for (int i=0; i<bufSize/sizeof(RC_DEVICE_Real); i++)
	{
		if (pRec[i].rc_type == RC_SHUNT || pRec[i].rc_type == RC_SERIESSHUNT)   //电容
		{

			m_szTmp.Format("TABLE(visualpw.Shunt),WHERE(NU=%d)", pRec[i].rc_id);
			pDBrec1 = (visualpw_Shunt*)g_DB.QueryRecord("Shunt",m_szTmp.GetBuffer(0),m_recn,"visualpw");
			if(pDBrec1 != NULL)
			{
				if (fabs(pDBrec1->Q - pRec[i].q_value)>0.01)
						g_DB.ModifyRecord(m_nTableID_Shunt, m_szTmp.GetBuffer(0), "Q", (void*)&pRec[i].q_value);

				BYTE Tsta=pDBrec1->Tsta;
				if(g_TimeFile.GetDay()!=pDBrec1->LogTime.GetDay())		//复位
					Tsta=0;
				if(fabs((pDBrec1->Q - pRec[i].q_value)/pDBrec1->Qmax)>0.5)
				{
					if(g_firstrun==false)
						Tsta++;
				}
				if(Tsta!=pDBrec1->Tsta)					//变位计数
					g_DB.ModifyRecord(m_nTableID_Shunt, m_szTmp.GetBuffer(0), "Tsta", (void*)&Tsta);

				BYTE sta=0;
				if(fabs(pDBrec1->Q)>0.1||fabs(pDBrec1->I)>0.1)
					sta=1;
				g_DB.ModifyRecord(m_nTableID_Shunt, m_szTmp.GetBuffer(0), "sta", (void*)&sta);
				
				g_DB.ModifyRecord(m_nTableID_Shunt, m_szTmp.GetBuffer(0), "LogTime", (void*)&g_TimeFile);
			}
		}

		else if (pRec[i].rc_type == 2 ||    //电抗
			pRec[i].rc_type == 4 ||
			pRec[i].rc_type == 5)
		{
			m_szTmp.Format("TABLE(visualpw.Sreact),WHERE(NU=%d)", pRec[i].rc_id);
			pDBrec2 = (visualpw_Sreact*)g_DB.QueryRecord("Sreact",m_szTmp.GetBuffer(0),m_recn,"visualpw");
			if(pDBrec2 != NULL)
			{
				
				if (fabs(pDBrec2->Zx - pRec[i].q_value)>0.01)
					g_DB.ModifyRecord(m_nTableID_Sreact, m_szTmp.GetBuffer(0), "Zx", (void*)&pRec[i].q_value);
				BYTE sta=0;
				if(fabs(pDBrec2->Zx)>0.1||fabs(pDBrec2->I)>0.1)
					sta=1;
				g_DB.ModifyRecord(m_nTableID_Sreact, m_szTmp.GetBuffer(0), "sta", (void*)&sta);

				g_DB.ModifyRecord(m_nTableID_Shunt, m_szTmp.GetBuffer(0), "LogTime", (void*)&g_TimeFile);
			}
		}

	}

	if(g_firstrun==true)
		g_firstrun=false;
}*/