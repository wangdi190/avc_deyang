#ifndef Open3000Real_H
#define Open3000Real_H


#define BRK_DEVICE_REAL 220
#define DISCR_DEVICE_REAL 221
#define BS_DEVICE_REAL 230
#define ACLN_DOT_REAL 242
#define TRWD_DEVICE_REAL 251
#define GN_DEVICE_REAL 260
#define LD_DEVICE_REAL 270
#define RC_DEVICE_REAL 275


//断路器信息表 Real
struct BRK_DEVICE_Real
{
  int brk_id;    //断路器ID号
  int run_state;    //投运状态
  unsigned char yx_value;    //遥信值

};

//刀闸表 Real
struct DISCR_DEVICE_Real
{
  int discr_id;    //刀闸ID号
  int run_state;    //投运状态
  unsigned char yx_value;    //遥信值

};

//母线表 Real
struct BS_DEVICE_Real
{
  int bs_id;    //母线ID号
  float v_value;    //线电压幅值(ab)
  float c_value;    //电压相角

};

//交流线段端点表 Real
struct ACLN_DOT_Real
{
  int acln_dot_id;    //交流线段端点ID号
  int fac_id;    //厂站ID号
  int acln_id;    //所属交流线段ID号
  float p_value;    //有功值
  float q_value;    //无功值
  float i_value;    //电流值

};

//变压器绕组表 Real
struct TRWD_DEVICE_Real
{
  int tr_id;    //变压器ID号
  unsigned char trwd_type;    //变压器绕组类型
  float p_value;    //有功值
  float q_value;    //无功值
  float i_value;    //电流值
  float tap_pos;    //分接头位置

};

//发电机表 Real
struct GN_DEVICE_Real
{
  int gn_id;    //发电机ID号
  float p_value;    //有功值
  float q_value;    //无功值
  float v_value;    //电压值
  float gn_angle;    //发电机功角

};

//负荷表 Real
struct LD_DEVICE_Real
{
  int ld_id;    //负荷ID号
  float p_value;    //有功值
  float q_value;    //无功值
  float i_value;    //电流值

};

//容抗器表 Real
struct RC_DEVICE_Real
{
  int rc_id;    //容抗器ID号
  unsigned char rc_type;    //容抗器类型
  float q_value;    //无功值

};

#endif
