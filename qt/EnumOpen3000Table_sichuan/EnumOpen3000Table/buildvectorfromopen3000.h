#ifndef BUILDVECTORFROMOPEN3000_H
#define BUILDVECTORFROMOPEN3000_H

#include <vector>
#include <fstream>
#include "ByteOrder.h"
using namespace std;

#include <QString>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QtDebug>
#include <QStringList>

#include <QTextCodec>
#include <QMessageBox>

const unsigned int ColorModel=0xff0000ff;
const unsigned int ColorReal=0xff00ff00;
const unsigned int ColorModelAndReal=0xffff0000;
const unsigned int ColorCancel=0xffffffff;

const unsigned int ColorTable=0x7d7d7d;

struct ST_ColumnInfo
{
    int table_id;       //表ID
    int apptype;        //应用类型
    short id;           //域内部ID号
    char name_eng[32];  //表英文名称
    char name_chn[64];  //表中文名称
    unsigned char dataType;     //数据类型
    unsigned short dataLength;  //数据长度

    unsigned int bColor;        //为ColorModel是模型 ColorReal为实时数据  ColorModelAndReal为既是模型 又是实时  默认为0xffffffff
};
typedef std::vector<ST_ColumnInfo> VecColumnInfo;

struct ST_TableInfo
{
    int SendTag;
    int AppNo;          //应用号
    int TypeID_Model;         //和客户端交互的ID
    int TypeID_Real;          //和客户端交互的ID
    int TimeInterval_Model;   //时间间隔 s
    int TimeInterval_Real;    //时间间隔 s


    int table_id;       //表ID
    int apptype;        //应用类型
    char name_eng[32];  //表英文名称
    char name_chn[64];  //表中文名称
    VecColumnInfo veccolumninfo;

    unsigned int bColor;   //为ColorTable表示有字段生成 struct  为0xffffffff表示没有字段生成struct
};
typedef std::vector<ST_TableInfo> VecTableInfo;

class BuildVectorFromOpen3000
{
public:
    BuildVectorFromOpen3000();
    void PhraseFile(char *pFilePath);
    void StartPhraseTableInfo(char* pPacket, int lLength);    //表信息表
    void StartPhraseColumnInfo(char* pPacket, int lLength);   //域信息表

    VecTableInfo m_VecTableInfo;
    ByteOrder m_ByteOrder;


    void PhraseXmlFile(char *pFilePath);

public:
    static bool SortBy_TableInfo_TableID(ST_TableInfo a, ST_TableInfo b);
    static bool SortBy_TableInfo_NameChn(ST_TableInfo a, ST_TableInfo b);

    int BinaryFind_TableInfo_TableID(int id);
    int BinaryFind_TableInfo_NameChn(char *pName);

    QString GetDataTypeByID(unsigned char datatype);

    void CreateHFile();
    void CreateXmlFile();

    void CreateVariable(char *pBuf, ST_ColumnInfo *pCol);

};

#pragma pack(8)

struct DataInfo_Struct
{
    char top;
    int nTypeID;
    int nAppNo;
    int nTableNo;
    int nBufSize;
    char pName[256];
    char bottom;
};

struct  Struct_TableInfo
{
    int table_id;       //表号
    char name_eng[32];  //表英文名称
    char name_chn[64];  //表中文名称
    int apptype;        //应用类型
    int tabletype;      //表类型
};

struct Struct_ColumnInfo
{
    int table_id;       //表号
    short id;           //域内部ID号
    char name_eng[32];  //表英文名称
    char name_chn[64];  //表中文名称
    unsigned char dataType;     //数据类型
    unsigned short dataLength;  //数据长度
    int apptype;        //应用类型
};

#pragma pack()

#endif // BUILDVECTORFROMOPEN3000_H
