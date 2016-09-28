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


//��·����Ϣ�� Real
struct BRK_DEVICE_Real
{
  int brk_id;    //��·��ID��
  int run_state;    //Ͷ��״̬
  unsigned char yx_value;    //ң��ֵ

};

//��բ�� Real
struct DISCR_DEVICE_Real
{
  int discr_id;    //��բID��
  int run_state;    //Ͷ��״̬
  unsigned char yx_value;    //ң��ֵ

};

//ĸ�߱� Real
struct BS_DEVICE_Real
{
  int bs_id;    //ĸ��ID��
  float v_value;    //�ߵ�ѹ��ֵ(ab)
  float c_value;    //��ѹ���

};

//�����߶ζ˵�� Real
struct ACLN_DOT_Real
{
  int acln_dot_id;    //�����߶ζ˵�ID��
  int fac_id;    //��վID��
  int acln_id;    //���������߶�ID��
  float p_value;    //�й�ֵ
  float q_value;    //�޹�ֵ
  float i_value;    //����ֵ

};

//��ѹ������� Real
struct TRWD_DEVICE_Real
{
  int tr_id;    //��ѹ��ID��
  unsigned char trwd_type;    //��ѹ����������
  float p_value;    //�й�ֵ
  float q_value;    //�޹�ֵ
  float i_value;    //����ֵ
  float tap_pos;    //�ֽ�ͷλ��

};

//������� Real
struct GN_DEVICE_Real
{
  int gn_id;    //�����ID��
  float p_value;    //�й�ֵ
  float q_value;    //�޹�ֵ
  float v_value;    //��ѹֵ
  float gn_angle;    //���������

};

//���ɱ� Real
struct LD_DEVICE_Real
{
  int ld_id;    //����ID��
  float p_value;    //�й�ֵ
  float q_value;    //�޹�ֵ
  float i_value;    //����ֵ

};

//�ݿ����� Real
struct RC_DEVICE_Real
{
  int rc_id;    //�ݿ���ID��
  unsigned char rc_type;    //�ݿ�������
  float q_value;    //�޹�ֵ

};

#endif
