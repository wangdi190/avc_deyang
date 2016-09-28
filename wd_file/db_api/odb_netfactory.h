/*******************************************************************************
ModuleName:   ODB Real Time Database management system
FileName:	  odb_netfactory.h
DESCRIPTION:  for class CTableNet of net access
FUNCTION LIST:
COMMENT:      for net access
History:                                                        
Date          Version     Modifier                Activities
2003-12-12    1.0                              modify
================================================================================
2003-01-09    1.0                              created
*******************************************************************************/

#ifndef __ODB_NETFACTORY_h__
#define __ODB_NETFACTORY_h__

#ifndef	__ODB_DEFINE_H__
#include "odb_define.h"
#endif

#ifndef __ODB_ORBMGR_H__
#include "odb_orbmgr.h"
#endif

#include <map>
#include <string>

#include "system.h"
#include "sam_service.h"

#include <OB/CORBA.h>
#include "odb_net.h"



using namespace std;
using namespace ODB_CORBA;
using namespace ODB;

//============================================================================//
struct SERVICE_MESSAGE
{
    char service_name[80];
    char service_object[40];
    char service_port[40];
    int  run_port;
};

struct NET_INFO
{
//	bool           is_managed;
//	char host_name[MAX_NAME_STRING_LEN];
	CORBA::ORB_var    orb_ptr;
	CORBA::Object_var object_ptr;
	CODB_NET_var      net_ptr;
	
	NET_INFO& operator= (const NET_INFO& other)
	{
		if( this == &other )
		{
			return *this;
		}
		
		orb_ptr 	= other.orb_ptr;
		object_ptr 	= other.object_ptr;
		net_ptr		= other.net_ptr ;
		
		return *this;
	}
	
};
//============================================================================//


namespace NET_ODB
{
class CNetFactory
{
public:
	CNetFactory();
	CNetFactory(const int app_no, const short context_no = 0);
	//CNetFactory(const char* host_name);
	~CNetFactory();
	
public:
	CODB_NET_var GetInstance();
	CODB_NET_var GetInstance(const int app_no, const short context_no = 0, const bool is_managed=true);
	CODB_NET_var GetInstance(const char* host_name , const int app_no, const short context_no = 0);
	
public:
	int DefaultService();
	int SetServiceInfo(struct SERVICE_MESSAGE& server_info);
	int SetServiceName(const char* server_name);
	int SetServiceObject(const char* server_object);
	int SetServiceName(const int server_port);

	int SetManagedMode(const bool is_managed);
	
private:
	int start();
	int InitNet();
	int AddToMap();
	
	int ReadHostFromfile(char* host_name);
	int GetHostByAppNo(char* host_name, const int app_no, const short context_no );
	
	int CheckHost(const int app_no, const short context_no);
	int CheckHost(const char* host_name);
	
	int IsCreated(const int app_no, const short context_no);
	int IsCreated(const std::string& host_name);
	
	void PrnMap();
	
private:
	CNetFactory(const CNetFactory& table_net);
	CNetFactory& operator=(const CNetFactory& table_net);

private:
	//std::map<int, std::string> m_MAppHost;
	std::map<std::string, std::string> m_MAppHost;
	std::map<std::string, struct NET_INFO> m_MHostNet;
	std::map<std::string, struct NET_INFO> m_MAppNet; //lmj add
	std::map<std::string, struct NET_INFO> m_MAppCtxHostNet; //lmj add
	
	CORBA::ORB_var         m_Orb;
	CORBA::Object_var      m_Obj;
	CODB_NET_var           m_OdbNet;
	
	struct SERVICE_MESSAGE m_ServiceMsg;
	
	short				   m_ContextNo;
	int                    m_AppNo;
	char                   m_HostName[MAX_NAME_STRING_LEN];
	char				   m_AppStr[20];
	char				   m_AppCtxHostStr[40];
	
	bool                   m_IsSysAdmHost;

	COrbMgr*               m_OrbMgr;
	CServicesManage*       m_ServicesManage;
};

}

#endif
