

#ifndef __NSLOG_H
#define __NSLOG_H

#pragma warning( disable : 4786)

#include "UtilityClass.h"

using namespace std;

namespace nsCLog {
	enum eSeverity {
		debug	=	100,
		info	=	200,
		warning	=	300,
		error	=	400,
		fatal	=	500,
		coreInfo =  600
	};
	
	enum eBits {
		KB = 1024,
		MB = 1048576
	};
	
	extern TString strDebug;
	extern TString strInfo;
	extern TString strWarn;
	extern TString strError;
	extern TString strFatal;
	extern TString strCoreInfo;

	TString getThresholdAsString(nsCLog::eSeverity threshold);
};

#endif