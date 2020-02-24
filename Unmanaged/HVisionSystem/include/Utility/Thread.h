// Thread.h: interface for the Thread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREAD_H__C44A76D2_3646_4643_AD3D_B24F2F5E7565__INCLUDED_)
#define AFX_THREAD_H__C44A76D2_3646_4643_AD3D_B24F2F5E7565__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if defined(_MT) || defined(_DLL)
// Due to the nature of the multithreaded C runtime lib we need to use _beginthreadex()
// and _endthreadex() instead of CreateThread() and ExitThread(). See Q104641.
#include <process.h>
#endif

#include "UtilityClass.h"

/** java like interface. To use this interface, derive a class from this class
	overriding Run method. Call Start() to start the thread.

	class MyRunnable : public IRunnable
	{
	public:
		void Run() { // do something...  }
	};

	// later... to start thread
	MyRunnable* pRun = new MyRunnable;
	Thread* pThread = new Thread(pRun);
	pThread->Start();
*/
interface UTILITYCLASS IRunnable
{
	/** virtual destructor */
	virtual ~IRunnable() {}
	/** subclass should override this method. */
	virtual void Run() throw() = 0;
};

/** java like Win32 Thread class
	To use this class, derive a class and override Run method. 
	Call Start() to start the thread.
*/
class UTILITYCLASS Thread  
{
public:
	/** Constructor
	*/
	Thread(IRunnable* pRunnable=NULL) throw();
	/** virtual Destructor
	*/
	virtual ~Thread();
	/** Call this function to start Thread
	*/
	void Start(int nPriority = THREAD_PRIORITY_NORMAL) throw();
	/** Change priority with this function. Thread should be in Suspend state for this
	function to work.
	*/
	void SetPriority(int iPriority) const throw();
	/** returns current priority of the Thread
	*/
	int GetPriority() const throw();
	/** Suspend the thread. returns true if succeeded.
	*/
	bool Suspend() throw();
	/** Resume the suspended Thread. If thread is running, does nothing
	*/
	bool Resume() throw();
	/** Wait either Thread is finished or timeout. Needs caution since this function
	can cause dead-lock.
	*/
	bool Wait(DWORD dwTimeout = INFINITE) throw();
	/** Stop the thread calling TerminateThread API. Not recommended to call.
	*/
	void Stop() throw();
	/** returns if Thread is suspended
	*/
	bool IsSuspended() const throw();
	/** returns if Thread is running
	*/
	bool IsRunning() const throw();
	/** returns ExitCode using GetExitCodeThread API
	*/
	DWORD GetExitCode() const throw();
	/** Operator overloading to use Thread like a HANDLE.
	*/
	operator HANDLE() throw() { return m_hThread; }

protected:
	/** This function is the heart of the Thread. Override this function
	and you're in business.
	*/
	virtual void Run() throw() = 0;
	bool m_bStopThread;
	IRunnable* m_pRunnable;

private:
	static DWORD WINAPI ThreadProc(LPVOID pData);
	HANDLE m_hThread;
	bool m_bSuspended;
};

#endif // !defined(AFX_THREAD_H__C44A76D2_3646_4643_AD3D_B24F2F5E7565__INCLUDED_)
