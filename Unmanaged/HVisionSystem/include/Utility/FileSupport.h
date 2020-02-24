#ifndef _FILESUPPORT_H_

#ifndef DOXYGEN_EXCLUDE
#define _FILESUPPORT_H_
#endif

#include "UtilityClass.h"

class UTILITYCLASS CFileSupport
{
public:
	static BOOL FindPath( HWND hOwner , LPCTSTR caption, LPTSTR path, int nLength);
	static CString FindFilePath ( BOOL isOpen , LPCTSTR defaultExt , LPCTSTR filter );
	static CString FindFilePath ( BOOL isOpen , LPCTSTR defaultExt , UINT filterID );
	
	static BOOL IsFile(LPCTSTR path, BOOL fOkAtBlank = FALSE );
	static BOOL IsDirectory(LPCTSTR path, BOOL fOkAtBlank = FALSE );
	static BOOL IsExistSubDirectory(LPCTSTR lpPath);
	static BOOL FileDate(LPCTSTR path, COleDateTime& fileDate);
	static BOOL RemoveReadonly(LPCTSTR path);

	static BOOL IsReadonly(LPCTSTR path);
	static BOOL IsEmpty(LPCTSTR lpDirName);

	static CString GetFileName(CString fullPath);
	static CString GetPathName(CString fullPath);
	static void GetPathAndFileName(CString fullPath , CString& path , CString& fileName );
	static CString GetFileExt(CString fullPath);

	static BOOL CreateDirectory( LPCTSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes = NULL );
	static void DeleteDirectory(LPCTSTR lpPathName, BOOL fConfirm);
	static void DeleteAllFile(LPCTSTR lpPath);
	static void DeleteAllDirectory(LPCTSTR lpPath);

	static BOOL ValidateName(CString name);

	static UINT ProgressCopy(LPCTSTR srcPathName , LPCTSTR destPathName);
	static BOOL SafeSave(LPCTSTR tempFileName, LPCTSTR bakFileName, LPCTSTR fileName);
	static void RevertFile(LPCTSTR bakFileName, LPCTSTR fileName);

	static BOOL Copy(LPCTSTR srcName, LPCTSTR destName, HWND hWnd = NULL);
	static BOOL CopyDirectory(LPCTSTR srcDirectory, LPCTSTR destDirectory, HWND hWnd = NULL);
	static BOOL CopyDirectory(LPCTSTR srcDirectory, LPCTSTR destDirectory, CString searchKeyword);
	static BOOL Delete(LPCTSTR path, HWND hWnd = NULL);

	static BOOL ExtractFile(LPCTSTR fileName, UINT resID, LPCTSTR type);
	static DWORD GetVersionOfFile(LPTSTR szFile, int* ipBuf, int iNumOfFields);

	static CString Combine(CString path1, CString path2);

	static void GetAppDirectory(CString &appPath);
	static void GetAppDirectoryEx(CString &appPath);

	// Directory Open Dialog를 열어서 경로를 탐색한다.
	static CString GetModalPath( LPCTSTR currentPath, CWnd* pWnd );
	static long GetFileCount( LPCTSTR lpPath, BOOL fIncludeSubPath=FALSE );
	static HANDLE CreateFileHandle(LPCTSTR fileName);

	// ???? ??ο??? ?? ???´.
	// 1. dirName : ????? ????
	// 2. searchPath : ????? ????? ???
	// 3. fFindSubPath : ???????? ????? ????? ?
	static CString GetFindPath(LPCTSTR dirName, LPCTSTR searchPath, BOOL fFindSubPath=FALSE);
	static CString GetAppPath();
	static CString GetSetupPath();
	static CString GetMotionSetupPath();
	static CString GetMotionAlarmImagePath();

	static CString iniFileRead(CString mainTitle, CString subTitle, int lineLength, CString filePath);
	static BOOL iniFileWrite(CString mainTitle, CString subTitle, CString inValue, CString filePath);
};

#define PC_SUCCESS	1
#define PC_FAILED	0
#define PC_CANCELLED	-1

#endif
