// PolyRect.h: interface for the CPolyRect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYRECT_H__C4FA177F_DCB2_42BB_B46D_488584792B16__INCLUDED_)
#define AFX_POLYRECT_H__C4FA177F_DCB2_42BB_B46D_488584792B16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CXmlNode;

#include <vector>
#include "UtilityClass.h"

class UTILITYCLASS CPolyRect  
{
public:
	CPolyRect();
	CPolyRect(CRect rect, double angle);
	virtual ~CPolyRect();

	CPolyRect& operator=(const CPolyRect& srcData)
	{
		m_pts[0] = srcData.m_pts[0];
		m_pts[1] = srcData.m_pts[1];
		m_pts[2] = srcData.m_pts[2];
		m_pts[3] = srcData.m_pts[3];

		return *this;
	}

	void SetRect(CRect rect, double angle);
	void DrawXMark(CDC* pDC);

	CRect GetOutterRect();
	CPoint* GetPts() { return m_pts; }

private:
	CPoint m_pts[4];
};

typedef std::vector<CPolyRect> VtrPolyRect;

#endif // !defined(AFX_POLYRECT_H__C4FA177F_DCB2_42BB_B46D_488584792B16__INCLUDED_)
