// MilGraphic.h: interface for the CMilGraphic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILGRAPHIC_H__3B544A4C_A169_41D7_B7DF_A8293E0E972E__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_MILGRAPHIC_H__3B544A4C_A169_41D7_B7DF_A8293E0E972E__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Utility/Defines.h"
#include "MATROXCLASS.h"
#include "Utility/Support.h"

class CMilImage;

enum GraControlType
{
	GraControl_BackMode = M_BACKGROUND_MODE,
	GraControl_Color = M_COLOR,
	GraControl_ColorRed = M_COLOR + M_RED,
	GraControl_ColorGreen = M_COLOR + M_GREEN,
	GraControl_ColorBlue = M_COLOR + M_BLUE,
	GraControl_BackColor = M_BACKCOLOR,
	GraControl_BackColorRed = M_BACKCOLOR + M_RED,
	GraControl_BackColorGreen = M_BACKCOLOR + M_GREEN,
	GraControl_BackColorBlue = M_BACKCOLOR + M_BLUE
};

enum GraControlValue
{
	GraMode_Transparent = M_TRANSPARENT,
	GraMode_Opaque = M_OPAQUE
};

enum GraInquireType
{
	GraInquire_BackMode = M_BACKGROUND_MODE, // double
	GraInquire_Color = M_COLOR, // double
	GraInquire_BackColor = M_BACKCOLOR, // long
	GraInquire_Font = M_FONT, // void *
	GraInquire_FontXScale = M_FONT_X_SCALE, // double
	GraInquire_FontYScale = M_FONT_Y_SCALE, // double
	GraInquire_Owner = M_OWNER_SYSTEM // MIL_ID
};

class MATROXCLASS CMilGraphic : public MilObject 
{
public:
	CMilGraphic();
	virtual ~CMilGraphic();

	BOOL Alloc();
	void Free();
	 
	void Clear(CMilImage *pMilImage);
	void Control(GraControlType graType, double dblControlValue);
	void Inquire(GraInquireType graType, void *UserVarPtr);
	void Color(double dblForegroundColor);
	void Fill(CMilImage *pMilImage, TPoint ptStart);
	void Line(CMilImage *pMilImage, TPoint ptStart, TPoint ptEnd);
	void Rect(CMilImage *pMilImage, TPoint ptStart, TPoint ptEnd);
	void RectFill(CMilImage *pMilImage, TPoint ptStart, TPoint ptEnd);
	void RoundRect(CMilImage *pMilImage, TPoint ptStart, TPoint ptEnd, double radius);
	void RoundRectFill(CMilImage *pMilImage, TPoint ptStart, TPoint ptEnd, double radius);
	void RoundRect(CMilImage *pMilImage, TPoint ptStart, TPoint ptEnd, double ltRadius, double rtRadius, double lbRadius, double rbRadius);
	void RoundRectFill(CMilImage *pMilImage, TPoint ptStart, TPoint ptEnd, double ltRadius, double rtRadius, double lbRadius, double rbRadius);
	
	void Arc(CMilImage *pMilImage, TPoint ptCenter, CSize radius, double startAngle, double endAngle);
	void ArcFill(CMilImage *pMilImage, TPoint ptCenter, CSize radius, double startAngle, double endAngle);

	void Polygon(CMilImage *pMilImage, VecPoint& pts);
	void PolygonFill(CMilImage *pMilImage, VecPoint& pts);

	void CustomRectFill(CMilImage *pMilImage, TRect rc, stCustomRectParam& stLeftTop, stCustomRectParam& stRightTop, stCustomRectParam& stLeftBot, stCustomRectParam& stRightBot, double lfStandardAngle /*= 0*/);
	void CustomRect(CMilImage *pMilImage, TRect rc, stCustomRectParam& stLeftTop, stCustomRectParam& stRightTop, stCustomRectParam& stLeftBot, stCustomRectParam& stRightBot, double lfStandardAngle /*= 0*/); // RoundRect의 Arc와 Line이 정확히 붙지 않는 문제 있음
};

#endif // !defined(AFX_MILGRAPHIC_H__3B544A4C_A169_41D7_B7DF_A8293E0E972E__INCLUDED_)
