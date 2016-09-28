// DB_AvcTrans.h: interface for the DB_AvcTrans class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCTRANS_H__DD205AC1_4611_48C9_B18B_10A4F9569073__INCLUDED_)
#define AFX_DB_AVCTRANS_H__DD205AC1_4611_48C9_B18B_10A4F9569073__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AvcTrans  
{
public:
	DB_AvcTrans();
	virtual ~DB_AvcTrans();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCTRANS_H__DD205AC1_4611_48C9_B18B_10A4F9569073__INCLUDED_)
