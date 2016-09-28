/*******************************************************************************
ModuleName:   ODB Real Time Database management system
FileName:	  odb_prv_struct.h
DESCRIPTION:  data struct define
FUNCTION LIST:
COMMENT:
History:                                                        
Date          Version     Modifier                Activities
2002-09-01    1.0                               modify
================================================================================
2002-09-01    1.0                               created
*******************************************************************************/

#ifndef	__ODB_PRV_STRUCT_H__
#define	__ODB_PRV_STRUCT_H__

#ifndef _WINDOWS32
#include <sys/sem.h>
#endif

#include <string>
#include <map>
#include <set>
#include <vector>

#ifndef __ODB_DEFINE_H__
#include "odb_define.h"
#endif

#include "odb_struct.h"
namespace ODB
{
	/* Lock struct */
	struct LOCK_STRU
	{
		DB_OBJECT_T lock_object;
		DB_LOCK_T   lock_type;
		int         lock_num;
		int         lock_pid;
		int         sem_key;
		int         sem_no;
		int         back_no;
		int	    reserved[2];
		struct LOCK_STRU& operator= (const struct LOCK_STRU& lock2)
		{
			if( this == &lock2)
			{
				return *this;	
			}
			
			lock_object = lock2.lock_object;
			lock_type   = lock2.lock_type;
			lock_num    = lock2.lock_num;
			lock_pid    = lock2.lock_pid;
			sem_key     = lock2.sem_key;
			sem_no      = lock2.sem_no;
			back_no     = lock2.back_no;
			reserved[0] = reserved[0];
			reserved[1] = reserved[1];
			return *this;
		};
	};
	
	
	struct SYS_CONTEXT_TAB
	{
		char		   		byte_tag;  //must use type cast from  DB_BYTE_T   // 2004-07-07
		short    			context_num;    //real context个数
		short    			cur_context_no; //
	//	DB_BYTE_T   		byte_tag;
		
		struct LOCK_STRU   	lock;           //2002-10-23
	};
	
	/*PAS应用，研究态多CASE支持*/
	struct DB_CONTEXT_TAB
	{
		short 				ctx_inner_no;
		short				context_no;
		char				context_name[MAX_NAME_STRING_LEN];
		
		char 				file_app[MAX_APP_NUM][120];       //app_name + app_alias
		int				app_size[MAX_APP_NUM];            //file size  //2002-10-22
		//char* 				context_app_ptr[MAX_APP_NUM];     //此context的app结构指针(映射后的内存地址)//  2002-12-20
		
		int   				app_num;                          //real app个数
		char   				cur_app_name[MAX_NAME_STRING_LEN];//app_name + app_alias
		bool  				is_in_use;                       //whether this struct info is valid. 
		
		DB_CONTEXT_T 			context_type;                     //REAL_TIME or not
		int	    			reserved[64];
	};
	
	
	/* Database application table  */
	//
	//judge application by app_name + app_status
	//
	struct DB_APP_TAB
	{
		char				byte_tag;          //must use type cast from  DB_BYTE_T   // 2004-07-07
		int				app_no;
		int				download_app_no;	//for multi_context
		char				app_name[MAX_NAME_STRING_LEN];
		char				app_alias[MAX_NAME_STRING_LEN]; //应用别名
		short  				context_no;
		char				context_name[MAX_NAME_STRING_LEN];
		
		bool  				is_in_use;               //is current application, or not
	//	DB_BYTE_T   			byte_tag;                 //this host's byte order
		struct LOCK_STRU   		lock;
		
		short       			table_sum;                //all table allowed to be created, from odb_app.sys; cannot be changed
		short       			table_num;                //table number in fact, may be increase/decrease when add/delete
		short       			table_no[MAX_DB_NUMBER];  //table relation between rtdbms & [rdbms]
		int	    			reserved[64];
	};
	
	/* Db system table */
	struct DB_SYSTEM_TAB
	{
		int    db_max_sum;
		int    proc_open_max_sum;
		int    db_sum;
	//	int    memory_db_num;
	//	int    disk_db_num;
		int    stdb_num;
		int    view_num;
		int    index_db_num;
		int    data_db_num;
		int    max_string_length;
		int    max_keyword_length;
		int    max_subkey_num;
		int	    		reserved[64];
	//	key_t  dbms_cur_shmkey;
	//	int    ctrl_tab_shmid;
	//	int    ctrl_tab_shmsize;
	};
	
	
	/* Db statics table */
	struct DB_STATICS_TAB 
	{
		time_t op_time;
		int    op_sum;
		int    success_num;
		int    fail_num;
		int    open_num;
		int    close_num;
		int    read_num;
		int    write_num;
		int    modify_num;
		int    erase_num;
	};
	
	
	
	
	/* Database control table  */
	struct DB_CTRL_TAB
	{
		short       		table_no;	//rtdbms 
		short			r_table_no;	//对应商用库
		int			app_no;
		int          		db_id;  	//net model edition //  2002-12-03
		DB_STATUS_T  		db_status;  //TABLE_NORMAL or not
		DB_CLASS_T   		db_class;   //STDB, VIEW
		DB_TYPES_T   		db_type;    //DATA, INDEX
		
		char         		table_name_eng[ENG_NAME_LEN]; 
		char         		table_name_chn[CHN_NAME_LEN];
	
		unsigned char       	is_record_apped;
	//	short	     		fac_rel_fieldno;
	//	short	     		ulevel_rel_field_no;
	
		char         		passwd[MAX_PASSWD_LEN];
		time_t       		last_close_time;
		int          		open_count;              //被打开或访问次数
		
		char         		db_file_name[120]; //table data file
		int          		db_size;           //table all len
		//char*        		db_ptr;            //表映射后的内存地址 //根据此来判断表是否可访问, default is NULL//  2002-12-20
		
		int          		db_offset;             //?
		int          		db_describ_area_size;  //表des area大小(STDB_TAB+SEQUENT_TAB+STD_FILELD_TAB+排序区)
		int          		db_data_area_size;     //表data area大小
		int	    		reserved[64];
	};
	
	
	/* Subkey describle */
	struct SUBKEY_STRU
	{
		int    subkey_type;
		int    min_subkey;
		int    max_subkey;
		int    fieldvalue_sum;
	};
	
	/* Keyword describle table */
	struct KEYWORD_STRU
	{
		int    key_type;
		int    key_len;
		int    intkey_len;
		int    charkey_len;
		int    subkey_num;
		//int    hash_sum;     //应该不需要
		//int    hash_prime;
		//int    hash_count;
		struct SUBKEY_STRU subkey[MAX_SUBKEY_NUMBER];
	};
	
	/*
	struct LOCK_ID   //处理读锁
	{
		int       lock_id;  //与lock_num一致
		int       first_record_pointer;  //for table's record 
		int       last_record_pointer;
	};*/
	
	/* Database describe struct table */
	struct STDB_TAB
	{
		char		    byte_tag;          //must use type cast from  DB_BYTE_T // 2004-07-07
		int                 record_size;                 //record size
		int                 phy_record_size;             //physical record size with head
		int                 record_number;               //current record in fact
		int    	            record_sum;                  //record allow to created all
		short               field_sum;                   //field sum
		short	            field_no[MAX_TABLE_FIELD];   //field relation between rtdbms & [rdbms]
	
		struct KEYWORD_STRU key;
		struct LOCK_STRU   	lock;
	
		int                 index_count;
		int                 data_area_offset;
		int                 data_area_size;
		
		//
	//	int                 table_type;                  //for graph, etc
		unsigned char       is_auto_generated;
	//	unsigned char       is_system_table;             //Added 2003-09-01
	//	unsigned char       is_record_app;
	//	unsigned char       is_record_lock;
	//	unsigned char       is_record_resp;
	
	//	int                 reserved_1;
	//	int                 reserved_2;
	//	int                 reserved_3;
	//	int                 reserved_4;
	//	int                 reserved_5;
	};
	
	/* Database fields describe table */
	struct STDB_FIELD_TAB
	{
		short               field_no;  //rtdbms
		short               r_field_no;
		short               field_id;
		short               column_id;
		short               field_length;
		short               check_tag;  //
		int                 offset;     //data offset from data pointer, after RECORD_HEAD_STRU of this record
		
		int                 column_special;
		int                 ref_tableno;
		short               ref_fieldno;
			
		unsigned char       data_type;
		unsigned char       is_keyword;
		unsigned char       is_index;
		unsigned char       allow_null;
		unsigned char       sort_order_no;
		
		unsigned char       display_type;
		unsigned char       reference_flag;
		unsigned char       reference_mode;
		unsigned char       reference_display;
		
		unsigned char       is_app_syn;
		unsigned char       auto_meas_type;
	
		char                field_name_eng[ENG_NAME_LEN];
		char                field_name_chn[CHN_NAME_LEN];
			
		char                menu_name[MENU_NAME_LEN];
		char                default_asciival[DEFAULT_VALUE_LEN];
		char                min_asciival[DEFAULT_VALUE_LEN];
		char                max_asciival[DEFAULT_VALUE_LEN];
		
		int                 search_attribute;   //  检索器的域特性           //Added 2003-09-01
		int                 statics_attribute;  //  统计的域特性
		int                 reserved_1;         //  系统保留
		int                 reserved_2;         //  系统保留
		int                 reserved_3;         //  系统保留
		int                 reserved_4;         //  系统保留
		int                 reserved_5;         //  系统保留
	};
	
	
	/* sequent area ctrl tab */ //排序
	struct SEQUENT_TAB
	{
		int  seq_field_no;  //指商用库的字段号
		int  seq_field_data_type;
		int  seq_field_offset;
		int  seq_area_offset;
		int  seq_area_size;
	};
	 
	/*----------------------------------------------------------------------------*/
	
	
	
	/* record head struct */
	struct RECORD_HEAD_STRU
	{
		unsigned    char exist_tag;
		unsigned    char select_tag;
		short       next_record_pointer;
	};
	/* ----------------------------------------------------------------------- */
	
	
	
	/* ---------------------------------------------------------------------------*/
	
	struct	DATA_FILE_HEAD
	{
		int	   db_size;
		int	   record_number;
		int	   record_total_number;
		int	   record_valid_sum;
		int	   record_sum;
		int	   hash_sum;
		int	   hash_prime;
		int	   data_phy_record_sum;
		int	   data_phy_record_num;
		int    data_area_size;
	};
	
	
	/* ---------------------------------------------------------------------------*/
	/* ---------------------------------------------------------------------------*/
	struct MEMBER_DEFINITION
	{
		int data_index;   //maybe only used bu sql
		int data_type;
		int data_size;
		//int data_space;
		int data_offset;
	};
	
	
	
	/* ---------------------------------------------------------------------------*/
	//  2002-10-18, for read sys file
	struct NAME_ID
	{
		char name[CHN_NAME_LEN];     //  2003-09-15 //may affect others
		int  no;
	};
	
	#if 0
	class SetSort
	{
	public:
		bool operator()(const NAME_ID& nl, const NAME_ID& nr)
		{
			if( nl.no < nr.no )
			{
				return true;	
			}
			else if( nl.no == nr.no )
			{
				if( strcmp(nl.name, nr.name) < 0 )
				{
					return true;
				}
			}
		
		  return false;
		}
	};
	#endif
	
	struct APP_ID
	{
		char app_name[MAX_NAME_STRING_LEN];
		std::vector<NAME_ID> vec_name_no;
	};
	
	/* ---------------------------------------------------------------------------*/
	typedef std::map<int,std::string> MAPTABLE_T;
	typedef std::map<int,std::string>::value_type VALTABLE_T;
	typedef std::map<std::string,MAPTABLE_T> MAPAPP_T;
	typedef std::map<std::string,MAPTABLE_T>::value_type VALAPP_T;
	
	
	/* ---------------------------------------------------------------------------*/
	//  2002-10-31, for sql query
	/*struct SQL_EXPRESS
	{
		struct NAME_ID field;
		DATA_TYPES_T   field_type;
		char*          field_value;
		
		CONDITION_OPERATOR_T cond_op;
	
		union 
		{ 
			double cond_value;  //条件值
			string cond_str;    //条件串
		};
		
		bool value;            //条件表达式的值
	};
	
	
	struct SQL_NODE
	{
		LOGICAL_OPERATOR_T log_op; //逻辑操作
		bool value;                //逻辑表达式的值
		int express_id;            //对应叶接点下标
		struct NODE* left;
		struct NODE* right;
	};
	*/
	
	/* ---------------------------------------------------------------------------*/
	/*---sql查询返回结果 ---*/
	struct SQL_RESPONSE
	{
		int ret_code;      /* 返回的状态 (0: 成功; 其余:失败原因) */
		
		int field_num;     /* 返回的域个数 */
		struct FIELD_INFO* fldinfo;
		
		int record_num;    /* 返回的记录个数 */
		int record_length;
		int* record_no;    /* 返回的记录下标 */
		char* val_buf;	   /* 返回的值   */
	};
	
	
	struct FIELD_INFO
	{
		char		  field_name[ENG_NAME_LEN];
		int  		  field_length;
		unsigned char data_type;
	};
	
	struct SQL_SORT
	{
		struct NAME_ID field;
		bool is_asc;
	};
	
	
	/* ---------------------------------------------------------------------------*/
	//app_no-->r_table_no-->table_name_eng----table_no 实时库表号
	//typedef std::map<int, NAME_ID> MAP_NO2NAMEID;
	//typedef std::map<int, MAP_NO2NAMEID> MAP_APP2NO;   //app_no to r_table_no
	
	
	/*----------------------------------------------------------------------------*/
	
	
	struct KEY_TYPE
	{
		enum { MAX = 10 };                 //缺省field最大个数
		  
		union SORT_DATA_TYPE fld_key[MAX]; //各个子field的值
		
		short fld_type[MAX];               //各field数据类型
		int   key_num;                     //实际field个数
		
		bool operator>= (const KEY_TYPE& K)  const
		{
			int iSize = key_num;
			for(int i = 0; i < iSize; ++i)
			{
				switch(fld_type[i])
				{
					case C_INT_TYPE:
					{
						if(fld_key[i].to_int == K.fld_key[i].to_int)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_int > K.fld_key[i].to_int);
						}
					}
					case C_STRING_TYPE:
					{
						int result = strcmp(fld_key[i].to_str, K.fld_key[i].to_str);
						if(result == 0)
						{
							continue;
						}
						else if(result > 0)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					case C_FLOAT_TYPE:
					{
						if(fld_key[i].to_float == K.fld_key[i].to_float)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_float > K.fld_key[i].to_float);
						}
					}
					case C_DOUBLE_TYPE:
					{
						if(fld_key[i].to_double == K.fld_key[i].to_double)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_double > K.fld_key[i].to_double);
						}
					}
					case C_KEYID_TYPE:
					{
						if(fld_key[i].to_key == K.fld_key[i].to_key)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_key > K.fld_key[i].to_key);
						}
					}
					case C_APPKEY_TYPE:
					{
						if(fld_key[i].to_appkey == K.fld_key[i].to_appkey)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_appkey > K.fld_key[i].to_appkey);
						}
					}
					case C_APPID_TYPE:
					{
						if(fld_key[i].to_appid == K.fld_key[i].to_appid)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_appid > K.fld_key[i].to_appid);
						}
					}
					default:
					    break;
				}//end switch
			} // end for i
			
			return true;
		}	
	
		bool operator<= (const KEY_TYPE& K)  const
		{
			int iSize = key_num;
			for(int i = 0; i < iSize; ++i)
			{
				switch(fld_type[i])
				{
					case C_INT_TYPE:
					{
						if(fld_key[i].to_int == K.fld_key[i].to_int)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_int < K.fld_key[i].to_int);
						}
					}
					case C_STRING_TYPE:
					{
						int result = strcmp(fld_key[i].to_str, K.fld_key[i].to_str);
						if(result == 0)
						{
							continue;
						}
						else if(result < 0)
						{
							return true;
						}
						else
						{
							return false;
						}				
					}
					case C_FLOAT_TYPE:
					{
						if(fld_key[i].to_float == K.fld_key[i].to_float)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_float < K.fld_key[i].to_float);
						}
					}
					case C_DOUBLE_TYPE:
					{
						if(fld_key[i].to_double == K.fld_key[i].to_double)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_double < K.fld_key[i].to_double);
						}
					}
					case C_KEYID_TYPE:
					{
						if( fld_key[i].to_key == K.fld_key[i].to_key ) 
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_key < K.fld_key[i].to_key);
						}
					}
					case C_APPKEY_TYPE:
					{
						if(fld_key[i].to_appkey == K.fld_key[i].to_appkey)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_appkey < K.fld_key[i].to_appkey);
						}
					}
					case C_APPID_TYPE:
					{
						if(fld_key[i].to_appid == K.fld_key[i].to_appid)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_appid < K.fld_key[i].to_appid);
						}
					}
					default:
					    break;
				}//end switch
			} // end for i
			
			return true;
		}
		
		bool operator > (const KEY_TYPE& K) const
		{
	     		 
	                int iSize = key_num;
	               
	                for(int i = 0; i < iSize; ++i)
	                {
	                        switch(fld_type[i])
	                        {
	                                case C_INT_TYPE:
	                                {
	                                	
	                                       	if(fld_key[i].to_int == K.fld_key[i].to_int)
						{
							continue;
						}
						else
						{
	                                        	return (fld_key[i].to_int > K.fld_key[i].to_int);
	                                	}
	
	                                }
	                                case C_STRING_TYPE:
	                                {
	                                        int result = strcmp(fld_key[i].to_str, K.fld_key[i].to_str);
						
						if(result == 0)
						{
							continue;
						}
						else if(result > 0)
	                                        {
	                                                return true;
	                                        }
	                                        else
						{
	                                                return false;
	                                        }
	                                }
	                                case C_FLOAT_TYPE:
	                                {
	                                	if(fld_key[i].to_float == K.fld_key[i].to_float)
						{
							continue;
						}
						else
						{
	                                       		return (fld_key[i].to_float > K.fld_key[i].to_float);
	                                	}
	
	                                }
	                                case C_DOUBLE_TYPE:
	                                {
	                                	if(fld_key[i].to_double == K.fld_key[i].to_double)
						{
							continue;
						}
						else
						{
	                                        	return (fld_key[i].to_double > K.fld_key[i].to_double);
	                                	}
	                                }
	                                case C_KEYID_TYPE:
	                                {
	                                	if( fld_key[i].to_key == K.fld_key[i].to_key ) 
						{
							continue;
						}
						else
						{
	                                        	return (fld_key[i].to_key > K.fld_key[i].to_key);
	                                	}
	
	                                }
	 				case C_APPKEY_TYPE:
	                                {
	                                        if(fld_key[i].to_appkey == K.fld_key[i].to_appkey)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_appkey > K.fld_key[i].to_appkey);
						}
	
	                                }
	                                case C_APPID_TYPE:
	                                {
	                                        if(fld_key[i].to_appid == K.fld_key[i].to_appid)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_appid > K.fld_key[i].to_appid);
						}
	
	                                }
	                                default:
	                                    break;
	                        }//end switch
	                } // end for i
	
	                return true;
	        }
	        
		bool operator< (const KEY_TYPE& K) const
	     	{
	     		//static int sta_num = 0;
	     		 
	                int iSize = key_num;
	               
	                for(int i = 0; i < iSize; ++i)
	                {
	                        switch(fld_type[i])
	                        {
	                                case C_INT_TYPE:
	                                {
	                                	
	                                       	if(fld_key[i].to_int == K.fld_key[i].to_int)
						{
							continue;
						}
						else
						{
	                                        	return (fld_key[i].to_int < K.fld_key[i].to_int);
	                                	}
	
	                                }
	                                case C_STRING_TYPE:
	                                {
	                                        int result = strcmp(fld_key[i].to_str, K.fld_key[i].to_str);
						
						if(result == 0)
						{
							continue;
						}
						else if(result < 0)
	                                        {
	                                                return true;
	                                        }
	                                        else
						{
	                                                return false;
	                                        }
	                                }
	                                case C_FLOAT_TYPE:
	                                {
	                                	if(fld_key[i].to_float == K.fld_key[i].to_float)
						{
							continue;
						}
						else
						{
	                                       		return (fld_key[i].to_float < K.fld_key[i].to_float);
	                                	}
	
	                                }
	                                case C_DOUBLE_TYPE:
	                                {
	                                	if(fld_key[i].to_double == K.fld_key[i].to_double)
						{
							continue;
						}
						else
						{ 
	                                        	return (fld_key[i].to_double < K.fld_key[i].to_double);
	                                	}
	                                }
	                                case C_KEYID_TYPE:
	                                {
	                                	if( fld_key[i].to_key == K.fld_key[i].to_key ) 
						{
							continue;
						}
						else
						{
	                                        	return (fld_key[i].to_key < K.fld_key[i].to_key);
	                                	}
	
	                                }
	 				case C_APPKEY_TYPE:
	                                {
	                                        if(fld_key[i].to_appkey == K.fld_key[i].to_appkey)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_appkey < K.fld_key[i].to_appkey);
						}
	
	                                }
	                                case C_APPID_TYPE:
	                                {
	                                        if(fld_key[i].to_appid == K.fld_key[i].to_appid)
						{
							continue;
						}
						else
						{
							return (fld_key[i].to_appid < K.fld_key[i].to_appid);
						}
	
	                                }
	                                default:
	                                    break;
	                        }//end switch
	                } // end for i
	
	                return true;
	        }
	};
	
	struct RCD_TYPE
	{
		struct KEY_TYPE key;  //complex keyword
		int pos;              //原来位置index
		int value;            //数据
		
		struct RCD_TYPE& operator = (const struct RCD_TYPE& T)
		{
			if( this == &T)
			{
				return *this;
			}
			 
			pos   = T.pos;
			value = T.value;
			key   = T.key;
			
			return *this;
		}
		
		bool operator >  (const struct RCD_TYPE& T) const
		{
		    return key > T.key;
		}
		
		bool operator <  (const struct RCD_TYPE& T) const
		{
		    return key < T.key;
		}
	};
	
	
	/*----------------------------------------------------------------------------*/
	union semun
	{
		int     val;
		struct semid_ds* buf;
		unsigned short* array;
	};
	
	/*----------------------------------------------------------------------------*/
	union DATA_VALUE
	{
		//char       to_str[40];
		char       to_char;
		char*      to_str;
		short      to_short;
		int        to_int;
		long       to_long;
		float      to_float;
		double     to_double;
		KEY_ID_STRU to_key;
		//binary
	};
	
	/*----------------------------------------------------------------------------*/
	
	///////////////////////////////////////////////////////////////////////////////
	struct MENU_INFO
	{
		char          menu_name[MENU_NAME_LEN];      /* 菜单名*/
		unsigned char menu_no;                       /* 序号*/
		int           actual_value;                  /* 实际值*/
		char          display_value[MENU_NAME_LEN];  /* 显示值*/
		unsigned char menu_status;                   /*菜单状态 */
		char          menu_macro_name[50];
	};
	

	struct MENU_RELEVANT
	{
		int          table_id;                       /* 表ID号 */
		short        column_id;                      /* 域ID号 */
		int          column_value;                   /* 域值 */
		short        r_column_id;                    /* 对应域ID号 */
		char         r_menu_name[MENU_NAME_LEN];     /* 对应菜单名 */
		int          default_value;                  /* 默认值 */
	};
	
	struct MENU_STRING
	{
		int  order_no;
		char menu_name[MENU_NAME_LEN];
	};
	
	 
	struct ORDER_KEY_REQ
	{
		int   order_no;
		int   key_id;
	};
	
	struct GRAPH_ORDER_KEY_REQ
	{
		 
		int   app_no;
		int   graph_id;
		std::vector<struct ORDER_KEY_REQ> vec_keyid;
	};
	
	struct ORDER_KEY_RSP
	{
		int   order_no;
		bool  is_in_app;
	};
	
	struct GRAPH_ORDER_KEY_RSP
	{
		int  graph_id;
		std::vector<struct ORDER_KEY_RSP> vec_app;
	};
	///////////////////////////////////////////////////////////////////////////////
	

}
#endif
