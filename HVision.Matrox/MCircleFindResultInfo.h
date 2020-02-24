#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox\MilCircleFind.h"

using namespace System;
using namespace msclr::interop;

namespace HVision
{
	namespace Matrox
	{
		public ref struct MCircleFindResultInfo
		{
		private:
			CircleFindResultInfo* m_pCircleFindResultInfo = nullptr;

		protected:
			!MCircleFindResultInfo();

		public:
			MCircleFindResultInfo();
			MCircleFindResultInfo(CircleFindResultInfo& circleFindResultInfo);
			~MCircleFindResultInfo();

			System::Drawing::Rectangle^ GetRect();
			double GetScore();
		};
	}
}