/*******************************************************************************
ModuleName:   ODB Real Time Database management system
FileName:	  odb_tableop.h
DESCRIPTION:  class system struct define
FUNCTION LIST:
COMMENT:
History:                                                        
Date          Version     Modifier                Activities
1004-06-28    1.1                              add context_no parameter
2002-11-06    1.0                              modify
================================================================================
2002-10-30    1.0                              created
*******************************************************************************/
#ifndef	__ODB_TABLEOP_H__
#define	__ODB_TABLEOP_H__

#ifndef	__ODB_SYSTEM_H__
#include "odb_system.h"
#endif

#ifndef	__ODB_TABLE_H__
#include "odb_table.h"
#endif

#ifndef	__ODB_FIELD_H__
#include "odb_field.h"
#endif

#ifndef __ODB_WHERE_H__
#include "odb_where.h"
#endif

#ifndef	__ODB_TABLEBASE_H__
#include "odb_tablebase.h"
#endif


#ifdef _WINDOWS32
#ifdef ODB_API_LIB_EXPORTS
#define ODB_API_LIB_API __declspec(dllexport)
#else
#define ODB_API_LIB_API __declspec(dllimport)
#endif
#endif

using namespace std;

namespace  ODB
{
	typedef struct   
	{
		int type;
	} TTableOpPriv;
	
	
#ifndef _WINDOWS32
class CTableOp: public CTableBase
#else
class ODB_API_LIB_API CTableOp: public CTableBase
#endif
{
public:
	//
	//constructor & destructor // 2002-11-06
	//
	CTableOp();   //then Open()
	CTableOp(const int app_no, const int table_no, const short context_no = 0);
	CTableOp(const int app_no, const char* table_name, const short context_no = 0);
	CTableOp(const char* app_name, const int table_no, const short context_no = 0);
	CTableOp(const char* app_name, const char* table_name, const short context_no = 0);
	CTableOp(const string& app_name, const string& table_name, const short context_no = 0);
	CTableOp(const int app_no, const short context_no = 0);
	//CTableOp(const char* context_name);    //abandon context_name // 2004-06-25

	~CTableOp();
	
	int SetAppNo(const int app_no, const short context_no = 0);
//	int Open(const std::pair<const int, const int>&, const short context_no = 0);
	int Open(std::pair<int, int>, short context_no = 0);
	int Open(const int app_no, const int table_no, const short context_no = 0);
	int Open(const char* app_name, const int table_no, const short context_no = 0);          //
	int Open(const int app_no, const char* table_name, const short context_no = 0);			//  2004-06-25
	int Open(const char* app_name, const char* table_name, const short context_no = 0); //
//	int Open(const int app_no, const char* table_name, const char* context_name = NULL);		 //abandon context_name // 2004-06-25
//	int Open(const char* app_name, const char* table_name, const char* context_name = NULL); //
		
	//create & delete
	int	TableCreate(const struct STDB_CREAT_REQ* stdb_creat_req_ptr, const struct FIELD_CREAT_REQ* multi_fields_ptr, const std::vector<MEMBER_DEFINITION>& vec_offset);  //创建、删除函数	
	int	TableWrite(const char* buf_ptr, const int record_num, const int record_size);
	int	TableWrite(const char* buf_ptr, const int buf_size);		                      //write one or many records
	int	TableDelete(const int app_no, const int table_no, const char* passwd_ptr);        //delete by table no
	int	TableDelete(const int app_no, const char* table_name, const char* passwd_ptr);    //delete by table name

	int	TableClear();                                                                     //clear a table	

	//
	//query	the whole table
	//
	int	TableGet(CBuffer& buf_base);
	int	TableGet(const int field_no, CBuffer& buf_base);
	int	TableGet(const char* field_name, CBuffer& buf_base);
	int	TableGet(const std::vector<int>& vec_field_no, CBuffer& buf_base);

	//
	int	TableGet(char* buf_ptr, const int buf_size);                                     //get all record of a table
	
	int	TableGet(char** buf_ptr, int& buf_size);
	int	TableGet(const int field_no, char** field_buf_ptr, int& buf_size) ;         //get one field of all record by field no	
	int	TableGet(const char* field_name, char** field_buf_ptr, int& buf_size);    //get one or many fields of all record by field name //2002-11-20
	int	TableGet(const std::vector<int>& vec_field_no, char** field_buf_ptr, int& buf_size);//get one or many fields of all record
	
	//
	//query	by key word
	//
	int	TableGetByKey(const char* key_ptr, char* buf_ptr, const int buf_size); // get one record by key word
	
	int	TableGetByKey(const char* key_ptr, const int field_no, char* field_buf_ptr, const int buf_size); //get one field  of one record by field no & key word
	int	TableGetByKey(const char* key_ptr, const int field_no, char* field_buf_ptr, const int buf_size, int& data_type, int& data_len);

	int	TableGetByKey(const char* key_ptr, const char* field_name, char* field_buf_ptr, const int buf_size);               //get one or many fields by field name & key word
	int	TableGetByKey(const char* key_ptr, const std::vector<int>& vec_field_no, char* field_buf_ptr, const int buf_size); //get one or many fields by field no & key word
	
	int	TableGetByKey(const char* key_ptr, const int keybuf_size, const std::vector<int>& vec_field_no, char* field_buf_ptr, const int buf_size);  //many key words
	
public:
	int	TableGet(const std::vector<int>& vec_field_no, char** field_buf_ptr, int& buf_size, std::vector<MEMBER_DEFINITION>& vec_offset);
	int	TableGetByKey(const char* key_ptr, const std::vector<int>& vec_field_no, char* field_buf_ptr, const int buf_size, std::vector<MEMBER_DEFINITION>& vec_offset);
	int	TableGetByKey(const char* key_ptr, const int keybuf_size, const std::vector<int>& vec_field_no, char* field_buf_ptr, const int buf_size, std::vector<MEMBER_DEFINITION>& vec_offset);

//lmj add 2004.1125
	int	TableGetByKeyAligned(const char* key_ptr, const std::vector<int>& vec_field_no, char* field_buf_ptr, const int buf_size, std::vector<MEMBER_DEFINITION>& vec_offset);
	int	TableGetByKeyAligned(const char* key_ptr, const int keybuf_size, const std::vector<int>& vec_field_no, char* field_buf_ptr, const int buf_size, std::vector<MEMBER_DEFINITION>& vec_offset);




	//
	//the whole record //modify // 2002-11-12
	//
public:
	int	TableModify(const char* buf_ptr, const int record_num, const int record_size);  //modify one or many record
	int	TableModify(const char* buf_ptr, const int buf_size);

	//
	//many fields of all record
	//
	int	TableModify(const int field_no, const char* field_buf_ptr, const int buf_size); //modify one field of all record by field no
	int	TableModify(const char* field_name, const char* field_buf_ptr, const int buf_size);                   //modify one or many fields of all record by field name
	int	TableModify(const std::vector<int>& vec_field_no, const char* field_buf_ptr, const int buf_size);     //modify many fields of all record by field no
	
	//
	//by keyword && fields
	//
	int	TableModifyByKey(const char* key_ptr, const int field_no, const char* field_buf_ptr, const int buf_size);  //modify one field by key word and field no
	int	TableModifyByKey(const char* key_ptr, const char* field_name, const char* field_buf_ptr, const int buf_size);               //modify many fields by key word and field name
	int	TableModifyByKey(const char* key_ptr, const std::vector<int>& vec_field_no, const char* field_buf_ptr, const int buf_size); //modify many fields by field no
	
	//lmj add 2004.1125
	int	TableModifyByKeyAligned(const char* key_ptr, const std::vector<int>& vec_field_no, const char* field_buf_ptr, const int buf_size, std::vector<MEMBER_DEFINITION>& vec_offset); //modify many fields by field no
	
	//
	//by keywords && fields
	//
	int	TableModifyByKey(const char* key_ptr, const int keybuf_size, const int field_no, const char* field_buf_ptr, const int buf_size);                   //modify one field or all fields of many records by key word

	int	TableModifyByKey(const char* key_ptr, const int keybuf_size, const char* field_name, const char* field_buf_ptr, const int buf_size);               //modify many fields or all fields of many records by key word
	int	TableModifyByKey(const char* key_ptr, const int keybuf_size, const std::vector<int>& vec_field_no, const char* field_buf_ptr, const int buf_size); //the same as above
	
	//lmj add 2004.1125
	int	TableModifyByKeyAligned(const char* key_ptr, const int keybuf_size, const std::vector<int>& vec_field_no, const char* field_buf_ptr, const int buf_size, std::vector<MEMBER_DEFINITION>& vec_offset); //the same as above
	
	
	//
	//update & delete // 2002-11-12	
	//
	int	TableUpdate(const char* buf_ptr, const int buf_size); //update one or more record
	int	TableUpdate(const char* buf_ptr, const int record_num, const int record_size);
	
	char*   GetDefaultRecord();
	
	int 	TableUpdate( const int field_no, const char* buf_ptr, const int buf_size);
	int 	TableUpdate( vector<int> field_vec, const char* buf_ptr, const int buf_size); //关键字域按顺序放在最前面
	int 	TableUpdate( const char* field_name, const char* buf_ptr, const int buf_size);  //关键字域按顺序放在最前面

	
	int	DeleteRecord(const char* key_ptr);                     //delete a record by key word
	
	//
	//query by condition  //aligned
	//
	int	ConGet(const int con_field_no, const int con_field_value, char* buf_ptr, const int buf_size);                        //one record by field(int)
	int	ConGet(const int con_field_no, const int con_field_value, char** buf_ptr, int& buf_size);                            //one record by field(int)
	int	ConGet(const int con_field_no, const char* con_field_value, char** buf_ptr, int& buf_size);                          //one record by field(string)
	int	ConGet(const int get_field_no, const int con_field_no, const int con_field_value, char* buf_ptr, const int buf_size);//one field by field(int)
	int	ConGet(const int get_field_no, const int con_field_no, const char* con_field_value, char** buf_ptr, int& buf_size);  //one field by field(string)
	
	//
	//sort record by condition  //aligned
	//
	int	SortGet(const int field_no, char* bu_fptr, const int buf_size, const bool is_asc = true);                      //one field and sorted by it
	int	SortGet(const char* field_name, char* bu_fptr, const int buf_size, const bool is_asc = true);                  //many fields and sorted by them
	int	SortGet(const std::vector<int>& vec_field_no, char* buf_ptr, const int buf_size, const bool is_asc=true);      //many fields and sorted by them
	int	SortGet(char* buf_ptr, const int buf_size, const bool is_asc = true);                         //get key word & index field and sorted by index
	
	//
	//SQL interface
	//
	int SqlUpdate(const char* str_sql);
	int SqlGet(const char* str_sql, CBuffer& buf_base);
	int SqlGet(const char* str_sql, char** buf_ptr, int& buf_size);
	int SqlGet(const char* str_sql, char** buf_ptr, int& buf_size, std::vector<MEMBER_DEFINITION>& vec_offset);

public:	
	int	GetTablePara(short& field_num, int& record_num, int& record_size);
	int	GetTablePara(struct TABLE_PARA& table_para);
	int	GetTablePara(struct STDB_FIELD_TAB* field_para_ptr, const int buf_size);
	int	GetTablePara(struct TABLE_PARA& table_para, struct STDB_FIELD_TAB* field_para_ptr, const int buf_size);
	int	GetTablePara(struct TABLE_PARA& table_para, std::vector<struct STDB_FIELD_TAB>& vec_field_para);
	//int	GetTablePara(std::vector<struct FIELD_PARA>& vec_field_para);              // 2003-05-21
	int	GetTablePara(const char* str_attribute, char** field_para_ptr, int& buf_size);
	int	GetTablePara(const char* str_attribute, char** field_para_ptr, int& buf_size, std::vector<MEMBER_DEFINITION>& vec_offset);  //by net daemon

//	int	GetRecordNum();
//	int GetKeyWordLength();

	//
	//field's parameter
	//
	int GetFieldEngNameByNo(char* field_name, const int field_no);
	int GetFieldChnNameByNo(char* field_name, const int field_no);
	int GetFieldNameByNo(char* field_name, const int field_no, const bool is_eng=true);
	
	int GetFieldNoByName(int& field_no, const char* field_name, const bool is_eng=true); //only one
	int GetFieldNoByName(std::vector<int>& vec_field_no, const char* field_name);        //many fields
	
	int SetFieldNameByNo(const char* field_name, const int field_no);
	
	int GetFieldNoBySql(std::vector<int>& vec_field_no, const char* str_sql);
	//int GetRtNoByFieldNo(int& field_no, const int r_field_no);
	
	//
	//table's parameter
	//
	int GetTableNameByNo(char* table_name, const int table_no, const bool is_eng=true);
	int GetTableNoByName(int& table_no, const char* table_name, const bool is_eng=true);
	int GetTableNoByName(const char* table_name);

	//
	//application's parameter
	//
	int GetAppNameByNo(char* app_name, const int app_no);
	int GetAppNoByName(int& app_no, const char* app_name);
	int GetAppNoByName(const char* app_name);

	//int GetAllOdbNoByAppName(short& app_no, std::vector<NAME_ID>& table, const char* app_name);  // 2002-12-02
	int GetAllOdbNoByAppName(int& app_no, std::vector<int>& table, const char* app_name);  // 2002-12-02
	int GetAllAppNo(std::vector<struct NAME_ID>& vec_appno);

public:
	struct STDB_TAB* GetCurStdbTab();                     // 2003-01-18
	struct STDB_FIELD_TAB* GetCurStdbFieldTab();          // 2003-03-03
	
	const struct STDB_TAB* GetStdbTab();                     // 2003-12-18
	const struct STDB_FIELD_TAB* GetStdbFieldTab();          // 2003-12-03
	
	int GetFieldPara(struct FIELD_BASE_INFO& field_info);
	int GetFieldParaByNo(std::vector<MEMBER_DEFINITION>& vec_offset, const std::vector<int>& vec_field_no);
	int GetFieldInfo(const std::vector<int>  vec_field_no, std::vector<struct FIELD_BASE_INFO>& vec_field);
	
	//exchange byte order for buffer data
	int ExchangeData(char* buf_ptr, const int buf_size, const std::vector<int>& vec_field, const DB_BYTE_T& remote_byte);
	int ExchangeKeyData(char* buf_ptr, const int buf_size, const DB_BYTE_T& remote_byte);
	
	int GetDbID(int& db_id);
	int SetDbID(const int db_id);
	
public:
	int AddApp(const char *all_name, const short context_no );
	int AddContext( const short context_no );

private:
	//sql
	int GetFieldNames(const char* str_sql, std::vector<NAME_ID>& vec_field);  //from select clause, call GetFieldNameBySelect()	
	
	bool GetFieldNameBySelect(const char* str_field, std::vector<NAME_ID>& vec_field) const;
	bool GetFieldNameByWhere(const char* str_condition, std::vector<NAME_ID>& vec_field) const;
	bool GetFieldNameByOrder(const char* str_orderby, std::vector<SQL_SORT>& vec_field_sort) const;
	
	int  GetFieldWhere(std::vector<FIELD_STRU>& vec_field_sql, const std::vector<NAME_ID>& vec_field_where);
	int  destory_field_where( std::vector<FIELD_STRU>& vec_field_sql );
	
	//
	//sort, only used by itself
	//
	int	SortGet(std::vector<NAME_ID>& vec_select, char** buf_ptr, int& buf_size, const std::vector<bool>& vec_where, std::vector<SQL_SORT>& vec_order);
	int	SortGet(std::vector<NAME_ID>& vec_select, char** buf_ptr, int& buf_size, const std::vector<bool>& vec_where, std::vector<SQL_SORT>& vec_order, std::vector<MEMBER_DEFINITION>& vec_offset);
	
	int GetSortedKey( std::vector<RCD_TYPE>& vec_sort,
	                  const char* all_record_ptr,
	                  const std::vector<int>& vec_field_no,
	                  const struct STDB_TAB* stdb_tab_ptr,
	                  const struct STDB_FIELD_TAB* stdb_field_tab_ptr);
	                  
	bool  ParseLike(const char* str_condition, std::vector<NAME_ID>& vec_field) const;
	char* CheckLike(const char* str_condition, const char* str_like) const;

private:
	int Start();

	int MoveTo(const char* app_name, const int table_no);
	int MoveTo(const int table_no);
	int MoveTo(const char* table_name);

	//delete
	int TableDelete(struct STDB_DELETE_REQ* stdb_delete_req_ptr);	

private:
	CTableOp(const CTableOp&);
	CTableOp& operator=(const CTableOp&);
	
	TTableOpPriv  *m_pPrvStru;

protected:
	COdbSystem* m_OdbSystemPtr;
	COdbTable*  m_OdbTablePtr;
	COdbField*  m_OdbFieldPtr;

public:
	COdbSystem* GetSys();
	COdbTable* GetTable();
};
	
}

#endif
