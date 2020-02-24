// MilCode.h: interface for the MilCode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILCODE_H__9CAB25C0_1EC4_44FC_9FA4_88D947BCA3A6__INCLUDED_)
#define AFX_MILCODE_H__9CAB25C0_1EC4_44FC_9FA4_88D947BCA3A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MATROXCLASS.h"
#include "MilBuffer.h"

class MATROXCLASS CMilCode : public MilObject  
{
private:
	MIL_ID m_resultId;
public:
	void Alloc(long CodeType, long ControlFlag);
	virtual void Free();

	void SetThreshold(long threshold);
	void SetSearchAngle(long neg, long pos);
	void SetSpeed(long speed);

	long Read(CMilBuffer* pImage);
	void GetResult(CString& result);
};

#endif // !defined(AFX_MILCODE_H__9CAB25C0_1EC4_44FC_9FA4_88D947BCA3A6__INCLUDED_)
