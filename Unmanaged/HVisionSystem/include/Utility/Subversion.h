#pragma once

#define SVN_EXE				_T("svn.exe")
#define SVN_ADMIN_EXE		_T("svnadmin.exe")

#include <atlcoll.h>
#include "UtilityClass.h"

enum SVNUpdateResult
{
	UpdateSVN_Success		= 0,
	UpdateSVN_ServerError,
	UpdateSVN_Conflict,
	UpdateSVN_Skipped,
};

struct SVNRepoBrowserInfo
{
	// Directory or file
	CString type;
	// Working Path
	CString workingPath;
	// Server URL
	CString serverPath;
	// Revision No.
	long nRevisionNo;
	// Revision User
	CString author;
	// Revision Date
	CString date;
	// Modify Status( Normal / Modify / Conflict / Delete / Add )
	CString status;

	SVNRepoBrowserInfo()
	{
		type = _T("");
		workingPath = _T("");
		serverPath = _T("");
		nRevisionNo = 0;
		author = _T("");
		date = _T("");
		status = _T("");
	}

	friend bool operator == ( const SVNRepoBrowserInfo& listInfo, const SVNRepoBrowserInfo& compareInfo )
	{
		CString path1 = listInfo.workingPath;
		CString path2 = compareInfo.workingPath;

		if( path1.MakeUpper() == path2.MakeUpper() )
			return true;

		return false;
	}
};

typedef CAtlList<SVNRepoBrowserInfo> SVNRepositoryList;

struct SVNLogInfo
{
	long nRevisionNo;
	CString actionType;
	CString author;
	CString dateTime;
	CString message;

	SVNLogInfo()
	{
		nRevisionNo = 0;
		actionType	= _T("");
		author		= _T("");
		dateTime	= _T("");
		message		= _T("");
	}
};

typedef CAtlList<SVNLogInfo> SVNLogList;

struct SVNModifyInfo
{

	CString folderPath;
	CString filePath;
	CString status;
	CString author;
	CString dateTime;
	long nRevision;
	SVNModifyInfo()
	{
		folderPath = _T("");
		filePath = _T("");
		status = _T("");
		author = _T("");
		dateTime = _T("");
		nRevision = 0;
	}

	friend bool operator == ( const SVNModifyInfo& listInfo, const SVNModifyInfo& compareInfo )
	{
		CString path1 = listInfo.folderPath;
		CString path2 = compareInfo.folderPath;

		if( path1.MakeUpper() == path2.MakeUpper() )
			return true;

		return false;
	}
};

typedef CAtlList<SVNModifyInfo> SVNModifyList;

class UTILITYCLASS CSubVersion
{
public:
	CSubVersion(void);
	~CSubVersion(void);

	BOOL CreateRepository(LPCTSTR lpTargetPath);
	BOOL Import(LPCTSTR lpTargetPath, LPCTSTR logMsg=_T(""));
	BOOL CheckOut(LPCTSTR lpTargetPath);

	SVNUpdateResult Update(LPCTSTR lpTargetPath, long nRevisionNo=-1);
	BOOL Commit(LPCTSTR lpTargetPath, LPCTSTR logMsg=_T(""), long timeout=0);
	// SVN의 로그를 출력한다. 출력된 로그는 변수로 넣은 경로의 ShowLog.txt파일에서 확인할 수 있다.
	BOOL ShowLog(LPCTSTR lpTargetPath, SVNLogList& logList);
	// addMode	- 0 : 파일만 추가
	//			- 1 : 하위 폴더 포함 모두 추가
	BOOL Add(LPCTSTR lpFileName, BOOL fIncludeSubPath=FALSE);
	// 파일 / 폴더 삭제
	BOOL Delete( LPCTSTR lpFilePath );

	// 저장소의 상태를 확인한다. 저장된 내역을 리스트로 반환한다.
	void RepoBrowser(LPCTSTR lpTargetPath, SVNRepositoryList& repoList);
	// 변경 내역을 되돌린다.
	BOOL Revert(LPCTSTR lpTargetPath);
	// 여러 요인으로 인해 폴더 정리가 필요한 경우 사용하는 정리 명령
	BOOL CleanUp( LPCTSTR lpTargetPath );
	// Conflict 등으로 인해 경로에 락이 걸릴 경우 풀어줘야한다.
	BOOL ReleaseLock( LPCTSTR lpTargetPath );
	BOOL Resolve( LPCTSTR lpTargetPath, BOOL fResolvedMine );
	BOOL CheckStatus( LPCTSTR lpTargetPath, SVNModifyList& modifyList );

private:
	SVNUpdateResult GetUpdateResult( LPCTSTR updateLog );

protected:
	CString m_serverPath;
	CString m_svnExe;
	CString m_svnAdminExe;
	CString m_svnServe;
	CString m_userInfoPacket;

public:
	void Initialize(LPCTSTR serverPath, LPCTSTR lpUserId, LPCTSTR lpUserPassword);
	void SetServerURL(LPCTSTR serverPath);
};