// MviException.h: interface for the CMviException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRACKEXCEPTION_H__AF8F984C_F46D_439E_98A5_8E0A74BD843B__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_TRACKEXCEPTION_H__AF8F984C_F46D_439E_98A5_8E0A74BD843B__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"
#include <afxmt.h>

class UTILITYCLASS CTrackException
{	
	static CStringList m_posLink;
	static CCriticalSection m_csPosLink;

protected:
	CString m_errorMsg;

	virtual ~CTrackException();
public:
	CTrackException();
	CTrackException(LPCTSTR msg);
	CTrackException(UINT errorID);
	CTrackException(UINT errorID, UINT reasonID);
	CTrackException(UINT errorID, LPCTSTR reasonStr);
	CTrackException(UINT errorID, CTrackException* e);
	CTrackException(LPCTSTR errorType, UINT reasonID);
	CTrackException(LPCTSTR errorType, LPCTSTR reasonStr);
	CTrackException(LPCTSTR errorType, CTrackException* e);

	static void PushPos(LPCTSTR position);
	static void PopPos();
	static void ClearPos();

	void Delete();
	virtual CString GetPosition();
	virtual CString GetErrorMessage();
};

#define TRACK_TRY(x)		\
	CTrackException::PushPos(_T(#x));		\
	try {

#define TRACK_TRY_EXIT		\
	CTrackException::PopPos();			\

#define TRACK_CATCH(e)			\
		CTrackException::PopPos();			\
	 } catch ( CTrackException* e) {		\
		CTrackException::PopPos();			\
		
#define TRACK_EXCEPT_HANDLE_IGNORE			\
		e->Delete();

#define TRACK_EXCEPT_HANDLE_SHOW					\
		if (e->GetErrorMessage() != _T("") ) 			\
			AfxMessageBox(e->GetErrorMessage(), MB_ICONSTOP);	\
		e->Delete();

#define TRACK_DEFAULT_CATCH(e)		\
		TRACK_CATCH(e)				\
		TRACK_EXCEPT_HANDLE_SHOW

#define TRACK_END }					

#define TRACK_DEFAULT_END(e)		\
		TRACK_DEFAULT_CATCH(e)		\
		TRACK_END

#endif // !defined(AFX_MVIEXCEPTION_H__AF8F984C_F46D_439E_98A5_8E0A74BD843B__INCLUDED_)
