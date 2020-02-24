// StopWatch.h: interface for the CStopWatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOPWATCH_H__1EF935FF_5B1C_4A58_B515_7C172A8DC206__INCLUDED_)
#define AFX_STOPWATCH_H__1EF935FF_5B1C_4A58_B515_7C172A8DC206__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"


#define USE_PERFORMANCE_TIMER

class UTILITYCLASS CStopWatch  
{
#ifdef USE_PERFORMANCE_TIMER
	LARGE_INTEGER m_startTime;
#else
	DWORD m_startTime;
#endif

	static bool fTimeFrqInitialized;
	static LARGE_INTEGER timeFrq;
public:
	CStopWatch();
	virtual ~CStopWatch();
	
	void Start();
	void Resume();
	void Pause();
	double Stop();
	BOOL IsStopped() { return m_fStopped; }
	BOOL IsAlarmed();

	double ElapsedTime();
	double TotalTime() {
		return m_totalTime;
	}

	void SetAlarmTime(long alarmTime);
	long GetAlarmTime()
	{
		return m_alarmTime;
	}
	void SetUseByAlarm(BOOL fUseByAlarm);

	double Reset();

	static void Sleep(long millisecond);
	static void Sleep(long millisecond, BOOL* bRun);
	static void NanoSleep(double nanoSecond);
		
//	void SetUseByAlarm(BOOL fUseByAlarm);
		
protected:
	BOOL m_fStopped;
	double m_totalTime;
	long m_alarmTime;
	BOOL m_fUseByAlarm;
};

#endif // !defined(AFX_STOPWATCH_H__1EF935FF_5B1C_4A58_B515_7C172A8DC206__INCLUDED_)
