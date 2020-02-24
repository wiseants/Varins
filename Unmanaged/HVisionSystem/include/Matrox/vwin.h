#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include "vis.h"


#define	prtLPRMsg(str,type)  MessageBox(GetFocus(), str, type, MB_OK|MB_ICONSTOP)

#define	YesNoDlg(str,type)  MessageBox(GetFocus(), str, type, \
						MB_ICONEXCLAMATION|MB_OKCANCEL)

#define	DllImport	__declspec(dllimport)
#define	DllExport	__declspec(dllexport)

typedef VOID	(*MyDllProc)();
extern	MyDllProc getMyDllProc (char*, char*);


extern HINSTANCE	hInst;		// Global window instance
extern HWND		hWndMDIClient;	// Image Display Window Handle


typedef struct	dib_buffer {
	HANDLE		hdib;
	char		*head;
	char		*data;
	int		width, height, depth;
	vis_buffer	*image;
} dib_buffer;


/*******************************************************************************
 * FrameEditor Data Structures
 *
 */

/*******************************************************************************
 * File Handling Functions (files.c)
 *
 */
//extern BOOL		getFileNameTyped(char*, int, char*);
//extern BOOL		getFileName	(char*, int);
//extern BOOL		getFileNameWork (char*, int);
//extern BOOL		checkIfFileExists (char*);
//extern vis_buffer	*getVISfromDialog();
//extern int		saveVISbyDlg (vis_buffer*);
//
//extern HWND		displayVISimage (vis_buffer*);
//extern int		closeDisplayWindow (HWND);


/*******************************************************************************
 * DIB related routines (dib.c)
 *
 */
extern DWORD		getDIBInfoHeaderSize (LPBYTE);
extern WORD			getDIBWidth (LPBYTE);
extern WORD			getDIBHeight (LPBYTE);
extern WORD			getDIBDepth (LPBYTE);
extern WORD			getDIBColor (LPBYTE);
extern LPBYTE		findDIBBits (LPBYTE);
extern WORD			getPaletteSize (LPBYTE);
extern HPALETTE		createDIBPalette (HANDLE);
extern HBITMAP		getBMPfromDIB (HANDLE, HPALETTE);
extern HANDLE		getDIBfromBMP (HBITMAP, HPALETTE);

extern dib_buffer	*getDIBfromVIS(vis_buffer*);

extern vis_buffer	*vfio_read_bmp (int fd, vis_buffer *dst);




/*******************************************************************************
 * Window related routines (cdisp.c)
 *
 */
extern HWND		vwin_display_image (vis_buffer *src, char *title, int x, int y);
extern vis_buffer	*getWindowVIS (HWND hWnd);
extern void		displayWindowPaint(HWND hWnd);
extern int		refreshWindow (HWND hWnd);
extern int		setImageWindowPosition (HWND hWnd);
extern int		moveWindowRel(HWND hwnd, int dx, int dy);
extern int		sizeWindow(HWND hwnd, int width, int height);


/*******************************************************************************
 * Drawing Functions (in gditools.c)
 *
 */
extern int	drawText	    (HWND, int, int, char*, int, int, int);
extern int	drawLine	    (HWND, int, int, int, int, int, int, int);
extern int	drawThickLine	    (HWND, int, int, int, int, int, int, int, int);
extern int	drawRectangle	    (HWND, int, int, int, int, int, int, int);
extern int	drawThickRectangle  (HWND, int, int, int, int, int, int, int, int);
extern int	drawFilledRectangle (HWND, int, int, int, int, int, int, int);
extern int	trackMouse	    (HWND, LPRECT, int, int);

