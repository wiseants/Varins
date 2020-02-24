// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__81CAD419_6FCA_4D7E_9837_0D49B18B2EB7__INCLUDED_)
#define AFX_STDAFX_H__81CAD419_6FCA_4D7E_9837_0D49B18B2EB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#pragma pack( push, enter_stdafx, 8 )

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define _CRT_SECURE_NO_WARNINGS

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows 95 and Windows NT 4 or later.
#define WINVER 0x0501		// Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0501		// Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0502 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 4.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target IE 5.0 or later.
#endif

#ifndef _UNICODE
#define _CRT_SECURE_NO_DEPRECATE
#define NO_WARN_MBCS_MFC_DEPRECATION
#endif

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT


#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>			// MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxtempl.h>

//#pragma pack( pop, enter_stdafx )

#if !defined(_DEBUG)
#define TRACE_SPI TRACE
#else
#define TRACE_SPI TRACE(_T("%s(%d) : "), __FILE__, __LINE__), TRACE
#endif

#pragma warning (disable : 4616)
#pragma warning (disable : 4786)
#pragma warning (disable : 1740)
#pragma warning (disable : 1744)
#pragma warning (once : 1125)
#pragma warning (once : 1595)


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__81CAD419_6FCA_4D7E_9837_0D49B18B2EB7__INCLUDED_)
