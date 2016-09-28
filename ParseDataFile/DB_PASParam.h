// DB_PASParam.h: interface for the DB_PASParam class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_PASPARAM_H__80720AD6_D376_477F_97A8_3F026BD8BB23__INCLUDED_)
#define AFX_DB_PASPARAM_H__80720AD6_D376_477F_97A8_3F026BD8BB23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_PASParam  
{
public:
	DB_PASParam();
	virtual ~DB_PASParam();
	void RefreshModel(char *pData, int bufSize);

};

#endif // !defined(AFX_DB_PASPARAM_H__80720AD6_D376_477F_97A8_3F026BD8BB23__INCLUDED_)
