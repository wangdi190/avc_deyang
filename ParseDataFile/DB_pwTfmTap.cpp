// DB_pwTfmTap.cpp: implementation of the DB_pwTfmTap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ParseDataFile.h"
#include "DB_pwTfmTap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DB_pwTfmTap::DB_pwTfmTap()
{

}

DB_pwTfmTap::~DB_pwTfmTap()
{
	int count = m_tap.GetSize();
	for(int i=0; i<count; i++)
	{
		TAP_TYPE_Model* ptmp=(TAP_TYPE_Model*)m_tap.GetAt(i);
		if(ptmp!=NULL)
			delete ptmp;
		ptmp=NULL;
	}
	m_tap.RemoveAll();

}

void DB_pwTfmTap::RefreshModel(char *pData, int bufSize)
{
	TAP_TYPE_Model *pRec = (TAP_TYPE_Model*)pData;
	visualpw_Tfm1 DBrec1;// *pDBrec1;
	visualpw_Tfm2 DBrec2;// *pDBrec2;
	
	int count = m_tap.GetSize();
	for(int i=0; i<count; i++)
	{
		TAP_TYPE_Model* ptmp=(TAP_TYPE_Model*)m_tap.GetAt(i);
		if(ptmp!=NULL)
			delete ptmp;
		ptmp=NULL;
	}
	m_tap.RemoveAll();

	for (i=0; i<bufSize/sizeof(TAP_TYPE_Model); i++)
	{
		//TRACE("%d, %s, %d, %d\n", pRec[i].fac_id, pRec[i].bs_name, pRec[i].vlty_id, pRec[i].vmax, pRec[i].vmin);
		TAP_TYPE_Model* pnew = new TAP_TYPE_Model();
		memcpy(pnew, &pRec[i], sizeof(TAP_TYPE_Model));
		m_tap.Add(pnew);
	}
}

TAP_TYPE_Model* DB_pwTfmTap::GetTapByID(int nu)
{
	TAP_TYPE_Model* ptap=NULL;
	if(nu<=0)
		return ptap;

	int count = m_tap.GetSize();
	for(int i=0; i<count; i++)
	{
		TAP_TYPE_Model* ptmp=(TAP_TYPE_Model*)m_tap.GetAt(i);
		if(ptmp==NULL)
			continue;

		if(ptmp->tapty_id==nu)
			return ptmp;
	}
	return NULL;
}