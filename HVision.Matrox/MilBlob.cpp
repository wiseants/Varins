#include "stdafx.h"
#include "MilBlob.h"
#include "MBlobBox.h"

using namespace HVision::Matrox;

MilBlob::MilBlob()
{
	m_pMilBlob = new CMilBlob();
}

MilBlob::~MilBlob()
{
	this->!MilBlob();
}

MilBlob::!MilBlob()
{
	if (m_pMilBlob != nullptr)
	{
		delete m_pMilBlob;
	}

	m_pMilBlob = nullptr;
}

void MilBlob::Alloc()
{
	m_pMilBlob->Alloc();
}

void MilBlob::SetSrcImage(MilImage^ milImage)
{
	m_pMilBlob->SetSrcImage(milImage->GetUInstance());
}

void MilBlob::SetDestImage(MilImage^ milImage)
{
	m_pMilBlob->SetDestImage(milImage->GetUInstance());
}

void MilBlob::SelectFeature(long featureList)
{
	m_pMilBlob->SelectFeature(featureList);
}

void MilBlob::Calculate()
{
	m_pMilBlob->Calculate();
}

long MilBlob::GetLabel(long xPos, long yPos)
{
	return m_pMilBlob->GetLabel(xPos, yPos);
}

BOOL MilBlob::IsAllocated()
{
	return m_pMilBlob->IsAllocated();
}

void MilBlob::FillHoles(long procMode)
{
	m_pMilBlob->FillHoles(procMode);
}

void MilBlob::ExtractHoles(long procMode)
{
	m_pMilBlob->ExtractHoles(procMode);
}

void MilBlob::Fill(long criterion, long value)
{
	m_pMilBlob->Fill(criterion, value);
}

void MilBlob::Select(long Operation, long Feature, long Condition, double CondLow, double CondHigh)
{
	m_pMilBlob->Select(Operation, Feature, Condition, CondLow, CondHigh);
}

MIL_INT MilBlob::GetNumber()
{
	return m_pMilBlob->GetNumber();
}

void MilBlob::GetBlobBoxs(cli::array<MBlobBox^>^ arrayBlobBox)
{
	VecBlobBox& vecBlobBox = *new VecBlobBox();
	for each (MBlobBox^ blobBox in arrayBlobBox)
	{
		vecBlobBox.Add(*blobBox->GetUInstance());
	}

	m_pMilBlob->GetBlobBoxs(vecBlobBox);
}

void MilBlob::Draw(MilImage^ milImage, long operation, long label)
{
	m_pMilBlob->Draw(milImage->GetUInstance(), operation, label);
}

MIL_ID MilBlob::GetBlobResult()
{
	return m_pMilBlob->GetBlobResult();
}
