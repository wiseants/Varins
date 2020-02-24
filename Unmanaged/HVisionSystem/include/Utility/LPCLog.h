/****************************************************************************/
/*																			*/
/*	SYSTEM		:	Inspector system										*/
/*	SUB SYSTEM	:	CLPCLog send Text Log to other process 					*/
/*	LANGUAGE	:	VC++ 2008												*/
/*																			*/
/*	FILE		:	LPCLog.h												*/
/*																			*/
/*	CAUTION		:	PRIVATE SOURCE FOR MIRTEC Co., Ltd.						*/
/*																			*/
/*	AUTHER		:	Lee, Hyuk Sang(mydos16@gmail.com)						*/
/*																			*/
/****************************************************************************/
#ifndef _LPCLOG_H_
#define _LPCLOG_H_

#include "LPCDef.h"
#include "Utility/UtilityClass.h"
#include "LPC_Obj.h"

#ifdef _UNICODE																					
	#define	INSPSYSLOG(filetype, loglevel, hinst, msg) {												\
		CLPCLog::Insp_SystemLog(filetype, loglevel, hinst, __FILEW__, __LINE__, __FUNCTIONW__, msg);	\
	}
#else																							
	#define	INSPSYSLOG(filetype, loglevel, hinst, msg) {												\
		CLPCLog::Insp_SystemLog(filetype, loglevel, hinst, __FILE__, __LINE__, __FUNCTION__, msg);		\
	}
#endif																							

#ifdef _UNICODE																						
	#define	INSPSYSLOGARG(filetype, loglevel, hinst, msg,...) {															\
		CLPCLog::Insp_SystemLogArg(filetype, loglevel, hinst, __FILEW__, __LINE__, __FUNCTIONW__, msg, __VA_ARGS__);	\
	}
#else																								
	#define	INSPSYSLOGARG(filetype, loglevel, hinst, msg,...) {															\
		CLPCLog::Insp_SystemLogArg(filetype, loglevel, hinst, __FILE__, __LINE__, __FUNCTION__, msg, __VA_ARGS__);		\
	}
#endif																								

#define	INSPSYSLOG_INIT(filetype, loglevel, path, mutex) {					\
	CLPCLog::SPI_Send_LogInit(filetype, loglevel, path, mutex);			\
}

class UTILITYCLASS CLPCLog
{
public:
	CLPCLog();
	~CLPCLog();

	CLPCObj* m_pLPCObj;

	BOOL Init();
	void Destroy();

	static int GetLogLevel();
	static void SetLogLevel(int loglevel);

	static void Insp_SystemLog(SPI_SYSTEMLOG_FILE_TYPE sysLogFile, SPI_SYSTEMLOG_TYPE  systemLogType, HMODULE hInst, const TCHAR *strFile, const int lineNumber, const TCHAR *strFunction, const TCHAR *strMessage);
	static void Insp_SystemLogArg(SPI_SYSTEMLOG_FILE_TYPE sysLogFile, SPI_SYSTEMLOG_TYPE systemLogType, HMODULE hInst, const TCHAR *strFile, const int lineNumber, const TCHAR *strFunction, const TCHAR *strFormat, ...);

	static BOOL SPI_Send_LogInit(int filetype, int loglevel, LPCTSTR pszPath, LPCTSTR pszMutex);
	static BOOL SPI_Send_LogWrite(int filetype, int loglevel, LPCTSTR pszLog);

	BOOL SPI_Send_ProcessExit(LPCSTR pszIpcName);

	static BOOL CheckLPCObject(LPCSTR pszIpcName);
	static void SetReplyWnd(HWND hWnd){ m_hWnd = hWnd; }

protected:
	static int m_LogLevel;
	static HWND m_hWnd;

	static LPCTSTR GetFileNameAddress(LPCTSTR strFilePath);

	CRITICAL_SECTION	m_Crit;

	void LockInit();
	void LockClear();
	void Lock();
	void Unlock();
};

#endif //_LPCLOG_H_
