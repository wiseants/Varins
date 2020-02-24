#pragma once

#include <windows.h>  
#include <vcclr.h>  
//#using <System.dll> 
#include <msclr\marshal.h>

#include "Matrox/MilApplication.h"

using namespace System;
using namespace msclr::interop;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilApplication
		{
		private:
			static MilApplication^ m_pInstance = nullptr;

			MilApplication();
			~MilApplication();

		public:
			static MilApplication^ Instance();
			bool Alloc();
			void Release();

			void RunErrorHandler();
			bool IsValid();
			void SetMilSysErrMsg(BOOL fDisplay);
		};
	}
}