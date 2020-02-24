#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "MilImage.h"
#include "MPatternMatchingResultInfo.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace msclr::interop;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilPatternFind : IDisposable
		{
		private:
			CMilPatternFind* m_pMilPatternFind = nullptr;

		protected:
			!MilPatternFind();

		public:
			MilPatternFind();
			~MilPatternFind();

			CMilPatternFind* GetUInstance();

			bool Alloc(MilImage^ milImage);
			void Free();

			bool Calculate(MilImage^ milImage);

			void SetParameter(int lfOffsetX, int lfOffsetY, int lfSizeX, int lfSizeY);

			void SetScore(long nScore);
			void SetSearchingNumber(long nNumber);
			void SetSearchSpeed(long nLevel);
			void SetFilterLevel(long nFilterLevel);

			void SetAccuracy(int nAccuracy);
			void SetBasePosition(long nPixelCenterX, long nPixelCenterY);

			void SetAngle(bool angleMode, double lfRange, double angleAccuracy, double interpolationMode);

			List<MPatternMatchingResultInfo^>^ GetResultList();
			void SetDontCareImage(MilImage^ dontcareImg);
			long GetResultMilID();
		};
	}
}
