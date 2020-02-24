#pragma once
#include "UtilityClass.h"

#define THREAD_DELAY_TIME		10

typedef struct _THREAD_DATA {
	LPTHREAD_START_ROUTINE Function;
	PVOID Context;
	HANDLE* pEvent;
}THREAD_DATA, *PTHREAD_DATA;

class UTILITYCLASS ThreadPool
{
public:
	ThreadPool(UINT maxThreads);
	virtual ~ThreadPool();

	BOOL Release(DWORD dwMilliseconds = THREAD_DELAY_TIME);

	BOOL CallbackWorkItem(LPTHREAD_START_ROUTINE Function, PVOID Context, ULONG Flags = WT_EXECUTEDEFAULT);

protected:
	static DWORD CALLBACK Callback(LPVOID lpThreadParameter);

private:
	UINT _maxThreads;
	HANDLE* _events;
	CRITICAL_SECTION _Lock;
};

