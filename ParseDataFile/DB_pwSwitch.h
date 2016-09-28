// DB_pwSwitch.h: interface for the DB_pwSwitch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PWSWITCH_H__FDA2D0C6_635E_4EC2_8614_F6A36E15D881__INCLUDED_)
#define AFX_DB_PWSWITCH_H__FDA2D0C6_635E_4EC2_8614_F6A36E15D881__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct  
{
	int nPos;//
	DWORD nu;
	visualpw_Switch rec;
}PositionSwitch;

typedef struct
{
	int nPos;
	DWORD nu;
	visualpw_GND rec;
}PositionGND;

class DB_pwSwitch  
{
public:
	DB_pwSwitch();
	virtual ~DB_pwSwitch();
public:
	PositionSwitch *m_pPosSwitch;
	typedef std::vector<PositionSwitch> VecSwitch;
	VecSwitch m_VecSwitch;

	PositionGND *m_pPosGND;
	typedef std::vector<PositionGND> VecGND;
	VecGND m_VecGND;


	CString m_szTmp;
	int m_recn, m_erro, m_nRet;

	int m_nTableID_Switch, m_nTableID_GND;
	bool InitParam();
	bool InitParam_Switch();
	bool InitParam_GND();

	void RefreshModel_Brk(char *pData, int bufSize);
	void RefreshModel_Discr(char *pData, int bufSize);
	void RefreshModel_Gddiscr(char *pData, int bufSize);

	void RefreshRealTime_Brk(char *pData, int bufSize);
	void RefreshRealTime_Discr(char *pData, int bufSize);

	int BinaryFindSwitchNu(DWORD nu);
	int BinaryFindGNDNu(DWORD nu);

	//void RefreshDISCR_DEVICE_Model(char *pData, int bufSize)
};

#endif // !defined(AFX_DB_PWSWITCH_H__FDA2D0C6_635E_4EC2_8614_F6A36E15D881__INCLUDED_)
