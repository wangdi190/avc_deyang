// DB_AvcStation.h: interface for the DB_AvcStation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCSTATION_H__88A837EA_E44E_4829_8B4A_C20FAE5815B2__INCLUDED_)
#define AFX_DB_AVCSTATION_H__88A837EA_E44E_4829_8B4A_C20FAE5815B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AvcStation  
{
public:
	DB_AvcStation();
	virtual ~DB_AvcStation();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCSTATION_H__88A837EA_E44E_4829_8B4A_C20FAE5815B2__INCLUDED_)
