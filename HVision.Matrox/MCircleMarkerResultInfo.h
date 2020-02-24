#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox/MilCircleMarker.h"

using namespace System;
using namespace msclr::interop;

namespace HVision
{
	namespace Matrox
	{
		public ref struct MCircleMarkerResultInfo : IDisposable
		{
		private:
			CircleMarkerResultInfo * m_pCircleMarkerResultInfo = nullptr;

		protected:
			!MCircleMarkerResultInfo();

		public:
			MCircleMarkerResultInfo();
			MCircleMarkerResultInfo(CircleMarkerResultInfo& circleMarkerResultInfo);
			~MCircleMarkerResultInfo();

			System::Drawing::Rectangle^ GetRect();
			double GetScore();
		};
	}
}