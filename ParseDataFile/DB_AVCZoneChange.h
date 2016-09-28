// DB_AVCZoneChange.h: interface for the DB_AVCZoneChange class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCZONECHANGE_H__D0804EFD_70AB_4454_992E_D6F647B8FCAE__INCLUDED_)
#define AFX_DB_AVCZONECHANGE_H__D0804EFD_70AB_4454_992E_D6F647B8FCAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AVCZoneChange  
{
public:
	DB_AVCZoneChange();
	virtual ~DB_AVCZoneChange();
	void RefreshModel(char* pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCZONECHANGE_H__D0804EFD_70AB_4454_992E_D6F647B8FCAE__INCLUDED_)
