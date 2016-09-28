
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the XMLTOOL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// XMLTOOL_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef XMLTOOL_EXPORTS
#define XMLTOOL_API __declspec(dllexport)
#else
#define XMLTOOL_API __declspec(dllimport)
#endif

#include <vector>
#define FLAG_LENGTH_MAX 64 // ����־����

class XMLTOOL_API IXmlNode  
{
public:
	//ͨ����־�����ӽڵ�
	virtual IXmlNode* GetSubNodeByFlag(const char* pFlag,std::vector<IXmlNode*>* pSubVtr)=0;
	//ͨ����־�����ӽڵ�ֵ
	virtual const char* GetSubValueByFlag(const char* pFlag)=0;
	//�����׸��ӽڵ�λ��
	virtual int GetFirstSubNode()=0;
	//���ص�ǰ�ӽڵ�
	virtual IXmlNode* GetNextSubNode()=0;
	//�����׸�����λ��
	virtual int GetFirstProp()=0;
	//���ص�ǰ����
	virtual int GetNextProp(const char** pName,const char** pValue)=0;

	//ȡ����ֵ
	virtual const char* GetPropValue(const char* pName)=0;
	//�Ƿ�ڵ��־
	virtual int IsKindof(const char* pFlag)=0;
	//���ر�־
	virtual const char* GetFlag()=0;
	//���ַ���ȡֵ
	virtual const char* GetValue()=0;


	IXmlNode(){};
	virtual ~IXmlNode(){};
};

XMLTOOL_API typedef std::vector<IXmlNode*> XMLNODEVTR;
XMLTOOL_API typedef std::vector<IXmlNode*>::iterator XMLITERATOR;

//����XML�ļ�
XMLTOOL_API int XMLAPI_Parse(const char* pXmlFile,XMLNODEVTR** pNodeVtr,const char* pRoot=NULL);
//����XML�ַ���
XMLTOOL_API int XMLAPI_Parse(const char* pXmlFile,int len,XMLNODEVTR** pNodeVtr,const char* pRoot=NULL);
//�ͷ�����
XMLTOOL_API void XMLAPI_Release(XMLNODEVTR* pNodeVtr);

