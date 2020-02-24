// MilCalib.h: interface for the CMilCalib class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILCALIB_H__FF184C33_E165_11D4_960A_00C04F155F01__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_MILCALIB_H__FF184C33_E165_11D4_960A_00C04F155F01__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum CalibMode {
	ecmLinear = 0x01,
	ecmPerspective = 0x02
};

#include "MATROXCLASS.h"
#include "MilImage.h"
#include "Utility/dblSize.h"
#include "Utility/dblRect.h"

class MATROXCLASS CMilCalib : public MilObject 
{
public:
	CMilCalib();
	~CMilCalib();

	BOOL Alloc(CalibMode mode, LPCTSTR fileName = NULL);
	void Free();
	BOOL IsCalibrated();
	BOOL Init(const CSize& pixelRect, const CdblRect& worldRect);

	BOOL Grid(CMilImage* pMilImage, double dblGridOffsetX, double dblGridOffsetY, long lngRowNumber, long lngColNumber, double dblRowSpacing, double dblColSpacing);
	BOOL List(double *XPixArray, double *YPixArray, double *XWorldArray, double *YWorldArray, long NumPoint);	

	void Save(LPCTSTR lpszFileName);
	void Restore(LPCTSTR lpszFileName);

	void GetPixelSize(double *dblPelSizeX, double *dblPelSizeY, BOOL fCheckInit = TRUE);
	void GetPixelSize(CdblSize &dblPelSize);
	void SetPixelSize(double dblPelSizeX, double dblPelSizeY);

	void SetCameraPosition(double dblCameraPosX, double dblCameraPosY);

	void SetRelativeOrigin(double XOffset, double YOffset);
	void SetRelativePosition(double XPos, double YPos);
	void GetRelativePosition(double *dblCameraPosX, double *dblCameraPosY);

	void WorldToPixel(double dblWorldX, double dblWorldY, double *dblPixelX, double *dblPixelY);
	CRect WorldToPixel(CdblRect realRect);
	CPoint WorldToPixel(CdblPoint realPt);

	void PixelToWorld(double dblPixelX, double dblPixelY, double *dblWorldX, double *dblWorldY);
	CdblPoint PixelToWorld(CdblPoint pelPt);

	CdblSize ScaleSize();
	double ScaleWidth();
	double ScaleHeight();

protected:
	BOOL m_bIsCalibrated;


	double		m_dblOrgOffsetX;
	double		m_dblOrgOffsetY;

private:
	void TransformCoordinate(long  ResultType, double X, double Y, double *ResXPtr, double *ResYPtr);
};

#endif // !defined(AFX_MILCALIB_H__FF184C33_E165_11D4_960A_00C04F155F01__INCLUDED_)
