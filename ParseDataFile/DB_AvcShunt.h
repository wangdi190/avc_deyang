// DB_AvcShunt.h: interface for the DB_AvcShunt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCSHUNT_H__7EB9A840_0124_46BF_A8CC_24963954CF89__INCLUDED_)
#define AFX_DB_AVCSHUNT_H__7EB9A840_0124_46BF_A8CC_24963954CF89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AvcShunt  
{
public:
	DB_AvcShunt();
	virtual ~DB_AvcShunt();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCSHUNT_H__7EB9A840_0124_46BF_A8CC_24963954CF89__INCLUDED_)
