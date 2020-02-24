#pragma once

#if !defined(_WIN32_WINNT)
#error "Must have _WIN32_WINNT definition. Include stdafx.h before."
#endif

#include <setupapi.h>								// SetupAPI version and types
#include "UtilityClass.h"

#define DATA_PORT_MASK		0x0000FFFF
#define DATA_VIRTUAL_MASK	0x00010000

class CEnumDevInfo;									// forward declaration for typedef
typedef void (CALLBACK* EnumCallBack)(CObject*, const CEnumDevInfo*);

#define INFO_PORT_NAME		0x00000001
#define INFO_NAME			0x00000002
#define INFO_ALL			0x0FFFFFFF

#define INFO_NON_PRESENT	0x80000000

#define INFO_PORTS		(INFO_PORT_NAME | INFO_NAME)

class UTILITYCLASS CEnumDevInfo
{
public:
	CEnumDevInfo();

	unsigned m_nStatus;
	int m_nPortNum;									// COM ports only
	CString m_strPort;								// COM and LPT ports only
	CString m_strName;								// user friendly name
	CString m_strService;
	CString m_strManufacturer;
	CString m_strPnPName;
	CString m_strDescription;
	CString m_strClassName;
	CString m_strClassGUID;
};

class UTILITYCLASS CEnumDevices
{
public:
	CEnumDevices();
	~CEnumDevices();

	BOOL EnumSerialPorts(CObject* pList, EnumCallBack pCallBack, BOOL bPresent = TRUE);
	BOOL EnumDevices(unsigned nInfo, CObject* pList, EnumCallBack pCallBack, const GUID* lpGUID);
	static int GetPortFromName(LPCTSTR lpszPort);

	inline void GetComDeviceStr(CString& str, int nPort) const
	{ 
		if(nPort <= 0)
			return;

		str.Format(nPort < 10 ? _T("COM%d") : _T("\\\\.\\COM%d"), nPort); 
	}

protected:
	BOOL InitSetupApi();
	HDEVINFO GetClassDevs(const GUID* lpGUID, BOOL bPresent = TRUE);
	BOOL GetPropertyString(HDEVINFO hDevInfo, PSP_DEVINFO_DATA pDevInfoData, DWORD dwProperty, CString& str);
	BOOL GetCustomPropertyString(HDEVINFO hDevInfo, PSP_DEVINFO_DATA pDevInfoData, LPCTSTR lpszEntry, CString& str);
	void Error(LPCTSTR lpszFunction, bool bMsg = false) const;
};
