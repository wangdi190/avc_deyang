// CommonFunc.cpp: implementation of the CCommonFunc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "CommonFunc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCommonFunc::CCommonFunc()
{

}

CCommonFunc::~CCommonFunc()
{

}

void CCommonFunc::PutCol(DWORD *pOldVal, DWORD NewVal, int nTableID, int nPos, char *pColName)
{
	if(*pOldVal != NewVal)
	{
		LSI_PutColVal(nTableID, nPos, pColName, &NewVal);
		*pOldVal = NewVal;
	}
}

void CCommonFunc::PutCol(short *pOldVal, short NewVal, int nTableID, int nPos, char *pColName)
{
	if(*pOldVal != NewVal)
	{
		LSI_PutColVal(nTableID, nPos, pColName, &NewVal);
		*pOldVal = NewVal;
	}
}

void CCommonFunc::PutCol(BYTE *pOldVal, BYTE NewVal, int nTableID, int nPos, char *pColName)
{
	if(*pOldVal != NewVal)
	{
		LSI_PutColVal(nTableID, nPos, pColName, &NewVal);
		*pOldVal = NewVal;
	}
}

void CCommonFunc::PutCol(CTime *pOldVal, CTime NewVal, int nTableID, int nPos, char *pColName)
{
	if(*pOldVal != NewVal)
	{
		LSI_PutColVal(nTableID, nPos, pColName, &NewVal);
		*pOldVal = NewVal;
	}
}

void CCommonFunc::PutCol(float *pOldVal, float NewVal, int nTableID, int nPos, char *pColName,float fInter)
{
	if(fabs(*pOldVal - NewVal)>fInter)
	{
		LSI_PutColVal(nTableID, nPos, pColName, &NewVal);
		*pOldVal = NewVal;
	}
}