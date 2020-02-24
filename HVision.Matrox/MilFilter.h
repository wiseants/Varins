#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox/MilFilter.h"
#include "MilImage.h"

namespace HVision
{
	namespace Matrox
	{
		public ref class MilFilter
		{
		public:
			static void MotionBlur(MilImage^ pSrcMilImage, MilImage^ pDestMilImage);
			static HRESULT Average_3by3(MilImage^ pSrcMilImage, MilImage^ pDestMilImage);
			static HRESULT Average_5by5(MilImage^ pSrcMilImage, MilImage^ pDestMilImage);
			static HRESULT Average_7by7(MilImage^ pSrcMilImage, MilImage^ pDestMilImage);
			static HRESULT Average_9by9(MilImage^ pSrcMilImage, MilImage^ pDestMilImage);
			static void SuppressArea(MilImage^ pSrcImage, MilImage^ pDestImage, long area);
			static void SuppressLength(MilImage^ pSrcImage, MilImage^ pDestImage, enum eDirection direction, long lMinLength);
			static HRESULT Smooth(MilImage^ pSrcImage, MilImage^ pDestImage);
			static void Median(MilImage^ SrcImage, MilImage^ DestImage, long StructElemBufId, long ProcMode);
			static void Median_CustomKernel(MilImage^ pSrcImage, MilImage^ pDestImage, long kernelSize, BOOL bCross);
			static void EdgeDetection(MilImage^ pSrcMilImage, MilImage^ pDestMilImage, long KernelBufId);
		};
	}
}
