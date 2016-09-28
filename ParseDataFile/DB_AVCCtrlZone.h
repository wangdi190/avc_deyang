// DB_AVCCtrlZone.h: interface for the DB_AVCCtrlZone class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_AVCCTRLZONE_H__279B98A5_735C_4747_895F_C217ABBBF686__INCLUDED_)
#define AFX_DB_AVCCTRLZONE_H__279B98A5_735C_4747_895F_C217ABBBF686__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_AVCCtrlZone  
{
public:
	DB_AVCCtrlZone();
	virtual ~DB_AVCCtrlZone();
	void RefreshModel(char* pData, int bufSize);

};

#endif // !defined(AFX_DB_AVCCTRLZONE_H__279B98A5_735C_4747_895F_C217ABBBF686__INCLUDED_)
