#pragma once

#include "UtilityClass.h"

struct UTILITYCLASS Locale
{
	CString name;
	CString shortName;
	LCID localeId;

	Locale() { }
	Locale(LPCTSTR _name, LPCTSTR _shortName, LCID _localeId)
	{
		name = _name;
		shortName = _shortName;
		localeId = _localeId;
	}
};

class UTILITYCLASS CLocaleTable
{
public:
	static BOOL GetLocale(LPCTSTR shortName, Locale& locale);
	static BOOL GetLocale(LCID localeId, Locale& locale);
	static BOOL	GetLocale(long index, Locale& locale);
};
