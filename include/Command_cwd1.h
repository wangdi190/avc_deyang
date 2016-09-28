#ifndef	__VARCS_COMMANDCWD__H
#define __VARCS_COMMANDCWD__H

/******************************************************************
**类名：DZ_STRUCT
**描述：DZ_STRUCT描述遥控遥调控制程序发定值至TCI的电压及功率因数等参数    
         用memcpy字节拷贝至 CONTROL_COMMAND的 CommandInfo 成员中     
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
  short	Station_add;//变电站地址

  short source_no;//数据源编号
  unsigned char CommandType;//命令类型，见下文的成员取值
  short	order_no;//控制命令对象号
  unsigned char CommandInfo[COMMANDINFOLENTH]; //见下文的成员取值，
                  //如果是遥控的开关，遥调的升降放在第一个字节，
                   //如是定值， DZ_STRUCT 也从CommandInfo[0]字节开始存放                        

};

//****CONTROL_COMMAND的CommandType成员取值*****************
const unsigned char COMMAND_YK_SELECT = 1;//遥控选择
const unsigned char COMMAND_YK_EXE = 2;//遥控执行
const unsigned char COMMAND_YK_CANCEL = 3;//遥控撤消
const unsigned char COMMAND_YT_SELECT = 4;//遥调选择
const unsigned char COMMAND_YT_EXE = 5;//遥调执行
const unsigned char COMMAND_YT_CANCEL = 6;//遥调撤消
const unsigned char	COMMAND_SETTING=7; //设定命令
const unsigned char	COMMAND_RESET=8; //复归命令 
const unsigned char COMMAND_FREEZE=9; //广播命令(冻结命令)
const unsigned char COMMAND_SET_TIME = 10;//设置时钟
const unsigned char COMMAND_ADJUSTTIME=11; //设置时钟校正值命令
const unsigned char	COMMAND_CALLSUBTIME=12;//召唤子站时钟命令

const unsigned char COMMAND_DZ_SET=21;    //设定定值
const unsigned char COMMAND_DZ_CANCEL=22; //定值撤消

const unsigned char COMMAND_VARCSRUN_NORMAL=30;  //VARCS系统运行正常


//CONTROL_COMMAND的CommandInfo 成员取值
//*********************************************************
const unsigned char OPER_UP=11; //遥调升
const unsigned char OPER_ON=12; //遥控合
const unsigned char OPER_DOWN=13;//遥调降
const unsigned char OPER_OFF=14;//遥控分
const unsigned char OPER_EXE=15;//遥控执行，遥调执行
const unsigned char OPER_CANCEL=16;//遥控取消，遥调取消
//若是定值设定命令，该成员取值是一个DZ_STRUCT 结构体
//*********************************************************



/******************************************************************
**类名：COMMAND_RETURN
**描述：COMMAND_RETURN描述控制命令的返校信息，由TCI发给遥控遥调控制程序
******************************************************************/
struct COMMAND_RETURN
{
  short	Station_add;//变电站地址
  short source_no;//数据源编号
  unsigned char CommandType;//命令类型，见下文的成员取值
  short	order_no;//控制命令对象号
  unsigned char ReturnInfo;//命令返回信息，见下文的成员取值
};

//****COMMAND_RETURN的CommandType成员取值******************
//**与CONTROL_COMMAND的CommandType成员取值对应
const unsigned char RETURN_YK_SELECT = 1;//遥控选择返校
const unsigned char RETURN_YK_EXE = 2;//遥控执行返校
const unsigned char RETURN_YT_SELECT = 4;//遥调选择返校
const unsigned char RETURN_YT_EXE = 5;//遥调执行返校
const unsigned char RETURN_SET_TIME = 7;//设置时钟返校
const unsigned char RETURN_DZ_SET=21;    //设定定值返校
//*********************************************************

//****COMMAND_RETURN的ReturnInfo成员取值*******************
const unsigned char RETURN_DOWN = 1;//分/降
const unsigned char RETURN_UP = 2;//合/升

const unsigned char RETURN_VERIFY_ERROR = 3;//校验错误
const unsigned char RETURN_COMMAND_ERROR = 4;//命令错误

const unsigned char RETURN_SUCCESS = 5;//执行成功
const unsigned char RETURN_FAIL = 6;//执行失败
const unsigned char RETURN_REJECT=7;  //设备拒动
const unsigned char RETURN_IMBALANCE=8;//三相不平衡电压
const unsigned char RETURN_LOCK=9;//闭锁或不可控
const unsigned char RETURN_PROTECT=10;//保护动作
const unsigned char RETURN_SLIDEPOS=11;//滑档
const unsigned char RETURN_ERRORPOS=12;//错档

const unsigned char RETURN_DZSET_SUCCESS = 13;//设置定值成功
const unsigned char RETURN_DZSET_FAIL = 14;//设置定值失败


//*******************************************************


/********************************************************
 类名：COMMAND_SENDED
 描述：COMMAND_SENDED  用于TCI 内记录某个SOCKET已接收并发送的控制命令
///******************************************************/
 struct COMMAND_SENDED
{
  short	Station_add;//变电站地址
  short source_no;//数据源编号
  unsigned char CommandType;//命令类型，同上文的CONTROL_COMMAND的CommandType成员取值
  short	order_no;//控制命令对象号
  CTime SendTime;//记录发送时间
};

///////////////////////


#endif 