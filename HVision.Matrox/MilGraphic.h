#pragma once

#include <windows.h>  
#include <vcclr.h>  
#include <msclr\marshal.h>

#include "Matrox/MilGraphic.h"
#include "MilImage.h"
#include "CustomRectParam.h"

using namespace System::Drawing;

namespace HVision
{
	namespace Matrox
	{
		public ref class MilGraphic : IDisposable
		{
		private:
			CMilGraphic* m_pMilGraphic = nullptr;

		protected:
			!MilGraphic();

		public:
			MilGraphic();
			~MilGraphic();

			bool Alloc();
			void Free();

			void Clear(MilImage^ milImage);
			void Color(double dblForegroundColor);
			void Fill(MilImage^ milImage, Point^ ptStart);
			void Line(MilImage^ milImage, Point^ ptStart, Point^ ptEnd);
			void Rect(MilImage^ milImage, Point^ ptStart, Point^ ptEnd);
			void RectFill(MilImage^ milImage, Point^ ptStart, Point^ ptEnd);
			void RoundRect(MilImage^ milImage, Point^ ptStart, Point^ ptEnd, double radius);
			void RoundRectFill(MilImage^ milImage, Point^ ptStart, Point^ ptEnd, double radius);
			void RoundRect(MilImage^ milImage, Point^ ptStart, Point^ ptEnd, double ltRadius, double rtRadius, double lbRadius, double rbRadius);
			void RoundRectFill(MilImage^ milImage, Point^ ptStart, Point^ ptEnd, double ltRadius, double rtRadius, double lbRadius, double rbRadius);

			void Arc(MilImage^ milImage, Point^ ptCenter, CSize radius, double startAngle, double endAngle);
			void ArcFill(MilImage^ milImage, Point^ ptCenter, CSize radius, double startAngle, double endAngle);

			void Polygon(MilImage^ milImage, cli::array<Point^>^ points);
			void PolygonFill(MilImage^ milImage, cli::array<Point^>^ points);

			void CustomRectFill(
				MilImage^ milImage, 
				System::Drawing::Rectangle^ rc, 
				CustomRectParam^ stLeftTop, 
				CustomRectParam^ stRightTop, 
				CustomRectParam^ stLeftBot, 
				CustomRectParam^ stRightBot, 
				double lfStandardAngle);
			void CustomRect(
				MilImage^ milImage, 
				System::Drawing::Rectangle^ rc, 
				CustomRectParam^ stLeftTop, 
				CustomRectParam^ stRightTop, 
				CustomRectParam^ stLeftBot, 
				CustomRectParam^ stRightBot, 
				double lfStandardAngle);
		};
	}
}