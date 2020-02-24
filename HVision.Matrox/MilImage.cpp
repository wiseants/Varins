#include "stdafx.h"
#include "MilImage.h"
#include "Enumerator.h"

using namespace HVision::Matrox;

MilImage::MilImage()
{
	m_pMilImage = new CMilImage();
}

MilImage::~MilImage()
{
	this->!MilImage();
}

MilImage::!MilImage()
{
	if (m_pMilImage != nullptr)
	{
		if (m_pMilImage->IsAllocated() == true)
		{
			m_pMilImage->Free();
		}

		delete m_pMilImage;
	}

	m_pMilImage = nullptr;
}

CMilImage* MilImage::GetUInstance()
{
	return m_pMilImage;
}

void MilImage::SetUInstance(CMilImage* pMilImage)
{
	if (m_pMilImage != nullptr)
	{
		m_pMilImage->Free();
	}

	m_pMilImage = pMilImage;
}

void MilImage::CopyToColor(MilImage^ destImage, long Band)
{
	m_pMilImage->CopyToColor(destImage->GetUInstance(), Band);
}

void MilImage::CopyFrom(MilImage^ srcImage, bool bColor)
{
	m_pMilImage->CopyFrom(srcImage->GetUInstance(), bColor);
}

void MilImage::CopyTo(MilImage^ destImage, bool bColor)
{
	m_pMilImage->CopyTo(destImage->GetUInstance(), bColor);
}

void MilImage::Load(String^ fileName)
{
	marshal_context context;
	LPCTSTR cstr = context.marshal_as<const TCHAR*>(fileName);

	m_pMilImage->Load(cstr);
}

bool MilImage::Restore(String^ fileName)
{
	marshal_context context;
	LPCTSTR cstr = context.marshal_as<const TCHAR*>(fileName);

	return m_pMilImage->Restore(cstr);
}

void MilImage::Export(String^ fileName)
{
	marshal_context context;
	LPCTSTR cstr = context.marshal_as<const TCHAR*>(fileName);

	m_pMilImage->Export(cstr);
}

void MilImage::ExportJPG(String^ fileName)
{
	marshal_context context;
	LPCTSTR cstr = context.marshal_as<const TCHAR*>(fileName);

	m_pMilImage->ExportJPG(cstr);
}

void MilImage::Import(String^ fileName)
{
	marshal_context context;
	LPCTSTR cstr = context.marshal_as<const TCHAR*>(fileName);

	m_pMilImage->Import(cstr);
}

void MilImage::DebugExport(String^ fileName)
{
	marshal_context context;
	LPCTSTR cstr = context.marshal_as<const TCHAR*>(fileName);

	m_pMilImage->DebugExport(cstr);
}

void MilImage::CreateColor(long sizeX, long sizeY, cli::array<Byte>^ buffer)
{
	pin_ptr<System::Byte> p = &buffer[0];
	void* pby = p;
	void* pch = reinterpret_cast<void*>(pby);

	m_pMilImage->CreateColor(sizeX, sizeY, 8, M_IMAGE + M_PROC + M_BGR24 + M_PACKED, M_HOST_ADDRESS + M_PITCH_BYTE, sizeX * 3, &pch);
}

long MilImage::GetBufferSize()
{
	return m_pMilImage->GetBufferSize();
}

Size^ MilImage::GetImageSize()
{
	CSize size = m_pMilImage->GetImageSize();
	return gcnew Size(size.cx, size.cy);
}

void MilImage::Alloc(MBandSize bandsize, long sizeX, long sizeY)
{
	m_pMilImage->Alloc((EBandSize)bandsize, sizeX, sizeY, 8, M_IMAGE + M_PROC);
}

void MilImage::Free()
{
	m_pMilImage->Free();
}

bool MilImage::IsAllocated()
{
	return m_pMilImage->IsAllocated();
}

MIL_ID MilImage::GetMilId()
{
	return m_pMilImage->GetMilId();
}

void MilImage::GetLine(Point^ Start, Point^ End, long* NbPixelsPtr, void* UserArrayPtr)
{
	m_pMilImage->GetLine(CPoint(Start->X, Start->Y), CPoint(End->X, End->Y), NbPixelsPtr, UserArrayPtr);
}

BOOL MilImage::CopyColor2d(MilImage^ pSrcImage, long srcBand, Point^ srcPt, long destBand, Point^ destPt, Size^ size)
{
	return m_pMilImage->CopyColor2d(pSrcImage->GetUInstance(), srcBand, CPoint(srcPt->X, srcPt->Y), destBand, CPoint(destPt->X, destPt->Y), CSize(size->Width, size->Height));
}

System::Drawing::Rectangle^ MilImage::GetRect()
{
	CRect rect = m_pMilImage->GetRect();

	return *new System::Drawing::Rectangle(rect.TopLeft().x, rect.TopLeft().y, rect.Width(), rect.Height());
}

void MilImage::Alloc1d(long size, long bitSize)
{
	m_pMilImage->Alloc1d(size, bitSize);
}

MilImage^ MilImage::CreateClipImage(System::Drawing::Rectangle^ clipRect)
{
	CRect rect = CRect(clipRect->Left, clipRect->Top, clipRect->Right, clipRect->Bottom);
	CMilImage* pClipImage = m_pMilImage->CreateClipImage(rect);

	MilImage^ returnImage = gcnew MilImage();
	returnImage->SetUInstance(pClipImage);

	return returnImage;
}

MilImage^ MilImage::CreateClipImage(System::Drawing::Rectangle^ clipRect, long band)
{
	CRect rect = CRect(clipRect->Left, clipRect->Top, clipRect->Right, clipRect->Bottom);
	CMilImage* pClipImage = m_pMilImage->CreateClipImage(rect, band);

	MilImage^ returnImage = gcnew MilImage();
	returnImage->SetUInstance(pClipImage);

	return returnImage;
}

MilImage^ MilImage::CreateRotateImage(double angle)
{
	CMilImage* pRotateImage = m_pMilImage->CreateRotateImage(angle);

	MilImage^ returnImage = gcnew MilImage();
	returnImage->SetUInstance(pRotateImage);

	return returnImage;
}

MilImage^ MilImage::CreateResizeImage(double scaleFactorX, double scaleFactorY)
{
	CMilImage* pResizeImage = m_pMilImage->CreateResizeImage(scaleFactorX, scaleFactorY);

	MilImage^ returnImage = gcnew MilImage();
	returnImage->SetUInstance(pResizeImage);

	return returnImage;
}

MilImage^ MilImage::CreateRotateImage(double angle, Size^ internalSize)
{
	CMilImage* pRotateImage = m_pMilImage->CreateRotateImage(angle, CSize(internalSize->Width, internalSize->Height));

	MilImage^ returnImage = gcnew MilImage();
	returnImage->SetUInstance(pRotateImage);

	return returnImage;
}

MIL_INT MilImage::GetBandSize()
{
	return m_pMilImage->GetBandSize();
}

void MilImage::Convert(long type)
{
	m_pMilImage->Convert(type);
}

void MilImage::Inverse()
{
	m_pMilImage->Inverse();
}

void MilImage::Rotate(double angle)
{
	m_pMilImage->Rotate(angle);
}

void MilImage::Rotate(double angle, Point^ offsetcenter, Point^ offset)
{
	m_pMilImage->Rotate(angle, CPoint(offsetcenter->X, offsetcenter->Y), CPoint(offset->X, offset->Y));
}

void MilImage::Rotate180() // MilImage^ pDestImage = NULL
{
	m_pMilImage->Rotate180();
}

void MilImage::Resize(double ScaleFactorX, double ScaleFactorY, long InterpolationType, MilImage^ pDestImage)
{
	CMilImage* pResizeImage = nullptr;
	m_pMilImage->Resize(ScaleFactorX, ScaleFactorY, InterpolationType, pResizeImage);

	pDestImage = gcnew MilImage();
	pDestImage->SetUInstance(pResizeImage);
}

double MilImage::CalcMean(MilImage^ pMilImage)
{
	CMilImage* pImage = nullptr;
	double result = m_pMilImage->CalcMean(pImage);

	pMilImage = gcnew MilImage();
	pMilImage->SetUInstance(pImage);

	return result;
}

void MilImage::GetColor(int nChannel, cli::array<unsigned char>^ buffer)
{
	int nFlag = 0;
	if (nChannel == 3)
	{
		nFlag = M_BGR24;
	}
	else if (nChannel == 4)
	{
		nFlag = M_BGR32;
	}

	byte* unmanagedBuffer = new byte[m_pMilImage->GetBufferSize()];
	memset(unmanagedBuffer, 0x00, m_pMilImage->GetBufferSize());

	m_pMilImage->GetColor(M_PACKED + nFlag, M_ALL_BANDS, unmanagedBuffer);
	System::IntPtr intPointer(unmanagedBuffer);

	Marshal::Copy(intPointer, buffer, 0, m_pMilImage->GetBufferSize());
}