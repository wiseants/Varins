/************************************************************************/
/*																		*/
/*	SYSTEM		:	Local Procedure Call								*/
/*	SUB SYSTEM	:	Dynamic DLL program of using LPC facility 			*/
/*	LANGUAGE	:	VC++ 2008											*/
/*																		*/
/*	FILE		:	LPCPFN.h											*/
/*																		*/
/*	CAUTION		:	PRIVATE SOURCE FOR Lee, Hyuk Sang					*/
/*																		*/
/*	AUTHER		:	Lee, Hyuk Sang(mydos16@gmail.com)					*/
/*																		*/
/************************************************************************/

#ifndef _LPC_PFN_H_
#define _LPC_PFN_H_

#include "LPCDLL.H"

//LPC option set
extern PFN_MIR_SETOPTION		pfnMIR_SetOption;

//LPC Port Creation
extern PFN_MIR_CREATEQUEUE		pfnMIR_CreateQueue;

//Send Message to LPC Port(server)
extern PFN_MIR_SENDMESSAGE		pfnMIR_SendMessage;

//LPC Port Check LPC Object
extern PFN_MIR_CHECKLPCOBJECT	pfnMIR_CheckLPCObject;

//LPC Port Destroy
extern PFN_MIR_DESTROYQUEUE		pfnMIR_DestroyQueue;

//initial part
extern PFN_LPC_INITIALIZE	pfnMIR_Initialize;

//destroy part
extern PFN_LPC_DESTROY		pfnMIR_Destroy;

BOOL MIRPFN_SetOption(DWORD option, DWORD timeout);
BOOL MIRPFN_DestroyQueue(LPCSTR pszIpcName);
BOOL MIRPFN_CreateQueue(LPCSTR pszIpcName, PIPC_CALLBACK_ROUTINE IpcCallback);
BOOL MIRPFN_CreateQueueEx(LPCSTR pszIpcName, PIPC_CALLBACK_ROUTINE IpcCallback, DWORD maxThreadCount);
BOOL MIRPFN_SendMessage(LPCSTR	pszIpcName, 
					   PVOID	pMessageBuf, 
					   DWORD	dwMessageLen, 
					   PVOID	pAnswerBuf = NULL, 
					   DWORD	dwAnswerLen = 0, 
					   DWORD	dwAnswerTimeOut = INFINITE, 
					   BOOL		bHandleMessages  = TRUE);

BOOL MIRPFN_CheckLPCObject(LPCSTR pszIpcName);

BOOL MIRPFN_Init();
BOOL MIRPFN_Destroy();
BOOL MIRPFN_LoadInit(HMODULE	s_hInst = NULL);


//local function
BOOL Load_LPC_DLL_API(HMODULE hDll);

#ifdef _UNICODE
#define GetFullPathDllName	GetFullPathDllNameW
#else
#define GetFullPathDllName	GetFullPathDllNameA
#endif

void GetFullPathDllNameA(HINSTANCE hInstance, const char * module, char fullname[]);
void GetFullPathDllNameW(HINSTANCE hInstance, const WCHAR * module, WCHAR fullname[]);

#endif //_LPC_PFN_H_
