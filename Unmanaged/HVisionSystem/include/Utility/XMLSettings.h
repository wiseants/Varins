#if !defined(XMLSETTINGS_H)

#ifndef DOXYGEN_EXCLUDE
#define XMLSETTINGS_H
#endif

/////////////////////////////////////////////////////////////////////////////
// CXmlSettings window

//#include "MEDLEYCLASS.h"
#include "UtilityClass.h"
#include "XmlArchive.h"

class UTILITYCLASS CXmlSettings
{
// Construction
public:
	CXmlSettings(BOOL fSyncSave = FALSE);
	~CXmlSettings();

// Implementation
public:
	BOOL Initialize(CString fileName);
	void SetSyncMode(BOOL fSyncSave = TRUE);
	CXmlArchive* GetXmlArchive() { return &m_xmlArchive; }

	long GetSettingLong(CString keyString, CString valueName, long lDefaultValue);
	long SetSettingLong(CString keyString, CString valueName, long lValue);

	double GetSettingDouble(CString keyString, CString valueName, double lDefaultValue);
	long SetSettingDouble(CString keyString, CString valueName, double fValue);

	unsigned long GetSettingULong(CString keyString, CString valueName, unsigned long defaultValue);
	long SetSettingULong(CString keyString, CString valueName, unsigned long lValue);

	CString GetSettingString(CString keyString, CString valueName, CString cstrDefaultValue);
	long SetSettingString(CString keyString, CString valueName, CString cstrValue);
	BOOL DeleteSetting(CString keyString, CString valueName);

	BOOL Flush();

	CXmlNode* GetNode(CString keyString, BOOL fAddNodes=FALSE);
protected:
	CXmlArchive m_xmlArchive;
	CString m_fileName;
	BOOL m_fSyncSave;
};

#endif XMLSETTINGS_H

