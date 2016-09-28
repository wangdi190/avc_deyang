#ifndef	__VARCS_COMMANDCWD__H
#define __VARCS_COMMANDCWD__H

/******************************************************************
**类名：DZ_STRUCT
**描述：DZ_STRUCT描述遥控遥调控制程序发定值至TCI的电压及功率因数等参数    
         用memcpy字节拷贝至 CONTROL_COMMAND的 szCommandInfo 成员中     
******************************************************************/
struct DZ_STRUCT
{
	float fVoltagHiValue;      //电压上限值
	float fVoltagLowValue;    //电压下限值
	float fPowerCosHiValue;    //功率因数上限值 
	float fPowerCosLowValue;  //功率因数下限值
};
const int COMMANDINFOLENTH=sizeof(DZ_STRUCT);   //DZ_STRUCT结构体大小

/******************************************************************
**类名：CONTROL_COMMAND
**描述：CONTROL_COMMAND描述遥控遥调控制程序发至TCI的控制命令       
******************************************************************/
struct CONTROL_COMMAND
{
  short	shStationAdd;//变电站地址
  short shSourceNo;//数据源编号
  BYTE  byCommandType;//命令类型，见下文的成员取值
  int	shOrderNo;//控制命令对象号
  BYTE  szCommandInfo[COMMANDINFOLENTH]; //见下文的成员取值，
                  //如果是遥控的开关，遥调的升降放在第一个字节，
                   //如是定值， DZ_STRUCT 也从CommandInfo[0]字节开始存放                        

};


//****CONTROL_COMMAND的byCommandType成员取值*****************
const BYTE COMMAND_YK_SELECT = 1;//遥控选择
const BYTE COMMAND_YK_EXE = 2;//遥控执行
const BYTE COMMAND_YK_CANCEL = 3;//遥控撤消
const BYTE COMMAND_YT_SELECT = 4;//遥调选择
const BYTE COMMAND_YT_EXE = 5;//遥调执行
const BYTE COMMAND_YT_CANCEL = 6;//遥调撤消
const BYTE COMMAND_SETTING=7; //设定命令
const BYTE COMMAND_RESET=8; //复归命令 
const BYTE COMMAND_FREEZE=9; //广播命令(冻结命令)
const BYTE COMMAND_SET_TIME = 10;//设置时钟
const BYTE COMMAND_ADJUSTTIME=11; //设置时钟校正值命令
const BYTE COMMAND_CALLSUBTIME=12;//召唤子站时钟命令
const BYTE RETURN_OVERTIME=15;//超时
const BYTE RETURN_EXCEPTION=16;//未知异常

const BYTE COMMAND_DZ_SET=21;    //设定定值
const BYTE COMMAND_DZ_CANCEL=22; //定值撤消

const BYTE COMMAND_LOCK_SET=26;    //闭锁
const BYTE COMMAND_LOCK_CANCEL=27; //解除闭锁

const BYTE COMMAND_VARCSRUN_NORMAL=30;  //VARCS系统运行正常


//CONTROL_COMMAND的szCommandInfo 成员取值
//*********************************************************
const BYTE OPER_UP=11; //遥调升
const BYTE OPER_ON=12; //遥控合
const BYTE OPER_DOWN=13;//遥调降
const BYTE OPER_OFF=14;//遥控分
const BYTE OPER_EXE=15;//遥控执行，遥调执行
const BYTE OPER_CANCEL=16;//遥控取消，遥调取消
const BYTE OPER_STOP=17;//急停
//若是定值设定命令，该成员取值是一个DZ_STRUCT 结构体
//*********************************************************



/******************************************************************
**类名：COMMAND_RETURN
**描述：COMMAND_RETURN描述控制命令的返校信息，由TCI发给遥控遥调控制程序
******************************************************************/
struct COMMAND_RETURN
{
  short	shStationAdd;//变电站地址
  short shSourceNo;//数据源编号
  BYTE  byCommandType;//命令类型，见下文的成员取值
  short	shOrderNo;//控制命令对象号
  BYTE  byReturnInfo;//命令返回信息，见下文的成员取值
};

//****COMMAND_RETURN的byCommandType成员取值******************
//**与CONTROL_COMMAND的byCommandType成员取值对应
const BYTE RETURN_YK_SELECT = 1;//遥控选择返校
const BYTE RETURN_YK_EXE = 2;//遥控执行返校
const BYTE RETURN_YT_SELECT = 4;//遥调选择返校
const BYTE RETURN_YT_EXE = 5;//遥调执行返校
const BYTE RETURN_SET_TIME = 7;//设置时钟返校
const BYTE RETURN_DZ_SET=21;    //设定定值返校
//*********************************************************

//****COMMAND_RETURN的byReturnInfo成员取值*******************
const BYTE RETURN_DOWN = 1;//分/降
const BYTE RETURN_UP = 2;//合/升

const BYTE RETURN_VERIFY_ERROR = 3;//校验错误
const BYTE RETURN_COMMAND_ERROR = 4;//命令错误,命令不合理，Vqc拒绝执行

const BYTE RETURN_SUCCESS = 5;//执行成功
const BYTE RETURN_FAIL = 6;//执行失败
const BYTE RETURN_REJECT=7;  //设备拒动
const BYTE RETURN_IMBALANCE=8;//三相不平衡电压
const BYTE RETURN_LOCK=9;//闭锁或不可控
const BYTE RETURN_PROTECT=10;//保护动作
const BYTE RETURN_SLIDEPOS=11;//滑档
const BYTE RETURN_ERRORPOS=12;//错档

const BYTE RETURN_DZSET_SUCCESS = 13;//设置定值成功
const BYTE RETURN_DZSET_FAIL = 14;//设置定值失败


//*******************************************************


/********************************************************
 类名：COMMAND_SENDED
 描述：COMMAND_SENDED  用于TCI 内记录某个SOCKET已接收并发送的控制命令
///******************************************************/
 struct COMMAND_SENDED
{
  short	shStationAdd;//变电站地址
  short shSourceNo;//数据源编号
  BYTE  byCommandType;//命令类型，同上文的CONTROL_COMMAND的CommandType成员取值
  short	shOrderNo;//控制命令对象号
  CTime SendTime;//记录发送时间
};

///////////////////////

/*****************************************************
为核对遥控遥调(6月14号添加)luo
******************************************************/
struct CHECKYKYT	
{
	short	shFacNo;
	int	shOrderNo;
	//char	szFacName[32];
	char	szObjName[32];

	CHECKYKYT()
	{
		shFacNo = -1;
		shOrderNo  = -1;
		//memset(szFacName, 0, sizeof(szFacName));
		memset(szObjName, 0, sizeof(szObjName));
	}
};
#endif 