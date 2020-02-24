#pragma once

#include "UtilityClass.h"

enum ProcessResult
{
	Process_Fail		= 0,
	Process_Success,
	Process_Cancel,
	Process_Timeout,
};

class UTILITYCLASS CProcessSupport
{
public:
	CProcessSupport(void);
	~CProcessSupport(void);

public:
	static BOOL OpenProcess(LPCTSTR _lpszExe, LPCTSTR _lpszArguments=NULL, BOOL _bIncludeAppPath=TRUE);
	static ProcessResult OpenProcessEx(LPCTSTR _lpszExe, LPCTSTR _lpszArguments=NULL, BOOL _bIncludeAppPath=TRUE, HANDLE hOutputFile=NULL, DWORD dwWaitTime=0, BOOL fShowProgres=TRUE);
	static BOOL FindProcess(LPCTSTR _lpszExe, BOOL _bIncludeAppPath=TRUE);
	static BOOL KillProcess(LPCTSTR _lpszExe);
};
