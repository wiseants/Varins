// $Log: Log.h,v $
// Revision 1.1.1.1  2007/06/11 08:33:58  hyunho
// no message
//
// Revision 1.2.6.1  2007/03/19 23:56:18  curtis
// no message
//
// Revision 1.2  2006/06/03 06:44:59  hsmin
// Initial Release
//
// Revision 1.1.4.1  2006/06/02 02:03:22  sbhong
// no message
//
// Revision 1.1.2.1  2006/05/09 08:56:24  sbhong
// no message
//
// Revision 1.1.1.1.32.1  2006/04/20 05:02:07  hsmin
// added pragma to suppress annoying message
//
// Revision 1.1.1.1  2004/09/20 09:07:17  curtis
// 최초 버전
//
// Revision 1.2  2002/10/28 00:11:44  curtis
// no message
//
// Revision 1.6  2002-01-05 11:01:58-06  wsenn
// fixed year of copyright
//
// Revision 1.5  2002-01-05 10:44:34-06  wsenn
// added copyright and permission notice
//
// Revision 1.4  2002-01-05 09:34:38-06  wsenn
// added file log appender and event log appender
//
// Revision 1.3  2001-11-14 21:41:02-06  wsenn
// lowercased method names
//
// Revision 1.2  2001-11-13 19:28:25-06  wsenn
// added CConsoleLogAppender and changed the vector to a vector of pointers
// for downstream polymorphism
//
// Revision 1.1  2001-11-11 14:16:52-06  wsenn
// first pass
//
// Revision 1.0  2001-11-11 13:05:49-06  wsenn
// Initial revision
//
//
// $Id: Log.h,v 1.1.1.1 2007/06/11 08:33:58 hyunho Exp $
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

#ifndef __LOG_H
#define __LOG_H

#pragma warning( disable : 4786)
#pragma warning( disable : 4251)
  
#include <string>	//string
#include <vector>	//vector
#include <utility>	//pair

#include "NsLog.h"
#include "LogAppender.h"
#include "ConsoleLogAppender.h"
#include "FileLogAppender.h"
#include "EventLogAppender.h"

#include "UtilityClass.h"

using namespace std;

class UTILITYCLASS CLog {
public:
	//default constructor
	CLog();	//filename will be the source
	
	//commonly used constructor
	CLog(TString source);
	
	//destructor
	~CLog();

	void clear();

	void Start();
	void Stop();

	//method to add appenders to the vector
	bool addAppender(CLogAppender * appender);

	//method for writing log messages to the appender logs
	bool writeLog(nsCLog::eSeverity severity, TString message);

private:
	vector<CLogAppender *> vecAppender;

	TString mStrSource;
	bool mLogActivated;
};

UTILITYCLASS CLog& GetModelLoadLog();
UTILITYCLASS CLog& GetModelSaveLog();
UTILITYCLASS CLog& GetOperationLog();

#endif
