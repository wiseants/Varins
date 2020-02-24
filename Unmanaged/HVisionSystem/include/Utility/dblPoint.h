// dblPoint.h: interface for the CdblPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBLPOINT_H__F7F7101F_27DE_4E75_B7EF_330DA28CB369__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_DBLPOINT_H__F7F7101F_27DE_4E75_B7EF_330DA28CB369__INCLUDED_
#endif

#include <atlcoll.h>
#include <vector>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CdblSize;

typedef struct tagdblPOINT {
	double x;
	double y;
} dblPOINT;

#include <atltypes.h>
#include <vector>

#include "UtilityClass.h"

class UTILITYCLASS CdblPoint : public dblPOINT
{
public:
	CdblPoint();
	CdblPoint(const CPoint& point);
	CdblPoint(const CdblPoint& point);
	CdblPoint(double initX, double initY);
	CdblPoint(const dblPOINT& point);
	virtual ~CdblPoint();
	operator CPoint()  const
	{
		return GetCPoint();
	}

	CPoint GetCPoint() const {
		return CPoint((long)(x+0.5), (long)(y+0.5));
	}
  
	void Offset(double xOffset, double yOffset);
	void Scale(double lfScaleX, double lfScaleY);
	void ScaleDown(double cx, double cy);

	void operator =(const CdblPoint &srcPoint);
	void operator =(const CPoint &srcPoint);
	BOOL operator!=(const CPoint& point);
	BOOL operator!=(const CdblPoint& point);
	BOOL operator == (const CPoint &point);
	BOOL operator == (const CdblPoint &point);
	void operator /=(const CdblSize& size);
	void operator *=(const CdblSize& size);

	void operator-=(const CdblSize& size);
	void operator+=(const CdblSize& size);
	void operator-=(const CdblPoint& point);
	void operator+=(const CdblPoint& point);

	CdblPoint operator-(const CdblSize& size) const;
	CdblPoint operator-() const;
	CdblPoint operator+(const CdblSize& size) const;
	CdblPoint operator-(const CdblPoint& point) const;
	CdblPoint operator+(const CdblPoint& point) const;

	CdblPoint operator-();
};

typedef CAtlArray<CPoint> VecPoint;
typedef VecPoint* VecPointPtr;
typedef std::vector<CdblPoint> VecDblPoint;
typedef VecDblPoint* VecDblPointPtr;

#endif // !defined(AFX_DBLPOINT_H__F7F7101F_27DE_4E75_B7EF_330DA28CB369__INCLUDED_)
