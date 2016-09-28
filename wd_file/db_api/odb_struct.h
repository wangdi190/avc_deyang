#ifndef	__ODB_STRUCT_H__
#define	__ODB_STRUCT_H__

#include "odb_define.h"

////////////////////////////////////////////////////////
	struct KEY_ID_STRU
	{
		int   record_id;
		short column_id; 
	 
		bool operator>(const struct KEY_ID_STRU& kr) const
		{
			return ( (this->record_id > kr.record_id) ||
			         ((this->record_id == kr.record_id) && (this->column_id > kr.column_id)) );
		}
		
		bool operator<(const struct KEY_ID_STRU& kr)  const
		{
			return ( (this->record_id < kr.record_id) ||
			         ((this->record_id == kr.record_id) && (this->column_id < kr.column_id)) );
		}
	#ifndef _SUN
		bool operator==(const struct KEY_ID_STRU& kr) const
		{
			return ( (this->record_id == kr.record_id) && (this->column_id == kr.column_id) );
		}
	#else
	        bool operator==(const struct KEY_ID_STRU& kr) const
	        {
	                return ( (record_id == kr.record_id) && (column_id == kr.column_id) );
	        }
	#endif
	};

//
//Added 2003-09-01
//
/* ---------------------------------------------------------------------------*/
	struct APP_KEY_STRU
	{
		int   app_id;
		int   record_id;
		short column_id;
	
		bool operator>(const struct APP_KEY_STRU& kr) const
		{
			return ( (this->app_id > kr.app_id) ||
			         ((this->app_id == kr.app_id) && (this->record_id > kr.record_id)) ||
			         ((this->app_id == kr.app_id) && (this->record_id == kr.record_id) && (this->column_id > kr.column_id)) );
		}
		
		bool operator<(const struct APP_KEY_STRU& kr) const
		{
			return ( (this->app_id < kr.app_id) ||
			         ((this->app_id == kr.app_id) && (this->record_id < kr.record_id)) ||
			         ((this->app_id == kr.app_id) && (this->record_id == kr.record_id) && (this->column_id < kr.column_id)) );
		}
		
		bool operator==(const struct APP_KEY_STRU& kr) const
		{
			return ( (this->app_id == kr.app_id) && (this->record_id == kr.record_id) && (this->column_id == kr.column_id) );
		}
	
	};
//
//Added 2003-09-01
//
/* ---------------------------------------------------------------------------*/
	struct APP_ID_STRU
	{
		int   app_id;
		int   record_id;
	
		bool operator>(const struct APP_ID_STRU& kr)  const
		{
			return ( (this->app_id > kr.app_id) ||
			         ((this->app_id == kr.app_id) && (this->record_id > kr.record_id)) );
		}
		
		bool operator<(const struct APP_ID_STRU& kr)  const
		{
			return ( (this->app_id < kr.app_id) ||
			         ((this->app_id == kr.app_id) && (this->record_id < kr.record_id)) );
		}
		
		bool operator==(const struct APP_ID_STRU& kr)  const
		{
			return ( (this->app_id == kr.app_id) && (this->record_id == kr.record_id) );
		}
	
	};


	
	//
	//data define for record sort of real time db
	//
	union SORT_DATA_TYPE
	{
		char         to_str[CHN_NAME_LEN];
		int          to_int;
		float        to_float;
		double       to_double;
		KEY_ID_STRU  to_key;
		APP_KEY_STRU to_appkey;
		APP_ID_STRU  to_appid;
	};
	
	//lmj add 2004.0521

	struct INT_VALUE_STATUS
	{
		int  			value;
		int			status;
	
	};
	
	struct FLOAT_VALUE_STATUS
	{
		float  			value;
		int			status;
	
	};
	
	
	struct CHAR_VALUE_STATUS
	{
	//	char  			value[CHN_NAME_LEN];
		unsigned char           value;
		int			status;
	
	};
	
	struct UNION_VALUE_STATUS
	{
		SORT_DATA_TYPE  	value;
		int			status;
	};
	
	
	struct KEY_ID_STA_STRU
	{
		struct KEY_ID_STRU	key_id_stru;
		short  			status_field;	
	
	};

	

#endif
