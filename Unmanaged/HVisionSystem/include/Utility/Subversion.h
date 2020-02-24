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
	// SVN�� �α׸� ����Ѵ�. ��µ� �α״� ������ ���� ����� ShowLog.txt���Ͽ��� Ȯ���� �� �ִ�.
	BOOL ShowLog(LPCTSTR lpTargetPath, SVNLogList& logList);
	// addMode	- 0 : ���ϸ� �߰�
	//			- 1 : ���� ���� ���� ��� �߰�
	BOOL Add(LPCTSTR lpFileName, BOOL fIncludeSubPath=FALSE);
	// ���� / ���� ����
	BOOL Delete( LPCTSTR lpFilePath );

	// ������� ���¸� Ȯ���Ѵ�. ����� ������ ����Ʈ�� ��ȯ�Ѵ�.
	void RepoBrowser(LPCTSTR lpTargetPath, SVNRepositoryList& repoList);
	// ���� ������ �ǵ�����.
	BOOL Revert(LPCTSTR lpTargetPath);
	// ���� �������� ���� ���� ������ �ʿ��� ��� ����ϴ� ���� ���
	BOOL CleanUp( LPCTSTR lpTargetPath );
	// Conflict ������ ���� ��ο� ���� �ɸ� ��� Ǯ������Ѵ�.
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