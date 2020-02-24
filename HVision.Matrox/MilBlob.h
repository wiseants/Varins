#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox/MilBlob.h"
#include "MilImage.h"
#include "MBlobBox.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace msclr::interop;
using namespace HVision::Matrox;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilBlob : IDisposable
		{
		private:
			CMilBlob * m_pMilBlob = nullptr;

		protected:
			!MilBlob();

		public:
			MilBlob();
			~MilBlob();

			void Alloc();
			void SetSrcImage(MilImage^ milImage);
			void SetDestImage(MilImage^ milImage);
			void SelectFeature(long featureList);
			void Calculate();
			long GetLabel(long xPos, long yPos);

			BOOL IsAllocated();
			void FillHoles(long ProcMode);
			void ExtractHoles(long ProcMode);
			void Fill(long Criterion, long Value);
			void Select(long Operation, long Feature, long Condition, double CondLow, double CondHigh);
			MIL_INT GetNumber();
			void GetBlobBoxs(cli::array<MBlobBox^>^ arrayBlobBox);
			void Draw(MilImage^ milImage, long operation, long label);
			MIL_ID GetBlobResult();
		};
	}
}

