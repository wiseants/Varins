#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "MCircleFindResultInfo.h"
#include "MilImage.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace msclr::interop;
using namespace HVision::Matrox;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilCircleFind : IDisposable
		{
		private:
			CMilCircleFind * m_pMilCircleFind = nullptr;

		protected:
			!MilCircleFind();

		public:
			MilCircleFind();
			~MilCircleFind();

			BOOL Alloc();
			void Free();

			BOOL Calculate(MilImage^ milImage);

			void SetScore(long nScore);
			void SetSearchingNumber(long nNumber);
			void SetSearchLevel(long nLevel);
			void SetFilterLevel(long nFilterLevel);
			void SetRadius(double lfRadius);
			void SetMinScale(double nMinScale);
			void SetMaxScale(double nMaxScale);

			List<MCircleFindResultInfo^>^ GetResultList();
		};
	}
}