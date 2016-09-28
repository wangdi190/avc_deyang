/******************************************************************
** 文件名:opfData.h
** Copyright (c) 1998-2003*********星宇软件开发股份有限公司
** 编码 :柴若愚    日期:2003-8-27
** 修改人:         日期:
** 描述:本文件提供数据库的优化计算中间数据和结果数据的数据结构和常量定义。
** 版本:1.0
**-----------------------------------------------------------------
******************************************************************/

#ifndef	__VARCS_OPFDATA__H
#define __VARCS_OPFDATA__H

const short OPF_DEVNAME_LENGTH = 64;
const short OPF_NAME_LENGTH = 100;
const short OPF_COMMENT_LENGTH = 200;

/******************************************************************
**类名：TISLAND_TABLE
**描述：TISLAND_TABLE对应于数据库的电力岛信息表
******************************************************************/
struct TISLAND_TABLE
{
  int iIslandNo;  //电力岛号
  int iNodeNum;  //节点数
  int iGenNum;  //发电机数
  int iLoadNum;  //负荷数
  short shSeTime;  //状态估计时间
  BYTE bySeResult;  //se结果，见下文的成员取值
  short shOpfTime;  //优化计算时间
  BYTE byOpfResult;  //opf结果，见下文的成员取值
  int iMeasNum;      //估计量测点数
  int iEligibleNum;  //估计后合格点数
  char szRefGen[OPF_COMMENT_LENGTH];  //平衡发电机
};

//****TISLAND_TABLE的bySeResult成员取值********************
/*const unsigned char SE_SUCCESS = 0;//计算成功
const unsigned char SE_INVALID = 1;//电气岛无效
const unsigned char SE_INOBSERV = 2;//不可观测
const unsigned char SE_NOCONVERGE = 3;//不收敛
const unsigned char SE_ERROR = 4;//计算错误
const unsigned char SE_ELIGIBLELOW = 5;//合格率过低*/
//*********************************************************

//****TISLAND_TABLE的byOpfResult成员取值*******************
/*const unsigned char OPF_SUCCESS = 0;//计算成功
const unsigned char OPF_NOCONVERGE = 1;//不收敛
const unsigned char OPF_ERROR = 2;//计算错误*/
//*********************************************************

/******************************************************************
**类名：TMPNODE_TABLE
**描述：TMPNODE_TABLE对应于数据库的节点信息表
******************************************************************/
struct TMPNODE_TABLE
{
  int iNodeNo;  //节点号
  int iIslandNo;  //电力岛号
  short shFacNo;  //所在厂号
  short shAreaNo;  //所在区域号
  short shZoneNo;  //所在区段号
  BYTE byBusType;  //母线类型，见下文的成员取值
  BYTE byCtrlType;  //优化控制类型，见下文的成员取值
  float fBaseVol;  //基准电压
  float fYcVol;  //遥测电压值
  float fVolWeight;  //电压权值
  float fVolStep;  //电压权值步长
  BYTE byJPV;  //电压限制状态，见下文的成员取值
  BYTE byJPC;  //电压变化限制状态，见下文的成员取值
  float fSeVoltage;  //se电压值
  float fSeAngle;  //se电压相角
  short shLimitNo;  //电压限制集号
  short shVarLimNo;  //电压变化限制集号
};

//****TMPNODE_TABLE的byBusType成员取值*********************
const unsigned char TMPNODE_NORMAL = 0;//普通母线
const unsigned char TMPNODE_LOAD = 1;//负荷母线
//*********************************************************

//****TMPNODE_TABLE的byCtrlType成员取值********************
const unsigned char TMPNODE_NOOPF = 0;//非优化控制
const unsigned char TMPNODE_OPF = 1;//优化控制
//*********************************************************

//****TMPNODE_TABLE的byJPV成员取值*************************
const unsigned char TMPNODE_JPV_NOFORCE = 0;//非强制监控
const unsigned char TMPNODE_JPV_FORCE = 1;//强制监控
//*********************************************************

//****TMPNODE_TABLE的byJPC成员取值*************************
const unsigned char TMPNODE_JPC_NOFORCE = 0;//非强制监控
const unsigned char TMPNODE_JPC_FORCE = 1;//强制监控
//*********************************************************

/******************************************************************
**类名：TMPTRANS_TABLE
**描述：TMPTRANS_TABLE对应于数据库的计算变压器表
******************************************************************/
struct TMPTRANS_TABLE
{
  short shFacNo;  //厂号
  short shMasterNo;  //主变压器号
  int iTransNo;  //变压器号
  BYTE byVolSide;  //电压侧，见下文的成员取值
  float fCapacity;  //额定容量
  BYTE byReguType;  //调压方式，见下文的成员取值
  BYTE byStatus;  //工作状态，见下文的成员取值
  BYTE byLock;  //闭锁状态，见下文的成员取值
  BYTE byCtrlType;  //优化控制类型，见下文的成员取值
  float fResistance;  //电阻值
  float fReactance;  //电抗值
  float fConductance;  //电导值
  float fSusceptance;  //电纳值
  float fMinRatio;  //最小变比
  float fMaxRatio;  //最大变比
  float fCurrentRatio;  //当前变比
  float fStepSize;  //档位步长
  float fYcFromP;  //首端有功量测
  float fFromPWeight;  //首端有功权值
  float fFromPStep;  //首端有功权值步长
  float fYcFromQ;  //首端无功量测
  float fFromQWeight;  //首端无功权值
  float fFromQStep;  //首端无功权值步长
  float fYcFromI;  //首端电流量测
  float fFromIWeight;  //首端电流权值
  float fFromIStep;  //首端电流权值步长
  float fYcToP;  //末端有功量测
  float fToPWeight;  //末端有功权值
  float fToPStep;  //末端有功权值步长
  float fYcToQ;	  //末端无功量测
  float fToQWeight;  //末端无功权值
  float fToQStep;  //末端无功权值步长
  float fYcToI;  //末端电流量测
  float fToIWeight;  //末端电流权值
  float fToIStep;  //末端电流权值步长
  int iFromNode;  //首端节点号
  int iToPoint;  //末端节点号
  float fSeFromP;  //首端有功
  float fSeFromQ;  //首端无功
  float fSeFromI;  //首端电流
  float fSeToP;  //末端有功
  float fSeToQ;  //末端无功
  float fSeToI;  //末端电流
  int iIslandNo;  //电力岛号
};

//****TMPTRANS_TABLE的byVolSide成员取值********************
const unsigned char TMPTRANS_SIDE_HI = 0;//高压侧
const unsigned char TMPTRANS_SIDE_MID = 2;//中压侧
const unsigned char TMPTRANS_SIDE_LOW = 1;//低压侧
//*********************************************************

//****TMPTRANS_TABLE的byReguType成员取值*******************
const unsigned char TMPTRANS_NO_REGU = 0;//不可调压
const unsigned char TMPTRANS_REGU = 1;//可以调压
//*********************************************************

//****TMPTRANS_TABLE的byStatus成员取值*********************
const unsigned char TMPDEVICE_QUIT = 0;//退出
const unsigned char TMPDEVICE_RUN = 1;//投入
//*********************************************************

//****TMPTRANS_TABLE的byLock成员取值***********************
const unsigned char TMPDEVICE_OPERATE_NORMAL = 0;//正常
const unsigned char TMPDEVICE_OPERATE_LOCK = 1;//闭锁
//*********************************************************

//****TMPTRANS_TABLE的byCtrlType成员取值*******************
const unsigned char TMPDEVICE_NO_OPF = 0;//非优化控制
const unsigned char TMPDEVICE_OPF = 1;//优化控制
//*********************************************************

/******************************************************************
**类名：TMPSHUNT_TABLE
**描述：TMPSHUNT_TABLE对应于数据库的计算无功设备表
******************************************************************/
struct TMPSHUNT_TABLE
{
  short shFacNo;  //厂号
  int iShuntNo;  //编号
  float fRateVol;  //额定电压
  float fCapacity;  //额定容量
  BYTE byStatus;  //工作状态，同计算变压器表的工作状态取值
  BYTE byLock;  //闭锁状态，同计算变压器表的闭锁状态取值
  BYTE byCtrlType;  //优化控制类型，同计算变压器表的优化控制类型取值
  float fYcP;  //有功量测
  float fPWeight;  //有功量测权值
  float fPStep;  //有功量测权值步长
  float fYcQ; //无功量测
  float fQWeight;  //无功量测权值
  float fQStep;  //无功量测权值步长
  float fYcI;  //电流量测
  float fIWeight;  //电流量测权值
  float fIStep;  //电流量测权值步长
  int iFromNode;  //首端节点号
  int iToPoint;  //末端节点号
  float fSeQ;  //无功估计值
  int iIslandNo;  //电力岛号
};

/******************************************************************
**类名：TMPGEN_TABLE
**描述：TMPGEN_TABLE对应于数据库的计算发电机表
******************************************************************/
struct TMPGEN_TABLE
{
  short shFacNo;  //厂号
  int iGenNo;  //发电机号
  float fRatedS;  //额定功率
  float fRatedP;  //额定出力
  float fRatedVol;  //额定电压
  BYTE byStatus;  //工作状态，同计算变压器表的工作状态取值
  float fYcP;  //有功遥测
  float fPWeight;  //有功遥测权值
  float fPStep;  //有功遥测权值步长
  float fYcQ;  //无功遥测
  float fQWeight;  //无功遥测权值
  float fQStep;  //无功遥测权值步长
  float fMaxP;  //最大有功
  float fMinP;  //最小有功
  float fMaxQ;  //最大无功
  float fMinQ;  //最小无功
  float fMaxI;  //上限电流
  BYTE byRunMode;  //运行模式，见下文的成员取值
  float fVolUpper;  //电压上限
  float fVolLower;  //电压下限
  int iNodeNo;  //节点号
  float fSeP;  //有功估计值
  float fSeQ;  //无功估计值
  int iIslandNo;  //电力岛号
};

//****TMPGEN_TABLE的byRunMode成员取值**********************
const unsigned char TMPGEN_PNOR_CTRLV = 0;//P正常，控制电压
const unsigned char TMPGEN_FIXPQ = 1;//固定P、Q输出
const unsigned char TMPGEN_FIXP_CTRLV = 2;//固定P输出，控制电压
const unsigned char TMPGEN_PNOR_FIXQ = 3;//P正常,固定Q输出
//*********************************************************

/******************************************************************
**类名：TMPLOAD_TABLE
**描述：TMPLOAD_TABLE对应于数据库的计算负荷表
******************************************************************/
struct TMPLOAD_TABLE
{
  short shFacNo;  //厂号
  int iLoadNo;  //编号
  BYTE byStatus;  //工作状态，同计算变压器表的工作状态取值
  float fYcP;  //有功遥测
  float fPWeight;  //有功遥测权值
  float fPStep;  //有功遥测权值步长
  float fYcQ;  //无功遥测
  float fQWeight;  //无功遥测权值
  float fQStep;  //无功遥测权值步长
  float fMaxP;  //最大有功
  float fMinP;  //最小有功
  float fMaxQ;  //最大无功
  float fMinQ;  //最小无功
  int iNodeNo;  //节点号
  float fSeP;  //有功估计值
  float fSeQ;  //无功估计值
  int iIslandNo;  //电力岛号
};

/******************************************************************
**类名：TMPLINE_TABLE
**描述：TMPLINE_TABLE对应于数据库的计算线路表
******************************************************************/
struct TMPLINE_TABLE
{
  int iLineNo;  //线路号
  short shFromFac;  //首端厂号
  short shToFac;  //末端厂号
  float fResistance;  //电阻值
  float fReactance;  //电抗值
  float fConductance;  //电导值
  float fSusceptance;  //电纳值
  float fFromCapacity;  //线路首端容量
  float fToCapacity;  //线路末端容量
  float fMaxI;  //电流限值
  float fYcFromP;  //首端有功量测
  float fFromPWeight;  //首端有功权值
  float fFromPStep;  //首端有功权值步长
  float fYcFromQ;  //首端无功量测
  float fFromQWeight;  //首端无功权值
  float fFromQStep;  //首端无功权值步长
  float fYcFromI;  //首端电流量测
  float fFromIWeight;  //首端电流权值
  float fFromIStep;  //首端电流权值步长
  float fYcToP;  //末端有功量测
  float fToPWeight;  //末端有功权值
  float fToPStep;  //末端有功权值步长
  float fYcToQ;  //末端无功量测
  float fToQWeight;  //末端无功权值
  float fToQStep;  //末端无功权值步长
  float fYcToI;  //末端电流量测
  float fToIWeight;  //末端电流权值
  float fToIStep;  //末端电流权值步长
  int iFromNode;  //首端节点号
  int iToNode;  //末端节点号
  float fSeFromP;  //首端有功估计
  float fSeFromQ;  //首端无功估计
  float fSeFromI;  //首端电流估计
  float fSeToP;  //末端有功估计
  float fSeToQ;  //末端无功估计
  float fSeToI;	  //末端电流估计
  int iIslandNo;  //电力岛号
};

/******************************************************************
**类名：TMPBUS_TABLE
**描述：TMPBUS_TABLE对应于数据库的计算母线表
******************************************************************/
struct TMPBUS_TABLE
{
  short shFacNo;  //厂号
  short shBusNo;  //母线号
  int iNodeNo;  //节点号
  BYTE byBusType;  //母线类型，同节点信息表母线类型的取值
  BYTE byCtrlType;  //优化控制类型，同节点信息表优化控制类型的取值
  float fBaseVol;  //基准电压
  float fYcVol;  //遥测电压值
  float fVolWeight;  //电压权值
  float fVolStep;  //电压权值步长
  BYTE byJPV;  //电压限制状态，同节点信息表电压限制状态的取值
  BYTE byJPC;  //电压变化限制状态，同节点信息表电压变化限制状态的取值
  short shLimitNo;  //电压限制集号
  short shVarLimNo;  //电压变化限制集号
};

/******************************************************************
**类名：OPFRES_TABLE
**描述：OPFRES_TABLE对应于数据库的优化计算控制信息表
******************************************************************/
struct OPFRES_TABLE
{
  short shAutoId;  //编号
  CTime tStartTime;  //启动时间
  CTime tEndTime;  //结束时间
  BYTE byResult;  //计算控制结果，见下文的成员取值
  float fSeEligible; //遥测估计合格率
  //short shTopoTime;  //拓扑分析时间
  //short shSeTime;  //状态估计时间
  //short shOpfTime;  //优化计算时间
  short shOperateTime;  //控制执行时间
  float fPrePLoss;  //优化前有功网损
  float fPostPLoss;  //优化后有功网损
  float fPreQLoss;  //优化前无功网损
  float fPostQLoss;  //优化后无功网损
  short shCmdNum;  //控制命令数量
  short shCmdSucNum;  //控制命令成功数量
  char szStartReason[OPF_NAME_LENGTH];  //启动原因
  char szComment[OPF_COMMENT_LENGTH];  //说明
};

//****OPFRES_TABLE的byResult成员取值***********************
const unsigned char OPFRES_CALSUCCESS = 0;//计算成功
const unsigned char OPFRES_CALFAIL = 1;//计算失败
const unsigned char OPFRES_CTRLSUCCESS = 2;//控制成功
const unsigned char OPFRES_CTRLFAIL = 3;//控制失败
const unsigned char OPFRES_DISELIGIBLE = 4;//遥测合格率低
//*********************************************************

/******************************************************************
**类名：MEASANALYSE_TABLE
**描述：MEASANALYSE_TABLE对应于数据库的量测数据分析表
******************************************************************/
struct MEASANA_TABLE //量测数据分析表
{
  int  iNoBalanceBranch;  //不平衡支路数
  int  iNoBalanceNode;    //不平衡支路数
  int  iBSNoMatch;        //开关潮流不匹配数
  int  iBadData;          //坏数据数
  int  iShadMeas;         //可疑量测数
  int  iDummyMeas;        //伪量测数
};

/******************************************************************
**类名：PRENODE_TABLE
**描述：PRENODE_TABLE对应于数据库的优化前节点信息
******************************************************************/
struct PRENODE_TABLE
{
  int iNodeNo;  //节点号
  int iIslandNo;  //电力岛号
  float  fVoltage;  //电压值
  float fVolAngle;  //电压相角
  float fGenMW;  //发电有功
  float fGenMvar;  //发电无功
  float fLoadMW;  //负荷有功
  float fLoadMvar;  //负荷无功
  float fShuntMW;  //并联支路有功
  float fShuntMvar;  //并联支路无功
};

/******************************************************************
**类名：POSTNODE_TABLE
**描述：POSTNODE_TABLE对应于数据库的优化后节点信息
******************************************************************/
struct POSTNODE_TABLE
{
  int iNodeNo;  //节点号
  int iIslandNo;  //电力岛号
  float fVoltage;  //电压值
  float fVolAngle;  //电压相角
  float fGenMW;  //发电有功
  float fGenMvar;  //发电无功
  float fLoadMW;  //负荷有功
  float fLoadMvar;  //负荷无功
  float fShuntMW;  //并联支路有功
  float fShuntMvar;  //并联支路无功
  float fPSen;  //有功灵敏度
  float fQSen;  //无功灵敏度
  float fSenLoss;  //灵敏度损耗因子
};

/******************************************************************
**类名：PRELINE_TABLE
**描述：PRELINE_TABLE对应于数据库的优化前线路信息
******************************************************************/
struct PRELINE_TABLE
{
  int iLineNo;  //线路号
  int iFromNode;  //首端节点号
  int iToNode;  //末端节点号
  float fFromMW;  //线路首端有功
  float fFromMvar;  //线路首端无功
  float fToMW;  //线路末端有功
  float fToMvar;  //线路末端无功
};

/******************************************************************
**类名：POSTLINE_TABLE
**描述：POSTLINE_TABLE对应于数据库的优化后线路信息
******************************************************************/
struct POSTLINE_TABLE
{
  int iLineNo;  //线路号
  int iFromNode;  //首端节点号
  int iToNode;  //末端节点号
  float fFromMW;  //线路首端有功
  float fFromMvar;  //线路首端无功
  float fToMW;  //线路末端有功
  float fToMvar;  //线路末端无功
};

/******************************************************************
**类名：PRETRANS_TABLE
**描述：PRETRANS_TABLE对应于数据库的优化前变压器信息
******************************************************************/
struct PRETRANS_TABLE
{
  short shFacNo;  //厂号
  short shMasterNo;  //主变压器号
  short shTransNo;  //变压器号
  BYTE byVolSide;  //电压侧，同计算变压器表电压侧取值
  int iFromNode;  //首端节点号
  int iToNode;  //末端节点号
  float fFromMW;  //首端有功
  float fFromMvar;  //首端无功
  float fToMW;  //末端有功
  float fToMvar;  //末端无功
  float fFromPf;  //首端功率因数
  float fToPf;  //末端功率因数
};

/******************************************************************
**类名：POSTTRANS_TABLE
**描述：POSTTRANS_TABLE对应于数据库的优化后变压器信息
******************************************************************/
struct POSTTRANS_TABLE
{
  short shFacNo;  //厂号
  short shMasterNo;  //主变压器号
  short shTransNo;  //变压器号
  BYTE byVolSide;  //电压侧，同计算变压器表电压侧取值
  int iFromNode;  //首端节点号
  int iToNode;  //末端节点号
  float fFromMW;  //首端有功
  float fFromMvar;  //首端无功
  float fToMW;  //末端有功
  float fToMvar;  //末端无功
  float fFromPf;  //首端功率因数
  float fToPf;  //末端功率因数
};

/******************************************************************
**类名：OPFTRANS_TABLE
**描述：OPFTRANS_TABLE对应于数据库的变压器输出信息表
******************************************************************/
struct OPFTRANS_TABLE
{
  short shFacNo;  //厂号
  short shMasterNo;  //主变压器号
  short shTransNo;  //变压器号
  BYTE byVolSide;  //电压侧，同计算变压器表电压侧取值
  int iFromNode;  //首端节点号
  int iToNode;  //末端节点号
  float fFromBaseVol;  //首端基准电压
  float fToBaseVol;  //末端基准电压
  float fPreRatio;  //优化前变比
  float fPostRatio;  //优化后变比
};

/******************************************************************
**类名：OPFSHUNT_TABLE
**描述：OPFSHUNT_TABLE对应于数据库的并联无功设备输出信息表
******************************************************************/
struct OPFSHUNT_TABLE
{
  short shFacNo;  //厂号
  short shShuntNo;  //编号
  int iFromNode;  //首端节点号
  int iToNode;  //末端节点号
  float fPreVar;  //优化前容量
  float fPostVar;  //优化后容量
};

/******************************************************************
**类名：VQCSET_TABLE
**描述：VQCSET_TABLE对应于数据库的VQC定值表
******************************************************************/
struct VQCSET_TABLE
{
  short shFacNo;  //厂号
  BYTE byType;  //变压器类型，见下文的成员取值
  short shTransNo;  //变压器号
  char szFacName[OPF_DEVNAME_LENGTH];  //厂站名
  char szTransName[OPF_DEVNAME_LENGTH];  //变压器名
  float fHiVolSet;  //电压定值上限
  float fLowVolSet;  //电压定值下限
  float fHiVarSet;  //无功/功率因数定值上限
  float fLowVarSet;  //无功/功率因数定值下限
  BYTE byStatus;  //发送状态，见下文的成员取值
};

//****VQCSET_TABLE的byType成员取值*************************
const unsigned char VQCSET_BITRANS = 0;//双绕组
const unsigned char VQCSET_TRITRANS = 1;//三绕组
//*********************************************************

//****VQCSET_TABLE的byStatus成员取值***********************
const unsigned char VQCSET_NOSEND = 0;  //未发送
const unsigned char VQCSET_SUCCESS = 1; //发送成功
const unsigned char VQCSET_FAIL = 2;    //发送失败
const unsigned char VQCSET_CANCEL = 5;  //撤消
const unsigned char VQCSET_READY  =6;   //准备
//*********************************************************

/******************************************************************
**类名：OPFCMD_TABLE
**描述：OPFCMD_TABLE对应于数据库的优化控制命令表
******************************************************************/
struct OPFCMD_TABLE
{
  time_t tmOrder;  //序号
  short shFacNo;  //厂号
  BYTE byType;  //设备类型，见下文的成员取值
  short shDeviceNo;  //设备编号
  char szFacName[OPF_DEVNAME_LENGTH];  //厂站名
  char szDevName[OPF_DEVNAME_LENGTH];  //设备名
  BYTE byCommand;  //命令，见下文的成员取值
  short shCurTap;  //当前档位
  short shEndTap;  //目标档位
  BYTE byStatus;  //控制状态，见下文的成员取值
};

//****OPFCMD_TABLE的byType成员取值*************************
const unsigned char OPFCMD_BITRANS = 0;//双绕组变压器
const unsigned char OPFCMD_TRITRANS = 1;//三绕组变压器
const unsigned char OPFCMD_SHUNT = 2;//并联无功设备
//*********************************************************

//****OPFCMD_TABLE的byCommand成员取值**********************
const unsigned char OPFCMD_OFF = 0;//分/升
const unsigned char OPFCMD_ON = 1;//合/降
const unsigned char OPFCMD_DZ = 2;//定值
//*********************************************************

//****OPFCMD_TABLE的byStatus成员取值*************************
const unsigned char OPFCMD_NOSEND = 0;  //未执行
const unsigned char OPFCMD_SUCCESS = 1; //控制成功
const unsigned char OPFCMD_FAIL = 2;    //控制失败
const unsigned char OPFCMD_REJECT = 3;  //拒动
const unsigned char OPFCMD_SLIP = 4;    //滑挡
const unsigned char OPFCMD_CANCEL = 5;  //撤消
const unsigned char OPFCMD_READY  =6;   //准备
//*********************************************************

/******************************************************************
**类名：OPFGEN_TABLE
**描述：OPFGEN_TABLE对应于数据库的发电机输出信息
******************************************************************/
struct OPFGEN_TABLE
{
  short shFacNo;  //厂号
  short shGenNo;  //发电机号
  int iNodeNo;  //节点号
  float fPreP;  //优化前有功
  float fPostP;  //优化后有功
  float fPreQ;  //优化前无功
  float fPostQ;  //优化后无功
};

/******************************************************************
**类名：OPFBUS_TABLE
**描述：OPFBUS_TABLE对应于数据库的母线优化结果表
******************************************************************/
struct OPFBUS_TABLE
{
  short shFacNo;  //厂号
  short shBusNo;  //母线号
  char szFacName[OPF_DEVNAME_LENGTH];  //厂站名
  char szBusName[OPF_DEVNAME_LENGTH];  //母线名
  float fYcVol;  //遥测电压值
  float fSeVol;  //状态估计电压值
  float fSeDev;  //量测估计偏差
  float fSeAngle;  //状态估计电压相角
  float fOpfVol;  //优化电压值
  float fOpfAngle;  //优化电压相角
  float fPostVol;  //控制后电压值
};

/******************************************************************
**类名：OPFLINE_TABLE
**描述：OPFLINE_TABLE对应于数据库的线路优化结果表
******************************************************************/
struct OPFLINE_TABLE
{
  int iLineNo;  //线路号
  char szName[OPF_DEVNAME_LENGTH];  ;//线路名
  float fYcFromP;  //首端有功遥测
  float fYcFromQ;  //首端无功遥测
  float fYcToP;  //末端有功遥测
  float fYcToQ;  //末端无功遥测
  float fSeFromP;  //状态估计首端有功
  float fSeFromQ;  //状态估计首端无功
  float fSeToP;  //状态估计末端有功
  float fSeToQ;  //状态估计末端无功
  float fOpfFromP;  //优化首端有功
  float fOpfFromQ;  //优化首端无功
  float fOpfToP;  //优化末端有功
  float fOpfToQ;  //优化末端无功
  float fPostFromP;  //控制后首端有功遥测
  float fPostFromQ;  //控制后首端无功遥测
  float fPostToP;  //控制后末端有功遥测
  float fPostToQ;  //控制后末端无功遥测
};

/******************************************************************
**类名：OPFBYQ_TABLE
**描述：OPFBYQ_TABLE对应于数据库的变压器优化结果表
******************************************************************/
struct OPFBYQ_TABLE
{
  short shFacNo;  //厂号
  BYTE byType;  //变压器类型，见下文的成员取值
  short shTransNo;  //变压器号
  char szFacName[OPF_DEVNAME_LENGTH];  //厂站名
  char szTransName[OPF_DEVNAME_LENGTH];  //变压器名
  float fYcHiP;  //高压侧有功遥测
  float fYcHiQ;  //高压侧无功遥测
  float fYcMidP;  //中压侧有功遥测
  float fYcMidQ;  //中压侧无功遥测
  float fYcLowP;  //低压侧有功遥测
  float fYcLowQ;  //低压侧无功遥测
  float fPreHiRatio;  //优化前高压变比
  float fPreMidRatio;  //优化前中压变比
  float fSeHiP;  //状态估计高压侧有功
  float fSeHiQ;  //状态估计高压侧无功
  float fSeMidP;  //状态估计中压侧有功
  float fSeMidQ;  //状态估计中压侧无功
  float fSeLowP;  //状态估计低压侧有功
  float fSeLowQ;  //状态估计低压侧无功
  float fOpfHiP;  //优化高压侧有功
  float fOpfHiQ;  //优化高压侧无功
  float fOpfMidP;  //优化中压侧有功
  float fOpfMidQ;  //优化中压侧无功
  float fOpfLowP;  //优化低压侧有功
  float fOpfLowQ;  //优化低压侧无功
  float fPostHiRatio;  //优化后高压变比
  float fPostMidRatio;  //优化后中压变比
  float fPostHiP;  //控制后高压侧有功遥测
  float fPostHiQ;  //控制后高压侧无功遥测
  float fPostMidP;  //控制后中压侧有功遥测
  float fPostMidQ;  //控制后中压侧无功遥测
  float fPostLowP;  //控制后低压侧有功遥测
  float fPostLowQ;  //控制后低压侧无功遥测
};

//****OPFBYQ_TABLE的byType成员取值**********************
const unsigned char OPFBYQ_BIT = 0;//双绕组变压器
const unsigned char OPFBYQ_TRIT = 1;//三绕组变压器
//*********************************************************

/******************************************************************
**类名：OPFWGSB_TABLE
**描述：OPFWGSB_TABLE对应于数据库的并联设备优化结果表
******************************************************************/
struct OPFWGSB_TABLE
{
  short shFacNo;  //厂号
  short shShuntNo;  //编号
  char szFacName[OPF_DEVNAME_LENGTH];  //厂站名
  char szName[OPF_DEVNAME_LENGTH];  //设备名
  float fYcQ;  //无功遥测
  float fSeQ;  //状态估计无功
  float fOpfQ;  //优化无功
  float fPostQ;  //控制后无功遥测
};

/******************************************************************
**类名：OPFFDJ_TABLE
**描述：OPFFDJ_TABLE对应于数据库的发电机优化结果表
******************************************************************/
struct OPFFDJ_TABLE
{
  short shFacNo;  //厂号
  short shGenNo;  //发电机号
  char szFacName[OPF_DEVNAME_LENGTH];  //厂站名
  char szName[OPF_DEVNAME_LENGTH];  //发电机名
  float fYcP;  //有功遥测
  float fYcQ;  //无功遥测
  float fSeP;  //状态估计有功
  float fSeQ;  //状态估计无功
  float fOpfP;  //优化有功
  float fOpfQ;  //优化无功
  float fPostP;  //控制后有功遥测
  float fPostQ;  //控制后无功遥测
};

/******************************************************************
**类名：VOLSESTA_TABLE
**描述：VOLSESTA_TABLE对应于数据库的遥测估计统计表
******************************************************************/
struct VOLSESTA_TABLE
{
  int iIslandNo;      //电力岛号
  BYTE byStaType;     //估计统计类型，见下文的成员取值
  BYTE byVolDegree;   //电压等级序号
  float fVolSeAccu;   //电压估计合格率
};
//****VOLSESTA_TABLE的byStaType成员取值**********************
const unsigned char SESTA_VOL = 0;//电压
const unsigned char SESTA_P = 1;//有功
const unsigned char SESTA_Q = 2;//无功
const unsigned char SESTA_I = 3;//电流
const unsigned char SESTA_TOTOLE = 4;//全部
//*********************************************************

/******************************************************************
**类名：BUSEXCEE_TABLE
**描述：BUSEXCEE_TABLE对应于数据库的母线电压越限表
******************************************************************/
struct BUSEXCEE_TABLE
{
  short shFacNo;  //厂号
  short shBusNo;  //母线号
  char szFacName[OPF_DEVNAME_LENGTH];  //厂站名
  char szBusName[OPF_DEVNAME_LENGTH];  //母线名
  float fYcVol;  //遥测电压值
  float fSeVol;  //状态估计电压值
  float fOpfVol;  //优化电压值
};

/******************************************************************
**类名：LOSSBYQ_TABLE
**描述：LOSSBYQ_TABLE对应于数据库的变压器损耗表
******************************************************************/
struct LOSSBYQ_TABLE
{
  short shFacNo;  //厂号
  BYTE  byType;  //变压器类型
  short shTransNo;  //变压器号
  char szFacName[OPF_DEVNAME_LENGTH];  //厂站名
  char szTransName[OPF_DEVNAME_LENGTH];  //变压器名
  float fPrePLoss;  //优化前有功损耗
  float fPostPLoss;  //优化后有功损耗
  float fPreQLoss;  //优化前无功损耗
  float fPostQLoss;  //优化后无功损耗
};

/******************************************************************
**类名：LOSSLINE_TABLE
**描述：LOSSLINE_TABLE对应于数据库的线路损耗表
******************************************************************/
struct LOSSLINE_TABLE
{
  int iLineNo;  //线路号
  char szName[OPF_DEVNAME_LENGTH];  //线路名
  float fPrePLoss;	 //优化前有功损耗
  float fPostPLoss; 	//优化后有功损耗
  float fPreQLoss;	 //优化前无功损耗
  float fPostQLoss;	 //优化后无功损耗
};

/******************************************************************
**类名：CURLOCK_TABLE
**描述：CURLOCK_TABLE对应于数据库的当前闭锁表
******************************************************************/
struct CURLOCK_TABLE
{
  FILETIME tLockTime;       //闭锁时间
  BYTE     byObjectType;    //闭锁对象类型,同LOCK_TABLE的byObjectType
  short    shObjectFac;     //闭锁对象厂号
  char     szFacName[OPF_DEVNAME_LENGTH];//厂站名
  short    shObjectNo;      //闭锁对象序号
  char     szObectName[OPF_DEVNAME_LENGTH];   //闭锁对象名
  char     szLockInfo[OPF_NAME_LENGTH];    //闭锁信息
};

/******************************************************************
**类名：DEVCTRL_TABLE
**描述：DEVCTRL_TABLE对应于数据库的设备控制设置表
******************************************************************/
struct DEVCTRL_TABLE
{
  short   shOrderNo;        //序号
  float   fVolIntegral;     //电压积分量
  float   fVolSecIncrease;  //电压二级增量
  short   shVolHop;         //电压跳变数
  float   fCosIntegral;     //力率积分面积
  float   fCosSecIncrease;  //力率二级增量
  short   shCosHop;         //力率跳变数
};

/******************************************************************
**类名：RULE_TABLE
**描述：RULE_TABLE对应于数据库的规则表
******************************************************************/
struct RULE_TABLE
{
  BYTE  rule_no;    //规则编号
  short order_no;   //序号
  BYTE  v_status;   //电压状态，见下文的成员取值
  BYTE  cos_status; //功率因数状态，见下文的成员取值
  BYTE  t_status;   //变压器当前状态，见下文的成员取值
  BYTE  c_status;   //补偿装置状态，见下文的成员取值
  BYTE  t_action;   //变压器动作，见下文的成员取值
  BYTE  c_action;   //补偿装置动作，见下文的成员取值
};

//****RULE_TABLE的v_status成员取值**********************
const unsigned char RULE_VOL_LOW    = 0;    //电压低
const unsigned char RULE_VOL_NLOW   = 1;    //电压正常低
const unsigned char RULE_VOL_NORMAL = 2;    //电压正常
const unsigned char RULE_VOL_NHIGH = 3;    //电压正常高
const unsigned char RULE_VOL_HIGH  = 4;    //电压高
//*********************************************************

//****RULE_TABLE的cos_status成员取值**********************
const unsigned char RULE_COS_LOW    = 0;    //力率低
const unsigned char RULE_COS_NORMAL = 1;    //力率正常
const unsigned char RULE_COS_HIGH  = 2;    //力率高
//*********************************************************

//****RULE_TABLE的t_status成员取值**********************
const unsigned char RULE_TRANS_EXIT   = 0;//变压器退出
const unsigned char RULE_TRANS_BOTTOM = 1;//变压器档位最低
const unsigned char RULE_TRANS_NORMAL = 2;//变压器档位正常
const unsigned char RULE_TRANS_TOP    = 3;//变压器档位最高
//*********************************************************

//****RULE_TABLE的c_status成员取值**********************
const unsigned char RULE_CAP_EXIT     = 0;//补偿装置退出
const unsigned char RULE_CAP_ALLDOWN  = 1;//补偿装置全切
const unsigned char RULE_CAP_NORMAL   = 2;//补偿装置可投可切
const unsigned char RULE_CAP_ALLUP    = 3;//补偿装置全投
//*********************************************************

//****RULE_TABLE的t_action成员取值**********************
const unsigned char TRANS_ACTION_KEEP = 0;//变压器不动
const unsigned char TRANS_ACTION_DOWN = 1;//变压器降
const unsigned char TRANS_ACTION_UP   = 2;//变压器升
//*********************************************************

//****RULE_TABLE的c_action成员取值**********************
const unsigned char CAP_ACTION_KEEP = 0;//补偿装置不动
const unsigned char CAP_ACTION_OFF  = 1;//补偿装置切
const unsigned char CAP_ACTION_ON   = 2;//补偿装置投
//*********************************************************

/******************************************************************
**类名：SHADY_TABLE
**描述：SHADY_TABLE对应于数据库的可疑数据表
******************************************************************/
/*struct SHADY_TABLE
{
	BYTE bType;//可疑数据类型，见下文的成员取值
	char szInfo[160];
};*/

//****SHADY_TABLE的bType成员取值**********************
/*const unsigned char SHADINESS_NONMEASURE=6;   //伪量测信息
const unsigned char SHADINESS_ERRORDATA=5;   //可疑量测
const unsigned char SHADINESS_BADDATA=4;   //坏数据
const unsigned char SHADINESS_BRANCH_BALANCE=3;   //支路不平衡
const unsigned char SHADINESS_NODE_BALANCE  =2;   //节点不平衡
const unsigned char SHADINESS_SWITCH_BRANCH =1;   //可疑开关支路组合
const unsigned char SHADINESS_OTHER_CASE    =0;   //其他拓扑不平衡数据*/
//*********************************************************

#endif //__VARCS_OPFDATA__H