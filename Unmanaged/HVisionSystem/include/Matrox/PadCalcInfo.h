#if !defined(_PAD_CALC_INFO_H_)
#define _PAD_CALC_INFO_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MATROXCLASS.h"
#include <vector>
#include "MilImage.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(x) if (x != NULL) delete x;
#endif

struct MATROXCLASS PadCalcInfo
{
	CMilImage* m_pZData[3];
	CMilImage m_avgImage;
	CMilImage m_sumImage;
	BOOL fSaveStepValue;
	VecMeasureStepValue m_vecMeasureStepValue;
	
	PadCalcInfo ()
	{
		m_pPadMask = NULL;
		m_p2DMask = NULL;
		
		m_pZData[0] = NULL;
		m_pZData[1] = NULL;
		m_pZData[2] = NULL;
		
		m_stencilThickness = 0;
	}
	
	~PadCalcInfo ()
	{
		SAFE_DELETE(m_pZData[0]);
		SAFE_DELETE(m_pZData[1]);
		SAFE_DELETE(m_pZData[2]);
	}
	
	void AddZData(float* pZRawData, CSize& imageSize, FLOAT padArea);
	CMilImage& GetAvgImage() { return m_avgImage; }
};

#endif //_PAD_CALC_INFO_H_