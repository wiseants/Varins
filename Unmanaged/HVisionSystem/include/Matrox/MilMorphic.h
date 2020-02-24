// MilMorphic.h: interface for the CMilMorphic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILMORPHIC_H__54A81CEC_37A4_41DF_BCEB_895F281BC2FB__INCLUDED_)
#define AFX_MILMORPHIC_H__54A81CEC_37A4_41DF_BCEB_895F281BC2FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MATROXCLASS.h"

class MATROXCLASS CMilMorphic  
{
public:
	static void Morphic(CMilImage* pSrcImage, CMilImage* pDestImage, CMilImage &StructEle, long Operation, long NbIteration, long ProcMode);
	static void Erode(CMilImage* pSrcImage, CMilImage* pDestImage, long nIteration, long nProcMode);
	static void Dilate(CMilImage* pSrcImage, CMilImage* pDestImage, long nIteration, long nProcMode);
	static void Open(CMilImage* pSrcImage, CMilImage* pDestImage, long nIteration, long nProcMode);
	static void Close(CMilImage* pSrcImage, CMilImage* pDestImage, long nIteration, long nProcMode);
	static void Thin(CMilImage* pSrcImage, CMilImage* pDestImage, long nIteration = M_TO_SKELETON, long nProcMode = M_BINARY);
	static void Thick(CMilImage* pSrcImage, CMilImage* pDestImage, long nIteration = M_TO_SKELETON, long nProcMode = M_BINARY);
	static void FillHoles(CMilImage* pSrcImage, CMilImage* pDestImage, long lArea);
};

#endif // !defined(AFX_MILMORPHIC_H__54A81CEC_37A4_41DF_BCEB_895F281BC2FB__INCLUDED_)
