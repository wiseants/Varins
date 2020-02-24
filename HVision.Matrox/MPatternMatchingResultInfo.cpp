#include "stdafx.h"
#include "MPatternMatchingResultInfo.h"

using namespace HVision::Matrox;

MPatternMatchingResultInfo::MPatternMatchingResultInfo()
{
	m_pPatternMatchingResultInfo = new PatternMatchingResultInfo();
}

MPatternMatchingResultInfo::~MPatternMatchingResultInfo()
{
	this->!MPatternMatchingResultInfo();
}

MPatternMatchingResultInfo::!MPatternMatchingResultInfo()
{
	if (m_pPatternMatchingResultInfo != nullptr)
	{
		m_pPatternMatchingResultInfo = new PatternMatchingResultInfo();
	}

	m_pPatternMatchingResultInfo = nullptr;
}

MPatternMatchingResultInfo::MPatternMatchingResultInfo(PatternMatchingResultInfo& patternMatchingResultInfo) : MPatternMatchingResultInfo()
{
	m_pPatternMatchingResultInfo->m_lfAngle = patternMatchingResultInfo.m_lfAngle;
	m_pPatternMatchingResultInfo->m_lfScore = patternMatchingResultInfo.m_lfScore;
	m_pPatternMatchingResultInfo->m_lfScale = patternMatchingResultInfo.m_lfScale;
	m_pPatternMatchingResultInfo->m_center_x = patternMatchingResultInfo.m_center_x;
	m_pPatternMatchingResultInfo->m_center_y = patternMatchingResultInfo.m_center_y;
}

PatternMatchingResultInfo* MPatternMatchingResultInfo::GetUInstance()
{
	return m_pPatternMatchingResultInfo;
}

double MPatternMatchingResultInfo::Angle::get()
{
	return m_pPatternMatchingResultInfo->m_lfAngle;
}
void MPatternMatchingResultInfo::Angle::set(double value)
{
	m_pPatternMatchingResultInfo->m_lfAngle = value;
}

double MPatternMatchingResultInfo::Score::get()
{
	return m_pPatternMatchingResultInfo->m_lfScore;
}

void MPatternMatchingResultInfo::Score::set(double value)
{
	m_pPatternMatchingResultInfo->m_lfScore = value;
}

double MPatternMatchingResultInfo::Scale::get()
{
	return m_pPatternMatchingResultInfo->m_lfScale;
}

void MPatternMatchingResultInfo::Scale::set(double value)
{
	m_pPatternMatchingResultInfo->m_lfScale = value;
}

Point^ MPatternMatchingResultInfo::CenterPt::get()
{
	return gcnew Point(m_pPatternMatchingResultInfo->m_center_x, m_pPatternMatchingResultInfo->m_center_y);
}

void MPatternMatchingResultInfo::CenterPt::set(Point^ value)
{
	m_pPatternMatchingResultInfo->m_center_x = value->X;
	m_pPatternMatchingResultInfo->m_center_y = value->Y;
}