// DB_CommonVec.cpp: implementation of the DB_CommonVec class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_CommonVec.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_CommonVec::DB_CommonVec()
{

}

DB_CommonVec::~DB_CommonVec()
{

}

BOOL DB_CommonVec::SortVoltageByVltyID(VL_TYPE_Model  a, VL_TYPE_Model  b)
{
	if(a.vlty_id < b.vlty_id)
		return TRUE;
	else
		return FALSE;
}

void DB_CommonVec::RefreshModel_Voltage(char *pData, int bufSize)
{
	m_Vec_VlType.clear();

	VL_TYPE_Model *pRec = (VL_TYPE_Model*)pData;
	VL_TYPE_Model DBrec;
	for (int i=0; i<bufSize/sizeof(VL_TYPE_Model); i++)
	{
		ZeroMemory(&DBrec, sizeof(DBrec));
		DBrec.vlty_id = pRec[i].vlty_id;
		DBrec.vbase = pRec[i].vbase;
		m_Vec_VlType.push_back(DBrec);
	}
	//ÅÅÐò
	std::sort(m_Vec_VlType.begin(), m_Vec_VlType.end(), SortVoltageByVltyID);
}



float DB_CommonVec::BinaryFindVoltageBase(int vlty_id)
{
	DWORD nRet;
	long lMin=0;long lMid=0;
	long lMax = m_Vec_VlType.size()-1;
	while(lMin<=lMax)
	{
		lMid = (lMin+lMax)/2;
		if (lMid>=0)
		{
			nRet = m_Vec_VlType.at(lMid).vlty_id;
			if (nRet>vlty_id)
				lMax = lMid-1;
			else if (nRet<vlty_id)
				lMin = lMid+1;
			else
				return m_Vec_VlType.at(lMid).vbase;
		}
		else
			break;
	}
	return -1;
}