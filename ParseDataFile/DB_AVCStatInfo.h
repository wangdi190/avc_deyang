// DB_AVCStatInfo.h: interface for the DB_AVCStatInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCSTATINFO_H__E7CD80F1_9BF4_4437_8A9D_ACEF99464FAF__INCLUDED_)
#define AFX_DB_AVCSTATINFO_H__E7CD80F1_9BF4_4437_8A9D_ACEF99464FAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AVCStatInfo  
{
public:
	DB_AVCStatInfo();
	virtual ~DB_AVCStatInfo();
	void RefreshModel(char* pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCSTATINFO_H__E7CD80F1_9BF4_4437_8A9D_ACEF99464FAF__INCLUDED_)
