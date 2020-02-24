#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox/MilModelFind.h"

using namespace System;
using namespace System::Drawing;
using namespace msclr::interop;

namespace HVision
{
	namespace Matrox
	{
		public ref class MModelFindResultInfo : IDisposable
		{
		private:
			ModelFindResultInfo* m_pModelFindResultInfo = nullptr;

		protected:
			!MModelFindResultInfo();

		public:
			MModelFindResultInfo();
			MModelFindResultInfo(ModelFindResultInfo& modelFindResultInfo);
			~MModelFindResultInfo();

			ModelFindResultInfo* GetUInstance();

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
