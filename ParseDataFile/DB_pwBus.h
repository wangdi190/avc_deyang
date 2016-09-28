// DB_pwBus.h: interface for the DB_pwBus class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PWBUS_H__6FFD77F1_F23B_4B1E_8686_CC5B37434CD5__INCLUDED_)
#define AFX_DB_PWBUS_H__6FFD77F1_F23B_4B1E_8686_CC5B37434CD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct  
{
	int nPos;//
	DWORD nu;
	visualpw_Bus rec;
}PositionBus;

class DB_pwBus  
{
public:
	DB_pwBus();
	virtual ~DB_pwBus();
public:
	PositionBus *m_pPosBus;
	typedef std::vector<PositionBus> VecBus;
	VecBus m_VecBus;
	
	int BinaryFindBusByNu(DWORD nu);

	CString m_szTmp;
	int m_recn, m_erro, m_nRet;
	int m_nTableID_Bus;
	bool InitParam();
	void RefreshModel(char *pData, int bufSize);

	void RefreshRealTime(char *pData, int bufSize);
};

#endif // !defined(AFX_DB_PWBUS_H__6FFD77F1_F23B_4B1E_8686_CC5B37434CD5__INCLUDED_)
