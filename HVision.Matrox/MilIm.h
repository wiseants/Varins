#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "MilImage.h"
#include "Matrox/MilIm.h"

using namespace System::Drawing;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilIm
		{
		public:
			static void Histogram(MilImage^ image, long* pResult);
			static bool Histogram(long* pProjData, long cntDomain, long cntRange, long* pResult);
			static long Binarize(MilImage^ srcImage, MilImage^ destImage, long Condition, double CondLow, double CondHigh);
			static bool HistogramNormalization(MilImage^ srcImage, MilImage^ destImage, long InLow, long InHigh, long OutLow, long OutHigh);
			static void Resize(MilImage^ srcImage, MilImage^ destImage, double ScaleFactorX, double ScaleFactorY, long InterpolationMode);
			static void SemiBinarize(MilImage^ srcImage, MilImage^ destImage, long Condition, double CondLow, double CondHigh);
			static void GetMinMaxGrayValue(MilImage^ image, long &max, long &min);
			static void RemoveSmallBlobs(MilImage^ srcImage, MilImage^ destImage, int condHigh);
			static bool HSLBinarize(
				MilImage^ srcImage,
				MilImage^ destImage, 
				double CondLowH, 
				double CondHighH, 
				double CondLowS, 
				double CondHighS, 
				double CondLowL, 
				double CondHighL);
			static void Rotate(
				MilImage^ srcImage, 
				MilImage^ destImage, 
				double Angle, 
				double SrcCenX, 
				double SrcCenY, 
				double DstCenX, 
				double DstCenY, 
				long InterpolationMode);
			static bool RGBBinarize(
				MilImage^ srcImage,
				MilImage^ destImage, 
				long Condition, 
				double CondLowR, 
				double CondHighR, 
				double CondLowG, 
				double CondHighG, 
				double CondLowB, 
				double CondHighB);
		};
	}
}