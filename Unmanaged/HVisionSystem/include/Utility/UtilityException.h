// UtilityException.h: interface for the UtilityException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTILITYEXCEPTION_H__A861530E_161E_4A6B_8A9D_A762F27CDACB__INCLUDED_)
#define AFX_UTILITYEXCEPTION_H__A861530E_161E_4A6B_8A9D_A762F27CDACB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"

namespace Utility
{
	enum
	{
		CreateOverlappedEventFailed,
		MonitorThreadAlreadyStarted,
		ErrorReadingComPort,
		ErrorWritingComPort
	};
}

#include <exception>

class UTILITYCLASS BaseException : public std::exception
{
public:
	BaseException();
	virtual ~BaseException() { }
	virtual LPCTSTR what() { return (LPCTSTR)GetErrorMessage(); }
	void Delete() { delete this; }

	virtual CString GetErrorMessage() = 0;
};

class UTILITYCLASS UtilityException : public BaseException
{
public:
	UtilityException(long nCode) : BaseException(), m_nCode(nCode) {}
	virtual CString GetErrorMessage();

protected:
	long m_nCode;
};


#endif // !defined(AFX_UTILITYEXCEPTION_H__A861530E_161E_4A6B_8A9D_A762F27CDACB__INCLUDED_)
