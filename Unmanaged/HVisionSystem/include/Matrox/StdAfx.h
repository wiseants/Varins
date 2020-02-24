// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__DA009AC3_DCC8_4E6F_BF85_53D32274FC0B__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_STDAFX_H__DA009AC3_DCC8_4E6F_BF85_53D32274FC0B__INCLUDED_
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

#ifndef WINVER                          // Specifies that the minimum required platform is Windows Vista.
#define WINVER 0x0501           // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _UNICODE
#define NO_WARN_MBCS_MFC_DEPRECATION
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#pragma pack( push, enter_stdafx, 8 )

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

#ifdef _M_IX86
#define BW_COMPATIBILITY 0x80
#endif

#include <mil.h>

//#pragma pack( pop, enter_stdafx )

//*
#define _SPI_HEIGHT_SYNC
//*/

//#define _ZSCAN_DLL_VERSION

#define _SPI_PROBE_THREAD

/*
#define _SPI_HEIGHTER
//*/

//#define MATROX_EXCEPTION

#pragma warning (disable : 4786)
#pragma warning (disable : 4616)
#pragma warning (disable : 1740)
#pragma warning (disable : 1744)
#pragma warning (once : 1125)
#pragma warning (once : 1595)

#include "Utility/LPCLog.h"

#ifdef _UNICODE
#include "Utility/StringSupport.h"
#endif

extern HINSTANCE g_hInst;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__DA009AC3_DCC8_4E6F_BF85_53D32274FC0B__INCLUDED_)
