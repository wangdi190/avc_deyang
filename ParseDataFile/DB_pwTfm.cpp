// DB_pwTfm.cpp: implementation of the DB_pwTfm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_pwTfm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern bool g_firstrun;

DB_pwTfm::DB_pwTfm()
{

}

DB_pwTfm::~DB_pwTfm()
{
}

bool DB_pwTfm::InitParam()
{
	InitParam_Tfm1();
	InitParam_Tfm2();
	InitParam_Winding();
	return true;
}

bool SortByTfm1Nu(PositionTfm1 a, PositionTfm1 b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool SortByTfm2Nu(PositionTfm2 a, PositionTfm2 b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool SortByWindingNu(PositionWinding a, PositionWinding b)
{
	if(a.nu<b.nu)
		return true;
	else
		return false;
}

bool DB_pwTfm::InitParam_Tfm1()
{
	m_nTableID_Tfm1 = g_DB.GetTableID("visualpw", "Tfm1");
	visualpw_Tfm1 *pDBrec = (visualpw_Tfm1*)g_DB.QueryRecord(m_nTableID_Tfm1,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	m_VecTfm1.clear();
	
	PositionTfm1 posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionTfm1));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBrec[i], sizeof(visualpw_Tfm1));
		posRec.nu = pDBrec[i].NU;
		
		m_VecTfm1.push_back(posRec);
	}
	std::sort(m_VecTfm1.begin(), m_VecTfm1.end(), SortByTfm1Nu);
	return true;
}

bool DB_pwTfm::InitParam_Tfm2()
{
	m_nTableID_Tfm2 = g_DB.GetTableID("visualpw", "Tfm2");
	visualpw_Tfm2 *pDBrec = (visualpw_Tfm2*)g_DB.QueryRecord(m_nTableID_Tfm2,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	m_VecTfm2.clear();
	
	PositionTfm2 posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionTfm2));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBrec[i], sizeof(visualpw_Tfm2));
		posRec.nu = pDBrec[i].NU;
		
		m_VecTfm2.push_back(posRec);
	}
	std::sort(m_VecTfm2.begin(), m_VecTfm2.end(), SortByTfm2Nu);
	return true;
}

bool DB_pwTfm::InitParam_Winding()
{
	m_nTableID_Winding = g_DB.GetTableID("visualpw", "Winding");
	visualpw_Winding *pDBrec = (visualpw_Winding*)g_DB.QueryRecord(m_nTableID_Winding,NULL,m_recn);
	if(m_recn<0) 
		return false;
	
	m_VecWinding.clear();
	
	PositionWinding posRec;
	for (int i=0; i<m_recn; i++)
	{
		memset(&posRec, 0 , sizeof(PositionWinding));
		posRec.nPos = i;
		memcpy(&posRec.rec, &pDBrec[i], sizeof(visualpw_Winding));
		posRec.nu = pDBrec[i].NU;
		
		m_VecWinding.push_back(posRec);
	}
	std::sort(m_VecWinding.begin(), m_VecWinding.end(), SortByWindingNu);
	return true;
}

int DB_pwTfm::BinaryFindTfm1Nu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecTfm1.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecTfm1.at(lMid).nu;
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

int DB_pwTfm::BinaryFindTfm2Nu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecTfm2.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecTfm2.at(lMid).nu;
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

int DB_pwTfm::BinaryFindWindingNu(DWORD nu)
{
	long lMin=0;long lMid=0;
	long lMax=m_VecWinding.size()-1;
	DWORD lid;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			lid= m_VecWinding.at(lMid).nu;
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

void DB_pwTfm::RefreshModel_TR(char *pData, int bufSize)
{
	TR_DEVICE_Model *pRec = (TR_DEVICE_Model*)pData;
	visualpw_Station *pSta=NULL;
	bool bAddNew_Tfm1=false, bAddNew_Tfm2=false;
	
	for (int i=0; i<bufSize/sizeof(TR_DEVICE_Model); i++)
	{
		if(MatchKeyNo(pRec[i].tr_id, TR_DEVICE_MODEL) == false)
		{
			break;
		}

		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);
		if (pRec[i].trty == 0)  //二绕组变压器
		{
			visualpw_Tfm1 DBrec1, *pDBrec1;
			ZeroMemory(&DBrec1, sizeof(DBrec1));

		//	m_szTmp.Format("TABLE(visualpw.Tfm1),WHERE(NU=%d)", pRec[i].tr_id);
		//	pDBrec1 = (visualpw_Tfm1*)g_DB.QueryRecord("Tfm1",m_szTmp.GetBuffer(0),m_recn,"visualpw");
			m_nRet = BinaryFindTfm1Nu(pRec[i].tr_id);
			if(m_nRet == -1)
			{
				DBrec1.NU = pRec[i].tr_id;
				sprintf(DBrec1.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].tr_name);
				DBrec1.Station = pRec[i].fac_id;
				DBrec1.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec1.Station);
				sprintf(DBrec1.ID, "%d", pRec[i].tr_id);
				DBrec1.ele = 1-pRec[i].run_state;
				DBrec1.sta = 1;
				LSI_AppendRec("visualpw.Tfm1", &DBrec1);
				bAddNew_Tfm1 = true;
			}
			else
			{
				//memcpy(&DBrec1, pDBrec1, sizeof(DBrec1));
				pDBrec1 = &m_VecTfm1.at(m_nRet).rec;
				sprintf(pDBrec1->Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].tr_name);
				pDBrec1->Station = pRec[i].fac_id;
				pDBrec1->ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec1.Station);
				sprintf(pDBrec1->ID, "%d", pRec[i].tr_id);
				pDBrec1->ele = 1-pRec[i].run_state;

				g_DB.UpdateRealRecord("Tfm1", m_VecTfm1.at(m_nRet).nPos, &m_VecTfm1.at(m_nRet).rec, "visualpw");
				//g_DB.UpdateRecord("Tfm1", m_szTmp.GetBuffer(0), &DBrec1, "visualpw");
			}
		}
		else if (pRec[i].trty == 1) // 三绕组变压器
		{
			visualpw_Tfm2 DBrec2, *pDBrec2;
			ZeroMemory(&DBrec2, sizeof(DBrec2));
			//m_szTmp.Format("TABLE(visualpw.Tfm2),WHERE(NU=%d)", pRec[i].tr_id);
			//pDBrec2 = (visualpw_Tfm2*)g_DB.QueryRecord("Tfm2",m_szTmp.GetBuffer(0),m_recn,"visualpw");

			m_nRet = BinaryFindTfm2Nu(pRec[i].tr_id);
			if(m_nRet == -1)
			{
				DBrec2.NU = pRec[i].tr_id;
				sprintf(DBrec2.Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].tr_name);
				DBrec2.Station = pRec[i].fac_id;
				DBrec2.ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec2.Station);
				sprintf(DBrec2.ID, "%d", pRec[i].tr_id);
				DBrec2.ele = 1-pRec[i].run_state;
				DBrec2.sta = 1;
				LSI_AppendRec("visualpw.Tfm2", &DBrec2);
				bAddNew_Tfm2 = true;
			}
			else
			{
				pDBrec2 = &m_VecTfm2.at(m_nRet).rec;
				//memcpy(&DBrec2, pDBrec2, sizeof(DBrec2));
				sprintf(pDBrec2->Name, "%s%s", pSta!=NULL?pSta->Name:"", pRec[i].tr_name);
				pDBrec2->Station = pRec[i].fac_id;
				pDBrec2->ZoneNU=pSta!=NULL?pSta->zoneNU:0;//GetZoneNU(DBrec2.Station);
				sprintf(pDBrec2->ID, "%d", pRec[i].tr_id);
				pDBrec2->ele = 1-pRec[i].run_state;
				g_DB.UpdateRealRecord("Tfm2", m_VecTfm2.at(m_nRet).nPos, &m_VecTfm2.at(m_nRet).rec, "visualpw");
			//	g_DB.UpdateRecord("Tfm2", m_szTmp.GetBuffer(0), &DBrec2, "visualpw");
			}
		}
	}
}

void DB_pwTfm::RefreshModel_TRWD(char *pData, int bufSize)
{
	
	TRWD_DEVICE_Model *pRec = (TRWD_DEVICE_Model*)pData;
	visualpw_Tfm1 DBrec1, *pDBrec1;
	visualpw_Tfm2 DBrec2, *pDBrec2;

	for (int i=0; i<bufSize/sizeof(TRWD_DEVICE_Model); i++)
	{
		//ZeroMemory(&DBrec1, sizeof(DBrec1));
		//ZeroMemory(&DBrec2, sizeof(DBrec2));
		
		//m_szTmp.Format("TABLE(visualpw.Tfm1),WHERE(NU=%d)", pRec[i].tr_id);
		//pDBrec1 = (visualpw_Tfm1*)g_DB.QueryRecord("Tfm1",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindTfm1Nu(pRec[i].tr_id);
		if(m_nRet != -1)
		{
			//memcpy(&DBrec1, pDBrec1, sizeof(DBrec1));
			pDBrec1 = &m_VecTfm1.at(m_nRet).rec;
			m_pPosTfm1 = &m_VecTfm1.at(m_nRet);
		
			if(pRec[i].nd_no<0)
				pRec[i].nd_no = 0;

			if(pRec[i].trwd_type == WINDING_HIGH)	//高
			{
				g_ComFunc.PutCol(&pDBrec1->NodeH, pRec[i].nd_no, m_nTableID_Tfm1, m_pPosTfm1->nPos, "NodeH");
				g_ComFunc.PutCol(&pDBrec1->Pmax, pRec[i].snom, m_nTableID_Tfm1, m_pPosTfm1->nPos, "Pmax");
				g_ComFunc.PutCol((DWORD*)(&pDBrec1->tap), pRec[i].tapty_id, m_nTableID_Tfm1, m_pPosTfm1->nPos, "tap");

			/*	DBrec1.NodeH = pRec[i].nd_no;
				DBrec1.Pmax = pRec[i].snom;
				DBrec1.tap = pRec[i].tapty_id;*/
			}
			else if (pRec[i].trwd_type == WINDING_LOW)//低
				g_ComFunc.PutCol(&pDBrec1->NodeL, pRec[i].nd_no, m_nTableID_Tfm1, m_pPosTfm1->nPos, "NodeL");
				//DBrec1.NodeL = pRec[i].nd_no;

			
			DBrec1.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			g_ComFunc.PutCol(&pDBrec1->VL, DBrec1.VL, m_nTableID_Tfm1, m_pPosTfm1->nPos, "VL");

			//DBrec1.LogTime=g_TimeFile;
			g_ComFunc.PutCol(&pDBrec1->LogTime, g_TimeFile, m_nTableID_Tfm1, m_pPosTfm1->nPos, "LogTime");
			//g_DB.UpdateRecord("Tfm1", m_szTmp.GetBuffer(0), &DBrec1, "visualpw");
				
		}
		else
		{
			//m_szTmp.Format("TABLE(visualpw.Tfm2),WHERE(NU=%d)", pRec[i].tr_id);
			//pDBrec2 = (visualpw_Tfm2*)g_DB.QueryRecord("Tfm2",m_szTmp.GetBuffer(0),m_recn,"visualpw");
			m_nRet = BinaryFindTfm2Nu(pRec[i].tr_id);
			if(m_nRet != -1)
			{
				//memcpy(&DBrec2, pDBrec2, sizeof(DBrec2));
				pDBrec2 = &m_VecTfm2.at(m_nRet).rec;
				m_pPosTfm2 = &m_VecTfm2.at(m_nRet);

				if(pRec[i].nd_no<0)
					pRec[i].nd_no = 0;

				if(pRec[i].trwd_type == WINDING_HIGH)	//高
				{
					//DBrec2.NodeH = pRec[i].nd_no;
					//DBrec2.Pmax = pRec[i].snom;
					//DBrec2.TapH = pRec[i].tapty_id;

					g_ComFunc.PutCol(&pDBrec2->NodeH, pRec[i].nd_no, m_nTableID_Tfm2, m_pPosTfm2->nPos, "NodeH");
					g_ComFunc.PutCol(&pDBrec2->Pmax, pRec[i].snom, m_nTableID_Tfm2, m_pPosTfm2->nPos, "Pmax");
					g_ComFunc.PutCol((DWORD*)&pDBrec2->TapH, pRec[i].tapty_id, m_nTableID_Tfm2, m_pPosTfm2->nPos, "TapH");
				}
				if(pRec[i].trwd_type == WINDING_MID)	//中
				{
					//DBrec2.NodeM = pRec[i].nd_no;
					//DBrec2.TapM = pRec[i].tapty_id;

					g_ComFunc.PutCol(&pDBrec2->NodeM, pRec[i].nd_no, m_nTableID_Tfm2, m_pPosTfm2->nPos, "NodeM");
					g_ComFunc.PutCol((DWORD*)&pDBrec2->TapM, pRec[i].tapty_id, m_nTableID_Tfm2, m_pPosTfm2->nPos, "TapM");
				}
				if(pRec[i].trwd_type == WINDING_LOW)	//低
				{
				//	DBrec2.NodeL = pRec[i].nd_no;
				//	DBrec2.TapL = pRec[i].tapty_id;

					g_ComFunc.PutCol(&pDBrec2->NodeL, pRec[i].nd_no, m_nTableID_Tfm2, m_pPosTfm2->nPos, "NodeL");
					g_ComFunc.PutCol((DWORD*)&pDBrec2->TapL, pRec[i].tapty_id, m_nTableID_Tfm2, m_pPosTfm2->nPos, "TapL");
				}

				DBrec2.VL = g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
				g_ComFunc.PutCol(&pDBrec2->VL, DBrec2.VL, m_nTableID_Tfm2, m_pPosTfm2->nPos, "VL");

				//DBrec2.LogTime=g_TimeFile;
				g_ComFunc.PutCol(&pDBrec2->LogTime, g_TimeFile, m_nTableID_Tfm2, m_pPosTfm2->nPos, "LogTime");
				//g_DB.UpdateRecord("Tfm2", m_szTmp.GetBuffer(0), &DBrec2, "visualpw");

			}
		}
	}

	visualpw_Winding DBrec, *pDBrec;
	visualpw_Station *pSta=NULL;
	bool bAddNew_Winding = false;
	for (i=0; i<bufSize/sizeof(TRWD_DEVICE_Model); i++)
	{

		if(MatchKeyNo(pRec[i].trwd_id, TRWD_DEVICE_MODEL) == false)
		{
			break;
		}

		ZeroMemory(&DBrec, sizeof(DBrec));
		pSta = g_DataBase.m_pwStation.GetSubStationNameByID(pRec[i].fac_id);

		//m_szTmp.Format("TABLE(visualpw.Winding),WHERE(NU=%d)", pRec[i].trwd_id);
		//pDBrec = (visualpw_Winding*)g_DB.QueryRecord("Winding",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindWindingNu(pRec[i].trwd_id);
		if(m_nRet == -1)
		{
			DBrec.NU = pRec[i].trwd_id;
			sprintf(DBrec.ID, "%d", pRec[i].trwd_id);
			sprintf(DBrec.Name, "%s.%s", pSta!=NULL?pSta->Name:"", pRec[i].trwd_name);
			sprintf(DBrec.TID, "%d", pRec[i].tr_id);
			DBrec.baseKV=g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			DBrec.ratedKV = pRec[i].vnom;
			DBrec.ratedMVA = pRec[i].snom;
			DBrec.Type = pRec[i].trwd_type;

//			DBrec.fShortLoss = pRec[i].pk;
//			DBrec.fShortVol = pRec[i].uk;
			DBrec.fR = pRec[i].r_value_pu/100;
//			DBrec.fR0 = pRec[i].r0_value_pu;
			DBrec.fX = pRec[i].x_value_pu/100;
//			DBrec.fX0 = pRec[i].x0_value_pu;

			
			TAP_TYPE_Model* ptap=g_DataBase.m_pwTfmTap.GetTapByID(pRec[i].tapty_id);
			if(ptap!=NULL)
			{
				DBrec.Tmax=ptap->tapty_mx;
				DBrec.Tmin=ptap->tapty_mn;
				DBrec.Tnor=ptap->tapty_nom;
				DBrec.step=fabs(ptap->tapty_step);
			}

			DBrec.LogTime=g_TimeFile;
			LSI_AppendRec("visualpw.Winding", &DBrec);
			bAddNew_Winding = true;
		}
		else
		{
			pDBrec = &m_VecWinding.at(m_nRet).rec;
			//memcpy(&DBrec, pDBrec, sizeof(DBrec));
			sprintf(pDBrec->ID, "%d", pRec[i].trwd_id);
			sprintf(pDBrec->Name, "%s.%s", pSta!=NULL?pSta->Name:"", pRec[i].trwd_name);
			sprintf(pDBrec->TID, "%d", pRec[i].tr_id);
			pDBrec->baseKV=g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			pDBrec->ratedKV = pRec[i].vnom;//g_DataBase.m_CommonVec.BinaryFindVoltageBase(pRec[i].vlty_id);
			pDBrec->ratedMVA = pRec[i].snom;
			pDBrec->Type = pRec[i].trwd_type;
//			DBrec.fShortLoss = pRec[i].pk;
//			DBrec.fShortVol = pRec[i].uk;
			pDBrec->fR = pRec[i].r_value_pu/100;
//			DBrec.fR0 = pRec[i].r0_value_pu;
			pDBrec->fX = pRec[i].x_value_pu/100;
//			DBrec.fX0 = pRec[i].x0_value_pu;
			pDBrec->LogTime=g_TimeFile;

			TAP_TYPE_Model* ptap=g_DataBase.m_pwTfmTap.GetTapByID(pRec[i].tapty_id);
			if(ptap!=NULL)
			{
				pDBrec->Tmax=ptap->tapty_mx;
				pDBrec->Tmin=ptap->tapty_mn;
				pDBrec->Tnor=ptap->tapty_nom;
				pDBrec->step=fabs(ptap->tapty_step);
			}
			g_DB.UpdateRealRecord("Winding", m_VecWinding.at(m_nRet).nPos, &m_VecWinding.at(m_nRet).rec, "visualpw");
			//g_DB.UpdateRecord("Winding", m_szTmp.GetBuffer(0), &DBrec, "visualpw");
		}
	}
	if(bAddNew_Winding)
		InitParam_Winding();
}


void DB_pwTfm::RefreshRealTime_TRWD(char *pData, int bufSize)
{
//	InitParam();

	
	TRWD_DEVICE_Real *pRec = (TRWD_DEVICE_Real*)pData;
	visualpw_Tfm1 *pDBrec1;
	visualpw_Tfm2 *pDBrec2;
	
	for (int i=0; i<bufSize/sizeof(TRWD_DEVICE_Real); i++)
	{
		 //sprintf(chSql,"TABLE(%s.%s),WHERE(%s)",pszDB,pszTable,pszWhere);
		//m_szTmp.Format("TABLE(visualpw.Tfm1),WHERE(NU=%d)", pRec[i].tr_id);
		//pDBrec1 = (visualpw_Tfm1*)g_DB.QueryRecord("Tfm1",m_szTmp.GetBuffer(0),m_recn,"visualpw");
		m_nRet = BinaryFindTfm1Nu(pRec[i].tr_id);
		if(m_nRet != -1)
		{
			pDBrec1 = &m_VecTfm1.at(m_nRet).rec;
			m_pPosTfm1 = &m_VecTfm1.at(m_nRet);
			if(pRec[i].trwd_type == 0)	   //高
			{
				g_ComFunc.PutCol(&pDBrec1->P, pRec[i].p_value, m_nTableID_Tfm1, m_pPosTfm1->nPos, "P");
				g_ComFunc.PutCol(&pDBrec1->Q, pRec[i].q_value, m_nTableID_Tfm1, m_pPosTfm1->nPos, "Q");
				g_ComFunc.PutCol(&pDBrec1->I, pRec[i].i_value, m_nTableID_Tfm1, m_pPosTfm1->nPos, "I");

				/*if(fabs(pDBrec1->P - pRec[i].p_value)>0.01)
					g_DB.ModifyRecord(m_nTableID_Tfm1, m_szTmp.GetBuffer(0), "P", (void*)&pRec[i].p_value);
				if(fabs(pDBrec1->Q - pRec[i].q_value)>0.01)
					g_DB.ModifyRecord(m_nTableID_Tfm1, m_szTmp.GetBuffer(0), "Q", (void*)&pRec[i].q_value);
				if(fabs(pDBrec1->I - pRec[i].i_value)>0.01)
					g_DB.ModifyRecord(m_nTableID_Tfm1, m_szTmp.GetBuffer(0), "I", (void*)&pRec[i].i_value);*/

				BYTE Tsta=pDBrec1->Tsta;
				if(g_TimeFile.GetDay()!=pDBrec1->LogTime.GetDay())		//每日复位
					Tsta=0;
				
				if(fabs(pDBrec1->tap - pRec[i].tap_pos)>=1)
				{
					//g_DB.ModifyRecord(m_nTableID_Tfm1, m_szTmp.GetBuffer(0), "tap", (void*)&pRec[i].tap_pos);
					LSI_PutColVal(m_nTableID_Tfm1, m_pPosTfm1->nPos, "tap", (void*)&pRec[i].tap_pos);
					if(g_firstrun==false)
						Tsta++;
				}
			//	if(Tsta!=pDBrec1->Tsta)					//变位计数
			//		g_DB.ModifyRecord(m_nTableID_Tfm1, m_szTmp.GetBuffer(0), "Tsta", (void*)&Tsta);

				g_ComFunc.PutCol(&pDBrec1->Tsta, Tsta, m_nTableID_Tfm1, m_pPosTfm1->nPos, "Tsta");

				BYTE sta=0;
				if(fabs(pRec[i].i_value)>0.1||fabs(pRec[i].p_value)>0.1||fabs(pRec[i].q_value)>0.1)
					sta=1;
				//g_DB.ModifyRecord(m_nTableID_Tfm1, m_szTmp.GetBuffer(0), "sta", (void*)&sta);
				g_ComFunc.PutCol(&pDBrec1->sta, sta, m_nTableID_Tfm1, m_pPosTfm1->nPos, "sta");

			}

			else if (pRec[i].trwd_type == 2)//低
			{
				g_ComFunc.PutCol(&pDBrec1->P2, pRec[i].p_value, m_nTableID_Tfm1, m_pPosTfm1->nPos, "P2");
				g_ComFunc.PutCol(&pDBrec1->Q2, pRec[i].q_value, m_nTableID_Tfm1, m_pPosTfm1->nPos, "Q2");
				g_ComFunc.PutCol(&pDBrec1->I2, pRec[i].i_value, m_nTableID_Tfm1, m_pPosTfm1->nPos, "I2");

			/*	if(fabs(pDBrec1->P2 - pRec[i].p_value)>0.01)
					g_DB.ModifyRecord(m_nTableID_Tfm1, m_szTmp.GetBuffer(0), "P2", (void*)&pRec[i].p_value);
				if(fabs(pDBrec1->Q2 - pRec[i].q_value)>0.01)
					g_DB.ModifyRecord(m_nTableID_Tfm1, m_szTmp.GetBuffer(0), "Q2", (void*)&pRec[i].q_value);
				if(fabs(pDBrec1->I2 - pRec[i].i_value)>0.01)
					g_DB.ModifyRecord(m_nTableID_Tfm1, m_szTmp.GetBuffer(0), "I2", (void*)&pRec[i].i_value);*/
			}

			//g_DB.ModifyRecord(m_nTableID_Tfm1, m_szTmp.GetBuffer(0), "LogTime", (void*)&g_TimeFile);
			g_ComFunc.PutCol(&pDBrec1->LogTime, g_TimeFile, m_nTableID_Tfm1, m_pPosTfm1->nPos, "LogTime");
		}
		else
		{
			//m_szTmp.Format("TABLE(visualpw.Tfm2),WHERE(NU=%d)", pRec[i].tr_id);
			//pDBrec2 = (visualpw_Tfm2*)g_DB.QueryRecord("Tfm2",m_szTmp.GetBuffer(0),m_recn,"visualpw");
			m_nRet = BinaryFindTfm2Nu(pRec[i].tr_id);
			if(m_nRet != -1)
			{
				pDBrec2 = &m_VecTfm2.at(m_nRet).rec;
				m_pPosTfm2 = &m_VecTfm2.at(m_nRet);
				if(pRec[i].trwd_type == 0)	//高
				{
					g_ComFunc.PutCol(&pDBrec2->P, pRec[i].p_value, m_nTableID_Tfm2, m_pPosTfm2->nPos, "P");
					g_ComFunc.PutCol(&pDBrec2->Q, pRec[i].q_value, m_nTableID_Tfm2, m_pPosTfm2->nPos, "Q");
					g_ComFunc.PutCol(&pDBrec2->I, pRec[i].i_value, m_nTableID_Tfm2, m_pPosTfm2->nPos, "I");

				/*	if(fabs(pDBrec2->P - pRec[i].p_value)>0.01)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "P", (void*)&pRec[i].p_value);
					if(fabs(pDBrec2->Q - pRec[i].q_value)>0.01)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "Q", (void*)&pRec[i].q_value);
					if(fabs(pDBrec2->I - pRec[i].i_value)>0.01)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "I", (void*)&pRec[i].i_value);*/

					BYTE Tsta=pDBrec2->Tsta;
					if(g_TimeFile.GetDay()!=pDBrec2->LogTime.GetDay())		//复位
						Tsta=0;
					if(fabs(pDBrec2->TapH - pRec[i].tap_pos)>=1)
					{
						//g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "TapH", (void*)&pRec[i].tap_pos);
						LSI_PutColVal(m_nTableID_Tfm2, m_pPosTfm2->nPos, "TapH", (void*)&pRec[i].tap_pos);
						if(g_firstrun==false)
							Tsta++;
					}
					//if(Tsta!=pDBrec2->Tsta)					//变位计数
					//	g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "Tsta", (void*)&Tsta);
					g_ComFunc.PutCol(&pDBrec2->Tsta, Tsta, m_nTableID_Tfm2, m_pPosTfm2->nPos, "Tsta");

					BYTE sta=0;
					if(fabs(pRec[i].i_value)>0.1||fabs(pRec[i].p_value)>0.1||fabs(pRec[i].q_value)>0.1)
						sta=1;
					//g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "sta", (void*)&sta);
					g_ComFunc.PutCol(&pDBrec2->sta, sta, m_nTableID_Tfm2, m_pPosTfm2->nPos, "sta");
				}
				else if(pRec[i].trwd_type == 1)	//中
				{
					g_ComFunc.PutCol(&pDBrec2->P2, pRec[i].p_value, m_nTableID_Tfm2, m_pPosTfm2->nPos, "P2");
					g_ComFunc.PutCol(&pDBrec2->Q2, pRec[i].q_value, m_nTableID_Tfm2, m_pPosTfm2->nPos, "Q2");
					g_ComFunc.PutCol(&pDBrec2->I2, pRec[i].i_value, m_nTableID_Tfm2, m_pPosTfm2->nPos, "I2");
					g_ComFunc.PutCol(&pDBrec2->TapM, pRec[i].tap_pos, m_nTableID_Tfm2, m_pPosTfm2->nPos, "TapM", 1);

				/*	if(fabs(pDBrec2->P2 - pRec[i].p_value)>0.01)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "P2", (void*)&pRec[i].p_value);
					if(fabs(pDBrec2->Q2 - pRec[i].q_value)>0.01)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "Q2", (void*)&pRec[i].q_value);
					if(fabs(pDBrec2->I2 - pRec[i].i_value)>0.01)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "I2", (void*)&pRec[i].i_value);
					if(fabs(pDBrec2->TapM - pRec[i].tap_pos)>=1)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "TapM", (void*)&pRec[i].tap_pos);*/

				}
				else if (pRec[i].trwd_type == 2)//低
				{
					g_ComFunc.PutCol(&pDBrec2->P2, pRec[i].p_value, m_nTableID_Tfm2, m_pPosTfm2->nPos, "P2");
					g_ComFunc.PutCol(&pDBrec2->Q2, pRec[i].q_value, m_nTableID_Tfm2, m_pPosTfm2->nPos, "Q2");
					g_ComFunc.PutCol(&pDBrec2->I2, pRec[i].i_value, m_nTableID_Tfm2, m_pPosTfm2->nPos, "I2");
					g_ComFunc.PutCol(&pDBrec2->TapL, pRec[i].tap_pos, m_nTableID_Tfm2, m_pPosTfm2->nPos, "TapL", 1);

					/*if(fabs(pDBrec2->P3 - pRec[i].p_value)>0.01)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "P3", (void*)&pRec[i].p_value);
					if(fabs(pDBrec2->Q3 - pRec[i].q_value)>0.01)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "Q3", (void*)&pRec[i].q_value);
					if(fabs(pDBrec2->I3 - pRec[i].i_value)>0.01)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "I3", (void*)&pRec[i].i_value);
					if(fabs(pDBrec2->TapL - pRec[i].tap_pos)>=1)
						g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "TapL", (void*)&pRec[i].tap_pos);*/

				}
				g_ComFunc.PutCol(&pDBrec2->LogTime, g_TimeFile, m_nTableID_Tfm2, m_pPosTfm2->nPos, "LogTime");
				//g_DB.ModifyRecord(m_nTableID_Tfm2, m_szTmp.GetBuffer(0), "LogTime", (void*)&g_TimeFile);
			}

		}
	}
}