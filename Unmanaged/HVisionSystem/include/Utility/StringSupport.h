// StringSupport.h: interface for the StringSupport class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRINGSUPPORT_H__44B5E3F1_76BF_4361_8CC1_F047E0AA012B__INCLUDED_)
#define AFX_STRINGSUPPORT_H__44B5E3F1_76BF_4361_8CC1_F047E0AA012B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"

class UTILITYCLASS CStringSupport
{
public:
	static CFont* m_pgFont;
	static CFont* GetGlobalFont();
	static CFont* CreateGlobalFont();

	static CString MakeShortString(CDC* pDC, LPCTSTR lpszLong, int width);
	static int WildCmp(LPCTSTR wild, LPCTSTR string);	
	static CString N2C(INT_PTR n);

#ifdef _M_X64
	static CString N2C(long n);
	static CString N2C(int n);
#endif	

	static CString N2C(double f, LPCTSTR format = _T("%.3f"));	
	static CString N2C(UINT n);
	static CString N2D(double val);
	static CString N2F(float val);

	static BOOL GetGuid(CString& rString);
	static CString GetResString(UINT resID, HINSTANCE hModule = 0);
	static CString GetLanguageID();
	static CString FormatString(LPCTSTR pstrFormat, ...);
	static CString GetString(CStringList& stringList, LPCTSTR lineMarker = _T("\r\n"));
	static CString GetErrorMessage();
	static INT AnsiToUTF8(CStringA _strAnsi, PCHAR _strUtf8);
	static INT WideToUTF8(CStringW _strW, PCHAR _strUtf8);
	static CStringW UTF8toWide(PCHAR UTF8char);
	
	static CStringW AnsiToWideChar(CStringA str);
	static CStringA WideToAnsiChar(CStringW str);
 
	static BOOL IsNumber(LPCTSTR _string);
};

#define BOOL_STR(x) ((x)? _T("TRUE") : _T("FALSE"))

#endif // !defined(AFX_STRINGSUPPORT_H__44B5E3F1_76BF_4361_8CC1_F047E0AA012B__INCLUDED_)

