#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox/MilArith.h"
#include "MilImage.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace msclr::interop;
using namespace HVision::Matrox;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilArith
		{
		public:
			static void Add(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage, bool bSaturation);
			static void And(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage);
			static void Divide(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage);
			static void Max(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage);
			static void Min(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage);
			static void Multiply(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage, bool bSaturation);
			static void Nand(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage);
			static void Nor(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage);
			static void Or(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage);
			static void Subtract(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage, bool bSaturation);
			static void AbsSubtract(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage, bool bSaturation);
			static void Xor(MilImage^ pSrcImage1, MilImage^ pSrcImage2, MilImage^ pDestImage);
			static ULONG CountDifference(MilImage^ pSrcImage, MilImage^ pSrcImage2);

			static void Add(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage, bool bSaturation);
			static void And(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage);
			static void Divide(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage);
			static void Max(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage);
			static void Min(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage);
			static void Multiply(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage, bool bSaturation);
			static void Nand(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage);
			static void Nor(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage);
			static void Or(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage);
			static void Xor(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage);
			static void Subtract(MilImage^ pSrcImage, double fConstant, MilImage^ pDestImage, bool bSaturation);

			static void Abs(MilImage^ pSrcImage, MilImage^ pDestImage);
			static void Not(MilImage^ pSrcImage, MilImage^ pDestImage);
		};
	}
}
