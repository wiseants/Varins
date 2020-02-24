/************************************************************************/
/*																		*/
/*	SYSTEM		:	Local Procedure Call Object Class					*/
/*	SUB SYSTEM	:	Dynamic DLL program of using LPC facility 			*/
/*	LANGUAGE	:	VC++ 2008											*/
/*																		*/
/*	FILE		:	LPC_OBJ.h										*/
/*																		*/
/*	CAUTION		:	PRIVATE SOURCE FOR MIRTEC Co., Ltd.					*/
/*																		*/
/*	AUTHER		:	Lee, Hyuk Sang(mydos16@gmail.com)					*/
/*																		*/
/************************************************************************/

#ifndef _LPC_OBJ_H_
#define _LPC_OBJ_H_

#include "Utility/UtilityClass.h"
#include "LPCDLL.H"

#ifdef _UNICODE
#define GetFullPathDllName	GetFullPathDllNameW
#else
#define GetFullPathDllName	GetFullPathDllNameA
#endif

#ifdef _UNICODE
#define GetFullDirectoryName	GetFullDirectoryNameW
#else
#define GetFullDirectoryName	GetFullDirectoryNameA
#endif

void GetFullPathDllNameA(HINSTANCE hInstance, const char * module, char fullname[]);
void GetFullPathDllNameW(HINSTANCE hInstance, const WCHAR * module, WCHAR fullname[]);

void GetFullDirectoryNameA(HINSTANCE hInstance, char fullname[]);
void GetFullDirectoryNameW(HINSTANCE hInstance, WCHAR fullname[]);

class UTILITYCLASS CLPCObj
{
public :
	CLPCObj();
	~CLPCObj();

	BOOL SetOption(DWORD option, DWORD timeout);
	BOOL DestroyQueue(LPCSTR pszIpcName);
	BOOL CreateQueue(LPCSTR pszIpcName, PIPC_CALLBACK_ROUTINE IpcCallback);
	BOOL CreateQueueEx(LPCSTR pszIpcName, PIPC_CALLBACK_ROUTINE IpcCallback, DWORD maxThreadCount);
	BOOL SendMessage(LPCSTR	pszIpcName, 
					 PVOID	pMessageBuf, 
					 DWORD	dwMessageLen, 
					 PVOID	pAnswerBuf = NULL, 
					 DWORD	dwAnswerLen = 0, 
					 DWORD	dwAnswerTimeOut = INFINITE, 
					 BOOL		bHandleMessages  = TRUE);

	BOOL CheckLPCObject(LPCSTR pszIpcName);

	BOOL Init();
	BOOL Destroy();
	BOOL LoadInit(HMODULE	s_hInst = NULL);

protected :
	HMODULE		g_hDll;

	//local function
	BOOL Load_DLL_API(HMODULE hDll);

	//----------------------------------------------//
	//LPC option set
	//----------------------------------------------//
	PFN_MIR_SETOPTION		pfnMIR_SetOption;

	//----------------------------------------------//
	//LPC Port Creation
	//----------------------------------------------//
	PFN_MIR_CREATEQUEUE		pfnMIR_CreateQueue;

	//----------------------------------------------//
	//LPC Port Creation
	//----------------------------------------------//
	PFN_MIR_CREATEQUEUEEX		pfnMIR_CreateQueueEx;

	//----------------------------------------------//
	//Send Message to LPC Port(server)
	//----------------------------------------------//
	PFN_MIR_SENDMESSAGE		pfnMIR_SendMessage;

	//----------------------------------------------//
	//LPC Port Check LPC Object
	//----------------------------------------------//
	PFN_MIR_CHECKLPCOBJECT	pfnMIR_CheckLPCObject;

	//----------------------------------------------//
	//LPC Port Destroy
	//----------------------------------------------//
	PFN_MIR_DESTROYQUEUE		pfnMIR_DestroyQueue;

	//----------------------------------------------//
	//initial part
	//----------------------------------------------//
	PFN_LPC_INITIALIZE	pfnMIR_Initialize;

	//----------------------------------------------//
	//destroy part
	//----------------------------------------------//
	PFN_LPC_DESTROY		pfnMIR_Destroy;
};

#endif //_LPC_OBJ_H_
