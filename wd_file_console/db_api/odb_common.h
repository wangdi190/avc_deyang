/*******************************************************************************
ModuleName:   ODB Real Time Database management system
FileName:	  odb_common.h
DESCRIPTION:  common data struct define
FUNCTION LIST:
COMMENT:	  public application
History:                                                        
Date          Version     Modifier                Activities
2002-09-01    1.0                              modify
================================================================================
2002-09-01    1.0                              created
*******************************************************************************/

#ifndef	__ODB_COMMON_H__
#define	__ODB_COMMON_H__

#include "odb_public.h"
//#include "odb_struct.h"
#include "odb_prv_struct.h"

#ifdef _WINDOWS32
#ifdef ODB_API_LIB_EXPORTS
#define ODB_API_LIB_API __declspec(dllexport)
#else
#define ODB_API_LIB_API __declspec(dllimport)
#endif
#endif

using namespace std;

namespace ODB
{
#define READONLY 0
#define READWRITE 1

//系统表管理类
#ifndef _WINDOWS32
class CCommon
#else
#ifdef _ODB_SOURCE
class CCommon
#else
class ODB_API_LIB_API CCommon
#endif
#endif
{
public:
	CCommon(){};
	~CCommon(){};

	//map file // 2002-10-01
	static char* MapFile(const char* file_name, const int stab_total_size, bool ReadOnly=false);
#ifdef _WINDOWS32
	static char* MapFile(const char* file_name, const int stab_total_size, const char* uniqFlag,bool ReadOnly=false);
#endif
	static int UmapFile(char* addr_t, const int size);

	//sort // 2002-11-20
	//static void QkSort(std::vector<RCD_TYPE>& r, int base, int top);
	static void QkSort(std::vector<RCD_TYPE>& r, const int base, const int top);
	 static void StlSort(std::vector<RCD_TYPE>& r);
	
	//char
	static char* itoa(const int value);
	static int str_lwr(char* str_dst, const char* str_src);
	static int str_upr(char* str_dst, const char* str_src);
	
	static bool strip_blank1(char* ptr);	
	static int  strip_blank2(char* str_src);
	static bool StripBlank(char* str_src);
	//static void str_up(char* str);
	//static void str_lower(char* str);
	//inline static char* dwcase(char* str);
	
	//sem  2002-12-28
#ifndef _WINDOWS32
	static int InitSem(const key_t key, const int nsems=1);
	static int p(const int sem_id, const int sem_num=0);
	static int v(const int sem_id, const int sem_num=0);
	static int GetValue(const int sem_id, const int sem_num=0);

	//shm
	static char* GetShmPtr(const key_t key, const int size);
	static int   GetShmID(const key_t key, const int size);
	static char* GetShmPtrByID(const int shm_id);
#else
	static int p(const char* sem_name, const int sem_num);
	static int v(const char* sem_name, const int sem_num=1, const int release_num=1);
#endif
	
	//time
	static void  TimevalSub(struct timeval* end, struct timeval* start);
	
	static bool IsApplication(const char* app_name);
	static bool IsApplication(const int app_no);
	
	static void* Malloc(const int buf_size);
	static void Free(void* pointer);

	static int GetOdbId(const char* odb_id_sysfile);
	
	static int TransTime(int cur_time, char* time_str);

public:
	static int ExchangeData(char* buf_ptr, const int buf_size, const std::vector<MEMBER_DEFINITION>& vec_offset, const DB_BYTE_T& remote_byte);
	static int ExchangeByteOrder(char* buf_ptr, const int len);
	static DB_BYTE_T GetByteTag();

	static int GetSize(std::vector<MEMBER_DEFINITION>& vec_member);

public:
	static int PrintCtrlTab(const struct DB_CTRL_TAB* ctrl_tab_ptr);
	static int PrintStdbTab(const struct STDB_TAB* stdb_tab_ptr);
	static int PrintStabField(const struct STDB_FIELD_TAB* stdb_field_tab_ptr);
	static int PrintField(const int data_type, const char* field_data_ptr);

private:
	//static void QkPass(std::vector<RCD_TYPE>& r, int start, int tend, int& i);
	static void QkPass(std::vector<RCD_TYPE>& r, const int start, const int tend, int& i);
	
	static int CheckSize(std::vector<MEMBER_DEFINITION>& m_vecMember);
	static int MakeOffset(std::vector<MEMBER_DEFINITION>& m_vecMember);
	static int AssignOffset(int& index_pos, const int assign_val);
	
	//int RCDCmp(const void *ee1,const void *ee2); 
	
//	//nothing
//	static void do_nothing1(int nn);
//	static void do_nothing2(int nn);
};

}

#endif

