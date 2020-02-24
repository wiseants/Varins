/************************************************************************/
/*																		*/
/*	SYSTEM		:	Local Procedure Call								*/
/*	SUB SYSTEM	:	Dynamic DLL program of using LPC facility 			*/
/*	LANGUAGE	:	VC++ 2008											*/
/*																		*/
/*	FILE		:	LPCDLL.h											*/
/*																		*/
/*	CAUTION		:	PRIVATE SOURCE FOR Lee, Hyuk Sang					*/
/*																		*/
/*	AUTHER		:	Lee, Hyuk Sang(mydos16@gmail.com)					*/
/*																		*/
/************************************************************************/

#ifndef _LPC_DLL_H_
#define _LPC_DLL_H_

//-----------------------------------------------------------------------------
// if need, change timeout number
//-----------------------------------------------------------------------------
#define	  LPC_TIMEOUT			15000
#define	  LPC_SUB_TIMEOUT		30000
//-----------------------------------------------------------------------------

#define USE_LPC_LOGIC				(DWORD) 0x00000001
#define SET_INTERNAL_LPC_TIMEOUT	(DWORD) 0x00000002

//-----------------------------------------------------------------------------
// IPC Callback funtion routine proto type. (implementation)
//-----------------------------------------------------------------------------
typedef VOID (WINAPI *PIPC_CALLBACK_ROUTINE)(LPCSTR		pIpc, 
											 LPCVOID	pMessageBuf, 
											 DWORD		dwMessageLen, 
											 LPCVOID	pAnswerBuf, 
											 DWORD		dwAnswerLen);

/*-----------------------------------------------------------------------------
// MIR_AddAccessForEveryone. (not implementation)
//-----------------------------------------------------------------------------
typedef BOOL (WINAPI *MIR_AddAccessForEveryone)(HANDLE ph, DWORD access);

//-----------------------------------------------------------------------------
// MIR_CreateGlobalEvent. (not implementation)
//-----------------------------------------------------------------------------
typedef HANDLE (WINAPI *MIR_CreateGlobalEvent)(LPSTR name, BOOL manual, BOOL initialState);

//-----------------------------------------------------------------------------
// MIR_OpenGlobalEvent. (not implementation)
//-----------------------------------------------------------------------------
typedef HANDLE (WINAPI *MIR_OpenGlobalEvent)(LPSTR name);

//-----------------------------------------------------------------------------
// MIR_CreateGlobalFileMapping. (not implementation)
//-----------------------------------------------------------------------------
typedef HANDLE (WINAPI *MIR_CreateGlobalFileMapping)(LPSTR name, DWORD size);

//-----------------------------------------------------------------------------
// MIR_OpenGlobalFileMapping. (not implementation)
//-----------------------------------------------------------------------------
typedef HANDLE (WINAPI *MIR_OpenGlobalFileMapping)(LPSTR name, BOOL write);
*/
//-----------------------------------------------------------------------------
// MIR_CreateQueueEx. (implementation)
//-----------------------------------------------------------------------------
typedef BOOL (*PFN_MIR_CREATEQUEUEEX)(LPCSTR pszIpcName, PIPC_CALLBACK_ROUTINE IpcCallback, DWORD maxThreadCount, DWORD maxQueueLen);

//-----------------------------------------------------------------------------
// MIR_CreateQueue. (implementation)
//-----------------------------------------------------------------------------
typedef BOOL (*PFN_MIR_CREATEQUEUE)(LPCSTR pszIpcName, PIPC_CALLBACK_ROUTINE IpcCallback);

//-----------------------------------------------------------------------------
// MIR_SetOption. (implementation)
//-----------------------------------------------------------------------------
typedef BOOL (*PFN_MIR_SETOPTION)(DWORD option, DWORD timeout);

//-----------------------------------------------------------------------------
// MIR_SendMessage. (implementation)
//-----------------------------------------------------------------------------
typedef BOOL (*PFN_MIR_SENDMESSAGE)(LPCSTR	pszIpcName, 
										  PVOID	pMessageBuf, 
										  DWORD	dwMessageLen, 
										  PVOID	pAnswerBuf, 
										  DWORD	dwAnswerLen, 
										  DWORD	dwAnswerTimeOut, 
										  BOOL	bHandleMessages);

//-----------------------------------------------------------------------------
// MIR_DestroyQueue. (implementation)
//-----------------------------------------------------------------------------
typedef BOOL (*PFN_MIR_CHECKLPCOBJECT)(LPCSTR	pszIpcName);

//-----------------------------------------------------------------------------
// MIR_DestroyQueue. (implementation)
//-----------------------------------------------------------------------------
typedef BOOL (*PFN_MIR_DESTROYQUEUE)(LPCSTR	pszIpcName);

//-----------------------------------------------------------------------------
// LPC_Destroy. (implementation) 
//-----------------------------------------------------------------------------
typedef void (*PFN_LPC_DESTROY)();

//-----------------------------------------------------------------------------
// LPC_Initialize. (implementation) 
//-----------------------------------------------------------------------------
typedef BOOL (*PFN_LPC_INITIALIZE)(BOOL bEnable);

#endif		//_LPC_DLL_H_
