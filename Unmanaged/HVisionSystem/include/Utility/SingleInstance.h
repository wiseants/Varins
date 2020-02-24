// SingleInstance.h: interface for the CSingleInstance class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLEINSTANCE_H__C0A2C6BB_1EB8_4849_830E_5535EE45977C__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_SINGLEINSTANCE_H__C0A2C6BB_1EB8_4849_830E_5535EE45977C__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"

class UTILITYCLASS CSingleInstance  
{
	HANDLE m_hMutex;
	CString m_strClassName;
public:
	CSingleInstance();
	virtual ~CSingleInstance();

	BOOL CheckSingleInstance(LPCTSTR name);
	BOOL CheckSingleInstance(CWinApp * pApp , UINT nID, LPCTSTR additional=_T(""));
	CString GetClassName(void);
};

template <typename T>
class AFX_CLASS_EXPORT CSingleton
{
public:
	static T * InstancePtr()
	{
		if (ms_Instance == NULL)
			ms_Instance = new T;
		return ms_Instance;
	}

	static T & Instance()
	{
		if (ms_Instance == NULL)
			ms_Instance = new T;
		return *ms_Instance;
	}

	static void DestroyInstance()
	{
		delete ms_Instance;
		ms_Instance = NULL;
	}

private:
	static T * ms_Instance;
};

template<typename T> T* CSingleton<T>::ms_Instance = NULL;

#endif // !defined(AFX_SINGLEINSTANCE_H__C0A2C6BB_1EB8_4849_830E_5535EE45977C__INCLUDED_)
