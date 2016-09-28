// DB_AVCShuntEvent.h: interface for the DB_AVCShuntEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCSHUNTEVENT_H__3DB542EA_ACA2_4C28_8E3A_C93D13F66D14__INCLUDED_)
#define AFX_DB_AVCSHUNTEVENT_H__3DB542EA_ACA2_4C28_8E3A_C93D13F66D14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AVCShuntEvent  
{
public:
	DB_AVCShuntEvent();
	virtual ~DB_AVCShuntEvent();
	void RefreshModel(char* pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCSHUNTEVENT_H__3DB542EA_ACA2_4C28_8E3A_C93D13F66D14__INCLUDED_)
