#pragma once



#define R_SCADA_BRK_DEVICE 10      //��·����Ϣ��
#define R_SCADA_DISCR_DEVICE 11    //��բ��
#define R_SCADA_GDDISCR_DEVICE 12  //�ӵص�բ��
#define R_SCADA_BS_DEVICE 13       //ĸ�߱�
#define R_SCADA_TR_DEVICE 14       //��ѹ����
#define R_SCADA_TRWD_DEVICE 15     //��ѹ������
#define R_SCADA_GN_DEVICE 16       //�������
#define R_SCADA_LD_DEVICE 17       //����
#define R_SCADA_ACLN_DEVICE 18     //�����߶α�
#define R_SCADA_ACLN_DOT 19        //�����߶ζ˵��
#define R_SCADA_FAC_INFO 20        //��վ��Ϣ��
#define R_SCADA_DIV_INFO 21        //���������
#define R_SCADA_RC_DEVICE 22       //�ݿ�����  ���ݺ͵翹
#define R_SCADA_VL_TYPE 23         //��ѹ���ͱ�

#pragma pack(8)


typedef struct
{
	char Title[5];  //0x68 0x68 ��� 0x68 0x68   
	int nLen;       //�������͵����ݳ���
}DataTitle;

//��ѹ�������
struct R_TRWD_DEVICE
{
	int tr_id;       //��ѹ��ID
	char trwd_type;  //��ѹ����������
	float p_value;   //�й�
	float q_value;   //�޹�
	float i_value;   //����
	float tap_pos;
};

//�����߶ζ˵��
struct R_ACLN_DOT
{
	int acln_id;     //�����߶ζ˵��
	int fac_id;      //��վID
	float p_value;   //�й�
	float q_value;   //�޹�
	float i_value;   //����
};


//ĸ�߱�
struct R_BS_DEVICE
{
	int bs_id;
	float v_value; //�ߵ�ѹ��ֵ
	float c_value; //��ѹ���
};

//�������
struct R_GN_DEVICE
{
	int gn_id;     //�����ID
	float p_value; //�й�ֵ
	float q_value; //�޹�ֵ
	float v_value; //��ѹֵ
	float gn_angle;//���������
};

//���ɱ�
struct R_LD_DEVICE 
{
	int ld_id;
	float p_value;   //�й�
	float q_value;   //�޹�
	float i_value;   //����
};

//��բ��
struct R_DISCR_DEVICE
{
	int discr_id;//��բID
	int run_state;//Ͷ��״̬
	unsigned char yx_value;//ң��״̬
};

//��·��
struct R_BRK_DEVICE
{
	int brk_id;
	int run_state;//Ͷ��״̬
	unsigned char yx_value;//ң��״̬
};

//�ݿ�����  ���ݺ͵翹
struct R_RC_DEVICE
{
	int rc_id;
	unsigned char rc_type;//�ݿ�������
	float q_value;//�޹�ֵ
};

#pragma pack()