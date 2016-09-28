// FileBroker.h: interface for the FileBroker class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEBROKER_H__CCABE399_4274_43FD_B8B7_F97BFC7D2C4E__INCLUDED_)
#define AFX_FILEBROKER_H__CCABE399_4274_43FD_B8B7_F97BFC7D2C4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class FileBroker  
{
public:
	FileBroker();
	virtual ~FileBroker();

};
void initializeFileBroker();
void systemTimeToFilePost(char *post);
BOOL tryAccessFile(const char* fname, const char* time, char* fAccessed, int size);
BOOL runCtgAnalyse(time_t tmIntime);
void DeleteOldFile(char* pszFileName,char* type);

#endif // !defined(AFX_FILEBROKER_H__CCABE399_4274_43FD_B8B7_F97BFC7D2C4E__INCLUDED_)
