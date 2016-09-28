#pragma once


#define AVCALARM_YX 0
#define AVCALARM_TRANSREFUSE 1
#define AVCALARM_TRANSSLIP 2
#define AVCALARM_CPREFUSE 3
#define AVCALARM_DISLOCATION 4
#define AVCALARM_MANUAL 5
#define AVCALARM_YCYXCLASH 6
#define AVCALARM_TOPU 7
#define AVCALARM_TRANSOVERLOAD 8
#define AVCALARM_BUSOVERVOL 9
#define AVCALARM_BUSLOWVOL 10
#define AVCALARM_CTRLOVER 11
#define AVCALARM_COLDBACK 12
#define AVCALARM_CANNOCTRL 13
#define AVCALARM_MEASURE 14
#define AVCALARM_WINDVOLFAIL 15
#define AVCALARM_TIMEPARTFAOL 16
#define AVCALARM_ONEGROUD 17
#define AVCALARM_VOLBALANCE 18
#define AVCALARM_BADDATA 19
#define AVCALARM_DEVICEFLAG 20
#define AVCALARM_SHUNTLOCK 21
#define AVCALARM_TRANSSERIES 22
const char AVCALARM_NAME[][20]={"遥信异常","分接头拒动","分接头滑档","容抗器拒动","并列主变错挡","手工操作","遥测遥信不匹配","拓扑异常","主变过载","母线过电压","母线欠电压",\
"动作次数越限","设备冷备用","无调节措施","量测不刷新","调档电压异常","时段设置错误","单相接地","三相电压不平衡","量测坏数据","设备挂牌","并联电容闭锁","主变连续同向调档",};

#define ALARMDEVICE_AVC 1
#define ALARMDEVICE_TRANS 2
#define ALARMDEVICE_SHUNT 3
#define ALARMDEVICE_GEN 4
#define ALARMDEVICE_BUS 5
#define ALARMDEVICE_STATION 6






#define RC_SHUNT 1							//并联电容	
#define RC_REACT 2							//并联电抗
#define RC_SERIESSHUNT 3					//串联电容
#define RC_SERIESREACT 4					//串联电抗
#define RC_SPLITREACT 5						//分裂电抗


#define WINDING_HIGH 0
#define WINDING_MID 1
#define WINDING_LOW 2

#define LOADTRANS_NO 0					//有载不可调压
#define LOADTRANS_YES 1					//有载可调压