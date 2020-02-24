#include "stdafx.h"
#include "MilPatternFind.h"

using namespace HVision::Matrox;

MilPatternFind::MilPatternFind()
{
	m_pMilPatternFind = new CMilPatternFind();
}

MilPatternFind::~MilPatternFind()
{
	this->!MilPatternFind();
}

MilPatternFind::!MilPatternFind()
{
	if (m_pMilPatternFind != nullptr)
	{
		delete m_pMilPatternFind;
	}

	m_pMilPatternFind != nullptr;
}

CMilPatternFind* MilPatternFind::GetUInstance()
{
	return m_pMilPatternFind;
}

bool MilPatternFind::Alloc(MilImage^ milImage)
{
	return m_pMilPatternFind->Alloc(milImage->GetUInstance());
}

void MilPatternFind::Free()
{
	m_pMilPatternFind->Free();
}

bool MilPatternFind::Calculate(MilImage^ milImage)
{
	return m_pMilPatternFind->Calculate(milImage->GetUInstance());
}

void MilPatternFind::SetParameter(int lfOffsetX, int lfOffsetY, int lfSizeX, int lfSizeY)
{
	m_pMilPatternFind->SetParameter(lfOffsetX, lfOffsetY, lfSizeX, lfSizeY);
}

void MilPatternFind::SetScore(long nScore)
{
	m_pMilPatternFind->SetScore(nScore);
}

void MilPatternFind::SetSearchingNumber(long nNumber)
{
	m_pMilPatternFind->SetSearchingNumber(nNumber);
}

void MilPatternFind::SetSearchSpeed(long nLevel)
{
	m_pMilPatternFind->SetSearchSpeed(nLevel);
}

void MilPatternFind::SetFilterLevel(long nFilterLevel)
{
	m_pMilPatternFind->SetFilterLevel(nFilterLevel);
}

void MilPatternFind::SetAccuracy(int nAccuracy)
{
	m_pMilPatternFind->SetAccuracy(nAccuracy);
}

void MilPatternFind::SetBasePosition(long nPixelCenterX, long nPixelCenterY)
{
	m_pMilPatternFind->SetBasePosition(nPixelCenterX, nPixelCenterY);
}

void MilPatternFind::SetAngle(bool angleMode, double lfRange, double angleAccuracy, double interpolationMode)
{
	m_pMilPatternFind->SetAngle(angleMode, lfRange, angleAccuracy, interpolationMode);
}

List<MPatternMatchingResultInfo^>^ MilPatternFind::GetResultList()
{
	List<MPatternMatchingResultInfo^>^ resultInfoList = gcnew List<MPatternMatchingResultInfo ^>();

	PatternMatchingResultList* pResultList = m_pMilPatternFind->GetResultList();
	if (pResultList == nullptr || pResultList->GetCount() <= 0)
	{
		return resultInfoList;
	}

	POSITION pos = pResultList->GetHeadPosition();
	while (pos != nullptr)
	{
		PatternMatchingResultInfo& resultInfo = pResultList->GetNext(pos);
		resultInfoList->Add(gcnew MPatternMatchingResultInfo(resultInfo));
	}

	return resultInfoList;
}

void MilPatternFind::SetDontCareImage(MilImage^ dontcareImg)
{
	m_pMilPatternFind->SetDontCareImage(dontcareImg->GetUInstance());
}

long MilPatternFind::GetResultMilID()
{
	return m_pMilPatternFind->GetResultMilID();
}