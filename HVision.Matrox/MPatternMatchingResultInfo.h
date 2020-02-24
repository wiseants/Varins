#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox/MilPatternFind.h"

using namespace System;
using namespace System::Drawing;
using namespace msclr::interop;

namespace HVision
{
	namespace Matrox
	{
		public ref class MPatternMatchingResultInfo : IDisposable
		{
		private:
			PatternMatchingResultInfo * m_pPatternMatchingResultInfo = nullptr;

		protected:
			!MPatternMatchingResultInfo();

		public:
			MPatternMatchingResultInfo();
			MPatternMatchingResultInfo(PatternMatchingResultInfo& patternMatchingResultInfo);
			~MPatternMatchingResultInfo();

			PatternMatchingResultInfo* GetUInstance();

			property double Angle
			{
				double get();
				void set(double value);
			}

			property double Score
			{
				double get();
				void set(double value);
			}

			property double Scale
			{
				double get();
				void set(double value);
			}

			property Point^ CenterPt
			{
				Point^ get();
				void set(Point^ value);
			}
		};
	}
}

