// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__73B66106_6A2A_4038_B687_3E63C5A56A1D__INCLUDED_)
#define AFX_STDAFX_H__73B66106_6A2A_4038_B687_3E63C5A56A1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <MATH.H>
#include <algorithm>
#include <vector>
#include <direct.h>
#include <sys/types.h>
#include <sys/stat.h>



#pragma comment(lib, "dbapi.lib")

#include "visualdb.h"
#include "USERAPI.H"
#include "dbapi.h"
#include "publicpw.h"
#include "PublicAvcDef.h"
//#include "OPEN3000.h"
#include "PublicAvcDef.h"

#include "CommonDefine.h"
#include "Open3000Model.h"
#include "Open3000Real.h"
#include "Utils.h"
#include "RealSearth.h"




void GetDevName(DWORD id, BYTE devtype, char* devname);	//获取设备名称
void GetIDByName(char* devname, BYTE devtype, DWORD& id);			//获取设备ID	


//=======================定值类处理函数====================================
typedef struct _AVCLimit
{
	_AVCLimit(){memset(this, 0, sizeof(_AVCLimit));};
	AVCLimitParam m_limit[7];
}AVCLimit;

bool GetVolLimit(CPtrArray& limitarray, DWORD pltyp, float* flimit, float vl, CTime curtm, bool isgate=false);
bool LoadSystemLimit(CPtrArray& syslimit);			//加载定值定义
inline void ClearSysLimit(CPtrArray& m_syslimit)		//清除定值
{
	int count = m_syslimit.GetSize();
	for(int i=0; i<count; i++)
	{
		AVCLimit* ptmp = (AVCLimit*)m_syslimit.GetAt(i);
		if(ptmp!=NULL)
			delete ptmp;
	}
	
	m_syslimit.RemoveAll();
};
//=======================定值类处理函数====================================

void GetDevMeasureName(SEMEAS_RTNET_EMS_Model* pmeas, char* measinfo);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__73B66106_6A2A_4038_B687_3E63C5A56A1D__INCLUDED_)
