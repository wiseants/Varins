// HoughTransform.h: interface for the CHoughTransform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOUGHTRANSFORM_H__5FECE3FE_EF67_4746_AD78_17F8073F142B__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_HOUGHTRANSFORM_H__5FECE3FE_EF67_4746_AD78_17F8073F142B__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMilImage;

#include "MATROXCLASS.h"

class MATROXCLASS CHoughTransform  
{
public:
	BOOL IsAllocated(void);
	static BOOL Alloc(const CSize& frameSize);
	static void Free(void);
	BOOL Circle(CMilImage *pMilImage, const CSize &sizeMark, const CRect &rectSearch, CPoint &CenterPos, double dblRhoRatio, BOOL bInverse = FALSE);
	BOOL Rectangle(CMilImage *pMilImage, const CSize &sizeMark, const CRect &rectSearch, CPoint &CenterPos, BOOL bInverse = FALSE);
	BOOL AllocSpace3d(long nChi, long nPsi, long nRho);
	void FreeSpace3d(void);
	BOOL AllocSpace2d(long nRadius, long nTheta);
	void FreeSpace2d(void);

	CHoughTransform();
	virtual ~CHoughTransform();

protected:
	long ***m_lpBruteSpace3d;
	long m_nChi, m_nPsi, m_nRho;
	long **m_lpBruteSpace2d;
	long m_nTheta, m_nRadius;

	CPoint Analyze(CMilImage *pMilImage, const CSize &sizeMask);
};

#endif // !defined(AFX_HOUGHTRANSFORM_H__5FECE3FE_EF67_4746_AD78_17F8073F142B__INCLUDED_)
