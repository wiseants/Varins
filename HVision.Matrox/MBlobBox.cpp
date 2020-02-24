#include "stdafx.h"
#include "MBlobBox.h"

using namespace HVision::Matrox;

MBlobBox::MBlobBox()
{
	m_pBlobBox = new BlobBox();
}

MBlobBox::~MBlobBox()
{
	this->!MBlobBox();
}

MBlobBox::!MBlobBox()
{
	if (m_pBlobBox != nullptr)
	{
		delete m_pBlobBox;
	}

	m_pBlobBox = nullptr;
}

MBlobBox::MBlobBox(MBlobBox^ blobBox)
{
	m_pBlobBox = new BlobBox(*blobBox->GetUInstance());
}

MBlobBox::MBlobBox(long left, long top, long right, long bottom, long area)
{
	m_pBlobBox = new BlobBox(left, top, right, bottom, area);
}

MBlobBox^ MBlobBox::operator = (MBlobBox^ blobBox)
{
	m_pBlobBox = blobBox->GetUInstance();

	return this;
}

BlobBox* MBlobBox::GetUInstance()
{
	return m_pBlobBox;
}