// DB_AVCVolEvent.h: interface for the DB_AVCVolEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCVOLEVENT_H__82265798_8DF7_4ECC_916E_14FE4BC5E4D9__INCLUDED_)
#define AFX_DB_AVCVOLEVENT_H__82265798_8DF7_4ECC_916E_14FE4BC5E4D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AVCVolEvent		//电压越限事件表
{
public:
	DB_AVCVolEvent();
	virtual ~DB_AVCVolEvent();
	void RefreshModel(char *pData, int bufSize);
};

#endif // !defined(AFX_DB_AVCVOLEVENT_H__82265798_8DF7_4ECC_916E_14FE4BC5E4D9__INCLUDED_)
