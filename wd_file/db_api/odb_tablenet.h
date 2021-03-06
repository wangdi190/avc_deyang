/*******************************************************************************
ModuleName:   ODB Real Time Database management system
FileName:	  odb_tablenet.h
DESCRIPTION:  for class CTableNet of net access
FUNCTION LIST:
COMMENT:      for net access
History:                                                        
Date          Version     Modifier                Activities
2004-06-25    1.1         						add context_no parameter
2003-01-09    1.0                              modify
2003-12-20    1.0                              modify
================================================================================
2003-01-09    1.0                              created
*******************************************************************************/
#ifndef __ODB_TABLENET_h__
#define __ODB_TABLENET_h__

#ifdef _WINDOWS32
#ifdef ODB_NET_LIB_EXPORTS
#define ODB_NET_LIB_API __declspec(dllexport)
#else
#define ODB_NET_LIB_API __declspec(dllimport)
#endif
#endif

#ifndef	__ODB_COMMON_H__
#include "odb_common.h"
#endif

#ifndef __PROFILE_FILE_H__
#include "odb_profile.h"
#endif

#ifndef	__ODB_TABLEBASE_H__
#include "odb_tablebase.h"
#endif

#ifndef __ODB_NETFACTORY_h__
#include "odb_netfactory.h"
#endif

#ifdef _WINDOWS32

#pragma warning(disable: 4251)

#endif

#include <OB/CORBA.h>
//#include "/usr/local/corba/include/OB/CORBA.h"

#include "odb_net.h"

using namespace std;
using namespace ODB_CORBA;
using namespace ODB;

//============================================================================//

namespace NET_ODB
{
	typedef struct   
	{
		int type;
	} TTableNetPriv;
	
	
#ifdef _WINDOWS32
class ODB_NET_LIB_API CTableNet: public CTableBase
#else
class CTableNet: public CTableBase
#endif
{
public:
	CTableNet();
	CTableNet(const int app_no, const short context_no = 0);
	CTableNet(const int app_no, const int table_no, const short context_no=0);
	 
	~CTableNet();

	int 	Open(const int app_no, const int table_no, const short context_no=0);
	int 	Open(const int table_no);
	 

	int 	SetAppNo(const int app_no, const short context_no = 0);
	int 	SetHostMode(const char* host_name);
	//int SetManagedMode(const bool is_managed);
	
public:	
	int	TableGet(CBuffer& buf_base);
	int	TableGet(const int field_no, CBuffer& buf_base);
	int	TableGet(const char* field_name, CBuffer& buf_base);
	int	TableGet(const std::vector<int>& vec_field_no, CBuffer& buf_base);
	
	int SqlGet(const char* str_sql, CBuffer& buf_base);

//////
	int	TableGet(char** buf_ptr, int& buf_size);	                             //all record
	int	TableGet(const int field_no, char** field_buf_ptr, int& buf_size);   //one field of all record
	int	TableGet(const std::vector<int>& vec_field_no, char** field_buf_ptr, int& buf_size); //get many fields of all record
	int	TableGet(const char* field_name, char** field_buf_ptr, int& buf_size); //Added at 2003-11-22
	
	int	TableGetByKey(const char* key_ptr, char* buf_ptr, const int buf_size);     //one record by key word
	int	TableGetByKey(const char* key_ptr, const int field_no, char* field_buf_ptr, const int buf_size); //one field of a record
	int	TableGetByKey(const char* key_ptr, const std::vector<int>& vec_field_no, char* field_buf_ptr, const int buf_size); //get many fields of a record
	int	TableGetByKey(const char* key_ptr, const char* field_name, char* field_buf_ptr, const int buf_size);               //Added at 2003-11-22
	int	TableGetByKey(const char* key_ptr, const int keybuf_size, const std::vector<int>& vec_field_no, char* field_buf_ptr, const int buf_size);

	int	TableWrite(const char* buf_ptr, const int buf_size);		           //write one or more record
	int	DeleteRecord(const char* key_ptr);                                     //delete a record by key word
	
	//int	TableModify(const char* buf_ptr, const int buf_size); //unused 2002-11-14     //modify one or many record
	int	TableModify(const char* buf_ptr, const int record_num, const int record_size);
	int	TableModify(const int field_no, const char* field_buf_ptr, const int buf_size);  //modify one field of all record by field no
	
	int	TableModifyByKey(const char* key_ptr, const int field_no, const char* field_buf_ptr, const int buf_size);      //modify one field by key word and field no, only one record
	int	TableModifyByKey(const char* key_ptr, const int keybuf_size, const int field_no, const char* field_buf_ptr, const int buf_size); //modify one field or all fields of many records by key word
	int	TableModifyByKey(const char* key_ptr, const int keybuf_size, const std::vector<int>& vec_field_no, const char* field_buf_ptr, const int buf_size); //modify many fields or all fields of many records by key word		

	//
	//
	int	TableModify(const char* field_name, const char* field_buf_ptr, const int buf_size)  ;
	int	TableModify(const std::vector<int>& vec_field_no, const char* field_buf_ptr, const int buf_size);

	int	TableModifyByKey(const char* key_ptr, const char* field_name, const char* field_buf_ptr, const int buf_size);
	int	TableModifyByKey(const char* key_ptr, const std::vector<int>& vec_field_no, const char* field_buf_ptr, const int buf_size);
	int	TableModifyByKey(const char* key_ptr, const int keybuf_size, const char* field_name, const char* field_buf_ptr, const int buf_size);

	int	TableUpdate(const char* buf_ptr, const int buf_size); //update one or more record
	
	int	TableClear();       
	//
	//SQL interface 
	//
	//int SqlUpdate(const char* str_sql);
	int 	SqlGet(const char* str_sql, char** buf_ptr, int& buf_size);
	
public:
	int 	GetFieldInfo(std::vector<struct FIELD_BASE_INFO>& vec_filed);
	int 	GetFieldInfo(const std::vector<int>  vec_field_no, std::vector<struct FIELD_BASE_INFO>& vec_field);
	
	int	GetTablePara(short& field_num, int& record_num, int& record_size);
	int	GetTablePara(struct TABLE_PARA& table_para); 
	int	GetTablePara(struct STDB_FIELD_TAB* field_descrbptr, const int buf_size);
	int	GetTablePara(struct TABLE_PARA& table_para, struct STDB_FIELD_TAB* field_descrbptr, const int buf_size);
	int	GetTablePara(struct TABLE_PARA& table_para, struct STDB_FIELD_TAB** field_descrbptr, int& buf_size);
	int	GetTablePara(struct TABLE_PARA& table_para, std::vector<struct STDB_FIELD_TAB>& vec_field_para);
	int	GetTablePara(const char* str_attribute, char** field_para_ptr, int& buf_size);
	
	//lmj add 2004.1126
	int	GetTablePara(struct TABLE_PARA& table_para, CBuffer& buf_base);

	
	int 	GetFieldPara(struct FIELD_BASE_INFO& field_info);
	
	int 	GetFieldPara(vector<struct FIELD_BASE_INFO>& field_info_vec);
	
	int 	GetFieldNameByNo(char* field_name, const int field_no, const bool is_eng=true);
	int	GetFieldNoByName(int& field_no, const char* field_name, const bool is_eng=true);

	int 	GetTableNameByNo(char* table_name, const int table_no, const bool is_eng=true);
	int 	GetTableNoByName(int& table_no, const char* table_name, const bool is_eng=true);
	
	int 	GetAppNameByNo(char* app_name, const int app_no);
	int 	GetAppNoByName(int& app_no, const char* app_name);
	
	int 	GetTableNoByName(const char* table_name, const bool is_eng=true);
	int 	GetTableNoByName(std::vector<int>& vec_table_no , const std::vector<string>& vec_table_name, const bool is_eng=true);
	int 	GetTableNameByNo(std::string& table_name, const int table_no, const bool is_eng=true);

	int	GetAllOdbNoByAppName(int& app_no, std::vector<NAME_ID>& vec_table, const char* app_name, const bool is_eng=true);
	int	GetAllOdbNoByAppNo(char* app_name, std::vector<NAME_ID>& vec_table, const int app_no, const bool is_eng=true);
	
	int ConGet(const int con_field_no, const char* con_field_value, const int con_value_size, CBuffer& buf_base);
	int ConGet(const int get_field_no, const int con_field_no, const char* con_field_value, const int con_value_size, CBuffer& buf_base);

#ifdef MULTI_PROC
public:
	int SetPort( int port);
#endif

public:
	int	PingRtdbServer(int req_data , int & rep_data);
private:
	int	TableModify(const char* buf_ptr, const int buf_size);

private:
	int 	Start();
	int 	Refresh();

	int	ParseRsp(char** buf_ptr, int& buf_size, const CODB_NET::RSP_READ_var& read_rsp);
	int	ParseRsp(char* buf_ptr, const int buf_size, const CODB_NET::RSP_READ_var& read_rsp);
	int 	GetKeyInfo();
	
	bool 	IsApplication(const int app_no);
	
private:
	CTableNet(const CTableNet&);
	CTableNet& operator=(const CTableNet&);

private:
	CODB_NET_var      m_OdbNet;
	CNetFactory*      m_Factory;
	
	static NProfile::CProfile  *m_IniFile;
	//
	short             m_ContextNo;
	int               m_AppNo;
	int               m_TableNo;
	DB_BYTE_T         m_ByteTag;
	
	bool              m_IsSysAdmHost;	
	char              m_HostName[MAX_NAME_STRING_LEN];

	std::vector<int>  m_VecKey;
	std::vector<struct FIELD_BASE_INFO> m_VecField;
	
	TTableNetPriv	  *m_pPrvStru;
};

}

#endif
