/*******************************************************************************
ModuleName:   ODB Real Time Database management system
FileName:	  odb_where.h
DESCRIPTION:  interface to hubo
FUNCTION LIST:
COMMENT:
History:                                                        
Date          Version     Modifier                Activities
2002-11-26    1.0                              modify
================================================================================
2002-11-26    1.0                              created
*******************************************************************************/

#ifndef __ODB_WHERE_H__
#define __ODB_WHERE_H__

#include <vector>

#include "odb_struct.h"

using namespace std;

/*
#ifdef  WIN32
//为NT版动态库增加
#ifdef ODB_WHERE_EXPORTS
#define ODB_WHERE_API __declspec(dllexport)
#else
#define ODB_WHERE_API __declspec(dllimport)
#endif
#endif
*/
namespace  ODB
{
	
struct SQL_KEY_ID
{
//	int   table_no;
//	short field_no;
	int   record_id;
	short column_id;
};

struct SQL_APP_ID
{
	int   app_id;
	int   record_id;
};

struct SQL_APP_KEY
{
	int   app_id;
	int   record_id;
	short column_id;
};

union SQL_DATA_TYPE
{
	//char       to_str[40];
	char        to_char;
	char*       to_str;
	short       to_short;
	int         to_int;
	//long      to_long;
	float       to_float;
	double      to_double;
	SQL_KEY_ID  to_key;
	SQL_APP_ID  to_appid;
	SQL_APP_KEY to_appkey;
	//binary
};

/*
#ifdef  WIN32
struct ODB_WHERE_API FIELD_STRU
#else
struct FIELD_STRU
#endif
*/
struct FIELD_STRU
{
	char field_name[64];   //CHN_NAME_LEN
	int  data_type;
	std::vector<SQL_DATA_TYPE> vec_value;
//	std::vector<SQL_APP_KEY> vec_stru_value;
};


/*
#ifdef  WIN32
class ODB_WHERE_API CWhere
#else
class CWhere
#endif
*/
class CWhere
{
public:	
	CWhere(){};
	~CWhere(){};
	bool GetWhere(std::vector<bool>& vec_where, const char* where_str, const std::vector<FIELD_STRU>& vec_sql);
	void Show();
};

}
#endif
