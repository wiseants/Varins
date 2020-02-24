#pragma once

#include "MatroxClass.h"
#include "MilImage.h"
#include "Utility/Defines.h"
#include <atlcoll.h>

struct MATROXCLASS CircleFindResultInfo
{
	TRect m_rect;
	double m_lfScore;
};

typedef CAtlList<CircleFindResultInfo> CircleFindResultList;

class MATROXCLASS CMilCircleFind : public MilObject
{
public:
	CMilCircleFind();
	~CMilCircleFind();

	BOOL Alloc();
	void Free();

	BOOL Calculate(CMilImage* pMilImage);

	// Parameter
	void SetScore(long nScore);
	void SetSearchingNumber(long nNumber);
	void SetSearchLevel(long nLevel);
	void SetFilterLevel(long nFilterLevel);
	void SetRadius(double lfRadius);
	void SetMinScale(double nMinScale);
	void SetMaxScale(double nMaxScale);

	CircleFindResultList* GetResultList(){ return &m_resultList; }
private:
	MIL_ID m_milResult;

	CircleFindResultList m_resultList;
};
