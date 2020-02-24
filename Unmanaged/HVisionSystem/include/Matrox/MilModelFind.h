#pragma once

#include "MatroxClass.h"
#include "MilImage.h"
#include "Utility/Defines.h"

struct ModelFindResultInfo
{
	TRect m_rect;
	double m_lfAngle;
	double m_lfScore;
	double m_lfScale;
	double m_center_x;
	double m_center_y;
};

typedef CAtlList<ModelFindResultInfo> ModelFindResultList;

class MATROXCLASS CMilModelFind : public MilObject
{
public:
	CMilModelFind();
	~CMilModelFind();

	BOOL Alloc(CMilImage* pModImage);
	void Free();

	BOOL Calculate(CMilImage* pMilImage);

	void SetParameter(double lfOffsetX = -1, double lfOffsetY = -1, double lfSizeX = -1, double lfSizeY = -1);
	void SearchInnerPosition();

	void SetScore(long nScore);
	void SetSearchingNumber(long nNumber);
	void SetSearchSpeed(long nLevel);
	void SetFilterLevel(long nFilterLevel);
	void SetAngle(BOOL bSearchAngle, double lfAngle = 360);

	void SetAccuracy(double lfAccuracy);
	void SetBasePosition(long nPixelCenterX, long nPixelCenterY);

	ModelFindResultList* GetResultList(){ return &m_resultList; }
	void AlignmentFindImage(CMilImage* pTargetImage, int nRstIndex);
	void SetDontCareImage(CMilImage* pDontcareImg);
private:
	MIL_ID m_milResult;
	CMilImage* m_pModImage;

	ModelFindResultList m_resultList;
};
