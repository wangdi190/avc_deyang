/*******************************************************************************
ModuleName:   ODB Real Time Database management system
FileName:	  odb_apinet.h
DESCRIPTION:  for class CTableNet of net access
FUNCTION LIST:
COMMENT:      for net access
History:                                                        
Date          Version     Modifier                Activities
2004-06-25    1.1         			add context_no parameter
2003-01-09    1.0                              modify
================================================================================
2003-01-09    1.0                              created
*******************************************************************************/

#ifndef __ODB_APINET_h__
#define __ODB_APINET_h__

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
#include "odb_net.h"

using namespace std;
using namespace ODB_CORBA;
using namespace ODB;

namespace NET_ODB
{
	//lmj add for GraphGetDataEx
	typedef struct 
 	{
	   long graph_id;
	   long cal_type;
	   long req_status; //-1,0��ȡ����,1(����)
	   CORBA::Request_var request;
	}  TGraphReq;
	
	typedef struct   
	{
		int type;
	} TApiNetPriv;
	
#ifdef _WINDOWS32
class ODB_NET_LIB_API CApiNet: public CTableBase
#else
class CApiNet: public CTableBase
#endif
{
public:
	CApiNet();
	CApiNet(const int app_no, const short context_no = 0 );
	CApiNet(const int app_no, const int table_no, const short context_no=0);
	//CApiNet(const char *hostname);
	~CApiNet();
	
public:
	int SetAppNo(const int app_no, const short context_no = 0);
	int SetHostMode(const char* host_name);
	
	int Open(const int table_no );
	int Open(const int app_no, const int table_no, const short context_no=0);
	//int Open(const char* hostname);

public:
	int	MenuRead(const char* menu_name, std::vector<struct MENU_INFO>& vec_menu, const int menu_status=MENU_ON);
	
	int 	TableReleMenuRead(const int table_no, std::vector<struct MENU_RELEVANT>& vec_menu);
	
	int	GetNameStringByKeyID(const struct KEY_ID_STRU& keyid_stru, string& ref_string);
	int	GetNameStringByKeyID(const std::vector<struct KEY_ID_STRU>& vec_keyid, std::vector<string>& vec_ref_string);
	
	int	GetRefMenuString(const int table_no, std::vector<struct MENU_STRING>& vec_menu);

	int 	GetNameStringByID(const int reference_id, string& ref_string);
	int 	GetNameStringByID(const std::vector<int>& vec_refid, std::vector<std::string>& vec_ref_string);
	int	GetNameStringBykey(const char* key_ptr, string& ref_string);
	
	int	GetNameStringByAppKeyID( const std::vector<struct APP_KEY_STRU>& vec_appkeyid, std::vector<string>& vec_name_string);
	int	GetNameStringByAppID( const std::vector<struct APP_ID_STRU>& vec_appid, std::vector<string>& vec_name_string);
	
	int 	GraphGetAppInfo(const struct GRAPH_ORDER_KEY_REQ& graph_req, struct GRAPH_ORDER_KEY_RSP& graph_rsp);
	int 	GraphGetData(const struct CODB_NET::GRAPH_REAL_REQ& real_req, CODB_NET::GRAPH_REAL_RSP_var& real_rsp);
	int 	GraphGetDataEx(const struct CODB_NET::GRAPH_REAL_REQ& real_req , CODB_NET::GRAPH_REAL_RSP_out real_rsp, bool is_req=true);
	int 	GraphDataSend(const struct CODB_NET::GRAPH_REAL_REQ& real_req );
	int 	GraphDataRecv(CODB_NET::GRAPH_REAL_RSP_out real_rsp );
	//int 	GraphDataRecv(const struct CODB_NET::GRAPH_REAL_REQ& real_req , CODB_NET::GRAPH_REAL_RSP_out real_rsp );
	
	//int SqlGet(const char* str_sql, char** buf_ptr, int& buf_size);

public:
	int	GetFacNameByKeyNo(const int table_no, const char* key_ptr, string& ref_string);
	int	GetFacNameByFacID(char* fac_name, const int fac_id);
	int	GetFacNameByFacNo(char* fac_name, const short fac_no);
	
	int	GetFacIDByFacName(int& fac_id, const char* fac_name);
	int	GetFacNoByFacName(short& fac_no, const char* fac_name);
	
	int	GetFacIDByFacNo(int& fac_id, const short fac_no);		
	int GetFacNoByFacID( short& fac_no, const int fac_id);
	
	int ColMeasType( const std::vector<KEY_ID_STRU> vec_keyid , std::vector<int>& vec_col_prop );
		
public:
	int GetAppNameByNo(char* app_name, const int app_no) { return 0;}
	int GetAppNoByName(int& app_no, const char* app_name) { return 0;}

	int GetTableNameByNo(char* table_name, const int table_no, const bool is_eng=true) { return 0;}
	int GetTableNoByName(int& table_no, const char* table_name, const bool is_eng=true) { return 0;}

	int GetFieldNameByNo(char* field_name, const int field_no, const bool is_eng=true) { return 0;}
	int GetFieldNoByName(int& field_no, const char* field_name, const bool is_eng=true) { return 0;}

public:
	int GetValueAndStatus(const std::vector<struct KEY_ID_STRU> &struVec , std::vector< struct INT_VALUE_STATUS >  &KeyIdValVec);  //ym

	int GetValueAndStatus(const std::vector<struct KEY_ID_STRU> &struVec , std::vector< struct FLOAT_VALUE_STATUS> & KeyIdValVec); //yc

	int GetValueAndStatus(const std::vector<struct KEY_ID_STRU> &struVec , std::vector< struct CHAR_VALUE_STATUS > & KeyIdValVec); //yx

	int GetValueAndStatus(const std::vector<struct KEY_ID_STRU> &struVec , std::vector< struct UNION_VALUE_STATUS> & KeyIdValVec  );//union type

	int GetValueAndStatus(const std::vector<struct KEY_ID_STA_STRU > &staStruVec , std::vector< struct INT_VALUE_STATUS> & KeyIdValVec);//ym
	
	int GetValueAndStatus(const std::vector<struct KEY_ID_STA_STRU > &staStruVec , std::vector< struct FLOAT_VALUE_STATUS> & KeyIdValVec);//yc
		
	int GetValueAndStatus(const std::vector<struct KEY_ID_STA_STRU> &staStruVec , std::vector< struct CHAR_VALUE_STATUS > & KeyIdValVec); //yx
	
	int GetValueAndStatus(const std::vector<struct KEY_ID_STA_STRU> &staStruVec , std::vector< struct UNION_VALUE_STATUS> & KeyIdValVec  );//union type
	
public:	
	int	PingRtdbServer(int req_data , int & rep_data);

private:
	int Start();
	int Refresh();
	int GetKeyInfo();
	
private:
	CApiNet(const CApiNet&);
	CApiNet& operator=(const CApiNet&);

private:
	CODB_NET_var      m_OdbNet;
	CNetFactory*      m_Factory;
	
	std::vector<int>  m_VecKey;
	//
	short             m_ContextNo;
	int               m_AppNo;
	int               m_TableNo;
	DB_BYTE_T         m_ByteTag;
	
	bool              m_IsSysAdmHost;	
	char              m_HostName[MAX_NAME_STRING_LEN];
	
	TGraphReq	  *m_pGraphReq;  //lmj add for GraphGetDataEx
	TApiNetPriv	  *m_pPrvStru;	//lmj add for reserver 
};

}

#endif
