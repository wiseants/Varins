// MilArith.h: interface for the CMilArith class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILARITH_H__93517467_A3B7_43B1_9275_DB56799AFB27__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_MILARITH_H__93517467_A3B7_43B1_9275_DB56799AFB27__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMilImage;

#include "MATROXCLASS.h"

class MATROXCLASS CMilArith  
{
public:
	//Using two Image(image,image)
	static void Add(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage, BOOL bSaturation);
	static void And(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage);
	static void Divide(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage);
	static void Max(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage);
	static void Min(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage);
	static void Multiply(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage, BOOL bSaturation);
	static void Nand(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage);
	static void Nor(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage);
	static void Or(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage);
	static void Subtract(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage, BOOL bSaturation);
	static void AbsSubtract(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage, BOOL bSaturation);
	static void Xor(CMilImage* pSrcImage1, CMilImage* pSrcImage2, CMilImage* pDestImage);
	static ULONG CountDifference(CMilImage* pSrcImage, CMilImage* pSrcImage2);

	//Using one Image and a constant(image, constant)
	static void Add(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage, BOOL bSaturation);
	static void And(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage);
	static void Divide(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage);
	static void Max(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage);
	static void Min(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage);
	static void Multiply(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage, BOOL bSaturation);
	static void Nand(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage);
	static void Nor(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage);
	static void Or(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage);
	static void Xor(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage);
	static void Subtract(CMilImage* pSrcImage, double fConstant, CMilImage* pDestImage, BOOL bSaturation);

	// Using one Image(image)
	static void Abs(CMilImage* pSrcImage, CMilImage* pDestImage);
	static void Not(CMilImage* pSrcImage, CMilImage* pDestImage);
};

#endif // !defined(AFX_MILARITH_H__93517467_A3B7_43B1_9275_DB56799AFB27__INCLUDED_)
