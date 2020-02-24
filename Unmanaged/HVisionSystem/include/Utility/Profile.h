#ifndef _PROFILE_H_

#ifndef DOXYGEN_EXCLUDE
#define _PROFILE_H_
#endif

enum {
	FileNotDefined,
	FileOpenFailed,
	FileVersionIsNewer,
	FileVersionIsOlder,
	FileReadError,
	FileOK
};

#include "UtilityClass.h"

class UTILITYCLASS CProfile
{
	CString m_profilePath;

public:

	int	SetProfileFile(LPCTSTR fileName);
	int ChangeConfiguration(int oldVersion);

	CString GetProfilePath() { return m_profilePath; } 

	CString GetParameter ( LPCTSTR section , LPCTSTR key , LPCTSTR defaultValue);
	CString GetParameterExt ( LPCTSTR section , LPCTSTR key , LPCTSTR defaultValue , LPCTSTR ext);
	CString GetParameterVar ( LPCTSTR section , LPCTSTR key , int pos , LPCTSTR defaultValue);
	void SetParameter ( LPCTSTR section , LPCTSTR key , LPCTSTR value);
	void SetParameterExt ( LPCTSTR section , LPCTSTR key , LPCTSTR value , LPCTSTR ext);
	void SetParameterVar ( LPCTSTR section , LPCTSTR key , LPCTSTR firstValue , ... );

	double GetParameter ( LPCTSTR section , LPCTSTR key , double defaultValue);
	double GetParameterExt ( LPCTSTR section , LPCTSTR key , double defaultValue , LPCTSTR ext);
	double GetParameterVar ( LPCTSTR section , LPCTSTR key , int pos , double defaultValue);
	void SetParameter ( LPCTSTR section , LPCTSTR key , double value);
	void SetParameterExt ( LPCTSTR section , LPCTSTR key , double value , LPCTSTR ext);
	void SetParameterVar ( LPCTSTR section , LPCTSTR key , double firstValue , ... );

	float GetParameter ( LPCTSTR section , LPCTSTR key , float defaultValue);
	float GetParameterExt ( LPCTSTR section , LPCTSTR key , float defaultValue , LPCTSTR ext);
	float GetParameterVar ( LPCTSTR section , LPCTSTR key , int pos , float defaultValue);
	void SetParameter ( LPCTSTR section , LPCTSTR key , float value);
	void SetParameterExt ( LPCTSTR section , LPCTSTR key , float value , LPCTSTR ext);
	void SetParameterVar ( LPCTSTR section , LPCTSTR key , float firstValue , ... );

	int GetParameter ( LPCTSTR section , LPCTSTR key , int defaultValue);
	int GetParameterExt ( LPCTSTR section , LPCTSTR key , int defaultValue , LPCTSTR ext);
	int GetParameterVar ( LPCTSTR section , LPCTSTR key , int pos , int defaultValue);
	void SetParameter ( LPCTSTR section , LPCTSTR key , int value);
	void SetParameterExt ( LPCTSTR section , LPCTSTR key , int value , LPCTSTR ext);
	void SetParameterVar ( LPCTSTR section , LPCTSTR key , int firstValue , ... );
};

#endif
