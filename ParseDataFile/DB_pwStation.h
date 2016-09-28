// DB_pwStation.h: interface for the DB_pwStation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PWSTATION_H__116AF9E2_8764_4648_99EB_6D82B4CC8A93__INCLUDED_)
#define AFX_DB_PWSTATION_H__116AF9E2_8764_4648_99EB_6D82B4CC8A93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct  
{
	int nPos;//
	DWORD nu;
	visualpw_Station rec;
}PositionStation;

class DB_pwStation  
{
public:
	DB_pwStation();
	virtual ~DB_pwStation();
public:
	typedef std::vector<PositionStation> VecStation;
	VecStation m_VecStation;
	
	
	bool InitParam();
	int BinaryFindStationByNu(DWORD nu);

	CString m_szTmp;
	int m_recn, m_erro, m_nRet, m_nTableID;
	void RefreshModel(char *pData, int bufSize);
	visualpw_Station *GetSubStationNameByID(int nu);

	visualpw_Station pwsta;
//private:
//	CPtrArray m_fac;
};

#endif // !defined(AFX_DB_PWSTATION_H__116AF9E2_8764_4648_99EB_6D82B4CC8A93__INCLUDED_)
