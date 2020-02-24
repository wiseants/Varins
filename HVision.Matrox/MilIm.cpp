#include "stdafx.h"
#include "MilIm.h"

using namespace HVision::Matrox;

void MilIm::Histogram(MilImage^ image, long* pResult)
{
	CMilIm::Histogram(image->GetUInstance(), pResult);
}

bool MilIm::Histogram(long* pProjData, long cntDomain, long cntRange, long* pResult)
{
	return CMilIm::Histogram(pProjData, cntDomain, cntRange, pResult);
}

long MilIm::Binarize(MilImage^ srcImage, MilImage^ destImage, long Condition, double CondLow, double CondHigh)
{
	return CMilIm::Binarize(srcImage->GetUInstance(), destImage->GetUInstance(), Condition, CondLow, CondHigh);
}

bool MilIm::HistogramNormalization(MilImage^ srcImage, MilImage^ destImage, long InLow, long InHigh, long OutLow, long OutHigh)
{
	return CMilIm::HistogramNormalization(srcImage->GetUInstance(), destImage->GetUInstance(), InLow, InHigh, OutLow, OutHigh);
}

void MilIm::Resize(MilImage^ srcImage, MilImage^ destImage, double ScaleFactorX, double ScaleFactorY, long InterpolationMode)
{
	CMilIm::Resize(srcImage->GetUInstance(), destImage->GetUInstance(), ScaleFactorX, ScaleFactorY, InterpolationMode);
}

void MilIm::SemiBinarize(MilImage^ srcImage, MilImage^ destImage, long Condition, double CondLow, double CondHigh)
{
	CMilIm::SemiBinarize(srcImage->GetUInstance(), destImage->GetUInstance(), Condition, CondLow, CondHigh);
}

void MilIm::GetMinMaxGrayValue(MilImage^ image, long &max, long &min)
{
	CMilIm::GetMinMaxGrayValue(image->GetUInstance(), max, min);
}

void MilIm::RemoveSmallBlobs(MilImage^ srcImage, MilImage^ destImage, int condHigh)
{
	CMilIm::RemoveSmallBlobs(srcImage->GetUInstance(), destImage->GetUInstance(), condHigh);
}

bool MilIm::HSLBinarize(
	MilImage^ srcImage,
	MilImage^ destImage, 
	double CondLowH, 
	double CondHighH, 
	double CondLowS, 
	double CondHighS, 
	double CondLowL, 
	double CondHighL)
{
	return CMilIm::HSLBinarize(srcImage->GetUInstance(), destImage->GetUInstance(), CondLowH, CondHighH, CondLowS, CondHighS, CondLowL, CondHighL);
}

void MilIm::Rotate(
	MilImage^ srcImage,
	MilImage^ destImage, 
	double Angle, 
	double SrcCenX, 
	double SrcCenY, 
	double DstCenX, 
	double DstCenY, 
	long InterpolationMode)
{
	CMilIm::Rotate(srcImage->GetUInstance(), destImage->GetUInstance(), Angle, SrcCenX, SrcCenY, DstCenX, DstCenY, InterpolationMode);
}

bool MilIm::RGBBinarize(
	MilImage^ srcImage,
	MilImage^ destImage, 
	long Condition, 
	double CondLowR, 
	double CondHighR, 
	double CondLowG, 
	double CondHighG, 
	double CondLowB, 
	double CondHighB)
{
	return CMilIm::RGBBinarize(srcImage->GetUInstance(), destImage->GetUInstance(), Condition, CondLowR, CondHighR, CondLowG, CondHighG, CondLowB, CondHighB);
}

