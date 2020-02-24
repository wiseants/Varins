#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "MilImage.h"
#include "MCircleMarkerResultInfo.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace msclr::interop;
using namespace HVision::Matrox;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilCircleMarker : IDisposable
		{
		private:
			CMilCircleMarker * m_pMilCircleMarker = nullptr;

		protected:
			!MilCircleMarker();

		public:
			MilCircleMarker();
			~MilCircleMarker();

			bool Alloc();
			void Free();
			bool Calculate(MilImage^ milImage);
			void SetScore();
			void SetSearchingNumber();
			void SetSearchingNumber(long nNumber); // 1
			void SetRadius(double lfRadius, double nMinScale, double nMaxScale);
			void SetPositiveDirection();
			void SetNegativeDirection();
			void SetAnyDirection();
			void SetCenter(double centerX, double centerY);

			List<MCircleMarkerResultInfo^>^ GetResultList();
		};
	}
}
