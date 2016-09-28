/*******************************************************************************
ModuleName:   ODB Real Time Database management system
FileName:	  odb_define.h
DESCRIPTION:  macro define and error no
FUNCTION LIST:
COMMENT:
History:                                                        
Date          Version     Modifier                Activities
2002-09-01    1.0                              modify
================================================================================
2002-09-01    1.0                              created
*******************************************************************************/
#include "system.h"

#ifndef	__ODB_DEFINE_H__
#define	__ODB_DEFINE_H__

const   int    MAX_DB_NUMBER       = 8000;
                                             // 2002-10-17
const   int    MAX_APP_TABLE       = 256;    //for each application
const   int    MAX_CONTEXT_NUM     = 64;
const   int    MAX_APP_NUM         = 256;
const   int    MAX_TABLE_FIELD     = 512;   //512
const   short  MAX_CONTEXT_NO	   = 16384;
/*----------------------------------------------------------------------------*/

const	int	   MAX_SUBKEY_NUMBER   =  4;

const	int	   MAX_KEY_LEN         =  40;
const	int	   MAX_FILE_PATH_LEN   =  40;
const	int	   MAX_NAME_STRING_LEN =  40;
const	int	   MAX_DATAFIELD_LEN   =  16;
const	int	   MAX_PASSWD_LEN      =  8;

const	int	   ENG_NAME_LEN 	   = 32;
const	int	   CHN_NAME_LEN 	   = 64;

const	int	   MENU_NAME_LEN 	   = 40;
const	int	   MENU_DISPLAY_LEN    = 40;
const	int	   DEFAULT_VALUE_LEN   = 20;
const	int	   ARRAY_NAME_LEN 	   = 32;
const	int	   DESCRIPTION_LEN 	   = 100;
/*----------------------------------------------------------------------------*/

const   int   RECORD_HEAD_LEN      = 4;
const   int   MV_SIZE              = 1024;
const   int   INT_ADDRESS_ASSIGN   = 4;

const   int   MAX_PHY_RECORD_LEN   = 15000;

const   int   RTDB_APP_MOD         = AF_AP_MOD;   //change from 100 at 2004-07-14
const   int   ORB_TRY_TIMES        = 3 ;     //initial 20
/*----------------------------------------------------------------------------*/

const   int   RTDB_SYSTEM_SEM_KEY  = 0x20000;
const   int   RTDB_APP_SEM_KEY     = 0x20010;
//const   int   RTDB_TABLE_SEM_KEY   = 0x3200;
const   int   RTDB_TABLE_SEM_KEY   = 0x201;

const   int   MAX_SEM_NUM          = 25;
const   int   RTDB_SEM_NUM         = 12;
/*----------------------------------------------------------------------------*/
const   short ENTITY_APP           = 1;
const   short ENTITY_TABLE         = 2;
const   short ENTITY_FIELD         = 3;

const unsigned char MODE_CHN        = 0;
const unsigned char MODE_ENG        = 1;

const unsigned char MODE_NAME_BY_NO = 0;
const unsigned char MODE_NO_BY_NAME = 1;
/*----------------------------------------------------------------------------*/

//#ifndef _WINDOWS32

const   char  PATH_VIRGULE        = '/';

//#else
//
//const   char  PATH_VIRGULE        = '\';
//
//#endif

/*----------------------------------------------------------------------------*/
const   int   MODE_API             = 1;


//      CONDITION_TYPE: condition_type
/*----------------------------------------------------------------------------*/


const   short    SIMPLE_CON  	 =  0;
const   short    MULTI_CON   	 =  1;
const   short    HIS_SIMPLE_CON  =  2;
const   short    HIS_MULTI_CON   =  3;
const   short    XY_CURVE_CON    =  4;
const   short    TABLE_CON   	 =  5;
const   short	 STATISTIC_CON   =  6;

/* ---------------------------------------------------------------------------*/
/* Db data type */
typedef  unsigned char DATA_TYPES_T;         //可以考虑为enum

/* -----------------------------------------------------------
   DB_OBJECT_T:  2002-10-22
   ---------------------------------------------------------- */
enum DB_OBJECT_T
{
	OBJECT_NONE          = 0,
	OBJECT_SYSTEM        = 1,
	OBJECT_APP           = 2,
	OBJECT_TABLE         = 3
};
/* -----------------------------------------------------------
   DB_LOCK_T:  2002-10-22
   ---------------------------------------------------------- */
enum DB_LOCK_T
{
	DB_LOCK_NONE    = 0,
	DB_LOCK_READ    = 1,
	DB_LOCK_WRITE   = 2
};

/* -----------------------------------------------------------
   DB_BYTE_T:  2002-10-22
   ---------------------------------------------------------- */
#if 0
enum DB_BYTE_T
{
	BYTE_LOW_LOW    = 0,   //低 高1_8 9_16 17_24 25_32
	BYTE_LOW_HIGH   = 1,   //     8_1 16_9 24_17 32_25
	BYTE_HIGH_HIGH  = 2,   //     32_25 24_17 16_9 8_1
	BYTE_HIGH_LOW   = 3,
	BYTE_OTHER      = 4
};
#endif
enum DB_BYTE_T
{
	BYTE_LITTLE_ENDIAN   = 0,
	BYTE_BIG_ENDIAN,
	BYTE_OTHER
};

/* -----------------------------------------------------------
   DB_CONTEXT_T:  2002-10-18
   ---------------------------------------------------------- */
enum DB_CONTEXT_T
{
	CONTEXT_REAL_TIME = 0,
	CONTEXT_RESEARCH,
	CONTEXT_INSTRUCT,
	CONTEXT_HISTORY   = 3,
	CONTEXT_NONE      = 4
};

/* -----------------------------------------------------------
   DB_STATUS_T:  2002-10-16
   ---------------------------------------------------------- */
enum DB_STATUS_T
{
	TABLE_INIT    = 0,  //系统初始化,表未创建
	TABLE_NORMAL  = 1,  //已经创建
	TABLE_DELETED = 2	//创建后删除
};

/* -----------------------------------------------------------
   DB_CLASS_T: db_class
   ---------------------------------------------------------- */
enum DB_CLASS_T
{
	STDB = 0,
	VIEW = 1
};

/* -----------------------------------------------------------
   DB_TYPES_T: db_type
   ---------------------------------------------------------- */
enum DB_TYPES_T
{
	DATA  = 0,
	INDEX = 1
};
/* -----------------------------------------------------------
   DB_MEDIA_T:   db_media
   ---------------------------------------------------------- */
enum DB_MEDIA_T
{
	MEMORY = 0,
	DISK   = 1
};
/* -----------------------------------------------------------
   INDEX_TYPE_T:   index_type
   ---------------------------------------------------------- */
enum INDEX_TYPE_T
{
	KEYWORD        = 0,
	RECORD_POINTER = 1
};

/* ---------------------------------------------------------
   DATA_TYPES_T: db data type
   --------------------------------------------------------- */
#if 0
enum DATA_TYPES_T
{
	C_STRING_TYPE = 1,
	C_UCHAR_TYPE  = 2,
	C_SHORT_TYPE  = 3,
	C_INT_TYPE    = 4,
	C_LONG_TYPE   = 5,
	C_FLOAT_TYPE  = 6,
	C_DOUBLE_TYPE = 7,
	C_KEYID_TYPE  = 8,
	C_BINARY_TYPE = 9
};
#endif

const int C_STRING_TYPE   = 1;
const int C_UCHAR_TYPE    = 2;
const int C_SHORT_TYPE    = 3;
const int C_INT_TYPE      = 4;
const int C_LONG_TYPE     = 58;
const int C_DATETIME_TYPE = 5;
const int C_FLOAT_TYPE    = 6;
const int C_DOUBLE_TYPE   = 7;
const int C_KEYID_TYPE    = 8;
const int C_BINARY_TYPE   = 9;
const int C_TEXT_TYPE     = 10;
const int C_IMAGE_TYPE    = 11;
const int C_APPKEY_TYPE   = 12;
const int C_APPID_TYPE    = 13;




/* ---------------------------------------------------------
   DATA_TYPES_DISPLAY: db data type
   --------------------------------------------------------- */
enum DATA_DISPLAY_T
{
	D_CHAR_TYPE              = 1,
	D_UCHAR_TYPE             = 2,
	D_SHORT_TYPE             = 3,
	D_INT_TYPE               = 4,
	D_LONG_TYPE              = 5,
	D_FLOAT_TYPE             = 6,
	D_DOUBLE_TYPE            = 7,
	D_SINGLEMENU_TYPE        = 8,
	D_MUTIMENU_TYPE          = 9,
	D_STRING_TYPE            = 10,
	D_DATE_TYPE              = 11,
	D_TIME_TYPE              = 12,
	D_DATETIME_TYPE          = 13,
	D_MULTISTRING_TYPE       = 14,
	D_KEYID_TYPE             = 15,
	D_BINARY_TYPE            = 16,
	D_PASSWORD_TYPE          = 17,
	D_TEXT_TYPE              = 18,
	D_IMAGE_TYPE             = 19,
	D_FORMULASTRING_TYPE     = 20,
	D_FIELD_NAME_STRING_TYPE = 21
};

   
#if 0
const int D_CHAR_TYPE             	1
const int D_UCHAR_TYPE            	2
const int D_SHORT_TYPE            	3
const int D_INT_TYPE              	4
const int D_LONG_TYPE             	5
const int D_FLOAT_TYPE            	6
const int D_DOUBLE_TYPE           	7
const int D_SINGLEMENU_TYPE       	8
const int D_MUTIMENU_TYPE         	9
const int D_STRING_TYPE  	       	10
const int D_DATE_TYPE         		11
const int D_TIME_TYPE         		12
const int D_DATETIME_TYPE         	13
const int D_MULTISTRING_TYPE      	14
const int D_KEYID_TYPE            	15
const int D_BINARY_TYPE           	16
const int D_PASSWORD_TYPE         	17
const int D_TEXT_TYPE         		18
const int D_IMAGE_TYPE         		19
const int D_FORMULASTRING_TYPE    	20
const int D_FIELD_NAME_STRING_TYPE	21
#endif

const int MENU_ALL = 2;
const int MENU_OFF = 1;
const int MENU_ON  = 0;

/* -------------------------------------------------------------
   ACCESS_METHODS_T: db storage methods
   ------------------------------------------------------------- */
enum ACCESS_METHODS_T
{
	ACCESS_SEQUENT            = 0,
	ACCESS_DIRECT             = 1,
	ACCESS_HASH               = 2,
	ACCESS_DIRECT_HASH        = 3,
	ACCESS_HASH_INDEX         = 4,
	ACCESS_DIRECTINDEX_HASH   = 5,
	ACCESS_FLOW               = 6,
	ACCESS_NAMEID_HASH        = 7,
	ACCESS_DIRECTINDEX_FLOW   = 8,	
	ACCESS_FIELD_SEQUENT_HASH = 9
};

/* -------------------------------------------------------------
   PHY_ACCESS_METHODS_T: db physical storage methods
   ------------------------------------------------------------- */
enum PHY_ACCESS_METHODS_T
{
	PHY_SEQUENT_ACCESS   = 0,
	PHY_LINK_ACCESS      = 1,
	PHY_BLOCKLINK_ACCESS = 2
};

/* -------------------------------------------------------------
   sequent order
   ------------------------------------------------------------- */

#define  ASC               	0
#define  DEC               	1

/* ------------------------------------------------------------
   db open mode
   ------------------------------------------------------------ */

#define  READ_OPEN         	0
#define  WRITE_OPEN        	1
#define  RDWR_OPEN         	2

/* ------------------------------------------------------------
   db record head  status
   ------------------------------------------------------------ */

#define  RECORD_EMPTY      	0
#define  RECORD_EXIST      	1
#define  RECORD_ERASED     	3


/* ------------------------------------------------------------
   db lock type
   ------------------------------------------------------------ */

#define  RECORD_LOCK        	0x01
#define  FIELD_LOCK         	0x02

/* ------------------------------------------------------------
   db lock status
   ------------------------------------------------------------ */

#define  UNLOCK     		0
#define  LOCK        		1


/*------------------------------------------------------------------------------
   keyword type
------------------------------------------------------------------------------*/
const int  INT_KEY           =  1;
const int  STRING_KEY        =  2;
const int  INT_STRING_KEY  	 =  3;
const int  KEYID_KEY         =  4;
const int  APPKEY_KEY        =  5;
const int  APPID_KEY         =  6;



/* -------------------------------------------------------------
   ------------------------------------------------------------- */
#define	ALL_FIELD		-1
#define	ALL_RECORD		-1

/*------------------------------------------------------------------------------
   real time dbms error retcode   2002-10-14
------------------------------------------------------------------------------*/
const int  DB_OK             =  0;        /*  success                           */
const int  DB_ERROR          =  -1;       /*  error                             */
const int  DBE_PARA	     =  -2;       /*  bad para_parameter		*/

//access
const int  DBE_ACCESSMETH    = -3001;   /*  access_meth is  error             */
const int  DBE_EXIST         = -3002;   /*  Db name is exist, cannot creat    */
const int  DBE_NODB          = -3003;   /*  Db name not founded               */
const int  DBE_INVDBNO       = -3004;   /*  Db no  is wrong                   */
const int  DBE_INVFNAME      = -3005;   /*  Field name not founded            */
const int  DBE_HASOPENED     = -3006;   /*  The db has been opened	          */
const int  DBE_FILE_NOPEN    = -3007;   /*  The file cannot open              */
const int  DBE_READ_FILE     = -3008;   /*  The file cannot read              */
const int  DBE_APP_NO_DB     = -3009;   /*  This table isn't in current application */
const int  DBE_DB_NONE       = -3010;   /*  The table is deleted or hasn't been created*/

//lock
const int  DBE_LOCK          = -3111;   /*  The db is locked                  */
const int  DBE_UNLOCK        = -3112;   /*  The db isnot locked               */
const int  DBE_INVUNLOCK     = -3113; 	/*  locker is not me                  */
const int  DBE_NOINDEX       = -3114; 	/*  havenot index                     */

const int  DBE_DIFFSIZE      = -3121;   /*  size is different                 */
const int  DBE_NOTCHKEY      = -3122; 	/*          ??                        */
const int  DBE_NOCACHE       = -3123; 	/*  no cache block                    */
const int  DBE_NOTE_NEND     = -3124; 	/*  NOTE must be last field           */

const int  DBE_CTRLFULL      = -3131; 	/*  The db ctrl table is full         */
const int  DBE_DBFULL        = -3132; 	/*  The db is full                    */
const int  DBE_EODB          = -3133; 	/*  End of Database                   */
const int  DBE_INVSIZE       = -3134;  	/*  The size is invalid               */
const int  DBE_DBBEGIN       = -3135; 	/*  Have reach the begin of db        */
const int  DBE_DBEND         = -3136; 	/*  Have reach the end of db          */

const int  DBE_INVCCOMM      = -3137; 	/*  Invalid comparition command       */
const int  DBE_TMOPEN        = -3138; 	/*  Too many open                     */

////key
const int  DBE_KEYNOTFIND    = -3241; 	/*  keyword not founded               */
const int  DBE_MULTIKEY      = -3242; 	/*  Multi-keywords                    */
const int  DBE_INVKEY        = -3243; 	/*  The keyword is invalid            */
const int  DBE_MKEYFIELD     = -3244; 	/*  The keyword field can be only one */
const int  DBE_KEYFLEN       = -3245; 	/*  The keyword length must be 4 times*/
const int  DBE_DBTYPE        = -3246; 	/*  Invalid db type                   */
const int  DBE_KEYTYPE       = -3247; 	/*  Invalid keyword type              */
const int  DBE_PASSWD        = -3248; 	/*  Invalid passwd                    */

////table
const int DBE_TABLE_NO       = -3300;  /*  no match table or no*/
const int DBE_TABLE_STA		 = -3301;  /*  table status is abnormal */

////record
const int  DBE_EXISTREC      = -3451; 	/*  Record existed, cannot write      */
const int  DBE_NEXISTREC     = -3452; 	/*  Record not existed, cannot modify */
const int  DBE_SUPMAX        = -3453; 	/*  record value too bigger           */
const int  DBE_BELMIN        = -3454; 	/*  record value too smaller          */
const int  DBE_RECSIZE       = -3455; 	/*  record size wrong                 */
const int  DBE_NOTERASE      = -3456; 	/*  record not erased                 */
const int  DBE_RECERASE      = -3457; 	/*  The record is erased              */
const int  DBE_POINTER       = -3458;   /*  record_pointer error              */
const int  DBE_CONT_ERR      = -3459; 	/*  condition express error           */

////field
const int  DBE_DATATYPE      = -3561; 	/*  field data type is wrong          */
const int  DBE_DIFFTYPE      = -3562; 	/*  type is different                 */
const int  DBE_KEYFIELD      = -3563; 	/*  The field is keyword              */
const int  DBE_BIGFIELDNO    = -3564; 	/*  The field no is too big           */
const int  DBE_DLT_WRITE     = -3565; 	/*  The direct link hash cannot write */
const int  DBE_INVFIELDNO    = -3566;   /*  field_no is wrong		          */
const int  DBE_NOTFIND       = -3567; 	/*  Not find the value                */
const int  DBE_FIELD_NO      = -3568;  /*  no match field name or no          */
const int  DBE_FIELD_SIZE    = -3569;  /*  field length wrong                 */
const int  DBE_NONE_FIELD    = -3570;  /*  this table has no field            */


//operation
const int  DBE_INVCOMM       = -3601;   /*  Invalid db operater command       */
const int  DBE_NPERMIT       = -3602; 	/*  The OP is not permit              */

const int  DBE_CONTEXT       = -3620;   /*  no context or application         */
const int  DBE_APP_UNLOAD    = -3621;   /*  application isn't loaded          */


// 2002-11-01
const int DBE_SQL_COMMAND    = -3631;   /*select error*/
const int DBE_SQL_FORM       = -3632;   /*form error*/
const int DBE_SQL_WHERE      = -3633;   /*where condition error*/
const int DBE_SQL_ORDER      = -3634;   /*order by error*/



//memory
const int  DBE_MEMORY        = -3700;   /*  Cannot malloc or calloc memory    */
const int  DBE_BUFFFULL      = -3701; 	 /*  Buffer is full                    */
const int  DBE_MEM_NOALLOC   = -3702;   /*  The memory cannot allocation      */

const int  DBE_MAP           = -3710;   /*  map file error                   */

//const int  DBE_PTABFULL = -10;    	/*  process tab is full               */

//sql
const int DBE_SQL			 = -3720;   /*  sql syntax error	*/



//
const int  DBE_DBNAMENOTF    = -3800;     /*  db_name not founded                */
const int  DBE_FACNAMENOTF   = -3801;     /*  fac_name not founded	              */
const int  DBE_VALNAMENOTF   = -3802;     /*  val_name not founded	              */
const int  DBE_FIELDNAMENOTF = -3803;     /*  field_name not founded	          */

//
const int  DBE_VIEWFIELD     = -3901;     /*  view get fieldnum over error       */
const int  DBE_SYBASE	     = -3902;     /*  modify sybase error                */
const int  DBE_INDEXERR	     = -3903;     /*  index number error                 */
const int  DBE_MODIFYSIZE    = -3904;     /*  modify bufsize error               */

const int  API_INVCOMM       = -3905;  	/*  Invalid db operater command       */
const int  API_NOAPP         = -3906;  	/*  App name not founded              */
const int  API_NODB          = -3907;  	/*  Db  name not founded              */
const int  API_INVDBNO       = -3908;  	/*  Db no  is wrong                   */

const int  API_NODEOFF       = -3909;  	/*  node  is offline                  */
const int  API_ERRINIT       = -3910;  	/*  odbms init error                  */
const int  API_NEWERR	     = -3911;  	/*  new space error                   */
const int  API_DATAERR       = -3912;  	/*  data tye error                    */
const int  DBE_NOSPACE       = -3915;  	/*  no space left in disk             */



/* -----------------------------------------------------------
   for sql query:  2002-10-31
   ---------------------------------------------------------- */
enum CONDITION_OPERATOR_T
{
	SQL_COND_LSC = 10,          /*   <     */
	SQL_COND_LEC = 11,			/*   <=    */
	SQL_COND_EQC = 12,			/*   ==    */
	SQL_COND_GEC = 13,			/*   >=    */
	SQL_COND_GTC = 14,			/*   >     */
	SQL_COND_NEQ = 15           /*   !=    */
};

enum LOGICAL_OPERATOR_T
{
	SQL_LOG_AND	= 16,			/*   &&    */
	SQL_LOG_OR	= 17,           /*   ||    */
	SQL_LOG_NOT	= 18,			/*   ~     */
	SQL_LOG_NONE= 20
};


enum SQL_METHOD_T
{
	METHOD_SELECT = 1,
	METHOD_UPDATE = 2,
	METHOD_DELETE = 3,
	METHOD_CREATE = 4
};


/*----------------------------------------------------------------------------*/
//const int	PUBLIC =  32768;     //PUBLIC
//const int	SCADA  =  1; 	     //1  SCADA
//const int	PAS    =  2; 	     //2
//const int	DTS    =  4;         //4
//const int	FRONT  =  8;         //8
//const int	AGC    =  16;        //16
/*----------------------------------------------------------------------------*/
const int	PUBLIC       = 32768000;

const int   SCADA        = 1000;

const int	PAS_MODEL    = 2000;
const int	PAS_RTNET    = 2110;
const int	PAS_DPF      = 2120;
const int	PAS_LF       = 2130;
const int	PAS_NETCA    = 2140;
const int	PAS_FAULT    = 2150;
const int	PAS_BUSLF    = 2160;
const int	PAS_SENS     = 2170;
const int	PAS_OPF      = 2180;
const int	PAS_NETEQ    = 2190;
const int	PAS_SCD      = 2200;

const int	DTS          = 4000;
const int	FEP          = 8000;
const int	AGC          = 16000;
/*----------------------------------------------------------------------------*/


#define EDC         (1<<4)  //16
#define	HTED		(1<<5)  //32
#define FA	        (1<<6)  //64
#define RECALL		(1<<10) //事故反演
#define HISTORY     (1<<11) // HISTORY
#define DMS	        (1<<12) //64

#define PAS_RES     (1<<8)
#define DTS_RES     (1<<9)

#define SE              9
#define LF              10
#define CA              11
#define OF              12
#define CF              13
#define CP              14

#define SE_RES          16393
#define LF_RES          16394
#define CA_RES          16395
#define OF_RES          16396
#define CF_RES          16397
#define CP_RES          16398
/*----------------------------------------------------------------------------*/

#endif
