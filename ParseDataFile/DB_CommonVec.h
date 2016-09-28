// DB_CommonVec.h: interface for the DB_CommonVec class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DB_COMMONVEC_H__9A90078C_9CA1_4A2E_815E_58CBBCB38EC3__INCLUDED_)
#define AFX_DB_COMMONVEC_H__9A90078C_9CA1_4A2E_815E_58CBBCB38EC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DB_CommonVec  
{
public:
	DB_CommonVec();
	virtual ~DB_CommonVec();
public:
	static BOOL SortVoltageByVltyID(VL_TYPE_Model  a, VL_TYPE_Model  b);
	void RefreshModel_Voltage(char *pData, int bufSize);
	float BinaryFindVoltageBase(int vlty_id);
	typedef std::vector<VL_TYPE_Model> VEC_MODEL_VL_TYPE;
	VEC_MODEL_VL_TYPE m_Vec_VlType;
};

#endif // !defined(AFX_DB_COMMONVEC_H__9A90078C_9CA1_4A2E_815E_58CBBCB38EC3__INCLUDED_)
