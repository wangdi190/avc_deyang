// DB_pwLine.h: interface for the DB_pwLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PWLINE_H__69BF3B8D_57DD_4570_9037_DBBCFF7465AE__INCLUDED_)
#define AFX_DB_PWLINE_H__69BF3B8D_57DD_4570_9037_DBBCFF7465AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct  
{
	int nPos;//
	DWORD nu;
	visualpw_Line rec;
}PositionLine;

typedef struct  
{
	int nPos;//
	DWORD nu;
	visualpw_Conductor rec;
}PositionConductor;

class DB_pwLine  
{
public:
	DB_pwLine();
	virtual ~DB_pwLine();

public:
	PositionLine *m_pPosLine;
	typedef std::vector<PositionLine> VecLine;
	VecLine m_VecLine;

	PositionConductor *m_pPosConductor;
	typedef std::vector<PositionConductor> VecConductor;
	VecConductor m_VecConductor;
	
	int BinaryFindLineByNu(DWORD nu);
	int BinaryFindConductoryNu(DWORD nu);

	CString m_szTmp;
	int m_recn, m_erro, m_nRet;
	int m_nTableID_Line, m_nTableID_Conductor;

	bool InitParam();
	bool InitParam_Line();
	bool InitParam_Conductor();

	void RefreshModel(char *pData, int bufSize);  //交流线段表
	void RefreshModel_Conductor(char *pData, int bufSize);
	void RefreshModel_Dot(char *pData, int bufSize);  //交流线段端点表

	void RefreshRealTime_Dot(char *pData, int bufSize);//交流线段端点表
};

#endif // !defined(AFX_DB_PWLINE_H__69BF3B8D_57DD_4570_9037_DBBCFF7465AE__INCLUDED_)
