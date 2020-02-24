#pragma once

#include "MatroxClass.h"
#include "MilImage.h"
#include "Utility/Defines.h"
#include <atlcoll.h>

struct EdgeFindResultInfo
{
	TRect m_rect;
	double m_lfAngle;
};

typedef CAtlList<EdgeFindResultInfo> EdgeFindResultList;

class MATROXCLASS CMilEdgeFinder
{
public:
	CMilEdgeFinder();
	~CMilEdgeFinder();

protected:
	MIL_ID m_context;
	MIL_ID m_result;

	BOOL m_bFind;
	EdgeFindResultList m_resultList;

public:
	BOOL Alloc();
	BOOL Calculate(CMilImage* pMilImage);

	// Result
	EdgeFindResultList* GetResultList(){ return &m_resultList; }
};
