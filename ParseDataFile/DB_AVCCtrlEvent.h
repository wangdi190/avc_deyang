// DB_AVCCtrlEvent.h: interface for the DB_AVCCtrlEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCCTRLEVENT_H__13552ED3_3E95_4229_A495_A44C0EC91355__INCLUDED_)
#define AFX_DB_AVCCTRLEVENT_H__13552ED3_3E95_4229_A495_A44C0EC91355__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AVCCtrlEvent  
{
public:
	DB_AVCCtrlEvent();
	virtual ~DB_AVCCtrlEvent();
	void RefreshModel(char* pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCCTRLEVENT_H__13552ED3_3E95_4229_A495_A44C0EC91355__INCLUDED_)
