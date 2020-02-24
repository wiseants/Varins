// ColorConverter.h: interface for the CColorConverter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORCONVERTER_H__D6127856_493B_44E1_85A8_9134229B2837__INCLUDED_)
#define AFX_COLORCONVERTER_H__D6127856_493B_44E1_85A8_9134229B2837__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MATROXCLASS.h"
#include "MilImage.h"

#define LAB_MIN_L  0.0
#define LAB_MAX_L  4.016567
#define LAB_MIN_A -9.878585
#define LAB_MAX_A  2.718396
#define LAB_MIN_B -5.982799
#define LAB_MAX_B  5.571535
#define LUV_MIN_L  0.0
#define LUV_MAX_L  4.016567
#define LUV_MIN_U -6.259813
#define LUV_MAX_U  1.851449
#define LUV_MIN_V -2.190312
#define LUV_MAX_V  4.351217

class MATROXCLASS CColorConverter
{
public:
	static BOOL TransPolarToCartesian(CSize sizeImage, double hue, double sat, double* col, double* row);
	
	static CMilImage* CreateSectionImage_HS(double nBrightness);
	static CMilImage* CreateSectionImage_RB(int nGreen);

	static CMilImage* CreateAxisImage_V();
	static CMilImage* CreateAxisImage_G();
	static CMilImage* CreateAxisImage_Blue();
	static CMilImage* CreateAxisImage_Red();
	static CMilImage* CreateBlueRatioImage(long colorRatio);
	static CMilImage* CreateRedRatioImage(long colorRatio);

	static void RGB2HSV(int nR, int nG, int nB, double* hr, double* sr, double* vr, double whiteRGBRef);
	static void RGB2HSV(double dblR, double dblG, double dblB, double* hr, double* sr, double* vr, double whiteRGBRef);
	static void HSV2RGB(double dblHue, double dblSat, double dblValue, int* nR, int* nG, int* nB, double whiteRGBRef);	
	static void HSV2RGB(double dblHue, double dblSat, double dblValue, double* dblR, double* dblG, double* dblB, double whiteRGBRef);
	
	static void RGB2LAB(int nR, int nG, int nB, double *l, double *a, double *b, double whiteRGBRef);
	static void LAB2RGB(double L, double a, double b, int* nR, int* nG, int* nB, double whiteRGBRef);

	static void RGB2XYZ(int nR, int nG, int nB, double *x, double *y, double *z, double whiteRGBRef);
	static void XYZ2RGB(double x, double y, double z, int* nR, int* nG, int* nB, double whiteRGBRef);

	static void RGB2LUV(int nR, int nG, int nB, double *l, double *u, double *v, double whiteRGBRef);
	static void LUV2RGB(double l, double u, double v, int* nR, int* nG, int* nB, double whiteRGBRef);
	
	static void RGB2YCrCb(int nR, int nG, int nB, double *Y, double *Cr, double *Cb, double whiteRGBRef);
	static void RGB2YCbCr_A(int nR, int nG, int nB, double *Y, double *Cr, double *Cb);
	static void YCrCb2RGB_A(double y, double cr, double cb, int* nR, int* nG, int* nB);

	static void RGB2YIQ (int nR, int nG, int nB, double *y, double *i, double *q);
	static void RGB2RGBY (int nR, int nG, int nB, double *ry, double *gy, double *by);
	static void RGB2YES(int nR, int nG, int nB, double *y, double *e, double *s);
	static void RGB2YUV(int nR, int nG, int nB, double *y, double *u, double *v);
	static void XYZ2UVWPrime(double x, double y, double z, double* up, double* vp, double* wp);
	static void RGB2xyY(int nR, int nG, int nB, double *x, double *y, double *Y, double whiteRGBRef);
	static void RGB2WR(int nR, int nG, int nB, double  *wr);

	static double Normalize(double dblInputMin, double dblInputMax, double dblOutputMin, double dblOutputMax, double value);
};

#endif // !defined(AFX_COLORCONVERTER_H__D6127856_493B_44E1_85A8_9134229B2837__INCLUDED_)
