#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Utility/Support.h"

using namespace System;
using namespace System::Drawing;
using namespace msclr::interop;

namespace HVision
{
	namespace Matrox
	{
		public ref class CustomRectParam : IDisposable
		{
		private:
			stCustomRectParam* m_pCustomRectParam = nullptr;

		protected:
			!CustomRectParam();

		public:
			CustomRectParam();
			CustomRectParam(stCustomRectParam& customRectParam);
			~CustomRectParam();

			stCustomRectParam* GetUInstance();

			property CustomRectType Type
			{
				CustomRectType get();
				void set(CustomRectType value);
			}

			property Size^ RectSize
			{
				Size^ get();
				void set(Size^ value);
			}

			void operator = (CustomRectParam^ dstParam);
		};
	}
}
