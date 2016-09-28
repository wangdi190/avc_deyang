// DB_PASMeasure.h: interface for the DB_PASMeasure class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PASMEASURE_H__16C0EF5F_38B6_493E_84FF_7FE168984298__INCLUDED_)
#define AFX_DB_PASMEASURE_H__16C0EF5F_38B6_493E_84FF_7FE168984298__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_PASMeasure  
{
public:
	DB_PASMeasure();
	virtual ~DB_PASMeasure();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_PASMEASURE_H__16C0EF5F_38B6_493E_84FF_7FE168984298__INCLUDED_)
