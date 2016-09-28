/*******************************************************************************
ModuleName:   ODB Real Time Database management system
FileName:	  odb_tablemgr.h
DESCRIPTION:  for application ctrl
FUNCTION LIST:
COMMENT:      for net access
History:                                                        
Date          Version     Modifier                Activities
2003-08-19    1.0                              modify
================================================================================
2003-08-18    1.0                              created
*******************************************************************************/

#ifndef __ODB_TABLEMGR_h__
#define __ODB_TABLEMGR_h__

#ifndef	__ODB_TABLEOP_H__
#include "odb_tableop.h"
#endif

#ifdef _WINDOWS32
#ifdef ODB_API_LIB_EXPORTS
#define ODB_API_LIB_API __declspec(dllexport)
#else
#define ODB_API_LIB_API __declspec(dllimport)
#endif
#endif

namespace ODB
{
#ifndef _WINDOWS32
class CTableMgr:public CTableOp
#else
class ODB_API_LIB_API CTableMgr:public CTableOp
#endif
{
public:
	CTableMgr();
	~CTableMgr();

public:
	int LoadContxt();
	int LoadContxt(const short context_no);
	int MoveTo(const short context_no);
	
	char* GetSysContxtTabPtr();
	struct DB_CONTEXT_TAB* GetCurContextTabPtr();
	
	int ShiftTo(const int app_no);
	struct DB_APP_TAB* GetCurAppTabPtr();
};

}

#endif
