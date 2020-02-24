#pragma once

#include "UtilityClass.h"

class UTILITYCLASS CTimeSupport
{
public:
	CTimeSupport(void);
	~CTimeSupport(void);

	static COleDateTime GetTime();
	//************************************
	// FullName:  CTimeSupport::GetFormatTime
	// Returns:   CString
	// Parameter: LPCTSTR lpFormat
	// Format String : [%Y]Year [%M]Month [%D]Day [%h]Hour [%m]Minute [%s]Second
	//************************************
	static CString FormatTime(LPCTSTR lpFormat);
	static CString FormatTime(COleDateTime& _time, LPCTSTR lpFormat);
	static COleDateTime ParseFormatTime(LPCTSTR lpDateTime, LPCTSTR _fmt);
	
	//************************************
	// FullName:  CTimeSupport::GetCurFormatTime
	// Returns:   CString
	// Parameter: LPCTSTR lpFormat
	// Format String : [%Y]Year [%M]Month [%D]Day [%h]Hour [%m]Minute [%s]Second [%S]Millisecond
	//************************************
	static CString CurFormatTime(LPCTSTR lpFormat);
};
