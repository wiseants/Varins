// MilBuffer.h: interface for the CMilBuffer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILBUFFER_H__7E3531C6_6C41_4687_A57C_D34005BF2ABB__INCLUDED_)
#define AFX_MILBUFFER_H__7E3531C6_6C41_4687_A57C_D34005BF2ABB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <atltypes.h>
#include "MATROXCLASS.h"
#include "MilObject.h"

class MATROXCLASS CMilBuffer : public MilObject
{
public:
	CMilBuffer() ;
	CMilBuffer(MIL_ID mi);
	virtual ~CMilBuffer();
	void Free();

	void Alloc2d(long SizeX, long SizeY, long Type=8+M_UNSIGNED, long Attribute=M_IMAGE+M_DISP); // MIL_INT64
	void Put1d(long OffX, long SizeX, void *UserArrayPtr);
	void Get2d(long OffX, long OffY, long SizeX, long SizeY, void *UserArrayPtr) const;
	void GenerateWarpParameter(CMilBuffer* pMilLutX, CMilBuffer* pMilLutY, long OperationMode, long Transform,
		double Val1, double Val2);

	CRect GetBufRect() const;
	MIL_INT GetBufType() const;
	MIL_INT GetBufAttribute() const;
	CSize GetImageSize() const;
	long GetBufferSize();

	void Clear(double dblColor=0.0);
	void Put2d(long OffX, long OffY, long SizeX, long SizeY, void *UserArrayPtr);
	MIL_INT GetHostAddress() const;

	void PutColor2d(long OffX, long OffY, long SizeX, long SizeY, void *UserArrayPtr);
	long GetPitch(BOOL bByteValue);

protected:
	long	m_nBufAttribute;
	long	m_nBufType;
};

#endif // !defined(AFX_MILBUFFER_H__7E3531C6_6C41_4687_A57C_D34005BF2ABB__INCLUDED_)
