// MilLut.h: interface for the CMilLut class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILLUT_H__E6EE1469_1E95_445B_95DD_630B8394B358__INCLUDED_)
#define AFX_MILLUT_H__E6EE1469_1E95_445B_95DD_630B8394B358__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MATROXCLASS.h"
#include "MilBuffer.h"
#include <vector>

class CMilImage;

class MATROXCLASS CMilLut : public CMilBuffer
{
public:
	BOOL Alloc(long size, long type);
	BOOL Alloc(long sizeX, long sizeY, long type);
	BOOL LutMap(CMilImage* pSrcImage, CMilImage* pDestImage);

	BOOL Build(long* values, int size);
};

#endif // !defined(AFX_MILLUT_H__E6EE1469_1E95_445B_95DD_630B8394B358__INCLUDED_)
