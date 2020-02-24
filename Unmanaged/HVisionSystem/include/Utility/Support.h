// Support.h: interface for the Support class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUPPORT_H__F6540FA8_E6B6_4C46_85C5_FBDD19F1A2E7__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_SUPPORT_H__F6540FA8_E6B6_4C46_85C5_FBDD19F1A2E7__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Defines.h"
#include "UtilityClass.h"

struct stCustomRectParam
{
	enum
	{
		ARC = 0,
		TRIANGLE,
	};

	int nType;
	TSize szSize;

	stCustomRectParam()
	{
		nType = ARC;
		szSize.cx = 50;
		szSize.cy = 50;
	}

	void operator=(const stCustomRectParam& dstParam)
	{
		nType = dstParam.nType;
		szSize = dstParam.szSize;
	}
};

class UTILITYCLASS CSupport  
{
public:
//	static BOOL GetGuid(CString& rString);
//	static void DeleteDir(const CString& strDirpath, BOOL bOnlyFiles = FALSE);
//	static BOOL CopyDir(const CString strSourcePath, const CString strTargetPath, CWnd *pWnd);
	static BOOL CheckValidFileName(LPCTSTR modelName);
	static BOOL CheckValidFileName2(LPCTSTR modelName);  //except "/:"
	static double GetAngle(const TPoint& basePt, const TPoint& point1, const TPoint& point2);
	static BOOL IsSloped(double angle);
	static double Round(double lfValue, int nPos, BOOL fFloor=FALSE);

	// 동작을 지연시키나 지연되는 사이에 시스템 메시지가 정상적으로 호출된다.
	static void Delay(DWORD dwMillisecond);
	static void PumpMessage();
	static void PumpMessage2();
	// 사분면 구하기
	static long Quadrant(CPoint ptCenter, CPoint pt);
};

#endif // !defined(AFX_SUPPORT_H__F6540FA8_E6B6_4C46_85C5_FBDD19F1A2E7__INCLUDED_)
