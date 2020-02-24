#include "stdafx.h"
#include "MCircleMarkerResultInfo.h"

using namespace HVision::Matrox;

MCircleMarkerResultInfo::MCircleMarkerResultInfo()
{
	m_pCircleMarkerResultInfo = new CircleMarkerResultInfo();
}

MCircleMarkerResultInfo::~MCircleMarkerResultInfo()
{
	this->!MCircleMarkerResultInfo();
}

MCircleMarkerResultInfo::!MCircleMarkerResultInfo()
{
	if (m_pCircleMarkerResultInfo != nullptr)
	{
		delete m_pCircleMarkerResultInfo;
	}

	m_pCircleMarkerResultInfo = nullptr;
}

MCircleMarkerResultInfo::MCircleMarkerResultInfo(CircleMarkerResultInfo& circleMarkerResultInfo)
{
	m_pCircleMarkerResultInfo = new CircleMarkerResultInfo();
	m_pCircleMarkerResultInfo->m_rect = circleMarkerResultInfo.m_rect;
	m_pCircleMarkerResultInfo->m_lfScore = circleMarkerResultInfo.m_lfScore;
}

System::Drawing::Rectangle^ MCircleMarkerResultInfo::GetRect()
{
	TRect rect = m_pCircleMarkerResultInfo->m_rect;
	return *new System::Drawing::Rectangle(rect.left, rect.top, rect.right, rect.bottom);
}

double MCircleMarkerResultInfo::GetScore()
{
	return m_pCircleMarkerResultInfo->m_lfScore;
}