// DB_pwShuntSreact.h: interface for the DB_pwShuntSreact class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PWSHUNTSREACT_H__DBABB96C_5468_42E1_B369_31C8DC370700__INCLUDED_)
#define AFX_DB_PWSHUNTSREACT_H__DBABB96C_5468_42E1_B369_31C8DC370700__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct  
{
	int nPos;//
	DWORD nu;
	visualpw_Shunt rec;
}PositionShunt;

typedef struct  
{
	int nPos;//
	DWORD nu;
	visualpw_Sreact rec;
}PositionSreact;

class DB_pwShuntSreact  
{
public:
	DB_pwShuntSreact();
	virtual ~DB_pwShuntSreact();

public:
	typedef std::vector<PositionShunt> VecShunt;
	VecShunt m_VecShunt;

	typedef std::vector<PositionSreact> VecSreact;
	VecSreact m_VecSreact;
	
	
	int BinaryFindShuntByNu(DWORD nu);
	int BinaryFindSreactByNu(DWORD nu);

	CString m_szTmp;
	int m_recn, m_erro, m_nRet;
	int m_nTableID_Shunt, m_nTableID_Sreact;
	void RefreshModel(char *pData, int bufSize);
	void RefreshRealTime(char *pData, int bufSize);
	bool InitParam();
	bool InitParam_Shunt();
	bool InitParam_Sreact();
};

#endif // !defined(AFX_DB_PWSHUNTSREACT_H__DBABB96C_5468_42E1_B369_31C8DC370700__INCLUDED_)
