// DB_AvcRunTimePart.h: interface for the DB_AvcRunTimePart class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCRUNTIMEPART_H__36CDAF61_8B4F_4FA7_9787_DB34684E6D5D__INCLUDED_)
#define AFX_DB_AVCRUNTIMEPART_H__36CDAF61_8B4F_4FA7_9787_DB34684E6D5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AvcRunTimePart  
{
public:
	DB_AvcRunTimePart();
	virtual ~DB_AvcRunTimePart();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCRUNTIMEPART_H__36CDAF61_8B4F_4FA7_9787_DB34684E6D5D__INCLUDED_)
