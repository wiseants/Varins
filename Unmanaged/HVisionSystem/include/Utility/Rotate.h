// Rotate.h: interface for the CRotate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROTATE_H__A188B40D_51C5_43D1_8AC3_1E5E4D957337__INCLUDED_)
#define AFX_ROTATE_H__A188B40D_51C5_43D1_8AC3_1E5E4D957337__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"

#include "dblPoint.h"
#include "dblSize.h"
#include "dblRect.h"

UTILITYCLASS void Rotate(long& x, long& y, double angle);
UTILITYCLASS void Rotate(double& x, double& y, double angle);
UTILITYCLASS void Rotate(CdblPoint& point, double angle);
UTILITYCLASS void Rotate(CdblPoint& point, CdblPoint ptCenter, double angle);
UTILITYCLASS void Rotate(CPoint& point, double angle);
UTILITYCLASS void Rotate(CPoint& point, CPoint ptCenter, double angle);
UTILITYCLASS void Rotate(CdblSize& size, double angle);
UTILITYCLASS void Rotate(CSize& size, double angle);
UTILITYCLASS void Rotate(CdblRect& rect, double angle);
UTILITYCLASS void Rotate(CdblRect& rect, const CdblPoint& centerPt, double angle);
UTILITYCLASS void Rotate(CRect& rect, double angle);
UTILITYCLASS void Rotate(CRect& rect, const CPoint& centerPt, double angle);
UTILITYCLASS void Rotate(CRect& rect, CRect& rectParent, double angle);
UTILITYCLASS void Rotate(CdblRect rect, double angle, CdblPoint pt[4]);
UTILITYCLASS void Rotate(CdblRect rect, double angle, CPoint pt[4]);
UTILITYCLASS void Rotate(CdblRect rect, CdblPoint centerPt, double angle, CdblPoint pt[4]);
UTILITYCLASS void Rotate(CRect rect, CPoint centerPt, double angle, CPoint pt[4]);
UTILITYCLASS CdblRect GetRealRect(const CdblRect& srcRect, double angle);
UTILITYCLASS CRect GetRealRect(const CRect& srcRect, double angle);
UTILITYCLASS BOOL IsRectAvailable(double angle);
UTILITYCLASS void Rotate(CRect rect, double angle, CPoint pt[4]);
UTILITYCLASS void RotateOffset(CdblRect& rect, const CdblPoint& centerPt, long angle);
UTILITYCLASS void RotateOffset(CRect& rect, const CPoint& centerPt, long angle);

#endif // !defined(AFX_ROTATE_H__A188B40D_51C5_43D1_8AC3_1E5E4D957337__INCLUDED_)
