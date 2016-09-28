// Utils.h: interface for the Utils class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTILS_H__8BDAAC47_FAD9_4140_979E_6D38E626E898__INCLUDED_)
#define AFX_UTILS_H__8BDAAC47_FAD9_4140_979E_6D38E626E898__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

void FormatDate(SYSTEMTIME& time, char* sz);
void FormatTime(SYSTEMTIME& time, char* sz);
char* trim_whites(char *s);
char* c_strncpy(char* dest, const char* src, int size);
void ErrMessage(DWORD error);
void splitFName(const char* fName, char* dir, char* basename);
//void splitBaseName(const char* baseName,  char* name, char* postfix);
char* basename(char* fullName);
char* getExePath(char* path);

BOOL findFile(const char* fname, char* finded);
BOOL tryAccessFile(const char* fnameLocate, const char* time, char* fAccessed, int size);

#endif // !defined(AFX_UTILS_H__8BDAAC47_FAD9_4140_979E_6D38E626E898__INCLUDED_)
