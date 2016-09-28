// DB_pwTfmTap.h: interface for the DB_pwTfmTap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PWTFMTAP_H__71A2DC60_07A7_42D8_9FC6_DB9FD1B800D0__INCLUDED_)
#define AFX_DB_PWTFMTAP_H__71A2DC60_07A7_42D8_9FC6_DB9FD1B800D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_pwTfmTap  
{
public:
	DB_pwTfmTap();
	virtual ~DB_pwTfmTap();
	void RefreshModel(char *pData, int bufSize);
	TAP_TYPE_Model* GetTapByID(int nu);
	
private:
	CPtrArray m_tap;

};

#endif // !defined(AFX_DB_PWTFMTAP_H__71A2DC60_07A7_42D8_9FC6_DB9FD1B800D0__INCLUDED_)
