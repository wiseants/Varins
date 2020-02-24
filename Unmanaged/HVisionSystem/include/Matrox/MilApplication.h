#pragma once

#include "MilObject.h"
#include "MatroxClass.h"

class MATROXCLASS CMilApplication : public MilObject
{
public:
	CMilApplication();
	virtual ~CMilApplication();

private:
	BOOL				m_fErrorDisplay;

	MAPPHOOKFCTPTR		m_pPrevErrorHandlerPtr;
	void*				m_pErrorHandlerUserPtr;

	static CMilApplication* _Instance;

public:
	long _stdcall DisplayError(MIL_INT HookType, MIL_ID eventId);
	static long _stdcall DisplayErrorExt(long HookType, MIL_ID EventId, void *UserDataPtr);
	void RunErrorHandler();

	virtual void Free();

public:
	static CMilApplication* Instance();
	static void Release();

	BOOL Alloc();

	double GetVersion();

	MIL_UINT GetLicense();
	BOOL IsValid();

	int GetAccelValue();
	
	void SetMilSysErrMsg(BOOL fDisplay);
};

MATROXCLASS CMilApplication* MxtGetApplication();