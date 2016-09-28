#ifndef Open3000Model_H
#define Open3000Model_H


#define VL_TYPE_MODEL 16777416
#define DIV_INFO_MODEL 16777425
#define FAC_INFO_MODEL 16777426
#define BRK_DEVICE_MODEL 16777436
#define DISCR_DEVICE_MODEL 16777437
#define GDDISCR_DEVICE_MODEL 16777438
#define BS_DEVICE_MODEL 16777446
#define ACLN_DEVICE_MODEL 16777456
#define ACLN_DOT_MODEL 16777458
#define TR_DEVICE_MODEL 16777466
#define TRWD_DEVICE_MODEL 16777467
#define TAP_TYPE_MODEL 16777468
#define GN_DEVICE_MODEL 16777476
#define LD_DEVICE_MODEL 16777486
#define RC_DEVICE_MODEL 16777491
#define DIILND_COMM_EMS_MODEL 16778228
#define RECENTMSG_COMM_EMS_MODEL 16778231
#define PARA_RTNET_EMS_MODEL 16778236
#define SEMEAS_RTNET_EMS_MODEL 16778246
#define STM_AVC_EMS_MODEL 16778387
#define NDM_AVC_EMS_MODEL 16778388
#define XFM_AVC_EMS_MODEL 16778389
#define CPM_AVC_EMS_MODEL 16778390
#define ITEM_AVC_EMS_MODEL 16778391
#define RUNPLT_AVC_EMS_MODEL 16778392
#define DEVPLT_AVC_EMS_MODEL 16778393
#define ALMTYP_AVC_EMS_MODEL 16778394
#define OPBUFF_AVC_EMS_MODEL 16778398
#define ALMYX_AVC_EMS_MODEL 16778399
#define RELAY_AVC_EMS_MODEL 16778400
#define OVBUS_AVC_EMS_MODEL 16778401
#define AOPMSG_AVC_EMS_MODEL 16778402
#define XFACT_AVC_EMS_MODEL 16778404
#define CPACT_AVC_EMS_MODEL 16778405
#define ZONE_AVC_EMS_MODEL 16778407
#define STAT_AVC_EMS_MODEL 16778410
#define EXCHG_AVC_EMS_MODEL 16778414


//电压类型表 Model
struct VL_TYPE_Model
{
  int vlty_id;    //电压类型ID号
  float vbase;    //电压基值

};

//行政区域表 Model
struct DIV_INFO_Model
{
  int area_id;    //区域ID号
  char area_name[64];    //区域名称
  short area_no;    //区域编号

};

//厂站信息表 Model
struct FAC_INFO_Model
{
  int fac_id;    //厂站ID
  int area_id;    //区域ID
  char fac_name[64];    //厂站名称
  short fac_serial;    //厂站编号
  unsigned char fac_type;    //厂站类型
  int vlty_id;    //最高电压等级

};

//断路器信息表 Model
struct BRK_DEVICE_Model
{
  int brk_id;    //断路器ID号
  int fac_id;    //厂站ID号
  char brk_name[64];    //断路器名称
  int vlty_id;    //电压类型ID号
  int nd1_no;    //节点1号
  int nd2_no;    //节点2号
  int run_state;    //投运状态

};

//刀闸表 Model
struct DISCR_DEVICE_Model
{
  int discr_id;    //刀闸ID号
  int fac_id;    //厂站ID号
  char discr_name[64];    //刀闸名称
  int vlty_id;    //电压类型ID号
  int nd1_no;    //节点1号
  int nd2_no;    //节点2号
  int run_state;    //投运状态

};

//接地刀闸表 Model
struct GDDISCR_DEVICE_Model
{
  int gddiscr_id;    //接地刀闸ID号
  int fac_id;    //厂站ID号
  char gddiscr_name[64];    //接地刀闸名称
  int vlty_id;    //电压类型ID号
  int nd_no;    //节点号

};

//母线表 Model
struct BS_DEVICE_Model
{
  int bs_id;    //母线ID号
  int fac_id;    //厂站ID号
  char bs_name[64];    //母线名称
  int vlty_id;    //电压类型ID号
  float vmax;    //电压上限
  float vmin;    //电压下限
  int nd_no;    //节点号
  int run_state;    //投运状态

};

//交流线段表 Model
struct ACLN_DEVICE_Model
{
  int acln_id;    //交流线段ID号
  int fac_id_s;    //一端厂站ID号
  int fac_id_e;    //二端厂站ID号
  char acln_name[64];    //交流线段名称
  int line_id;    //线路ID号
  float smax;    //功率限值
  float imax1;    //电流正常限
  int vlty_id;    //电压类型ID号
  unsigned char eq_fg;    //等值标志
  float r_value_pu;    //正序电阻标幺值
  float x_value_pu;    //正序电抗标幺值
  float bch_value_pu;    //正序电纳标幺值
  float r0_value_pu;    //零序电阻标幺值
  float x0_value_pu;    //零序电抗标幺值
  float bch0_value_pu;    //零序电纳标幺值
  int run_state;    //投运状态

};

//交流线段端点表 Model
struct ACLN_DOT_Model
{
  int fac_id;    //厂站ID号
  char acln_dot_name[64];    //交流线段端点名称
  int acln_id;    //所属交流线段ID号
  int vlty_id;    //电压类型ID号
  int nd_no;    //节点号

};

//变压器表 Model
struct TR_DEVICE_Model
{
  int tr_id;    //变压器ID号
  int fac_id;    //厂站ID号
  char tr_name[64];    //变压器名称
  unsigned char trty;    //绕组类型
  int run_state;    //投运状态

};

//变压器绕组表 Model
struct TRWD_DEVICE_Model
{
  int trwd_id;    //变压器绕组ID号
  int fac_id;    //厂站ID号
  char trwd_name[64];    //变压器绕组名称
  int tr_id;    //变压器ID号
  int vlty_id;    //电压类型ID号
  unsigned char trwd_type;    //变压器绕组类型
  int tapty_id;    //分接头类型ID号
  float snom;    //额定功率
  float vnom;    //额定电压
  int nd_no;    //节点号
  float pk;    //短路损耗
  float uk;    //短路电压百分值
  float r_value_pu;    //正序电阻标幺值
  float x_value_pu;    //正序电抗标幺值
  float r0_value_pu;    //零序电阻标幺值
  float x0_value_pu;    //零序电抗标幺值
  float tap_pos;    //分接头位置

};

//变压器分接头类型表 Model
struct TAP_TYPE_Model
{
  int tapty_id;    //变压器分接头类型ID
  char tapty_name[64];    //变压器分接头类型名称
  int tapty_mn;    //最小档位
  int tapty_mx;    //最大档位
  int tapty_nom;    //额定档位
  float tapty_step;    //步长

};

//发电机表 Model
struct GN_DEVICE_Model
{
  int gn_id;    //发电机ID号
  int fac_id;    //厂站ID号
  char gn_name[64];    //发电机名称
  int vlty_id;    //电压类型ID号
  float snom;    //额定功率
  float pmax;    //有功上限
  int nd_no;    //节点号
  int run_state;    //投运状态

};

//负荷表 Model
struct LD_DEVICE_Model
{
  int ld_id;    //负荷ID号
  int fac_id;    //厂站ID号
  char ld_name[64];    //负荷名称
  int vlty_id;    //电压类型ID号
  int nd_no;    //节点号
  int run_state;    //投运状态

};

//容抗器表 Model
struct RC_DEVICE_Model
{
  int rc_id;    //容抗器ID号
  int fac_id;    //厂站ID号
  char rc_name[64];    //容抗器名称
  int vlty_id;    //电压类型ID号
  unsigned char rc_type;    //容抗器类型
  float qnom;    //额定容量
  float vnom;    //额定电压
  int nd1_no;    //节点1号
  int nd2_no;    //节点2号
  int nd3_no;    //节点3号
  int q_status;    //无功状态
  int run_state;    //投运状态

};

//PAS电气岛信息表 Model
struct DIILND_COMM_EMS_Model
{
  int keyno;    //序号
  short isrec;    //岛号
  char chst[16];    //平衡机厂站名
  int stid;    //平衡机厂站ID
  char un[20];    //平衡机名称
  int unid;    //平衡机ID
  short bus;    //节点数
  unsigned char stat;    //收敛状态
  unsigned char obisle;    //是否可观测
  unsigned char lvbadp;    //有功坏数据点数
  unsigned char lvbadq;    //无功坏数据点数

};

//PAS最近运行信息表 Model
struct RECENTMSG_COMM_EMS_Model
{
  CTime time;    //时间
  char msg[160];    //消息

};

//状态估计参数和信息表 Model
struct PARA_RTNET_EMS_Model
{
  unsigned char pause_flag;    //暂停计算标志
  int conv_state;    //收敛状态
  int run_flag;    //运行中标志
  float estimable_rate;    //量测覆盖率
  CTime datemark;    //日戳
  float conv_rate;    //当日收敛率
  CTime hourmark;    //时戳
  float cycle_period;    //运行周期(分)
  int iter_step_limit;    //最大迭代次数
  float epsp;    //有功收敛精度
  float epsq;    //无功收敛精度

};

//状态估计量测一览表 Model
struct SEMEAS_RTNET_EMS_Model
{
  int keyno;    //序号
  int stid;    //厂站名称
  int devid;    //设备名称
  short meassub;    //量测下标
  short type;    //量测类型
  int devmtyp;    //设备量测类型
  float measval;    //量测值
  float seval;    //状态估计值
  float err;    //误差百分数
  unsigned char qbigerr;    //大误差点
  unsigned char qbad;    //坏数据

};

//AVC厂站控制表 Model
struct STM_AVC_EMS_Model
{
  int fac_id;    //厂站ID
  int respar;    //所属责任区
  unsigned char remove;    //厂站排除
  unsigned char qaut;    //自动控制
  int pltyp;    //时段类型
  unsigned char qdevlck;    //下属设备闭锁

};

//AVC母线控制表 Model
struct NDM_AVC_EMS_Model
{
  int fac_id;    //厂站ID
  int bsid;    //母线ID号
  int pltyp;    //时段类型
  unsigned char offavr;    //闭锁状态
  unsigned char qavr;    //参与计算
  unsigned char qgate;    //关口母线

};

//AVC变压器控制表 Model
struct XFM_AVC_EMS_Model
{
  int fac_id;    //厂站ID
  int trid;    //变压器ID号
  unsigned char offavr;    //闭锁状态
  unsigned char qavr;    //参与计算
  int pltyp;    //时段类型
  short limtnum;    //动作次数限值
  int upyxid;    //升档遥信ID
  int upykno;    //升档遥控点号
  int dnyxid;    //降档遥信ID
  int dnykno;    //降档遥控点号
  int isbsid;    //控制母线ID
  int numday;    //日AVC动作次数
  int tnumday;    //日总动作次数
  int cnumday;    //日AVC控制次数
  int nummon;    //月AVC动作次数
  int tnummon;    //月总动作次数
  int cnummon;    //月AVC控制次数
  int numyea;    //年AVC动作次数
  int tnumyea;    //年总动作次数
  int cnumyea;    //年AVC控制次数
  unsigned char qgate;    //关口主变

};

//AVC电容器控制表 Model
struct CPM_AVC_EMS_Model
{
  int fac_id;    //厂站ID
  int cpid;    //电容器ID号
  unsigned char offavr;    //闭锁状态
  unsigned char qavr;    //参与计算
  int pltyp;    //时段类型
  short limtnum;    //动作次数限值
  int yxid;    //控制开关ID
  int ykno;    //遥控序号
  int isbsid;    //控制母线ID
  int numday;    //日AVC动作次数
  int tnumday;    //日总动作次数
  int cnumday;    //日AVC控制次数
  int nummon;    //月AVC动作次数
  int tnummon;    //月总动作次数
  int cnummon;    //月AVC控制次数
  int numyea;    //年AVC动作次数
  int tnumyea;    //年总动作次数
  int cnumyea;    //年AVC控制次数
  int rtmday;    //日运行时长
  int rtmmon;    //月运行时长
  int rtmyea;    //年运行时长

};

//AVC控制参数表 Model
struct ITEM_AVC_EMS_Model
{
  char sysinfo[16];    //系统信息
  char avcmsg[64];    //运行信息
  int avcnum;    //运行次数
  CTime strtime;    //开始时间
  CTime avctime;    //计算结束时间
  unsigned char run;    //运行状态
  unsigned char aut;    //自动控制
  unsigned char abort;    //程序退出
  unsigned char cmd;    //命令下发
  unsigned char remote;    //远方模式
  short cycvol;    //采样周期
  int ctrlmtd;    //控制算法
  unsigned char ctrlre;    //电抗器控制
  unsigned char ctrlcq;    //区域无功控制
  unsigned char ctrltcv;    //区域电压控制
  int xfregin;    //主变调档时间间隔
  int cpouin;    //电容器投入后切除时间
  int cpinin;    //电容器切除后投入时间
  int znctlin;    //区域控制时间间隔
  float xfhvld;    //主变过负荷系数
  float avcuper;    //AVC可用率
  int avcautt;    //AVC闭环时长
  int ctrlnum;    //控制指令次数
  int ctrlsuc;    //控制成功次数
  float sucper;    //控制成功率
  int mxopnum;    //最大可动设备数
  int cpacfnm;    //容抗器判拒动次数
  int xfacfnm;    //主变判拒动次数
  int enable;    //AVC可用标志
  float lossdec;    //日降损量

};

//AVC运行参数表 Model
struct RUNPLT_AVC_EMS_Model
{
  int keyno;    //序号
  int strtm;    //开始时间
  int endtm;    //结束时间
  short type;    //时段类型
  int cpnum;    //电容器可动次数
  int xfnum;    //变压器可动次数
  float cosfup;    //关口功率因数上限
  float cosfdn;    //关口功率因数下限
  float scosfup;    //厂站功率因数上限
  float scosfdn;    //厂站功率因数下限
  float v6up;    //6kV电压上限
  float v6dn;    //6kV电压下限
  float v10up;    //10kV电压上限
  float v10dn;    //10kV电压下限
  float v35up;    //35kV电压上限
  float v35dn;    //35kV电压下限
  float v110up;    //110kV电压上限
  float v110dn;    //110kV电压下限
  float v220up;    //220kV电压上限
  float v220dn;    //220kV电压下限
  float v330up;    //330kV电压上限
  float v330dn;    //330kV电压下限

};

//AVC设备时段类型表 Model
struct DEVPLT_AVC_EMS_Model
{
  int keyno;    //序号
  char id[32];    //时段名称
  float vup1;    //电压上限1
  float vdn1;    //电压下限1
  short cpnum1;    //电容器可动次数1
  short xfnum1;    //变压器可动次数1
  float cosfup1;    //功率因数上限1
  float cosfdn1;    //功率因数下限1
  int tm1;    //时段1分隔点
  float vup2;    //电压上限2
  float vdn2;    //电压下限2
  int cpnum2;    //电容器可动次数2
  int xfnum2;    //变压器可动次数2
  float cosfup2;    //功率因数上限2
  float cosfdn2;    //功率因数下限2
  int tm2;    //时段2分隔点
  float vup3;    //电压上限3
  float vdn3;    //电压下限3
  int cpnum3;    //电容器可动次数3
  int xfnum3;    //变压器可动次数3
  float cosfup3;    //功率因数上限3
  float cosfdn3;    //功率因数下限3
  int tm3;    //时段3分隔点
  float vup4;    //电压上限4
  float vdn4;    //电压下限4
  int cpnum4;    //电容器可动次数4
  int xfnum4;    //变压器可动次数4
  float cosfup4;    //功率因数上限4
  float cosfdn4;    //功率因数下限4
  int tm4;    //时段4分隔点
  float vup5;    //电压上限5
  float vdn5;    //电压下限5
  int cpnum5;    //电容器可动次数5
  int xfnum5;    //变压器可动次数5
  float cosfup5;    //功率因数上限5
  float cosfdn5;    //功率因数下限5
  int tm5;    //时段5分隔点
  float vup6;    //电压上限6
  float vdn6;    //电压下限6
  int cpnum6;    //电容器可动次数6
  int xfnum6;    //变压器可动次数6
  float cosfup6;    //功率因数上限6
  float cosfdn6;    //功率因数下限6

};

//AVC告警类型表 Model
struct ALMTYP_AVC_EMS_Model
{
  int keyno;    //序号
  int id;    //告警名称
  short ot;    //告警设备类型
  char txt[32];    //告警内容
  unsigned char qskip;    //是否抑制告警
  unsigned char qlock;    //闭锁复归方式
  unsigned char qsend;    //是否送告警
  int deltm;    //复归延时时间

};

//AVC控制策略表 Model
struct OPBUFF_AVC_EMS_Model
{
  int keyno;    //序号
  char stm[32];    //厂站控制名
  char id[24];    //设备名
  int facid;    //厂站ID
  int devid;    //设备ID
  int devsub;    //控制设备下标
  CTime isstm;    //发命时刻
  CTime comtm;    //执行时刻
  char cause[80];    //原因
  char result[80];    //措施
  char text[120];    //命令信息
  char cmdtype[8];    //命令类型
  short optype;    //操作类型
  char rslttyp[12];    //处理状态
  unsigned char qcheck;    //命令确认
  unsigned char qaut;    //自控命令
  int seq;    //命令编号
  int zone;    //区域ID
  int resp;    //责任区

};

//AVC告警信号表 Model
struct ALMYX_AVC_EMS_Model
{
  int fac_id;    //厂站ID号
  int devid;    //告警设备ID号
  int atyid;    //告警类型ID号
  unsigned char qlock;    //闭锁复归方式
  unsigned char stat;    //闭锁状态
  short almtyp;    //告警类型
  int ontm;    //动作时间
  int offtm;    //复归时间

};

//AVC保护信号表 Model
struct RELAY_AVC_EMS_Model
{
  int fac_id;    //厂站ID
  int rlyid;    //保护名称
  unsigned char stat;    //状态
  short qlock;    //闭锁复归方式
  int devid1;    //关联设备1
  int ontm;    //动作时间
  int offtm;    //复归时间

};

//AVC电压越限表 Model
struct OVBUS_AVC_EMS_Model
{
  int keyno;    //序号
  char st[32];    //厂站
  char id[32];    //母线名
  float val;    //电压值
  float lmt;    //电压限值

};

//AVC操作信息表 Model
struct AOPMSG_AVC_EMS_Model
{
  int keyno;    //序号
  char usr[12];    //用户名
  CTime time;    //操作时刻
  char opefunc[24];    //操作项
  char text[120];    //操作内容

};

//AVC变压器动作事件表 Model
struct XFACT_AVC_EMS_Model
{
  int keyno;    //序号
  char stm[32];    //厂站名
  char chid[16];    //变压器中文名
  short sub;    //主变序号
  int facid;    //厂站ID
  int id;    //变压器名
  CTime optime;    //操作时刻
  short afttap;    //操作后档位
  short pretap;    //操作前档位
  float val;    //操作后电压
  char optype[8];    //命令类型
  float prekv;    //操作前电压
  float prevh;    //动作前高压侧电压
  float prewh;    //动作前高压侧有功
  float prerh;    //动作前高压侧无功
  float prevm;    //动作前中压侧电压
  float prewm;    //动作前中压侧有功
  float prerm;    //动作前中压侧无功
  float prevl;    //动作前低压侧电压
  float prewl;    //动作前低压侧有功
  float prerl;    //动作前低压侧无功
  float aftvh;    //动作后高压侧电压
  float aftwh;    //动作后高压侧有功
  float aftrh;    //动作后高压侧无功
  float aftvm;    //动作后中压侧电压
  float aftwm;    //动作后中压侧有功
  float aftrm;    //动作后中压侧无功
  float aftvl;    //动作后低压侧电压
  float aftwl;    //动作后低压侧有功
  float aftrl;    //动作后低压侧无功
  unsigned char qavc;    //是否AVC指令

};

//AVC电容器动作事件表 Model
struct CPACT_AVC_EMS_Model
{
  int keyno;    //序号
  char stm[32];    //厂站名
  char chid[32];    //电容器中文名
  short sub;    //电容器序号
  int facid;    //厂站ID
  int id;    //电容器名
  CTime optime;    //操作时刻
  char optype[8];    //命令类型
  float val;    //操作后电压
  float prekv;    //操作前电压
  unsigned char qopen;    //操作后运行状态
  unsigned char qavc;    //是否AVC指令

};

//AVC控制区域表 Model
struct ZONE_AVC_EMS_Model
{
  int keyno;    //序号
  char chid[32];    //区域名称
  int vovnum;    //电压考核点越限数
  int qovnum;    //无功考核点越限数
  float wloss;    //区域网损值
  int normcp;    //可控容抗器数
  int lockcp;    //闭锁容抗器数
  int normxf;    //可控主变数
  int lockxf;    //闭锁主变数
  float varin;    //已投无功总容量
  float varoff;    //未投无功总容量
  float cosfi;    //关口功率因数
  float score;    //区域状态得分

};

//AVC统计信息表 Model
struct STAT_AVC_EMS_Model
{
  int keyno;    //序号
  int devid;    //设备名称
  int fac_id;    //厂站名称
  int numall;    //日动作次数
  int numavc;    //日成功次数
  int numorder;    //日下令次数
  int numfail;    //日失败次数
  float sucrate;    //日成功率
  char devname[64];    //设备中文名

};

//AVC省地交换信息表 Model
struct EXCHG_AVC_EMS_Model
{
  int keyno;    //序号
  int objtyp;    //对象类型
  int objid;    //对象ID
  int objcdid;    //对象测点ID
  float fval;    //浮点对象值
  int datdir;    //数据传送方向

};

#endif
