// DB_AVCCtrlParam.h: interface for the DB_AVCCtrlParam class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCCTRLPARAM_H__94CBC502_69DB_4F30_98E0_0532CE12A720__INCLUDED_)
#define AFX_DB_AVCCTRLPARAM_H__94CBC502_69DB_4F30_98E0_0532CE12A720__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AVCCtrlParam  //AVC控制参数表
{
public:
	DB_AVCCtrlParam();
	virtual ~DB_AVCCtrlParam();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCCTRLPARAM_H__94CBC502_69DB_4F30_98E0_0532CE12A720__INCLUDED_)
