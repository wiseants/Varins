// Registry.h: interface for the CRegistry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGISTRY_H__DA270FA8_B56D_42B6_AC87_20BBB618DB0D__INCLUDED_)
#define AFX_REGISTRY_H__DA270FA8_B56D_42B6_AC87_20BBB618DB0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"

#include <string>

typedef std::basic_string<TCHAR> RegValueStr;

class UTILITYCLASS CRegistry  
{
public:
	CRegistry(HKEY _hKey, LPCTSTR _lpszRoot);
	~CRegistry();
	
	BOOL ReadInt(LPCTSTR _lpszValue, OUT INT& _iResult);
	BOOL ReadString(LPCTSTR _lpszValue, OUT RegValueStr& _strResult);
	BOOL WriteInt(LPCTSTR _lpszValue, CONST INT& _iResult);
	BOOL WriteString(LPCTSTR _lpszValue, LPCTSTR _lpszResult);

protected:
	HKEY m_hKey;
};

#endif // !defined(AFX_REGISTRY_H__DA270FA8_B56D_42B6_AC87_20BBB618DB0D__INCLUDED_)
