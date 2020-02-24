// NetworkSupport.h: interface for the CNetworkSupport class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETWORKSUPPORT_H__DCBC08DE_C198_4EB4_8301_A4263CE0275B__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_NETWORKSUPPORT_H__DCBC08DE_C198_4EB4_8301_A4263CE0275B__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"

class UTILITYCLASS CNetworkSupport  
{
public:
	CNetworkSupport();
	virtual ~CNetworkSupport();

	static CString GetComputerName();
	static void ShareFolder(LPTSTR machineName, LPTSTR shareName, LPTSTR modelPath);
	static BOOL CheckShare(LPTSTR machineName, LPTSTR shareName);
	static void AddUser(LPTSTR userID, LPTSTR passwd);
	static void Login(LPTSTR folderName, LPTSTR userID, LPTSTR passwd);
};

#endif // !defined(AFX_NETWORKSUPPORT_H__DCBC08DE_C198_4EB4_8301_A4263CE0275B__INCLUDED_)
