#include "stdafx.h"
#include "MModelOffsetInfo.h"

using namespace HVision::Matrox;

MModelOffsetInfo::MModelOffsetInfo()
{
	m_pModelOffsetInfo = new ModelOffsetInfo();
}

MModelOffsetInfo::!MModelOffsetInfo()
{
	this->!MModelOffsetInfo();
}

MModelOffsetInfo::~MModelOffsetInfo()
{
	if (m_pModelOffsetInfo != nullptr)
	{
		delete m_pModelOffsetInfo;
	}

	m_pModelOffsetInfo = nullptr;
}

ModelOffsetInfo* MModelOffsetInfo::GetUInstance()
{
	return m_pModelOffsetInfo;
}
