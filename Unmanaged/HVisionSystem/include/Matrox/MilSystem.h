// MilSystem.h: interface for the CMilSystem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILSYSTEM_H__9598BB13_4478_417F_9938_C8467B27F6B4__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_MILSYSTEM_H__9598BB13_4478_417F_9938_C8467B27F6B4__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MilCalib.h"
#include "MilGraphic.h"
#include "MATROXCLASS.h"
#include "MilObject.h"
#include "Utility/Log.h"

class CLog;

enum DIGITIZER_TYPE
{
	DIGITIZER_NONE = 0,
	DIGITIZER_SOLIOS,
	DIGITIZER_RADIENT_CLK,
	DIGITIZER_RADIENT_CXP,
	DIGITIZER_GIGE,
	DIGITIZER_ACTIVESILICON_CLK,
	DIGITIZER_ACTIVESILICON_CXP,
	DIGITIZER_TYPE_COUNT,
};

struct MATROXCLASS MilConstant
{
	static const int cStructElement;
	static const int cArray;
	static const __int64 cDefaultHost;
	static const int c3By3Rect;
	static const int cVertEdge;
	static const int cHorizEdge;
	static const int cSobel;
};

class MATROXCLASS CMilSystem : public MilObject  
{
public:
	
	virtual ~CMilSystem();

	static CMilSystem* Instance();
	static void Release();

	BOOL Alloc(int type);
	void Free();
	
	MIL_INT GetNumOfDigitizer();

	CMilGraphic* GetGraphic();

protected:
	CMilSystem();
	static CMilSystem* _instance;

	MIL_INT m_numberOfDigitizer;
	
	long m_lastErrorCode;
	void *pDioPortFunc;
};

inline CMilSystem* MxtGetSystem()
{
	return CMilSystem::Instance();
}

#endif // !defined(AFX_MILSYSTEM_H__9598BB13_4478_417F_9938_C8467B27F6B4__INCLUDED_)
