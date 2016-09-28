// DB_PASRuninfo.h: interface for the DB_PASRuninfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PASRUNINFO_H__927B0054_41C0_48F8_9A1C_F070A33D0D70__INCLUDED_)
#define AFX_DB_PASRUNINFO_H__927B0054_41C0_48F8_9A1C_F070A33D0D70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_PASRuninfo  
{
public:
	DB_PASRuninfo();
	virtual ~DB_PASRuninfo();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_PASRUNINFO_H__927B0054_41C0_48F8_9A1C_F070A33D0D70__INCLUDED_)
