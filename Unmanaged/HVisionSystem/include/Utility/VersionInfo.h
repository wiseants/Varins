/*
 Written by Steve Bryndin (fishbed@tezcat.com, steveb@gvsi.com).

 This code may be used in compiled form in any way you wish. This
 file may be redistributed unmodified by any means PROVIDING it is 
 not sold for profit without the authors written consent, and 
 providing that this notice and the authors name is included. 
 An email letting me know that you are using it would be 
 nice as well. 

 This software is provided "as is" without express or implied warranty. 
 Use it at you own risk! The author accepts no liability for any damages 
 to your computer or data these products may cause.
*/


// VersionInfo.h: interface for the CVersionInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VERSIONINFO_H__75CAB01F_DD4B_11D2_84FE_00801E035520__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_VERSIONINFO_H__75CAB01F_DD4B_11D2_84FE_00801E035520__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma comment (lib, "version.lib")

#include "UtilityClass.h"

class UTILITYCLASS CVersionInfo  
{
public:
	CString GetSpecialBuild();
	CString GetPrivateBuild();
	CString GetLegalTrademarks();
	CString GetInternalName();
	CString GetFileVersion();
	CString GetFileDescription();
	CString GetComments();
	CString GetCopyright();
	CString GetCompanyName();
	CString GetProductVersion();
	CString GetProductName();

	CVersionInfo();
	CVersionInfo(LPCTSTR lpszImageName);
	virtual ~CVersionInfo();

	CString GetVersion();
	CString GetBuildNumber();

	BOOL IsNewVersion(LPCTSTR lpszVersion);

private:
	void InitVer();
	LPCTSTR m_lpszImageName;
	CString m_strImage;
	DWORD	m_dwHandle;
	DWORD	m_dwSize;
	LPVOID	m_lpBuffer;
	LPVOID	m_lpData;
	UINT	m_uiDataSize;

	LCID	m_language;
	LCID	m_codePage;
};

#endif // !defined(AFX_EXECIMAGEVERSION_H__75CAB01F_DD4B_11D2_84FE_00801E035520__INCLUDED_)
