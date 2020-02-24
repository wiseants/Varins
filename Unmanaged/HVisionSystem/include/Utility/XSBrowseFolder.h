/**************************************************************************************/
/* CXSBrowseFolder                                                                    */
/**************************************************************************************/
/* This is a simple class to wrap the SHBrowseForFolder function.                     */
/**************************************************************************************/
/* Written by Dana Holt, Xenos Software                                             */
/* http://www.xenossoftware.com                                                       */
/* This class is provided as-is, and carries no warranty or guarantee of any kind.    */
/* Use at your own risk.                                                              */
/**************************************************************************************/

/* Sample Code

	// Create class 
	CXSBrowseFolder foo; 

	// Use the new style dialog
	foo.ModifyStyle(BIF_NEWDIALOGSTYLE, 0);

	// Set the dialog's title text
	foo.SetTitle("This is the title text. Use CXSBrowseFolder::SetTitle() to set it:");

	// Buffer for the returned path
	char path[MAX_PATH];

	// Display the dalog and check the return code
	switch (foo.Show(GetSafeHwnd(), path)) 
	{
		// Success
		case CXSBrowseFolder::RET_OK:
		MessageBox(path, "You Selected", MB_ICONINFORMATION | MB_TOPMOST);
		break;

		// User clicked cancel
		case CXSBrowseFolder::RET_CANCEL:
		MessageBox("Operation cancelled.", "Info", MB_ICONINFORMATION | MB_TOPMOST);
		break;

		// The shell did not return a path for the selection
		case CXSBrowseFolder::RET_NOPATH:
		MessageBox("The shell did not return a path for the selected item!", 
				   "Uh Oh", MB_ICONSTOP | MB_TOPMOST);
		break;
	}

*/

#include "UtilityClass.h"

#pragma once

class UTILITYCLASS CXSBrowseFolder
{
public:

	enum retCode {

		RET_CANCEL = 0,
		RET_NOPATH,
		RET_OK

	};

public:
	CXSBrowseFolder(void);
	~CXSBrowseFolder(void);
protected:
	// Holds the current style
	DWORD m_style;
public:
	// Modifies the current style
	DWORD ModifyStyle(DWORD add, DWORD remove = 0);
	// Returns the current style
	DWORD GetStyle(void);
	// Displays the dialog
	CXSBrowseFolder::retCode Show(HWND parent = NULL);
	// Set the title of the dialog
	void SetTitle(LPCTSTR title);
	// Get the title of the dialog
	LPCTSTR GetTitle();
	// Set Text to display above the tree view control
	void SetMessage(LPCTSTR message);
	// Get display name
	CString GetDisplayName();
	// Set display name
	void SetEditContents(LPCTSTR);
	// Get display name
	LPCTSTR GetEditContents();
	// Set display name
	void SetEditCaption(LPCTSTR);
	// Get display name
	LPCTSTR GetEditCaption();
	// Get selected path
	CString GetSelectedPath();
	// Set initial path
	void SetPath(LPCTSTR path);
	// Save previous WndProc
	void SetOldWndProc(WNDPROC);
	// Get previous WndProc
	WNDPROC GetOldWndProc();
protected:
	// Buffer to receieve the display name of the selected object
	TCHAR m_displayName[MAX_PATH];
	// Buffer to receieve the path of the selected object
	TCHAR m_selectedPath[MAX_PATH];
	// Root item to start browsing at
	LPITEMIDLIST m_root;
	// Text to display above the tree view control
	TCHAR m_message[MAX_PATH];
	// Dialog title
	TCHAR m_title[MAX_PATH];
	// Content of edit box
	TCHAR m_editContents[MAX_PATH];
	// Caption of edit box
	TCHAR m_editCaption[MAX_PATH];

	WNDPROC m_oldWndProc;
};
