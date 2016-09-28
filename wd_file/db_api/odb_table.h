/*******************************************************************************
ModuleName:   ODB Real Time Database management system
FileName:	  odb_table.h
DESCRIPTION:  class table struct define
FUNCTION LIST:
COMMENT:
History:                                                        
Date          Version     Modifier                Activities
2002-09-01    1.0                              modify
================================================================================
2002-09-01    1.0                              created
*******************************************************************************/

#ifndef	__ODB_TABLE_H__
#define	__ODB_TABLE_H__

//#include "odb_struct.h"
#include "odb_prv_struct.h"
#include "odb_public.h"
#include "odb_common.h"

using namespace std;

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
class COdbTable
#else
class ODB_API_LIB_API COdbTable
#endif
{
public:
	COdbTable();
	COdbTable(struct DB_APP_TAB* app_tab_ptr, struct DB_CTRL_TAB* ctrl_tab_ptr);
	//COdbTable(struct DB_APP_TAB* app_tab_ptr, struct DB_CTRL_TAB* ctrl_tab_ptr, char* odb_file_name);
	//COdbTable(struct DB_APP_TAB* app_tab_ptr, struct DB_CTRL_TAB* ctrl_tab_ptr, int odb_no);
	//COdbTable(struct DB_APP_TAB* app_tab_ptr, struct DB_CTRL_TAB* ctrl_tab_ptr, char* odb_name);	
	COdbTable(struct DB_APP_TAB* app_tab_ptr, int odb_no);
	COdbTable(struct DB_APP_TAB* app_tab_ptr, char* odb_name);
	
	COdbTable(char* app_ptr);
	~COdbTable();
	
	//set environment after default constructor
	int  SetAppCtrl(struct DB_APP_TAB* app_tab_ptr, struct DB_CTRL_TAB* ctrl_tab_ptr = NULL);
		
	//
	//create & delete
	//
	int  CreateTable(const struct STDB_CREAT_REQ* odb_creat_ptr, const struct FIELD_CREAT_REQ* odb_field_descrb_ptr, const std::vector<MEMBER_DEFINITION>& vec_offset);
	int  DeleteTable(struct STDB_DELETE_REQ* stdb_delete_req_ptr);
	int  ClearTable();
	
	//write record
	int	 WriteRecords(const char* buf_ptr, const int buf_size);
	
	//
	//operation by key word
	//
	int  ReadRecordByKey(const char* keyword, char** record_data_ptr, int& record_data_size);
	int  WriteRecordByKey(const char* keyword, const char* write_record_ptr, const int write_record_size);
	int  DeleteRecordByKey(const char* keyword);
	int  UpdateRecordByKey(const char* keyword, const char* update_record_ptr, const int update_record_size);
	int  ModifyRecordByKey(const char* keyword, const char* modify_record_ptr, const int modify_record_size);

	//
	//query the whole table //2002-11-07
	//
	//int	 GetAllRecords(char* buf_ptr, int& buf_size);
	int	 GetAllRecords(char* buf_ptr, const int buf_size);

	//
	//move table among application
	//
	int  MoveTo(const int r_table_no);
	int  MoveTo(const char* table_name);
	
	//
	//move record each other
	//
	void RecordFirst();
	int  RecordPre();
	int  RecordNext();
	int  RecordTo(const int no);
	int  RecordTo(const char* key_ptr);
	void RecordLast();
		
	//
	//parameter //2002-10-16
	//
	struct DB_CTRL_TAB*	    GetCtrlTabPtr();
	struct STDB_TAB*        GetStdbTabPtr();
	struct STDB_FIELD_TAB*	GetFieldTabPtr();
	char*  GetDbPtr();
	char*  GetCurRecordPtr();
	int    GetKeyWordLength();
	int    GetRecordNum();
	int    GetPara(short& field_num, int& record_num, int& record_size);
	int    GetPara(struct TABLE_PARA& table_para);

	//
	//physical file name
	//
	int   GetFileName(const char* table_name_eng);
	int   GetWholeMapFileName(char* str_file_name);
#ifdef _WINDOWS32
	int   GetUniqFlag(string & uniqFlag, int table_no);
#endif
	char* GetTableName();
	int   GetTableName(char* table_name);
	int   GetTableNo(bool is_real = false);
	
private:
	//
	//Access environment //2002-10-15
	//
	int SetDefaultEnv();
	int SetAppEnv(char* app_file_ptr);
	int SetTableEnv(const struct DB_CTRL_TAB* const init_ctrl_tab_ptr);
	int CleanEnv();

	//
	//lock 2002-10-28
	//
	bool  Lock(const DB_LOCK_T& lock_type);
	bool  UnLock(const DB_LOCK_T& lock_type);
	
	//
	//stat 2002-10-28
	//
	int	 MinusDbNumTab();
	int	 AddDbNumTab();
	int	 SetStaticsParaPtr(int tag, int op_time);
	
	//
	//Operation to Create // 2002-10-10
	//
	int fill_stdb_tab(const struct STDB_CREAT_REQ* stdb_creat_req_ptr);
	//int fill_field_tab(const struct STDB_CREAT_REQ* stdb_creat_req_ptr, const struct STDB_FIELD_DESCRIBLE* stdb_field_describle_ptr);
	int fill_field_tab(const struct FIELD_CREAT_REQ* stdb_field_describle_ptr, const int field_num, const std::vector<MEMBER_DEFINITION>& vec_offset);
	int get_keyword();
	int fill_sequent_tab(const struct STDB_CREAT_REQ* stdb_creat_req_ptr, int& stdb_describ_area_size, int& stab_total_size);
	int fill_db_ctrl_tab(const struct STDB_CREAT_REQ* stdb_creat_req_ptr,int& stdb_describ_area_size);
	
	//
	int    binary_search(const char* keyword, int& record_pointer);
	struct RECORD_HEAD_STRU* get_record_head_ptr(const int record_pointer);
	char*  get_record_ptr(const int record_pointer);
	char*  get_record_ptr(const int record_pointer, int& record_size );
	int compare_keyword(const char* keyword1_ptr, const char* keyword2_ptr,  const int keyword_len);
	
	//
	//memory data
	//
	int move_record(int targ_reccord_pointer,int sour_record_pointer, const int move_num);
	static int mem_move(char* targ_ptr, char* sour_ptr, const int count);
	int	assign_position(int* position_ptr, int  assign_val);
	
	//
	//Operation to a record
	//
	int read_record(const int record_pointer, char** record_data_ptr, int& record_data_size);                //locked by caller
	int write_record(const int record_pointer, const char* write_record_ptr, const int write_record_size);   //locked by caller
	int delete_record(const int record_pointer);  							                                 //locked
	int modify_record(const int record_pointer, const char* modify_record_ptr, const int modify_record_size);//locked
	
	//
	//Operation to Record Head //2002-10-15
	//
	int set_record_head(char* record_ptr, const int exist_tag);
	int get_record_head(char* record_ptr);
	
private:
	COdbTable(const COdbTable& odb_table);
	COdbTable& operator=(const COdbTable& odb_table);

private:
	struct DB_APP_TAB*      m_AppTabPtr;        //App info area
	struct DB_SYSTEM_TAB*	m_SysTabPtr;
	struct DB_STATICS_TAB*  m_StaticsTabPtr;
	struct DB_CTRL_TAB*     m_CtrlTabPtr;       //Ctrl info area
		
	struct DB_CTRL_TAB*     m_CurCtrlTabPtr;    //current table's Ctrl info
	struct STDB_TAB*        m_StdbTabPtr;       //
	struct SEQUENT_TAB*     m_SequentTabPtr;    //
	struct STDB_FIELD_TAB*	m_StdbFieldTabPtr;  //

	//std::map<int, char*> m_DbFilePtr;
	char* m_DbFilePtr[MAX_APP_TABLE];
	char* m_SequentAreaPtr;                     //current sequent area
	char* m_DataAreaPtr;                        //current data area
	
	int   m_CurRecordPointer;                   //current record position
	char  m_FileName[120];                      //current table's physical file name
	friend class CTableOp;
};
}

#endif
