#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox/MilBlob.h"

using namespace System;
using namespace msclr::interop;

namespace HVision
{
	namespace Matrox
	{
		public ref struct MBlobBox
		{
		private:
			BlobBox* m_pBlobBox = nullptr;

		protected:
			!MBlobBox();

		public:
			MBlobBox();
			MBlobBox(MBlobBox^ blobBox);
			MBlobBox(long left, long top, long right, long bottom, long area);
			~MBlobBox();

			MBlobBox^ operator = (MBlobBox^ blobBox);

			BlobBox* GetUInstance();
		};
	}
}