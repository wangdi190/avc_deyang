// CommonFunc.h: interface for the CCommonFunc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMONFUNC_H__B2850728_D335_4FAE_85BD_B668CBE65642__INCLUDED_)
#define AFX_COMMONFUNC_H__B2850728_D335_4FAE_85BD_B668CBE65642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*#include <LIST>

typedef struct  
{
	CTime time;
	char file[64];
	DWORD size;
}ST_LOG;
typedef std::list<ST_LOG> ListLog;
*/

#pragma comment(lib, "LogLibrary.lib")
bool WINAPI WriteRecord(char *pApp, char *pData);

#pragma comment(lib, "CUserApi.lib")
bool WINAPI V_CheckUser(char *name, char *pw,int &type);

class CCommonFunc  
{
public:
	CCommonFunc();
	virtual ~CCommonFunc();

	void PutCol(DWORD *pOldVal, DWORD NewVal, int nTableID, int nPos, char *pColName);
	void PutCol(BYTE *pOldVal, BYTE NewVal, int nTableID, int nPos, char *pColName);
	void PutCol(CTime *pOldVal, CTime NewVal, int nTableID, int nPos, char *pColName);
	void PutCol(float *pOldVal, float NewVal, int nTableID, int nPos, char *pColName, float fInter=0.01);
	void PutCol(short *pOldVal, short NewVal, int nTableID, int nPos, char *pColName);

//	ListLog m_Listlog;
};

#endif // !defined(AFX_COMMONFUNC_H__B2850728_D335_4FAE_85BD_B668CBE65642__INCLUDED_)
