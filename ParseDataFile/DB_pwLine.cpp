// DB_pwLine.cpp: implementation of the DB_pwLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_pwLine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_pwLine::DB_pwLine()
{

}

DB_pwLine::~DB_pwLine()
{

}


bool SortByLineNu(PositionLine a, PositionLine b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool SortByConductorNu(PositionConductor a, PositionConductor b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool DB_pwLine::InitParam()
{
	InitParam_Line();
	InitParam_Conductor();
	return true;
}

bool DB_pwLine::InitParam_Line()
{
	m_nTableID_Line = g_DB.GetTableID("visualpw", "Line");
	m_VecLine.clear();
	
	visualpw_Line *pDBRec = (visualpw_Line*)g_DB.QueryRecord(m_nTableID_Line,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	PositionLine posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionLine));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBRec[i], sizeof(visualpw_Line));
		posRec.nu = pDBRec[i].NU;
		
		m_VecLine.push_back(posRec);
	}
	
	std::sort(m_VecLine.begin(), m_VecLine.end(), SortByLineNu);
	return true;
}

bool DB_pwLine::InitParam_Conductor()
{
	m_nTableID_Conductor = g_DB.GetTableID("visualpw", "Conductor");
	m_VecConductor.clear();
	
	visualpw_Conductor *pDBRec = (visualpw_Conductor*)g_DB.QueryRecord(m_nTableID_Conductor,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	PositionConductor posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionConductor));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBRec[i], sizeof(visualpw_Conductor));
		posRec.nu = pDBRec[i].NU;
		
		m_VecConductor.push_back(posRec);
	}
	
	std::sort(m_VecConductor.begin(), m_VecConductor.end(), SortByConductorNu);
	return true;
}

int DB_pwLine::BinaryFindLineByNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecLine.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecLine.at(lMid).nu;
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

int DB_pwLine::BinaryFindConductoryNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecConductor.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecConductor.at(lMid).nu;
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

void DB_pwLine::RefreshModel(char *pData, int bufSize)
{
	
	ACLN_DEVICE_Model *pRec = (ACLN_DEVICE_Model*)pData;
	visualpw_Line DBrec, *pDBrec;
	bool bAddNew = false;
	for (int i=0; i<bufSize/sizeof(ACLN_DEVICE_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		ZeroMemory(&DBrec, sizeof(DBrec));
		
		if(MatchKeyNo(pRec[i].acln_id, ACLN_DEVICE_MODEL) == false)
		{
			break;
		}

		//m_szTmp.Format("TABLE(visualpw.Line),WHERE(NU=%d)", pRec[i].acln_id);
		//pDBrec = (visualpw_Line*)g_DB.QueryRecord("Line",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindLineByNu(pRec[i].acln_id);
		if(m_nRet == -1)
		{
			DBrec.NU = pRec[i].acln_id;
			strcpy(DBrec.Name, pRec[i].acln_name);
			sprintf(DBrec.ID, "%d", pRec[i].acln_id);
			DBrec.Imax=pRec[i].imax1;
			DBrec.MaxP = pRec[i].smax;
			DBrec.sta = 1;
			DBrec.ele = 1-pRec[i].run_state;
			DBrec.EquiSta=pRec[i].eq_fg;
			DBrec.Stationf = pRec[i].fac_id_s; 
			DBrec.Zonef=GetZoneNU(DBrec.Stationf);
			DBrec.Stationt = pRec[i].fac_id_e;
			DBrec.Zonet=GetZoneNU(DBrec.Stationt);
			DBrec.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);

			if(DBrec.MaxP<1.0)
				DBrec.MaxP=DBrec.Imax*DBrec.VL/1000*1.732;
			LSI_AppendRec("visualpw.Line", &DBrec);
			bAddNew = true;
		}
		else
		{
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			pDBrec = &m_VecLine.at(m_nRet).rec;
			strcpy(pDBrec->Name, pRec[i].acln_name);
			sprintf(pDBrec->ID, "%d", pRec[i].acln_id);
			pDBrec->ele = 1-pRec[i].run_state;
			pDBrec->EquiSta=pRec[i].eq_fg;
			pDBrec->MaxP = pRec[i].smax;
			pDBrec->Imax=pRec[i].imax1;
			pDBrec->Stationf = pRec[i].fac_id_s;
			pDBrec->Zonef=GetZoneNU(pDBrec->Stationf);
			pDBrec->Stationt = pRec[i].fac_id_e;
			pDBrec->Zonet=GetZoneNU(pDBrec->Stationt);
			pDBrec->VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);

			if(pDBrec->MaxP<1.0)
				pDBrec->MaxP=pDBrec->Imax*pDBrec->VL/1000*1.732;
			g_DB.UpdateRealRecord("Line", m_VecLine.at(m_nRet).nPos, &m_VecLine.at(m_nRet).rec, "visualpw");
			//g_DB.UpdateRecord("Line", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
	}
	if(bAddNew)
		InitParam_Line();

	RefreshModel_Conductor(pData, bufSize);
}

void DB_pwLine::RefreshModel_Conductor(char *pData, int bufSize)
{
	ACLN_DEVICE_Model *pRec = (ACLN_DEVICE_Model*)pData;
	visualpw_Conductor DBrec, *pDBrec;
	bool bAddNew = false;
	for (int i=0; i<bufSize/sizeof(ACLN_DEVICE_Model); i++)
	{
		ZeroMemory(&DBrec, sizeof(DBrec));

		if(MatchKeyNo(pRec[i].acln_id, ACLN_DEVICE_MODEL) == false)
		{
			break;
		}

		
		//m_szTmp.Format("TABLE(visualpw.Conductor),WHERE(NU=%d)", pRec[i].acln_id);
		//pDBrec = (visualpw_Conductor*)g_DB.QueryRecord("Conductor",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindConductoryNu(pRec[i].acln_id);
		if(m_nRet == -1)
		{
			DBrec.NU = pRec[i].acln_id;
			sprintf(DBrec.LID, "%d", pRec[i].acln_id);
			
			DBrec.fB = pRec[i].bch_value_pu/100.0;
			DBrec.fR = pRec[i].r_value_pu/100.0;
			DBrec.fX = pRec[i].x_value_pu/100.0;
//			DBrec.fB0 = pRec[i].bch0_value_pu;
//			DBrec.fR0 = pRec[i].r0_value_pu;
//			DBrec.fX0 = pRec[i].x0_value_pu;

			LSI_AppendRec("visualpw.Conductor", &DBrec);
			bAddNew = true;
		}
		else
		{
			pDBrec = &m_VecConductor.at(m_nRet).rec;
			pDBrec->NU = pRec[i].acln_id;
			sprintf(pDBrec->LID, "%d", pRec[i].acln_id);
			
			pDBrec->fB = pRec[i].bch_value_pu/100.0;
			pDBrec->fR = pRec[i].r_value_pu/100.0;
			pDBrec->fX = pRec[i].x_value_pu/100.0;
//			DBrec.fB0 = pRec[i].bch0_value_pu;
//			DBrec.fR0 = pRec[i].r0_value_pu;
//			DBrec.fX0 = pRec[i].x0_value_pu;

			g_DB.UpdateRealRecord("Conductor", m_VecConductor.at(m_nRet).nPos, &m_VecConductor.at(m_nRet).rec, "visualpw");
			//g_DB.UpdateRecord("Conductor", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
	}
	if(bAddNew)
		InitParam_Conductor();
}

void DB_pwLine::RefreshModel_Dot(char *pData, int bufSize)  //交流线段端点表
{
	
	ACLN_DOT_Model *pRec = (ACLN_DOT_Model*)pData;
	visualpw_Line DBrec, *pDBrec;
	for (int i=0; i<bufSize/sizeof(ACLN_DOT_Model); i++)
	{
		ZeroMemory(&DBrec, sizeof(DBrec));
		
		//m_szTmp.Format("TABLE(visualpw.Line),WHERE(NU=%d)", pRec[i].acln_id);
		//pDBrec = (visualpw_Line*)g_DB.QueryRecord("Line",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindLineByNu(pRec[i].acln_id);
		if(m_nRet != -1)
		{
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			pDBrec = &m_VecLine.at(m_nRet).rec;
			m_pPosLine = &m_VecLine.at(m_nRet);
			if (pDBrec->Stationf == pRec[i].fac_id)
			{
				if(pRec[i].nd_no<0)
					pRec[i].nd_no = 0;

				if(pDBrec->NodeF!=pRec[i].nd_no)
				{
					LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "NodeF", &pRec[i].nd_no);
					pDBrec->NodeF = pRec[i].nd_no;
				}

				
			}
			else if (pDBrec->Stationt == pRec[i].fac_id)
			{
				if(pRec[i].nd_no<0)
					pRec[i].nd_no = 0;

				if(pDBrec->NodeT!=pRec[i].nd_no)
				{
					LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "NodeT", &pRec[i].nd_no);
					pDBrec->NodeT = pRec[i].nd_no;
				}
			}
			
			if (pDBrec->LogTime != g_TimeFile)
			{
				LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "LogTime", &g_TimeFile);
				pDBrec->LogTime = g_TimeFile;
			}
		}
	}
}



void DB_pwLine::RefreshRealTime_Dot(char *pData, int bufSize)//交流线段端点表
{
	ACLN_DOT_Real *pRec = (ACLN_DOT_Real*)pData;
	visualpw_Line *pDBrec;
	for (int i=0; i<bufSize/sizeof(ACLN_DOT_Real); i++)
	{
	//	m_szTmp.Format("TABLE(visualpw.Line),WHERE(NU=%d)", pRec[i].acln_id);//.acln_dot_id);
	//	pDBrec = (visualpw_Line*)g_DB.QueryRecord("Line",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindLineByNu(pRec[i].acln_id);
		if(m_nRet != -1)
		{
			pDBrec = &m_VecLine.at(m_nRet).rec;
			m_pPosLine = &m_VecLine.at(m_nRet);
			if (pDBrec->Stationf == pRec[i].fac_id)
			{
				if (fabs(pDBrec->Pf - pRec[i].p_value)>0.01)
				{
					LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "Pf", (void*)&pRec[i].p_value);
					pDBrec->Pf = pRec[i].p_value;
					//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "Pf", (void*)&pRec[i].p_value);
				}
				if (fabs(pDBrec->Qf - pRec[i].q_value)>0.01)
				{
					LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "Qf", (void*)&pRec[i].q_value);
					pDBrec->Qf = pRec[i].q_value;
					//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "Qf", (void*)&pRec[i].q_value);
				}
				if (fabs(pDBrec->I - pRec[i].i_value)>0.01)
				{
					LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "I", (void*)&pRec[i].i_value);
					pDBrec->I = pRec[i].i_value;
					//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "I", (void*)&pRec[i].i_value);
				}
				BYTE sta=0;
				if(fabs(pRec[i].i_value)>0.1||fabs(pRec[i].p_value)>0.1||fabs(pRec[i].q_value)>0.1)
				{
					sta=1;
					//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "sta", (void*)&sta);
				}
				else if(fabs(pDBrec->Pt)>0.1||fabs(pDBrec->Qt)>0.1||fabs(pDBrec->I)>0.1)
				{
					sta=1;
					//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "sta", (void*)&sta);
				}
				if(pDBrec->sta != sta)
				{
					LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "sta", &sta);
					pDBrec->sta = sta;
				}
			}
			else if (pDBrec->Stationt == pRec[i].fac_id)
			{
				if (fabs(pDBrec->Pt - pRec[i].p_value)>0.01)
				{
					LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos,"Pt", (void*)&pRec[i].p_value);
					pDBrec->Pt = pRec[i].p_value;
					//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "Pt", (void*)&pRec[i].p_value);
				}
				if (fabs(pDBrec->Qt - pRec[i].q_value)>0.01)
				{
					LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "Qt", (void*)&pRec[i].q_value);
					pDBrec->Qt = pRec[i].q_value;
					//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "Qt", (void*)&pRec[i].q_value);
				}
				if (fabs(pDBrec->I - pRec[i].i_value)>0.01)
				{
					LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "I", (void*)&pRec[i].i_value);
					pDBrec->I = pRec[i].i_value;
					//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "I", (void*)&pRec[i].i_value);
				}
			}
			BYTE sta=0;
			if(fabs(pRec[i].i_value)>0.1||fabs(pRec[i].p_value)>0.1||fabs(pRec[i].q_value)>0.1)
			{
				sta=1;
				//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "sta", (void*)&sta);
			}
			else if(fabs(pDBrec->Pf)>0.1||fabs(pDBrec->Qf)>0.1||fabs(pDBrec->I)>0.1)
			{
				sta=1;
				//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "sta", (void*)&sta);
			}

			if(pDBrec->sta != sta)
			{
				LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "sta", &sta);
				pDBrec->sta = sta;
			}

			if (pDBrec->LogTime != g_TimeFile)
			{
				LSI_PutColVal(m_nTableID_Line, m_pPosLine->nPos, "LogTime", (void*)&g_TimeFile);
				pDBrec->LogTime = g_TimeFile;
			}
			//g_DB.ModifyRecord(m_nTableID_Line, m_szTmp.GetBuffer(0), "LogTime", (void*)&g_TimeFile);
		}
	}
}