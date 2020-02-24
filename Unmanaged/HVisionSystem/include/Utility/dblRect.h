// dblRect.h: interface for the CdblRect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBLRECT_H__5E0B3D4A_7A9B_46EB_B05E_CB637584A47C__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_DBLRECT_H__5E0B3D4A_7A9B_46EB_B05E_CB637584A47C__INCLUDED_
#endif

#include <vector>
#include <atltypes.h>

#include "dblSize.h"	// Added by ClassView
#include "dblPoint.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"

struct tagdblRECT {
	double left;
	double top;
	double right;
	double bottom;
};

typedef tagdblRECT dblRECT, *PdblRECT, NEAR *NPdblRECT, FAR *LPdblRECT;

//class CdblRect : public dblRECT
class UTILITYCLASS CdblRect : public tagdblRECT
{
public :
	CdblRect();
	CdblRect(double l, double t, double r, double b);
	CdblRect(const CdblPoint& leftTop, const CdblPoint& bottomRight);
	CdblRect(const CdblPoint& point, const CdblSize& size);
	CdblRect(const CRect& rect);
	virtual ~CdblRect();

// Implememtations
public :
	VOID SetRect(double l, double t, double r, double b);
	VOID SetRect( CdblPoint lt, CdblPoint rb );
	CdblSize Size() const;
	CdblPoint TopLeft() const;
	CdblPoint TopRight() const;
	CdblPoint BottomLeft() const;
	CdblPoint BottomRight() const;
	CRect GetCRect() const {
		return CRect((long)(left), (long)(top), (long)(right), (long)(bottom));
	}
	
	BOOL IsCreated() const;
	
	void SetRectEmpty();
	BOOL IsRectEmpty() const;
	BOOL IsRectNull() const;

	void NormalizeRect();
	void OffsetRect(const CdblSize& size);
	void OffsetRect(double x, double y);

	void CenterPoint(double& dblCenterX, double& dblCenterY) const;
	CdblPoint CenterPoint() const;
	
	void UnionRect(const CdblRect& rect);
	BOOL IntersectRect(const CdblRect& rect1, const CdblRect& rect2);
	void InflateRect(double dx, double dy);
	void InflateRect(int l, int t, int r, int b);
	void InflateRect(const CdblSize& _size);
	void ScaleRect(const double& _scaleX, const double& _scaleY);
	void DescaleRect(const double& _scaleX, const double& _scaleY);
	BOOL PtInRect(const CdblPoint& point) const;
	BOOL PtInRect(const CdblPoint& point, BOOL& _bX, BOOL& _bY) const;
	//! deplicated
	BOOL IsIncluded(const CdblRect& rect) const;
	BOOL RectInRect(const CdblRect& rect) const;
	BOOL EqualRect(const CdblRect& rect);
	void EnsureInRect(CdblRect& rect);

	double Height() const;
	double Width() const;

	operator CRect() const
	{
		return GetCRect();
	}

	void operator=(const CdblRect& srcRect);
	void operator=(const CRect& srcRect);
	void operator+=(const CdblSize& size);
	void operator+=(const CdblRect& rect);
	void operator-=(const CdblSize& size);
	void operator+=(const CdblPoint& point);
	void operator-=(const CdblPoint& point);
	void operator|=(const CdblRect& rect);
	void operator|=(const CdblPoint& point);
	BOOL operator!=(const CdblRect& rect);
	BOOL operator==(const CdblRect& rect);
	CdblRect operator+(const CdblSize& size);
	CdblRect operator+(const CdblRect& rect);

	CdblRect operator|(const CdblRect& rect);
	CdblRect operator&(const CdblRect& rect);

	static BOOL IsCrossed2(CdblRect *lpRect1, CdblRect *lpRect2);
	static BOOL IsCrossed(CdblRect *lpRect1, CdblRect *lpRect2);

	// by sub //
	/*
	CdblPoint PointRotate(CdblPoint pt, double degree);
	void RotateRect(const CdblPoint& PointOffset, const double& Angle);
	*/

};

typedef std::vector<CRect> VecRect;
typedef VecRect* VecRectPtr;
typedef std::vector<CdblRect> VecDblRect;
typedef VecDblRect* VecDblRectPtr;

#endif // !defined(AFX_DBLRECT_H__5E0B3D4A_7A9B_46EB_B05E_CB637584A47C__INCLUDED_)
