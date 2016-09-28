// DB_AvcRelay.h: interface for the DB_AvcRelay class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCRELAY_H__AC4D3E76_CA72_4BC9_B4AF_8101E13E5769__INCLUDED_)
#define AFX_DB_AVCRELAY_H__AC4D3E76_CA72_4BC9_B4AF_8101E13E5769__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AvcRelay  //保护信息定义表
{
public:
	DB_AvcRelay();
	virtual ~DB_AvcRelay();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCRELAY_H__AC4D3E76_CA72_4BC9_B4AF_8101E13E5769__INCLUDED_)
