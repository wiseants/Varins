#include "stdafx.h"
#include "MilCircleMarker.h"


MilCircleMarker::MilCircleMarker()
{
	m_pMilCircleMarker = new CMilCircleMarker();
}

MilCircleMarker::~MilCircleMarker()
{
	this->!MilCircleMarker();
}

MilCircleMarker::!MilCircleMarker()
{
	if (m_pMilCircleMarker != nullptr)
	{
		delete m_pMilCircleMarker;
	}

	m_pMilCircleMarker = nullptr;
}

bool MilCircleMarker::Alloc()
{
	return m_pMilCircleMarker->Alloc();
}

void MilCircleMarker::Free()
{
	m_pMilCircleMarker->Free();
}

bool MilCircleMarker::Calculate(MilImage^ milImage)
{
	return m_pMilCircleMarker->Calculate(milImage->GetUInstance());
}

void MilCircleMarker::SetScore()
{
	m_pMilCircleMarker->SetScore();
}

void MilCircleMarker::SetSearchingNumber()
{
	m_pMilCircleMarker->SetSearchingNumber(1);
}

void MilCircleMarker::SetSearchingNumber(long nNumber)
{
	m_pMilCircleMarker->SetSearchingNumber(nNumber);
}

void MilCircleMarker::SetRadius(double lfRadius, double nMinScale, double nMaxScale)
{
	m_pMilCircleMarker->SetRadius(lfRadius, nMinScale, nMaxScale);
}

void MilCircleMarker::SetPositiveDirection()
{
	m_pMilCircleMarker->SetPositiveDirection();
}

void MilCircleMarker::SetNegativeDirection()
{
	m_pMilCircleMarker->SetNegativeDirection();
}

void MilCircleMarker::SetAnyDirection()
{
	m_pMilCircleMarker->SetAnyDirection();
}

void MilCircleMarker::SetCenter(double centerX, double centerY)
{
	m_pMilCircleMarker->SetCenter(centerX, centerY);
}

List<MCircleMarkerResultInfo^>^ MilCircleMarker::GetResultList()
{
	List<MCircleMarkerResultInfo^>^ resultList = gcnew List<MCircleMarkerResultInfo^>();

	CircleMarkerResultList* pCircleMarkerResultList = m_pMilCircleMarker->GetResultList();
	if (pCircleMarkerResultList == nullptr || pCircleMarkerResultList->GetCount() <= 0)
	{
		return resultList;
	}

	POSITION pos = pCircleMarkerResultList->GetHeadPosition();
	while (pos != nullptr)
	{
		CircleMarkerResultInfo& circleMarkerResultInfo = pCircleMarkerResultList->GetNext(pos);
		resultList->Add(gcnew MCircleMarkerResultInfo(circleMarkerResultInfo));
	}

	return resultList;
}
