#pragma once

#include "MatroxClass.h"
#include "MilImage.h"
#include "Utility/Defines.h"
#include <atlcoll.h>

struct MATROXCLASS CircleMarkerResultInfo
{
	TRect m_rect;
	double m_lfScore;
};

typedef CAtlList<CircleMarkerResultInfo> CircleMarkerResultList;

class MATROXCLASS CMilCircleMarker : public MilObject
{
public:
	CMilCircleMarker();
	~CMilCircleMarker();

	BOOL Alloc();
	void Free();

	BOOL Calculate(CMilImage* pMilImage);

	// Parameter
	void SetScore();
	void SetSearchingNumber(long nNumber = 1);
	void SetRadius(double lfRadius, double nMinScale, double nMaxScale);
	void SetPositiveDirection();
	void SetNegativeDirection();
	void SetAnyDirection();
	void SetCenter(double centerX, double centerY);

	CircleMarkerResultList* GetResultList(){ return &m_resultList; }

private:
	MIL_ID m_CircleMarker;

	CircleMarkerResultList m_resultList;
};
