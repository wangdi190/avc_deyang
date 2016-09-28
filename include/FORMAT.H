#if !defined(format_h)
#define format_h

class CMemDC;
typedef struct _SCR_FORMAT{  //��Ļ��ʽ���ļ�ͷ
 WORD     Version;           //�ļ��汾��=2000
 char     Name[40];		     //��������
 char     bgflag;            //�������� 0=�ļ���ʽ 1=ӳ�󱣴��ڱ��ļ��� ѹ����ʽ��СΪbgsize; 
 COLORREF BkColor;			 //������ɫ
 char     BgStyle;			 //�������� 0����1����2ƽ��
 WORD     Width;			 //����
 WORD     Height;			 //�߶�;
 WORD	  ObjSum;            //��������
 DWORD    fsize;			 //�ļ��ֽ���
 DWORD    attribsize;        //�����ֽ���
 DWORD    dbsize;            //�����ֽ���
 DWORD    bgsize;	         //����ͼ���ֽ���
 char resved[118];			 //����118�ֽ�
 }SCR_FORMAT;
//FMT�ļ��洢˳��
/*
 [00000]:�ļ�ͷ
 [xxxxx]:OBJ
 [yyyyy]:db
 [zzzzz]:bgimg
  */
typedef struct _ATTRIB_OBJ{  //���еĶ���ͨ������
 BYTE  type;				 //��������
 BYTE  enable;				 //0=��Ч 1=��Ч
 short x1,y1,x2,y2;          //��ռ�ľ�������
 WORD  size;                 //�����ֽ���
 DWORD offset;               //����ƫ����
}ATTRIB_OBJ;
//�������Ͷ���
/*	0=��̬ͼ��
	1=����
	2=��ť
	3=ģ����
	4=״̬��
	5=�ۼ���
	6=����
	7=��ͼ
	8=��ͼ
	9=����ͼ
	10=�豸
	11=վ
	12=��
	13=��
	14=�����(��պͲ���գ�
	15=ͼ��Ԫ��
	16=�ı�
	17=ʱ��
	18=����
	19=վ���豸ʵʱ����
	20=͹����
	21=������
	22=������
	23=��������
	24=���Ƶ�
	25=AVI��Ӱ
	26=�Զ������ı�
	27=�����ؼ�(*.dll)
	28=����԰��
*/
typedef struct OBJ_CIRBAR{ //������
	BYTE  type;            //0=԰�� 1=������
	BYTE  outline;		   //�Ƿ������
	BYTE  shad;			   //����ɫ 0=�� 1=��
	DWORD color;		   //��ɫ
	char reserved[12];	   //����12�ֽ�Ϊ��������
}OBJ_CIRBAR;


typedef struct _OBJ_IMG{//��̬ͼ��
 char  fname[64];		//�ļ���
 BYTE  tranbk;          //����͸��
 BYTE  shadow;          //��Ӱ��ʾ0û�� 1-3��Ч
 DWORD BkColor;         //͸����ɫ
 BYTE  depth;			//͸����
 CMemDC *dc;			//ͼ��DCָ��
}OBJ_IMG;

typedef OBJ_IMG OBJ_GIFAML;//GIF����


typedef struct OBJ_LINE{//��
   BYTE  width;		    //�߿���
   DWORD color;			//����ɫ
   BYTE  shadow;        //��Ӱ��ʾ0û�� 1-3��Ч
}OBJ_LINE;

typedef struct OBJ_DBX{ //�����
   char  close;			//<0����� >=0��� ���
   char  outline;       //�Ƿ񻭱߿� 0=No 1=Yes
   BYTE  width;			//�߿���
   DWORD fcolor;		//����ɫ
   DWORD bcolor1;		//����һ��ɫ
   DWORD bcolor2;		//���ڶ���ɫ
   WORD  ptsum;			//������
   POINT pt;            //������еĵ�           
}OBJ_DBX;

typedef struct OBJ_TX{  //���Σ�԰
   char  type;          //0=�վ���	1=ʵ�� 2=��԰ 3=ʵ԰
   char  style;         //��䷽ʽ0-9
   char  outline;       //�Ƿ񻭱߿� 0=No 1=Yes
   BYTE  width;			//�߿���
   DWORD fcolor;		//����ɫ
   DWORD bcolor1;		//����һ��ɫ
   DWORD bcolor2;		//���ڶ���ɫ
   BYTE  shadow;		//��Ӱ
}OBJ_TX;

typedef struct OBJ_GLASS{
   BYTE  outline;		//����
   DWORD bcolor;		//����ɫ
   DWORD fcolor;		//����ɫ
   BYTE  depth;			//���
}OBJ_GLASS;
typedef struct OBJ_TEXT{//�ı���ʽ
   LOGFONT font;        //����
   DWORD   color;		//��ɫ
   char    style;		//ʽ��
   BYTE    shadow;		//��Ӱ
   char    text[45];	//�ı�����
}OBJ_TEXT;

typedef struct OBJ_PUSH{//��ť��ʽ
   BYTE style;          //��ťʽ��0=��ͨ��ť 1=���ɼ���ť
						//2=����͹�ΰ�ť 3=�������ΰ�ť 
						//4=������ɫ 
   char title[32];		//��ť����
   BYTE shadow;			//��Ӱ
   BYTE cmdtype;        //��������
   WORD cmdnum;		    //�Զ���ʱ��WM_COMMAND��ϢwParam
   char command[45];	//�����ַ���
   DWORD color1;		//��ɫ1
   DWORD color2;		//��ɫ2
   int   selfid;		//Ҫ���Ƶ������ؼ���ID
   char reserved[8];    //�����ֽ�
}OBJ_PUSH;

typedef struct OBJ_SRLTEXT{//�����ı�
   BYTE direct;			//����   0=��̬�ı� 1=���� 2=���� 
						//3=���� 4=����
   BYTE tstyle;			//�ı���ʽ
   BYTE glass;			//�Ƿ��ò�����
   BYTE depth;			//���
   DWORD bcolor;		//�߿�
   DWORD gcolor;		//������ɫ
   DWORD tcolor;		//�ı���ɫ
   LOGFONT lf;			//��������
   BYTE  align;		    //���з�ʽ
   WORD  id;			//ID��
   char text[256];		//���ִ�
}OBJ_SRLTEXT;


typedef struct OBJ_SMSG{//״̬��Ķ�̬��
   int msgid;			//�ź�ID������״̬�����豸��վ
   BYTE grpn;           //ͼ��
   BYTE status;			//��ǰ״̬
   BYTE alarm;			//�Ƿ�澯
}OBJ_SMSG;

typedef struct OBJ_3DRT{//3D����
   BYTE  width;		    //�߿�
}OBJ_3DRT;

typedef struct OBJ_ANL{      //ģ������ʾ�ṹ
 int      Id;				 //ģ����ID
 char     unit[10];			 //��λ�ַ���
 float    max;				 //���ֵ
 float    min;				 //��Сֵ
 LOGFONT  lf;		         //����
 COLORREF acolor;		     //�澯��ɫ
 COLORREF ncolor;	         //������ɫ
 BYTE     ws;			     //��ʾλ��
 BYTE     xs;				 //С��λ
 BYTE     style;		     //������ʾ 0=���� 1=�� 2=͹
 BYTE     xsmode;			 //��ʾ��ʽ 0=������ʾ 1=ˮƽ�����ʾ
							 //2=��ֱ���
 BYTE     shadow;			 //��Ӱ
 float    curval;			 //��ǰֵ
 BYTE     alarm;			 //�澯
 }OBJ_ANL;

typedef struct OBJ_RAT{      //�ۼ���ʾ�ṹ
 int      Id;				 //�ۼ���ID
 LOGFONT  lf;		         //����
 COLORREF acolor;		     //�澯��ɫ
 COLORREF color;	         //������ɫ
 BYTE     style;		     //������ʾ 0=���� 1=�� 2=͹
 DWORD    curval;			 //��ǰֵ
 BYTE     alarm;			 //�澯
 }OBJ_RAT;

typedef struct OBJ_DTIME{    //ʱ�����ڸ�ʽ
 BYTE    type;				 //0=������ʾ 1=�û�����������ʾ
 BYTE    outline;			 //�߿� 0=�� 1=�� 2=͹
 DWORD   fcolor;			 //��ɫ
 DWORD   bcolor;			 //����ɫ
 LOGFONT font;				 //����
 BYTE    style;			     //������ʾ 0=���� 1=�� 2=͹
}OBJ_DTIME;;

typedef struct OBJ_BAR{		 //��ͼ
   int  xy;                  //0=x���� 1=Y����
   int  id1;				 //ģ����
   int  id2;				 //ģ����
   int  id3;				 //ģ����
   float max;				 //���ֵ
   float min;				 //��Сֵ
   DWORD color1;			 //��һ����ɫ
   DWORD color2;			 //�ڶ�����ɫ
   DWORD color3;			 //�ڶ�����ɫ
   float val[3];			 //��ǰֵ
}OBJ_BAR;

typedef struct OBJ_TREND{	 //����
   int  id;					 //ģ����ID
   BYTE seg;				 //ʱ�����
   BYTE jg;					 //���
   float max;				 //���ֵ
   float min;				 //��Сֵ
   BYTE  shadow;			 //��Ӱ
   float val[9];			 //���8����
}OB_TREND;

typedef struct OBJ_FORM{     //�豸ʵʱYC��YX����
   BYTE  type;				 //0=�豸��1=վ 2=�豸���� 
   int   id;                 //վ���豸ID
   char  name[32];			 //��������
   BYTE  bgtr;				 //����͸��
   DWORD acolor;			 //�澯��ɫ
   DWORD ncolor;			 //������ɫ
}OBJ_FORM;

typedef struct OBJ_QX{       //����
   int   id;                 //ģ����ID
   float max;			     //���ֵ
   float min;				 //��Сֵ
   BYTE  bgtr;				 //����͸��
   BYTE  shadow;			 //��Ӱ
   DWORD color[5];			 //0����ɫ 1������ɫ 2-4��������ɫ
   float val1[96];			 //��96��15�ּ����24Сʱ	 
   float val2[96];				
   float val3[96];			 
   //��һ����=�������� �ڶ��������� ��������=������
}OBJ_QX;
 
typedef struct OBJ_COMCTL{	//��������
   BYTE  type;				//0=�༭ 1=�б��� 2=��Ͽ� 3=TREE 
   WORD  eid;				//�༭��IDֵ
   BYTE  outline;			//�����
   DWORD wstyle;            //���
   BYTE  left;				//�����
   BYTE  right;				//�Ҷ���
   BYTE  top;				//�϶���
   BYTE  bottom;			//�¶���
   short width;				//��������
   short height;			//�����߶�
   char  str[320];			//�������������ص���Ϣ(���б���Ϣ��)
}OBJ_COMCTL;


typedef struct OBJ_CONTROL{ //���Ƶ�=YK��YT
   BYTE type;				//0=YK;1=YT;2=�Զ����
   int  id;					//YK��YT idֵ
   BYTE check;				//�Ƿ�У
   WORD group;				//���
   WORD rtu;				//RTU��
   WORD num;				//˳���
   char name[26];			//YK������
}OBJ_CONTROL;

typedef struct OBJ_SELFCTL{ //�����ؼ�
   char  dllname[64];		//��̬���ӿ���
   DWORD style;				//����,�ɿؼ�����
   int   id;				//ID��,�Ա��໥����
   char  lkbuf[255];		//����ʱ�����ӻ�����
   BYTE  aleft;				//�����
   BYTE  aright;			//�Ҷ���
   BYTE  atop;				//�϶���
   BYTE  abottom;			//�¶���
   short awdth;				//��������
   short ahght;				//�����߶�
   HINSTANCE hinst;         //DLL������
   HWND  hwnd;				//���ھ��
   void  *rc;				//��ʼ����������Դ(�����)
   int  (WINAPI*DfGetVer)();//���ذ汾��
   void (WINAPI*DfDrawDemo)(HDC,RECT,DWORD,char *);    //��ʾ��ͼ
   void*(WINAPI*DfInit)(HWND,HWND&,RECT,int,DWORD,char*);//��ʼ��
   void (WINAPI*DfClose)(void *rc);		  //�ر�
   void (WINAPI*DfAbout)();				  //���ڸÿؼ�
   void (WINAPI*DfSetParam)(DWORD&,char*);//���ò���
   char reserved[120];		              //�����ֽ�,���ŷ�չ
}OBJ_SELFCTL;

#endif