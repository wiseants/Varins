#include "stdafx.h"
#include "MilCircleFind.h"

using namespace HVision::Matrox;

MilCircleFind::MilCircleFind()
{
	m_pMilCircleFind = new CMilCircleFind();
}

MilCircleFind::~MilCircleFind()
{
	this->!MilCircleFind();
}

MilCircleFind::!MilCircleFind()
{
	if (m_pMilCircleFind != nullptr)
	{
		delete m_pMilCircleFind;
	}

	m_pMilCircleFind = nullptr;
}

BOOL MilCircleFind::Alloc()
{
	return m_pMilCircleFind->Alloc();
}

void MilCircleFind::Free()
{
	m_pMilCircleFind->Free();
}

BOOL MilCircleFind::Calculate(MilImage^ milImage)
{
	return m_pMilCircleFind->Calculate(milImage->GetUInstance());
}

void MilCircleFind::SetScore(long nScore)
{
	m_pMilCircleFind->SetScore(nScore);
}

void MilCircleFind::SetSearchingNumber(long nNumber)
{
	m_pMilCircleFind->SetSearchingNumber(nNumber);
}

void MilCircleFind::SetSearchLevel(long nLevel)
{
	m_pMilCircleFind->SetFilterLevel(nLevel);
}

void MilCircleFind::SetFilterLevel(long nFilterLevel)
{
	m_pMilCircleFind->SetFilterLevel(nFilterLevel);
}

void MilCircleFind::SetRadius(double lfRadius)
{
	m_pMilCircleFind->SetRadius(lfRadius);
}

void MilCircleFind::SetMinScale(double nMinScale)
{
	m_pMilCircleFind->SetMinScale(nMinScale);
}

void MilCircleFind::SetMaxScale(double nMaxScale)
{
	m_pMilCircleFind->SetMaxScale(nMaxScale);
}

List<MCircleFindResultInfo^>^ MilCircleFind::GetResultList()
{
	List<MCircleFindResultInfo^>^ resultList = gcnew List<MCircleFindResultInfo^>();

	CircleFindResultList* pCircleFindResultList = m_pMilCircleFind->GetResultList();
	if (pCircleFindResultList == nullptr || pCircleFindResultList->GetCount() <= 0)
	{
		return resultList;
	}
	
	POSITION pos = pCircleFindResultList->GetHeadPosition();
	while (pos != nullptr)
	{
		CircleFindResultInfo& circleFindResultInfo = pCircleFindResultList->GetNext(pos);
		resultList->Add(gcnew MCircleFindResultInfo(circleFindResultInfo));
	}

	return resultList;
}
