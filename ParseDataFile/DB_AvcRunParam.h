// DB_AvcRunParam.h: interface for the DB_AvcRunParam class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCRUNPARAM_H__CE1F218D_3E8D_48B9_8A43_2ED6890E34CC__INCLUDED_)
#define AFX_DB_AVCRUNPARAM_H__CE1F218D_3E8D_48B9_8A43_2ED6890E34CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AvcRunParam		//AVC运行参数表
{
public:
	DB_AvcRunParam();
	virtual ~DB_AvcRunParam();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCRUNPARAM_H__CE1F218D_3E8D_48B9_8A43_2ED6890E34CC__INCLUDED_)
