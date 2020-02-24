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
		public ref struct BlobFeature
		{
		public:
			long AREA = M_AREA;
			long FERET_X = M_FERET_X;
			long FERET_Y = M_FERET_Y;
			long FERET_MIN_ANGLE = M_FERET_MIN_ANGLE;
			long FERET_MAX_ANGLE = M_FERET_MAX_ANGLE;
			long FIRST_POINT_X = M_FIRST_POINT_X;
			long FIRST_POINT_Y = M_FIRST_POINT_Y;
			long CHAIN_X = M_CHAIN_X;
			long CHAIN_Y = M_CHAIN_Y;
			long BOX = M_BOX;
			long BOX_X_MIN = M_BOX_X_MIN;
			long BOX_Y_MIN = M_BOX_Y_MIN;
			long BOX_X_MAX = M_BOX_X_MAX;
			long BOX_Y_MAX = M_BOX_Y_MAX;
			long COMPACTNESS = M_COMPACTNESS;
			long NUMBER_OF_HOLES = M_NUMBER_OF_HOLES;
			long CENTER_OF_GRAVITY_X = M_CENTER_OF_GRAVITY_X;
			long CENTER_OF_GRAVITY_Y = M_CENTER_OF_GRAVITY_Y;

			void Init();
		};
	}
}