// MilIm.h: interface for the CMilIm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILIM_H__60DCC28D_526E_4F05_A9AA_1F68B6A1ABAD__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_MILIM_H__60DCC28D_526E_4F05_A9AA_1F68B6A1ABAD__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMilImage;

#include "MATROXCLASS.h"
#include "MilBuffer.h"

enum FlipOperation {
	flipHorizontal = M_FLIP_HORIZONTAL,
	flipVertical = M_FLIP_VERTICAL
};

class MATROXCLASS CMilIm  
{
public :
	CMilIm();
	~CMilIm();

// Implementations
public :
	long LocalLevelFactor(long lBackgroundRef);
	long LocalBinarize(long lBackgroundRef, long nLevelFactor = 0);
	long Fill(long sx, long sy, long color, long SizeX, long SizeY, BYTE *img);
	long Yen(); // Auto Threshold Method
	long MaxEntropy(); // Auto Threshold Method
	long Otsu(void); // Auto Threshold Method
	long Li(); // Auto Threshold Method
	long CalcAutoThreshold(long* pHistCount, double cntData, long minValue, long maxValue);

	BOOL Alloc(long NbEntries, long ResultType);
	void Free(DWORDLONG ResultType = M_ALL_BUFFER_TYPES);
	void GetResult(long ResultType, void *UserArrayPtr);
	BOOL Histogram(long* pHistCnt);
	long FindExtreme(long ExtremeType);
	unsigned long CountDifference(void);

	void Hue(const long nTolerance);
	void Saturation(const long nTolerance);

	void SetSrcImage(CMilImage *pMilImage) { m_pSrcMilImage = pMilImage; }
	void SetDestImage(CMilImage *pMilImage) { m_pDestMilImage = pMilImage; };

	MIL_INT Binarize(long Condition, double CondLow, double CondHigh);
	void Clip(long Condition, double CondLow, double CondHigh, double WriteLow, double WriteHigh);
//	void Project(double ProjAngle = M_0_DEGREE);

	void Contrast(const long &lRef = 127);
	void Brightness(const long &lRef = 127);
	BOOL HistogramNormalization(long InLow = 0, long InHigh = 255, long OutLow = 0, long OutHigh = 255);

	void WarpByPolynomial(CMilBuffer* pWarpParam, long OperationMode, long InterpolationMode);
	void WarpByLUT(CMilBuffer* pWarpParam1, CMilBuffer* pWarpParam2, long OperationMode, long InterpolationMode);

private :
	CMilImage *m_pSrcMilImage;
	CMilImage *m_pDestMilImage;

//	static long			m_nHistCount[256];

//	MIL_ID				m_MilProjID;
	MIL_ID				m_MilHistID;
	MIL_ID				m_MilCountID;
	MIL_ID				m_MilExtreamID;

// 
public:
	static void Histogram(CMilImage* pImage, long* pResult);	
	static BOOL Histogram(long* pProjData, long cntDomain, long cntRange, long* pResult);
	static MIL_INT Binarize(CMilImage* pSrcImage, CMilImage* pDestImage, MIL_INT Condition, double CondLow, double CondHigh);
	static BOOL HistogramNormalization(CMilImage* pSrcImage, CMilImage* pDestImage, long InLow, long InHigh, long OutLow, long OutHigh);
	static void Rotate(CMilImage* pSrcImage, CMilImage* pDestImage, double Angle, double SrcCenX, double SrcCenY, 
					double DstCenX, double DstCenY, long InterpolationMode);
	static void Resize(CMilImage* pSrcImage, CMilImage* pDestImage, double ScaleFactorX, double ScaleFactorY, long InterpolationMode);
	static void SemiBinarize(CMilImage* pSrcImage, CMilImage* pDestImage, long Condition, double CondLow, double CondHigh, long setValue = 0);
	static BOOL HSLBinarize(CMilImage* pSrcHSLImage, CMilImage* pDestImage, double CondLowH, double CondHighH, double CondLowS, double CondHighS, double CondLowL, double CondHighL);
	static void GetMinMaxGrayValue(CMilImage* pImage, long &max, long &min);
	static void RemoveSmallBlobs(CMilImage *pMilSrcImage, CMilImage* pMilDstImage, int condHigh);
	/////////////////// by sub ///////////////////////
	static BOOL RGBBinarize(CMilImage* pSrcRGBImage, CMilImage* pDestImage, MIL_INT Condition, double CondLowR, double CondHighR, double CondLowG, double CondHighG, double CondLowB, double CondHighB);
};

#endif // !defined(AFX_MILIM_H__60DCC28D_526E_4F05_A9AA_1F68B6A1ABAD__INCLUDED_)
