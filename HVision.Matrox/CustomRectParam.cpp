#include "stdafx.h"
#include "CustomRectParam.h"

using namespace HVision::Matrox;

CustomRectParam::CustomRectParam()
{
	m_pCustomRectParam = new stCustomRectParam();
}

CustomRectParam::~CustomRectParam()
{
	this->!CustomRectParam();
}

CustomRectParam::!CustomRectParam()
{
	if (m_pCustomRectParam != nullptr)
	{
		delete m_pCustomRectParam;
	}

	m_pCustomRectParam = nullptr;
}

CustomRectParam::CustomRectParam(stCustomRectParam& customRectParam) : CustomRectParam()
{
	m_pCustomRectParam->nType = customRectParam.nType;
	m_pCustomRectParam->szSize = customRectParam.szSize;
}

stCustomRectParam* CustomRectParam::GetUInstance()
{
	return m_pCustomRectParam;
}

CustomRectType CustomRectParam::Type::get()
{
	return (CustomRectType)m_pCustomRectParam->nType;
}

void CustomRectParam::Type::set(CustomRectType value)
{
	m_pCustomRectParam->nType = (int)value;
}

Size^ CustomRectParam::RectSize::get()
{
	return gcnew Size(m_pCustomRectParam->szSize.cx, m_pCustomRectParam->szSize.cy);
}

void CustomRectParam::RectSize::set(Size^ value)
{
	m_pCustomRectParam->szSize.cx = value->Width;
	m_pCustomRectParam->szSize.cy = value->Height;
}

void CustomRectParam::operator = (CustomRectParam^ dstParam)
{
	Type = dstParam->Type;
	RectSize = dstParam->RectSize;
}