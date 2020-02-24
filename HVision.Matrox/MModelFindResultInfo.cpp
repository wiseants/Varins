#include "stdafx.h"
#include "MModelFindResultInfo.h"

using namespace HVision::Matrox;

MModelFindResultInfo::MModelFindResultInfo()
{
	m_pModelFindResultInfo = new ModelFindResultInfo();
}

MModelFindResultInfo::~MModelFindResultInfo()
{
	this->!MModelFindResultInfo();
}

MModelFindResultInfo::!MModelFindResultInfo()
{
	if (m_pModelFindResultInfo != nullptr)
	{
		delete m_pModelFindResultInfo;
	}

	m_pModelFindResultInfo = nullptr;
}

MModelFindResultInfo::MModelFindResultInfo(ModelFindResultInfo& modelFindResultInfo) : MModelFindResultInfo()
{
	m_pModelFindResultInfo->m_lfAngle = modelFindResultInfo.m_lfAngle;
	m_pModelFindResultInfo->m_lfScore = modelFindResultInfo.m_lfScore;
	m_pModelFindResultInfo->m_lfScale = modelFindResultInfo.m_lfScale;
	m_pModelFindResultInfo->m_center_x = modelFindResultInfo.m_center_x;
	m_pModelFindResultInfo->m_center_y = modelFindResultInfo.m_center_y;
}

ModelFindResultInfo* MModelFindResultInfo::GetUInstance()
{
	return m_pModelFindResultInfo;
}

double MModelFindResultInfo::Angle::get()
{
	return m_pModelFindResultInfo->m_lfAngle;
}
void MModelFindResultInfo::Angle::set(double value)
{
	m_pModelFindResultInfo->m_lfAngle = value;
}

double MModelFindResultInfo::Score::get()
{
	return m_pModelFindResultInfo->m_lfScore;
}

void MModelFindResultInfo::Score::set(double value)
{
	m_pModelFindResultInfo->m_lfScore = value;
}

double MModelFindResultInfo::Scale::get()
{
	return m_pModelFindResultInfo->m_lfScale;
}

void MModelFindResultInfo::Scale::set(double value)
{
	m_pModelFindResultInfo->m_lfScale = value;
}

Point^ MModelFindResultInfo::CenterPt::get()
{
	return gcnew Point(m_pModelFindResultInfo->m_center_x, m_pModelFindResultInfo->m_center_y);
}

void MModelFindResultInfo::CenterPt::set(Point^ value)
{
	m_pModelFindResultInfo->m_center_x = value->X;
	m_pModelFindResultInfo->m_center_y = value->Y;
}