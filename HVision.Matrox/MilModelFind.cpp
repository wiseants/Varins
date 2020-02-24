#include "stdafx.h"
#include "MilModelFind.h"

using namespace HVision::Matrox;

MilModelFind::MilModelFind()
{
	m_pMilModelFind = new CMilModelFind();
}

MilModelFind::~MilModelFind()
{
	this->!MilModelFind();
}

MilModelFind::!MilModelFind()
{
	if (m_pMilModelFind != nullptr)
	{
		delete m_pMilModelFind;
	}
	
	m_pMilModelFind = nullptr;
}

CMilModelFind* MilModelFind::GetUInstance()
{
	return m_pMilModelFind;
}

bool MilModelFind::Alloc(MilImage^ milImage)
{
	return m_pMilModelFind->Alloc(milImage->GetUInstance());
}

void MilModelFind::Free()
{
	m_pMilModelFind->Free();
}

bool MilModelFind::Calculate(MilImage^ milImage)
{
	return m_pMilModelFind->Calculate(milImage->GetUInstance());
}

void MilModelFind::SetParameter(double lfOffsetX, double lfOffsetY, double lfSizeX, double lfSizeY)
{
	m_pMilModelFind->SetParameter(lfOffsetX, lfOffsetY, lfSizeX, lfSizeY);
}

void MilModelFind::SearchInnerPosition()
{
	m_pMilModelFind->SearchInnerPosition();
}

void MilModelFind::SetScore(long nScore)
{
	m_pMilModelFind->SetScore(nScore);
}

void MilModelFind::SetSearchingNumber(long nNumber)
{
	m_pMilModelFind->SetSearchingNumber(nNumber);
}

void MilModelFind::SetSearchSpeed(long nLevel)
{
	m_pMilModelFind->SetSearchSpeed(nLevel);
}

void MilModelFind::SetFilterLevel(long nFilterLevel)
{
	m_pMilModelFind->SetFilterLevel(nFilterLevel);
}

void MilModelFind::SetAngle(bool bSearchAngle) //  double lfAngle = 360
{
	m_pMilModelFind->SetAngle(bSearchAngle, 360);
}

void MilModelFind::SetAccuracy(double lfAccuracy)
{
	m_pMilModelFind->SetAccuracy(lfAccuracy);
}

void MilModelFind::SetBasePosition(long nPixelCenterX, long nPixelCenterY)
{
	m_pMilModelFind->SetBasePosition(nPixelCenterX, nPixelCenterY);
}

List<MModelFindResultInfo^>^ MilModelFind::GetResultList()
{
	List<MModelFindResultInfo^>^ resultInfoList = gcnew List<MModelFindResultInfo ^>();

	ModelFindResultList* pResultList = m_pMilModelFind->GetResultList();
	if (pResultList == nullptr || pResultList->GetCount() <= 0)
	{
		return resultInfoList;
	}

	POSITION pos = pResultList->GetHeadPosition();
	while (pos != nullptr)
	{
		ModelFindResultInfo& resultInfo = pResultList->GetNext(pos);
		resultInfoList->Add(gcnew MModelFindResultInfo(resultInfo));
	}

	return resultInfoList;
}

void MilModelFind::AlignmentFindImage(MilImage^ targetImage, int nRstIndex)
{
	m_pMilModelFind->AlignmentFindImage(targetImage->GetUInstance(), nRstIndex);
}

void MilModelFind::SetDontCareImage(MilImage^ dontcareImg)
{
	m_pMilModelFind->SetDontCareImage(dontcareImg->GetUInstance());
}