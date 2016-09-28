// DB_AvcBus.h: interface for the DB_AvcBus class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCBUS_H__3FDE41CB_6332_400F_87B3_BD4DDF399620__INCLUDED_)
#define AFX_DB_AVCBUS_H__3FDE41CB_6332_400F_87B3_BD4DDF399620__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AvcBus  
{
public:
	DB_AvcBus();
	virtual ~DB_AvcBus();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCBUS_H__3FDE41CB_6332_400F_87B3_BD4DDF399620__INCLUDED_)
