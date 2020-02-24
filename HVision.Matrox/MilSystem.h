#pragma once

#include <windows.h>  
#include <vcclr.h>  
//#using <System.dll> 
#include <msclr\marshal.h>

#include "Matrox/MilSystem.h"

using namespace System;
using namespace msclr::interop;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilSystem
		{
		private:
			static MilSystem ^ m_pInstance = nullptr;

			MilSystem();
			~MilSystem();

		public:
			static MilSystem ^ Instance();
			bool Alloc();
			void Release();
		};
	}
}
