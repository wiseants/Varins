// MilObject.h: interface for the MilObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILOBJECT_H__8BACE693_DC7F_4D99_8AE5_053C8A282C5E__INCLUDED_)
#define AFX_MILOBJECT_H__8BACE693_DC7F_4D99_8AE5_053C8A282C5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <mil.h>
#include "MatroxClass.h"

class MATROXCLASS MilObject  
{
public:
	MilObject() : m_MilId(M_NULL) {}
	MilObject(MIL_ID mi) : m_MilId(mi) {}
	virtual ~MilObject() {}
	operator MIL_ID() { return m_MilId; }
	MIL_ID GetMilId() const { return m_MilId; }
	bool IsAllocated() const { return m_MilId != M_NULL; }
	void Attach(MIL_ID mi) { m_MilId = mi; }
	MIL_ID Detach() { MIL_ID old = m_MilId; m_MilId = M_NULL; return old; }
	virtual void Free() = 0;

protected:
	MIL_ID m_MilId;
};

#endif // !defined(AFX_MILOBJECT_H__8BACE693_DC7F_4D99_8AE5_053C8A282C5E__INCLUDED_)
