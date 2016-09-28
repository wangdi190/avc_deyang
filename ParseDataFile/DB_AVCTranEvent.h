// DB_AVCTranEvent.h: interface for the DB_AVCTranEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCTRANEVENT_H__E449782A_45E5_41CF_8CC8_F1ED40144580__INCLUDED_)
#define AFX_DB_AVCTRANEVENT_H__E449782A_45E5_41CF_8CC8_F1ED40144580__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AVCTranEvent  
{
public:
	DB_AVCTranEvent();
	virtual ~DB_AVCTranEvent();
	void RefreshModel(char* pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCTRANEVENT_H__E449782A_45E5_41CF_8CC8_F1ED40144580__INCLUDED_)
