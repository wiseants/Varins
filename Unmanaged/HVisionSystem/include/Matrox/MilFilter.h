// MilFilter.h: interface for the CMilFilter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILFILTER_H__830CBAB8_0159_4EA1_9D5B_1B878A690243__INCLUDED_)
#define AFX_MILFILTER_H__830CBAB8_0159_4EA1_9D5B_1B878A690243__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMilKernel;
class CMilImage;

#include "MilKernel.h"
#include "MATROXCLASS.h"

enum eDirection {
	edHorizontal = 0,
	edVertical
};

class MATROXCLASS CMilFilter  
{
public:
	enum
	{
		Horizontal, Vertical
	};
	static void InitKernel();
	static void ReleaseKernel();

	static void MotionBlur(CMilImage* pSrcMilImage, CMilImage* pDestMilImage, long Direction = M_HORIZONTAL, long Speed = 16);
	static HRESULT Average_3by3(CMilImage* pSrcMilImage, CMilImage* pDestMilImage);
	static HRESULT Average_5by5(CMilImage* pSrcMilImage, CMilImage* pDestMilImage);
	static HRESULT Average_7by7(CMilImage* pSrcMilImage, CMilImage* pDestMilImage);
	static HRESULT Average_9by9(CMilImage* pSrcMilImage, CMilImage* pDestMilImage);

	static void SuppressArea(CMilImage* pSrcImage, CMilImage* pDestImage, long area);
	
	static void SuppressLength(CMilImage* pSrcImage, CMilImage* pDestImage, enum eDirection direction, long lMinLength);
	
	static HRESULT Smooth(CMilImage* pSrcImage, CMilImage* pDestImage);
	
	static void Median(CMilImage* pSrcImage, CMilImage* pDestImage, MIL_ID StructElemBufId, long ProcMode = M_GRAYSCALE);
	static void Median_CustomKernel(CMilImage* pSrcImage, CMilImage* pDestImage, long kernelSize, BOOL bCross, long ProcMode = M_GRAYSCALE);
	
	static void EdgeDetection(CMilImage* pSrcMilImage, CMilImage* pDestMilImage, long KernelBufId);

private:
	static CMilKernel* m_milKernel_Avg3by3;
	static CMilKernel* m_milKernel_Avg5by5;
	static CMilKernel* m_milKernel_Avg7by7;
	static CMilKernel* m_milKernel_Avg9by9;
};

#endif // !defined(AFX_MILFILTER_H__830CBAB8_0159_4EA1_9D5B_1B878A690243__INCLUDED_)
