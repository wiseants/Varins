#if !defined(AFX_UTILITYCLASS_H__E03BEEAF_8186_4DCC_8C30_E0F8124E2063__INCLUDED_)
#define AFX_UTILITYCLASS_H__E03BEEAF_8186_4DCC_8C30_E0F8124E2063__INCLUDED_

#include <windows.h>
#include <tchar.h>
#include <string>

using namespace std;

typedef std::basic_string<TCHAR> TString;
typedef std::basic_string<CHAR> AString;
typedef std::basic_string<WCHAR> WString;

#ifdef UTILITY_DLL
   #define UTILITYCLASS  _declspec(dllexport)
#else
   #define UTILITYCLASS  _declspec(dllimport)
#endif

#ifdef _DEBUG
#define UTILITY_MODULE_NAME _T("Utilityd.dll")
#else
#define UTILITY_MODULE_NAME _T("Utility.dll")
#endif
#endif

#define MIRTEC_GLOBAL_FONT	_T("Noto Sans CJK KR Bold")
