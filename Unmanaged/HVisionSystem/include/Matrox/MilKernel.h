// MilKernel.h: interface for the CMilKernel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILKERNEL_H__6611A8BA_D3F3_4F65_9FCF_021C38BBB06C__INCLUDED_)
#define AFX_MILKERNEL_H__6611A8BA_D3F3_4F65_9FCF_021C38BBB06C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MATROXCLASS.h"
#include "MilBuffer.h"

class MATROXCLASS CMilKernel : public CMilBuffer  
{
public:
	void Alloc(long sizeX, long sizeY, long type);

	void SetDefault();
	void SetAbsoluteValue(long OperationValue);
	void SetNormalizationFactor(long OperationValue);
	void SetOffsetCenterXY(long ControlType, long OperationValue);
	void SetOverScan(long OperationValue);
	void SetOverScanReplaceValue(long OperationValue);
	void SetSaturation(long OperationValue);

};

#endif // !defined(AFX_MILKERNEL_H__6611A8BA_D3F3_4F65_9FCF_021C38BBB06C__INCLUDED_)
