#include "stdafx.h"
#include "MCircleFindResultInfo.h"

using namespace HVision::Matrox;

MCircleFindResultInfo::MCircleFindResultInfo()
{
	m_pCircleFindResultInfo = new CircleFindResultInfo();
}

MCircleFindResultInfo::~MCircleFindResultInfo()
{
	this->!MCircleFindResultInfo();
}

MCircleFindResultInfo::!MCircleFindResultInfo()
{
	if (m_pCircleFindResultInfo != nullptr)
	{
		delete m_pCircleFindResultInfo;
	}

	m_pCircleFindResultInfo = nullptr;
}

MCircleFindResultInfo::MCircleFindResultInfo(CircleFindResultInfo& circleFindResultInfo)
{
	m_pCircleFindResultInfo = new CircleFindResultInfo();
	m_pCircleFindResultInfo->m_rect = circleFindResultInfo.m_rect;
	m_pCircleFindResultInfo->m_lfScore = circleFindResultInfo.m_lfScore;
}

System::Drawing::Rectangle^ MCircleFindResultInfo::GetRect()
{
	TRect rect = m_pCircleFindResultInfo->m_rect;
	return *new System::Drawing::Rectangle(rect.left, rect.top, rect.right, rect.bottom);
}

double MCircleFindResultInfo::GetScore()
{
	return m_pCircleFindResultInfo->m_lfScore;
}