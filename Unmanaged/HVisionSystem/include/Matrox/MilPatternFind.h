#pragma once

#include "MatroxClass.h"
#include "MilImage.h"
#include "Utility/Defines.h"

struct PatternMatchingResultInfo
{
	TRect m_rect;
	double m_lfAngle;
	double m_lfScore;
	double m_lfScale;

	////////// by sub ////////
	double m_center_x;
	double m_center_y;
};

typedef CAtlList<PatternMatchingResultInfo> PatternMatchingResultList;

class MATROXCLASS CMilPatternFind : public MilObject
{
public:
	CMilPatternFind();
	~CMilPatternFind();

	BOOL Alloc(CMilImage* pModImage);
	void Free();

	BOOL Calculate(CMilImage* pMilImage);

	void SetParameter(int lfOffsetX = -1, int lfOffsetY = -1, int lfSizeX = -1, int lfSizeY = -1);

	void SetScore(long nScore);
	void SetSearchingNumber(long nNumber);
	void SetSearchSpeed(long nLevel);
	void SetFilterLevel(long nFilterLevel);

	void SetAccuracy(int nAccuracy);
	void SetBasePosition(long nPixelCenterX, long nPixelCenterY);

	void SetAngle(BOOL angleMode = TRUE, double lfRange = 10, double angleAccuracy = 0.25, double interpolationMode = M_BILINEAR);

	PatternMatchingResultList* GetResultList(){ return &m_resultList; }
	void SetDontCareImage(CMilImage* pDontcareImg);
	MIL_ID GetResultMilID() const { return m_milResult; }
private:
	MIL_ID m_milResult;
	CMilImage* m_pModImage;

	PatternMatchingResultList m_resultList;
};
