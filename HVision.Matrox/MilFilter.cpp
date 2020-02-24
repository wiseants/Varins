#include "stdafx.h"
#include "MilFilter.h"
#include "Matrox/MilIm.h"

using namespace HVision::Matrox;

void MilFilter::MotionBlur(MilImage^ pSrcMilImage, MilImage^ pDestMilImage)
{
	CMilFilter::MotionBlur(pSrcMilImage->GetUInstance(), pDestMilImage->GetUInstance(), M_HORIZONTAL, 16);
}

HRESULT MilFilter::Average_3by3(MilImage^ pSrcMilImage, MilImage^ pDestMilImage)
{
	return CMilFilter::Average_3by3(pSrcMilImage->GetUInstance(), pDestMilImage->GetUInstance());
}

HRESULT MilFilter::Average_5by5(MilImage^ pSrcMilImage, MilImage^ pDestMilImage)
{
	return CMilFilter::Average_5by5(pSrcMilImage->GetUInstance(), pDestMilImage->GetUInstance());
}

HRESULT MilFilter::Average_7by7(MilImage^ pSrcMilImage, MilImage^ pDestMilImage)
{
	return CMilFilter::Average_7by7(pSrcMilImage->GetUInstance(), pDestMilImage->GetUInstance());
}

HRESULT MilFilter::Average_9by9(MilImage^ pSrcMilImage, MilImage^ pDestMilImage)
{
	return CMilFilter::Average_9by9(pSrcMilImage->GetUInstance(), pDestMilImage->GetUInstance());
}

void MilFilter::SuppressArea(MilImage^ pSrcImage, MilImage^ pDestImage, long area)
{
	return CMilFilter::SuppressArea(pSrcImage->GetUInstance(), pDestImage->GetUInstance(), area);
}

void MilFilter::SuppressLength(MilImage^ pSrcImage, MilImage^ pDestImage, enum eDirection direction, long lMinLength)
{
	CMilFilter::SuppressLength(pSrcImage->GetUInstance(), pDestImage->GetUInstance(), direction, lMinLength);
};

HRESULT MilFilter::Smooth(MilImage^ pSrcImage, MilImage^ pDestImage)
{
	return CMilFilter::Smooth(pSrcImage->GetUInstance(), pDestImage->GetUInstance());
}

void MilFilter::Median(MilImage^ SrcImage, MilImage^ DestImage, long StructElemBufId, long ProcMode)
{
	CMilFilter::Median(SrcImage->GetUInstance(), DestImage->GetUInstance(), StructElemBufId, ProcMode);
}

void MilFilter::Median_CustomKernel(MilImage^ pSrcImage, MilImage^ pDestImage, long kernelSize, BOOL bCross)
{
	CMilFilter::Median_CustomKernel(pSrcImage->GetUInstance(), pDestImage->GetUInstance(), kernelSize, bCross, M_GRAYSCALE);
}

void MilFilter::EdgeDetection(MilImage^ pSrcMilImage, MilImage^ pDestMilImage, long KernelBufId)
{
	CMilFilter::EdgeDetection(pSrcMilImage->GetUInstance(), pDestMilImage->GetUInstance(), KernelBufId);
}