#include "buildvectorfromopen3000.h"

BuildVectorFromOpen3000::BuildVectorFromOpen3000()
{

}

bool BuildVectorFromOpen3000::SortBy_TableInfo_TableID(ST_TableInfo a, ST_TableInfo b)
{
    if(a.table_id < b.table_id)
        return true;
    else
        return false;
}

bool BuildVectorFromOpen3000::SortBy_TableInfo_NameChn(ST_TableInfo a, ST_TableInfo b)
{
    if(strcmp(a.name_chn, b.name_chn)<0)
        return true;
    else
        return false;
}

int BuildVectorFromOpen3000::BinaryFind_TableInfo_TableID(int id)
{
    int nRet;
    long lMin=0;long lMid=0;
    long lMax = m_VecTableInfo.size()-1;
    while(lMin<=lMax)
    {
        lMid = (lMin+lMax)/2;
        if (lMid>=0)
        {
            nRet = m_VecTableInfo.at(lMid).table_id;
            if (nRet>id)
                lMax = lMid-1;
            else if (nRet<id)
                lMin = lMid+1;
            else
                return lMid;
        }
        else
            break;
    }
    return -1;
}

int BuildVectorFromOpen3000::BinaryFind_TableInfo_NameChn(char *pName)
{
    int nRet;
    long lMin=0;long lMid=0;
    long lMax = m_VecTableInfo.size()-1;
    while(lMin<=lMax)
    {
        lMid = (lMin+lMax)/2;
        if (lMid>=0)
        {
            nRet = strcmp(m_VecTableInfo.at(lMid).name_chn, pName);
            if (nRet>0)
                lMax = lMid-1;
            else if (nRet<0)
                lMin = lMid+1;
            else
                return lMid;
        }
        else
            break;
    }
    return -1;
}

void BuildVectorFromOpen3000::PhraseFile(char *pFilePath)
{
    if(pFilePath == NULL)
        return;

    DataInfo_Struct dInfo;
    std::ifstream fin(pFilePath, std::ios::binary);
    if(fin)
    {
        while(fin.good())
        {
            memset(&dInfo, 0, sizeof(DataInfo_Struct));
            fin.read((char*)&dInfo, sizeof(DataInfo_Struct));

            //dInfo.nTypeID = m_ByteOrder.FlipBytes(dInfo.nTypeID);
            //dInfo.nBufSize = m_ByteOrder.FlipBytes(dInfo.nBufSize);
            if( dInfo.top ==0x16 && dInfo.bottom ==0x16 )
            {
                char *pData = new char[dInfo.nBufSize+1];
                memset(pData, 0, dInfo.nBufSize+1);
                fin.read(pData, dInfo.nBufSize);

                switch (dInfo.nTypeID)
                {
                case 10:
                    StartPhraseTableInfo(pData, dInfo.nBufSize);
                    break;
                case 20:
                    StartPhraseColumnInfo(pData, dInfo.nBufSize);
                    break;
                }
                delete pData;
            }
            else
                break;
        }
    }
    fin.close();
}

//表信息表
void BuildVectorFromOpen3000::StartPhraseTableInfo(char* pPacket, int lLength)
{
    Struct_TableInfo *pRec = (Struct_TableInfo*)pPacket;
    ST_TableInfo stTab;
    for (int i=0; i<lLength/sizeof(Struct_TableInfo); i++)
    {
        memset(&stTab, 0, sizeof(stTab));
        stTab.apptype = pRec[i].apptype;//m_ByteOrder.FlipBytes(pRec[i].apptype);
        stTab.table_id = pRec[i].table_id;//m_ByteOrder.FlipBytes(pRec[i].table_id);


        strcpy(stTab.name_chn, pRec[i].name_chn);

        strcpy(stTab.name_eng, pRec[i].name_eng);
        stTab.bColor = ColorCancel;

        stTab.TimeInterval_Real = 60;
        stTab.TimeInterval_Model = 86400;

        stTab.TypeID_Real = stTab.table_id;
        stTab.TypeID_Model = stTab.table_id|0x01000000;

        m_VecTableInfo.push_back(stTab);
    }
    std::sort(m_VecTableInfo.begin(), m_VecTableInfo.end(), SortBy_TableInfo_TableID);
}


//域信息表
void BuildVectorFromOpen3000::StartPhraseColumnInfo(char* pPacket, int lLength)
{
    Struct_ColumnInfo *pRec = (Struct_ColumnInfo*)pPacket;
    int nAppIndex, nTableIndex;
    ST_TableInfo *pTableInfo;

    ST_ColumnInfo stCol;
    for (int i=0; i<lLength/sizeof(Struct_ColumnInfo); i++)
    {
        memset(&stCol, 0, sizeof(stCol));
        stCol.apptype = pRec[i].apptype;//m_ByteOrder.FlipBytes(pRec[i].apptype);
        stCol.id = pRec[i].id;//m_ByteOrder.FlipBytes(pRec[i].id);
        stCol.table_id = pRec[i].table_id;//m_ByteOrder.FlipBytes(pRec[i].table_id);
        stCol.dataType = pRec[i].dataType;
        stCol.dataLength =  pRec[i].dataLength;//m_ByteOrder.FlipBytes(pRec[i].dataLength);

        strcpy(stCol.name_chn, pRec[i].name_chn);
        strcpy(stCol.name_eng, pRec[i].name_eng);
        stCol.bColor = ColorCancel;


        int nIndex = BinaryFind_TableInfo_TableID(stCol.table_id);
        if(nIndex != -1)
        {
            m_VecTableInfo.at(nIndex).veccolumninfo.push_back(stCol);
        }
    }
}

QString BuildVectorFromOpen3000::GetDataTypeByID(unsigned char datatype)
{
    QString szType="";
    switch(datatype)
    {
    case 1:szType = "CHAR";break;
    case 2:szType = "STRING";break;
    case 3:szType = "UCHAR";break;
    case 4:szType = "SHORT";break;
    case 5:szType = "INT";break;
    case 6:szType = "FLOAT";break;
    case 7:szType = "DOUBLE";break;
    case 8:szType = "DATETIME";break;
    case 9:szType = "KEYID";break;
    case 10:szType = "BINARY";break;
    case 11:szType = "TEXT";break;
    case 12:szType = "IMAGE";break;
    case 13:szType = "APPKEYID";break;
    case 14:szType = "APPID";break;
    }
    return szType;
}

void BuildVectorFromOpen3000::CreateXmlFile()
{

    ST_TableInfo *pTab;
    ST_ColumnInfo *pCol;

    QFile file("profile.xml");
    file.open(QFile::WriteOnly|QFile::Text);
    QXmlStreamWriter xml;
    xml.setAutoFormatting(true);
    xml.setDevice(&file);
    xml.writeStartDocument();
    xml.writeStartElement("Profile");

    bool bModel, bReal;

    char Characters[512];

    for(int i=0; i<m_VecTableInfo.size(); i++)
    {
        pTab = &m_VecTableInfo.at(i);
        if(pTab->bColor == ColorTable)
        {
            bModel=false; bReal = false;
            for(int n=0; n<pTab->veccolumninfo.size(); n++)
            {
                pCol = &pTab->veccolumninfo.at(n);
                if(pCol->bColor == ColorModelAndReal)
                {
                    bModel = true;
                    bReal = true;
                    break;
                }
                else if(pCol->bColor == ColorModel)
                    bModel = true;
                else if(pCol->bColor == ColorReal)
                    bReal = true;
            }

            //Real
            if(bReal == true)
            {

                xml.writeStartElement("Data");
                xml.writeAttribute("SendTag", QString::number(pTab->SendTag));
                xml.writeAttribute("TypeID", QString::number(pTab->TypeID_Real));
                xml.writeAttribute("AppNo", QString::number(pTab->AppNo));
                xml.writeAttribute("TableNo", QString::number(pTab->table_id));
                xml.writeAttribute("TimeInterval", QString::number(pTab->TimeInterval_Real));
                xml.writeAttribute("Name", QString::fromLocal8Bit(pTab->name_chn));

                memset(Characters, 0, 512);
                for(int n=0; n<pTab->veccolumninfo.size(); n++)
                {
                    pCol = &pTab->veccolumninfo.at(n);
                    if(pCol->bColor == ColorReal ||
                       pCol->bColor == ColorModelAndReal)
                    {
                        strcat(Characters, pCol->name_eng);
                        strcat(Characters, ",");
                    }
                }
                Characters[strlen(Characters)-1] = NULL;
                xml.writeCharacters(Characters);
                xml.writeEndElement();
            }

            //Model
            if(bModel == true)
            {
                xml.writeStartElement("Data");
                xml.writeAttribute("SendTag", QString::number(pTab->SendTag));
                xml.writeAttribute("TypeID", QString::number(pTab->TypeID_Model));
                xml.writeAttribute("AppNo", QString::number(pTab->AppNo));
                xml.writeAttribute("TableNo", QString::number(pTab->table_id));
                xml.writeAttribute("TimeInterval", QString::number(pTab->TimeInterval_Model));
                xml.writeAttribute("Name", QString::fromLocal8Bit(pTab->name_chn)+"_Model");

                memset(Characters, 0, 512);
                for(int n=0; n<pTab->veccolumninfo.size(); n++)
                {
                    pCol = &pTab->veccolumninfo.at(n);
                    if(pCol->bColor == ColorModel ||
                       pCol->bColor == ColorModelAndReal)
                    {
                        strcat(Characters, pCol->name_eng);
                        strcat(Characters, ",");
                    }

                }
                Characters[strlen(Characters)-1] = NULL;
                xml.writeCharacters(Characters);
                xml.writeEndElement();
            }

        }
    }

    xml.writeEndElement();
    file.close();
}


void BuildVectorFromOpen3000::CreateHFile()
{
    ofstream fModelout("./Open3000Model.h");
    ofstream fRealout("./Open3000Real.h");
    ST_TableInfo *pTab;
    ST_ColumnInfo *pCol;

    bool bModelAndReal;
    bool bModel, bReal;

    char arrTemp[128];
    fModelout<<"#ifndef Open3000Model_H\n#define Open3000Model_H\n\n\n";
    fRealout<<"#ifndef Open3000Real_H\n#define Open3000Real_H\n\n\n";

    for(int i=0; i<m_VecTableInfo.size(); i++)
    {
        bModelAndReal = false;
        pTab = &m_VecTableInfo.at(i);
        if(pTab->bColor == ColorTable)
        {
            bModel=false; bReal=false;
            for(int n=0; n<pTab->veccolumninfo.size(); n++)
            {
                pCol = &pTab->veccolumninfo.at(n);
                if(pCol->bColor == ColorModelAndReal)
                {
                    bModel = true;
                    bReal = true;
                    break;
                }
                else if(pCol->bColor == ColorModel)
                    bModel = true;
                else if(pCol->bColor == ColorReal)
                    bReal = true;
            }

            if(bReal == true)
                fRealout<<"#define "<<_strupr(pTab->name_eng)<<"_REAL "<<pTab->TypeID_Real<<"\n";

            if(bModel == true)
                fModelout<<"#define "<<_strupr(pTab->name_eng)<<"_MODEL "<<pTab->TypeID_Model<<"\n";

        }
    }
    fModelout<<"\n\n";
    fRealout<<"\n\n";


    for(int i=0; i<m_VecTableInfo.size(); i++)
    {
        pTab = &m_VecTableInfo.at(i);
        if(pTab->bColor == ColorTable)
        {

            bModel=false; bReal=false;
            for(int n=0; n<pTab->veccolumninfo.size(); n++)
            {
                pCol = &pTab->veccolumninfo.at(n);
                if(pCol->bColor == ColorModelAndReal)
                {
                    bModel = true;
                    bReal = true;
                    break;
                }
                else if(pCol->bColor == ColorModel)
                    bModel = true;
                else if(pCol->bColor == ColorReal)
                    bReal = true;
            }

            //Real
            if(bReal == true)
            {
                fRealout<<"//"<<pTab->name_chn<<" Real\n";
                fRealout<<"struct "<<pTab->name_eng<<"_Real\n{\n";

                for(int n=0; n<pTab->veccolumninfo.size(); n++)
                {
                    pCol = &pTab->veccolumninfo.at(n);

                    if(pCol->bColor == ColorReal ||
                       pCol->bColor == ColorModelAndReal)
                    {
                        memset(arrTemp, 0, 128);
                        CreateVariable(arrTemp, pCol);
                        fRealout<<arrTemp<<"\n";
                    }

                }
                fRealout<<"\n};\n\n";
            }

            //Model
            if(bModel == true)
            {
                fModelout<<"//"<<pTab->name_chn<<" Model\n";
                fModelout<<"struct "<<pTab->name_eng<<"_Model\n{\n";

                for(int n=0; n<pTab->veccolumninfo.size(); n++)
                {
                    pCol = &pTab->veccolumninfo.at(n);
                    if(pCol->bColor == ColorModel ||
                       pCol->bColor == ColorModelAndReal)
                    {
                        memset(arrTemp, 0, 128);
                        CreateVariable(arrTemp, pCol);
                        fModelout<<arrTemp<<"\n";
                    }
                }
                fModelout<<"\n};\n\n";
            }
        }
    }

    fModelout<<"#endif\n";
    fRealout<<"#endif\n";
    fModelout.close();
    fRealout.close();

}

void BuildVectorFromOpen3000::CreateVariable(char *pBuf, ST_ColumnInfo *pCol)
{
    QString szType="";
    switch(pCol->dataType)
    {
    case 1:sprintf(pBuf, "  char %s;    //%s", pCol->name_eng, pCol->name_chn);break;
    case 2:sprintf(pBuf, "  char %s[%d];    //%s", pCol->name_eng, pCol->dataLength, pCol->name_chn);break;
    case 3:sprintf(pBuf, "  unsigned char %s;    //%s", pCol->name_eng, pCol->name_chn);break;
    case 4:sprintf(pBuf, "  short %s;    //%s", pCol->name_eng, pCol->name_chn);break;
    case 5:sprintf(pBuf, "  int %s;    //%s", pCol->name_eng, pCol->name_chn);break;
    case 6:sprintf(pBuf, "  float %s;    //%s", pCol->name_eng, pCol->name_chn);break;
    case 7:sprintf(pBuf, "  double %s;    //%s", pCol->name_eng, pCol->name_chn);break;
    case 8:sprintf(pBuf, "  CTime %s;    //%s", pCol->name_eng, pCol->name_chn);break;
    case 9:szType = "KEYID";break;
    case 10:szType = "BINARY";break;
    case 11:szType = "TEXT";break;
    case 12:szType = "IMAGE";break;
    case 13:szType = "APPKEYID";break;
    case 14:szType = "APPID";break;
    }
}


void BuildVectorFromOpen3000::PhraseXmlFile(char *pFilePath)
{
    QFile file(pFilePath);
    file.open(QFile::ReadOnly|QFile::Text);
    QXmlStreamReader xml;
    xml.setDevice(&file);
//    ST_ColumnInfo *pST;
    ST_TableInfo *pTab;
    ST_ColumnInfo *pCol;

    while (!xml.atEnd())
    {
       xml.readNext();
       if (xml.isStartElement() && xml.name() == "Profile")
       {
           while (!xml.atEnd())
           {
               xml.readNext();
               if (xml.isStartElement() && xml.name()=="Data")
               {
                   int id = xml.attributes().value("TableNo").toString().toInt();
                   int nIndex = BinaryFind_TableInfo_TableID(id);

                   if(nIndex != -1)
                   {
                       pTab = &m_VecTableInfo.at(nIndex);

                       pTab->AppNo = xml.attributes().value("AppNo").toString().toInt();
                       pTab->SendTag = xml.attributes().value("SendTag").toString().toInt();

                       unsigned int color;
                       bool bModel= xml.attributes().value("Name").toString().contains("_Model");
                       if(bModel)
                       {
                           color = ColorModel;
                        //   pTab->TypeID_Model = xml.attributes().value("TypeID").toString().toInt();
                           pTab->TimeInterval_Model = xml.attributes().value("TimeInterval").toString().toInt();
                       }
                       else
                       {
                           color = ColorReal;
                         //  pTab->TypeID_Real = xml.attributes().value("TypeID").toString().toInt();
                           pTab->TimeInterval_Real = xml.attributes().value("TimeInterval").toString().toInt();
                       }

                       pTab->bColor = ColorTable;


                        QStringList  list = xml.readElementText().split(",");
                        for(int i=0; i<list.size(); i++)
                        {
                            for(int n=0; n<m_VecTableInfo.at(nIndex).veccolumninfo.size(); n++)
                            {
                                pCol = &m_VecTableInfo.at(nIndex).veccolumninfo.at(n);
                                if(list.at(i).compare(m_VecTableInfo.at(nIndex).veccolumninfo.at(n).name_eng) == 0)
                                {
                                    if(pCol->bColor == ColorCancel)
                                        pCol->bColor = color;
                                    else if(pCol->bColor == ColorModel ||
                                            pCol->bColor == ColorReal)
                                        pCol->bColor = ColorModelAndReal;
                                }
                            }
                        }
                   }
               }
           }
       }
    }
    file.close();
}
