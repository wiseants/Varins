#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox/milimage.h"

using namespace System;
using namespace System::Drawing;
using namespace msclr::interop;
using namespace System::Runtime::InteropServices;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilImage : IDisposable
		{
		private:
			CMilImage * m_pMilImage;

		protected:
			!MilImage();

		public:
			MilImage();
			~MilImage();

			CMilImage* GetUInstance();
			void SetUInstance(CMilImage* pMilImage);
			void CopyToColor(MilImage^ DestImage, long Band);
			void CopyFrom(MilImage^ SrcImage, bool bColor);
			void CopyTo(MilImage^ DestImage, bool bColor);

			void Load(String^ FileName);
			bool Restore(String^ FileName);
			void Export(String^ FileName);
			void ExportJPG(String^ FileName);
			void Import(String^ fileName);
			void DebugExport(String^ fileName);

			void CreateColor(long sizeX, long sizeY, cli::array<Byte>^ buffer);
			Size^ GetImageSize();
			long GetBufferSize();

			void Alloc(MBandSize bandsize, long sizeX, long sizeY);
			void Free();
			bool IsAllocated();
			MIL_ID GetMilId();

			void GetLine(Point^ Start, Point^ End, long* NbPixelsPtr, void* UserArrayPtr);

			BOOL CopyColor2d(MilImage^ pSrcImage, long srcBand, Point^ srcPt, long destBand, Point^ destPt, Size^ size);

			System::Drawing::Rectangle^ GetRect();

			void Alloc1d(long size, long bitSize);

			MilImage^ CreateClipImage(System::Drawing::Rectangle^ clipRect);
			MilImage^ CreateClipImage(System::Drawing::Rectangle^ clipRect, long band);

			MilImage^ CreateRotateImage(double angle);

			MilImage^ CreateResizeImage(double scaleFactorX, double scaleFactorY);
			MilImage^ CreateRotateImage(double angle, Size^ internalSize);

			MIL_INT GetBandSize();

			void GetColor(int nChannel, cli::array<unsigned char>^ buffer);

			void Convert(long type);

			void Inverse();

			void Rotate(double angle);
			void Rotate(double angle, Point^ offsetcenter, Point^ offset);
			void Rotate180();

			void Resize(double ScaleFactorX, double ScaleFactorY, long InterpolationType, MilImage^ pDestImage);
			double CalcMean(MilImage^ pMilImage);
		};
	}
}