// DB_pwLoad.h: interface for the DB_pwLoad class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PWLOAD_H__61AAA80D_99DA_42BC_B6A9_92E2D2E7905A__INCLUDED_)
#define AFX_DB_PWLOAD_H__61AAA80D_99DA_42BC_B6A9_92E2D2E7905A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct  
{
	int nPos;//
	DWORD nu;
	visualpw_Load rec;
}PositionLoad;


class DB_pwLoad  
{
public:
	DB_pwLoad();
	virtual ~DB_pwLoad();
public:
	PositionLoad *m_pPosLoad;
	typedef std::vector<PositionLoad> VecLoad;
	VecLoad m_VecLoad;
	
	int BinaryFindLoadByNu(DWORD nu);

	CString m_szTmp;
	int m_recn, m_erro;
	int m_nTableID_Load, m_nRet;
	bool InitParam();

	void RefreshModel(char *pData, int bufSize);
	void RefreshRealTime(char *pData, int bufSize);
};

#endif // !defined(AFX_DB_PWLOAD_H__61AAA80D_99DA_42BC_B6A9_92E2D2E7905A__INCLUDED_)
