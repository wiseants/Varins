#ifndef _FUNCTION_PROFILER_
#define _FUNCTION_PROFILER_

#pragma once
#include <afxtempl.h>
#include <atlcoll.h>

#ifdef _MT
#include <afxmt.h>
#endif

#include "UtilityClass.h"

#define FUNCTION_PROFILE

// define a handy macro to use
#ifdef FUNCTION_PROFILE
#define DO_FUNCTION_PROFILE(x) CFunctionProfiler profiler(_T(#x));
#define DO_FUNCTION_PROFILE_STR(x) CFunctionProfiler profiler(x);
#else
#define DO_FUNCTION_PROFILE 
#endif

#pragma pack(8)

// profiler record: registers at function entry and exit points
typedef struct
{
	BOOL			m_bEntry;
	LARGE_INTEGER	m_lnTimeStamp;  // "total-time" timestamp
	LARGE_INTEGER	m_lnTimeStampE; // "execution" timestamp
	DWORD			m_dwThreadId;	// thread-id
	TCHAR*			m_pszFuncName;
} ProfRecord;

// function record: records the statistics for each function
typedef struct
{
	int		m_nInvoke;
	double		m_nTotElapsed;
	double		m_nExecElapsed;
} FuncRecord;

// helper class: a stack for calculation of duration of each invocation of fuction
class CStack
{
public:
	CStack(){}

	~CStack(){}

	void Push(ProfRecord* lpProfRec)
	{
		m_listProfRec.AddHead(lpProfRec);
	}

	ProfRecord* Pop()
	{
		if (m_listProfRec.GetCount() > 0)
			return m_listProfRec.RemoveHead();
		else
			return NULL;
	}

	// AddStack() increase the entry time to offset other function execution times
	// each thread has its own stack
	void AddStack(ULONGLONG ullTickDiff, DWORD dwThreadId)
	{
		for (POSITION pos = m_listProfRec.GetHeadPosition(); pos != NULL; )
		{
			ProfRecord* pProfRec = m_listProfRec.GetNext(pos);
			if (pProfRec && pProfRec->m_dwThreadId == dwThreadId && pProfRec->m_bEntry)
				pProfRec->m_lnTimeStampE.QuadPart += ullTickDiff;
		}
	}

	int GetCount()
	{
		return (int)m_listProfRec.GetCount();
	}

	CString GetCascadeName(DWORD dwThreadId)
	{
		CString cascadeName;
		for (POSITION pos = m_listProfRec.GetHeadPosition(); pos != NULL; )
		{
			ProfRecord* pProfRec = m_listProfRec.GetNext(pos);
			if (pProfRec && pProfRec->m_dwThreadId == dwThreadId && pProfRec->m_bEntry)
				cascadeName += CString(pProfRec->m_pszFuncName) + _T("\\");
		}

		return cascadeName;
	}

private:
	CAtlList<ProfRecord*> m_listProfRec;
};

// the main class
class UTILITYCLASS CFunctionProfiler
{
public:
	// the constructor and the destructor each registers a ProfRecord 
	// at the entry and the exit points of the functions
	CFunctionProfiler(TCHAR* lpszFuncName);
	~CFunctionProfiler();

	// exports results to a CSV file
	// call when all profiling is done
	static void ExportProf(CString strFileName=_T("")); 

	static BOOL m_fUseFunctionProfiling;
	static BOOL m_fUseCascadeName;

private:
	// get a stack from g_mapStack according to the thread
	// if there is none, add a stack into g_mapStack
	static CStack* GetStack(DWORD dwThreadId); 
	TCHAR*	m_pszFuncName; // record the function name so that the destructor 
						   //knows of which function the exit point is

	// a CS to protect the operations of the static collections
	#ifdef _MT
	static CCriticalSection g_critSect;
	#endif

	static CAtlList<ProfRecord*> g_listProfRec; // a list if ProfRecord
	static CMap<CString, LPCTSTR, FuncRecord*, FuncRecord*> g_mapFuncRec; // a table of statistics
	static CMap<DWORD, DWORD, CStack*, CStack*> g_mapStack; // a map of stacks for calculation of the execution times
};

#pragma pack()

#endif





















