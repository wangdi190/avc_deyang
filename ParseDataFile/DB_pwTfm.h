// DB_pwTfm.h: interface for the DB_pwTfm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PWTFM_H__51A3B185_582E_491D_AFEB_C384DB36002B__INCLUDED_)
#define AFX_DB_PWTFM_H__51A3B185_582E_491D_AFEB_C384DB36002B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct
{
	int nPos;
	DWORD nu;
	visualpw_Tfm1 rec;
}PositionTfm1;

typedef struct
{
	int nPos;
	DWORD nu;
	visualpw_Tfm2 rec;
}PositionTfm2;

typedef struct
{
	int nPos;
	DWORD nu;
	visualpw_Winding rec;
}PositionWinding;

class DB_pwTfm  
{
public:
	DB_pwTfm();
	virtual ~DB_pwTfm();
public:

	PositionTfm1 *m_pPosTfm1;
	typedef std::vector<PositionTfm1> VecTfm1;
	VecTfm1 m_VecTfm1;

	PositionTfm2 *m_pPosTfm2;
	typedef std::vector<PositionTfm2> VecTfm2;
	VecTfm2 m_VecTfm2;

	PositionWinding *m_pPosWinding;
	typedef std::vector<PositionWinding> VecWinding;
	VecWinding m_VecWinding;

	CString m_szTmp;
	int m_recn, m_erro, m_nRet;
	int m_nTableID_Tfm1, m_nTableID_Tfm2, m_nTableID_Winding;
	bool InitParam();
	bool InitParam_Tfm1();
	bool InitParam_Tfm2();
	bool InitParam_Winding();


	int BinaryFindTfm1Nu(DWORD nu);
	int BinaryFindTfm2Nu(DWORD nu);
	int BinaryFindWindingNu(DWORD nu);

	void RefreshModel_TR(char *pData, int bufSize);
	void RefreshModel_TRWD(char *pData, int bufSize);

	void RefreshRealTime_TRWD(char *pData, int bufSize);
};

#endif // !defined(AFX_DB_PWTFM_H__51A3B185_582E_491D_AFEB_C384DB36002B__INCLUDED_)
