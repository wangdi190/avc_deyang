// DB_pwGen.h: interface for the DB_pwGen class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PWGEN_H__0865C80F_EDD4_47F1_A476_DF0026E693F8__INCLUDED_)
#define AFX_DB_PWGEN_H__0865C80F_EDD4_47F1_A476_DF0026E693F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct  
{
	int nPos;//
	DWORD nu;
	visualpw_Gen rec;
}PositionGen;

class DB_pwGen  
{
public:
	DB_pwGen();
	virtual ~DB_pwGen();

public:
	PositionGen *m_pPosGen;
	typedef std::vector<PositionGen> VecGen;
	VecGen m_VecGen;
	
	int BinaryFindGenByNu(DWORD nu);

	CString m_szTmp;
	int m_recn, m_erro, m_nRet;
	int m_nTableID_Gen;
	bool InitParam();
	void RefreshModel(char *pData, int bufSize);

	void RefreshRealTime(char *pData, int bufSize);
};

#endif // !defined(AFX_DB_PWGEN_H__0865C80F_EDD4_47F1_A476_DF0026E693F8__INCLUDED_)
