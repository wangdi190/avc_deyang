// DB_pwZone.h: interface for the DB_pwZone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PWZONE_H__48462EE8_DB26_45C0_B3F7_DD17D67AF9D1__INCLUDED_)
#define AFX_DB_PWZONE_H__48462EE8_DB26_45C0_B3F7_DD17D67AF9D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_pwZone  
{
public:
	DB_pwZone();
	virtual ~DB_pwZone();
public:
	CString m_szTmp;
	int m_recn, m_erro;
	void RefreshModel(char *pData, int bufSize);
};

#endif // !defined(AFX_DB_PWZONE_H__48462EE8_DB26_45C0_B3F7_DD17D67AF9D1__INCLUDED_)
