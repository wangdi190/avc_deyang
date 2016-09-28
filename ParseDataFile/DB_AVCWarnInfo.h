// DB_AVCWarnInfo.h: interface for the DB_AVCWarnInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCWARNINFO_H__5C1951A6_8BC4_405F_BE8C_FD1BB6D0BBA7__INCLUDED_)
#define AFX_DB_AVCWARNINFO_H__5C1951A6_8BC4_405F_BE8C_FD1BB6D0BBA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AVCWarnInfo  
{
public:
	DB_AVCWarnInfo();
	virtual ~DB_AVCWarnInfo();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCWARNINFO_H__5C1951A6_8BC4_405F_BE8C_FD1BB6D0BBA7__INCLUDED_)
