#include "stdafx.h"
#include "MilGraphic.h"

using namespace HVision::Matrox;

MilGraphic::MilGraphic()
{
	m_pMilGraphic = new CMilGraphic();
}

MilGraphic::~MilGraphic()
{
	this->!MilGraphic();
}

MilGraphic::!MilGraphic()
{
	if (m_pMilGraphic != nullptr)
	{
		delete m_pMilGraphic;
	}

	m_pMilGraphic = nullptr;
}

bool MilGraphic::Alloc()
{
	return m_pMilGraphic->Alloc();
}

void MilGraphic::Free()
{
	m_pMilGraphic->Free();
}

void MilGraphic::Clear(MilImage^ milImage)
{
	m_pMilGraphic->Clear(milImage->GetUInstance());
}

void MilGraphic::Color(double dblForegroundColor)
{
	m_pMilGraphic->Color(dblForegroundColor);
}

void MilGraphic::Fill(MilImage^ milImage, Point^ ptStart)
{
	m_pMilGraphic->Fill(milImage->GetUInstance(), CPoint(ptStart->X, ptStart->Y));
}

void MilGraphic::Line(MilImage^ milImage, Point^ ptStart, Point^ ptEnd)
{
	m_pMilGraphic->Line(milImage->GetUInstance(), CPoint(ptStart->X, ptStart->Y), CPoint(ptEnd->X, ptEnd->Y));
}

void MilGraphic::Rect(MilImage^ milImage, Point^ ptStart, Point^ ptEnd)
{
	m_pMilGraphic->Rect(milImage->GetUInstance(), CPoint(ptStart->X, ptStart->Y), CPoint(ptEnd->X, ptEnd->Y));
}

void MilGraphic::RectFill(MilImage^ milImage, Point^ ptStart, Point^ ptEnd)
{
	m_pMilGraphic->RectFill(milImage->GetUInstance(), CPoint(ptStart->X, ptStart->Y), CPoint(ptEnd->X, ptEnd->Y));
}

void MilGraphic::RoundRect(MilImage^ milImage, Point^ ptStart, Point^ ptEnd, double radius)
{
	m_pMilGraphic->RoundRect(milImage->GetUInstance(), CPoint(ptStart->X, ptStart->Y), CPoint(ptEnd->X, ptEnd->Y), radius);
}

void MilGraphic::RoundRectFill(MilImage^ milImage, Point^ ptStart, Point^ ptEnd, double radius)
{
	m_pMilGraphic->RoundRectFill(milImage->GetUInstance(), CPoint(ptStart->X, ptStart->Y), CPoint(ptEnd->X, ptEnd->Y), radius);
}

void MilGraphic::RoundRect(MilImage^ milImage, Point^ ptStart, Point^ ptEnd, double ltRadius, double rtRadius, double lbRadius, double rbRadius)
{
	m_pMilGraphic->RoundRect(
		milImage->GetUInstance(), 
		CPoint(ptStart->X, ptStart->Y), 
		CPoint(ptEnd->X, ptEnd->Y), 
		ltRadius, rtRadius, lbRadius, rbRadius);
}

void MilGraphic::RoundRectFill(MilImage^ milImage, Point^ ptStart, Point^ ptEnd, double ltRadius, double rtRadius, double lbRadius, double rbRadius)
{
	m_pMilGraphic->RoundRectFill(
		milImage->GetUInstance(),
		CPoint(ptStart->X, ptStart->Y),
		CPoint(ptEnd->X, ptEnd->Y),
		ltRadius, rtRadius, lbRadius, rbRadius);
}

void MilGraphic::Arc(MilImage^ milImage, Point^ ptCenter, CSize radius, double startAngle, double endAngle)
{
	m_pMilGraphic->Arc(milImage->GetUInstance(), CPoint(ptCenter->X, ptCenter->Y), CSize(radius.cx, radius.cy), startAngle, endAngle);
}

void MilGraphic::ArcFill(MilImage^ milImage, Point^ ptCenter, CSize radius, double startAngle, double endAngle)
{
	m_pMilGraphic->ArcFill(milImage->GetUInstance(), CPoint(ptCenter->X, ptCenter->Y), CSize(radius.cx, radius.cy), startAngle, endAngle);
}

void MilGraphic::Polygon(MilImage^ milImage, cli::array<Point^>^ points)
{
	VecPoint* pVecPoint = new VecPoint();
	for each (Point^ point in points)
	{
		pVecPoint->Add(CPoint(point->X, point->Y));
	}

	m_pMilGraphic->Polygon(milImage->GetUInstance(), *pVecPoint);
}

void MilGraphic::PolygonFill(MilImage^ milImage, cli::array<Point^>^ points)
{
	VecPoint* pVecPoint = new VecPoint();
	for each (Point^ point in points)
	{
		pVecPoint->Add(CPoint(point->X, point->Y));
	}

	m_pMilGraphic->PolygonFill(milImage->GetUInstance(), *pVecPoint);
}

void MilGraphic::CustomRectFill(
	MilImage^ milImage, 
	System::Drawing::Rectangle^ rc, 
	CustomRectParam^ stLeftTop, 
	CustomRectParam^ stRightTop, 
	CustomRectParam^ stLeftBot, 
	CustomRectParam^ stRightBot, 
	double lfStandardAngle)
{
	m_pMilGraphic->CustomRectFill(
		milImage->GetUInstance(), 
		CRect(rc->Left, rc->Top, rc->Right, rc->Bottom),
		*stLeftTop->GetUInstance(),
		*stRightTop->GetUInstance(),
		*stLeftBot->GetUInstance(),
		*stRightBot->GetUInstance(),
		lfStandardAngle);
}

void MilGraphic::CustomRect(
	MilImage^ milImage, 
	System::Drawing::Rectangle^ rc, 
	CustomRectParam^ stLeftTop, 
	CustomRectParam^ stRightTop, 
	CustomRectParam^ stLeftBot, 
	CustomRectParam^ stRightBot, 
	double lfStandardAngle)
{
	m_pMilGraphic->CustomRect(
		milImage->GetUInstance(),
		CRect(rc->Left, rc->Top, rc->Right, rc->Bottom),
		*stLeftTop->GetUInstance(),
		*stRightTop->GetUInstance(),
		*stLeftBot->GetUInstance(),
		*stRightBot->GetUInstance(),
		lfStandardAngle);
}