#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox/MilImage.h"

namespace HVision
{
	namespace Matrox
	{
		public enum class MBandSize
		{
			Gray = 1,
			RGB = 3
		};

		public enum class CustomRectType
		{
			Arc = 0,
			Triangle
		};
	}
}