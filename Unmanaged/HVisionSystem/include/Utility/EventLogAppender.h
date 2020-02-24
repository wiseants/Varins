//
// $Log: EventLogAppender.h,v $
// Revision 1.1.1.1  2007/06/11 08:33:58  hyunho
// no message
//
// Revision 1.2  2006/06/03 06:44:47  hsmin
// Initial Release
//
// Revision 1.1.4.1  2006/06/02 02:03:22  sbhong
// no message
//
// Revision 1.1.2.1  2006/05/09 08:56:24  sbhong
// no message
//
// Revision 1.1.1.1  2004/09/20 09:07:17  curtis
// 최초 버전
//
// Revision 1.3  2002/12/14 09:28:45  curtis
// no message
//
// Revision 1.2  2002/10/28 00:11:44  curtis
// no message
//
// Revision 1.2  2002-01-05 11:02:00-06  wsenn
// fixed year of copyright
//
// Revision 1.1  2002-01-05 10:44:34-06  wsenn
// added copyright and permission notice
//
// Revision 1.0  2002-01-05 09:32:39-06  wsenn
// Initial revision
//
//
// $Id: EventLogAppender.h,v 1.1.1.1 2007/06/11 08:33:58 hyunho Exp $
//
// COPYRIGHT AND PERMISSION NOTICE
//
// Copyright (c) 2002 Will Senn
//
// All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, provided that the above
// copyright notice(s) and this permission notice appear in all copies of
// the Software and that both the above copyright notice(s) and this
// permission notice appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT
// OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL
// INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING
// FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
// NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
// WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
// Except as contained in this notice, the name of a copyright holder
// shall not be used in advertising or otherwise to promote the sale, use
// or other dealings in this Software without prior written authorization
// of the copyright holder.
//

#ifndef __EVENTLOGAPPENDER_H
#define __EVENTLOGAPPENDER_H

#include <windows.h>
#include <string>

#include "NsLog.h"
#include "LogAppender.h"

#include "UtilityClass.h"

using namespace std;

class UTILITYCLASS CEventLogAppender : public CLogAppender {
public:
	//default constructor
	CEventLogAppender();
	
	//commonly used constructor
	CEventLogAppender(nsCLog::eSeverity threshold,
		TString strFormat = TString(_T("%d_%t | %s | %e | %m")));

	//destructor
	virtual ~CEventLogAppender();

	bool CEventLogAppender::registerEventLog(TString source);
	bool CEventLogAppender::deRegisterEventLog();

	
	//inherited and overriden
	virtual bool writeLog(nsCLog::eSeverity severity, TString message);

private:
	HANDLE hEventLogHandle;
	bool bIsOpen;
};


#endif
