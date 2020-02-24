#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "MilImage.h"
#include "MModelFindResultInfo.h"
#include "Matrox/MilModelFind.h"
#include "Matrox/milimage.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace msclr::interop;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilModelFind : IDisposable
		{
		private:
			CMilModelFind* m_pMilModelFind = nullptr;

		protected:
			!MilModelFind();

		public:
			MilModelFind();
			~MilModelFind();

			CMilModelFind* GetUInstance();

			bool Alloc(MilImage^ milImage);
			void Free();

			bool Calculate(MilImage^ milImage);

			void SetParameter(double lfOffsetX, double lfOffsetY, double lfSizeX, double lfSizeY);
			void SearchInnerPosition();

			void SetScore(long nScore);
			void SetSearchingNumber(long nNumber);
			void SetSearchSpeed(long nLevel);
			void SetFilterLevel(long nFilterLevel);
			void SetAngle(bool bSearchAngle); //  double lfAngle = 360

			void SetAccuracy(double lfAccuracy);
			void SetBasePosition(long nPixelCenterX, long nPixelCenterY);

			List<MModelFindResultInfo^>^ GetResultList();
			void AlignmentFindImage(MilImage^ targetImage, int nRstIndex);
			void SetDontCareImage(MilImage^ dontcareImg);
		};
	}
}
