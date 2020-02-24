#ifndef _BITMAPSUPPORT_H_

#ifndef DOXYGEN_EXCLUDE
#define _BITMAPSUPPORT_H_
#endif

#include "resource.h"
#include <atlimage.h>
#include "UtilityClass.h"

#define BLACK_COLOR		RGB(0, 0, 0)
#define WHITE_COLOR		RGB(255, 255, 255)
#define GRAY_COLOR		RGB(128, 128, 128)
#define RED_COLOR		RGB(255, 0, 0)
#define GREEN_COLOR		RGB(0, 255, 0)
#define SKY_BLUE_COLOR	RGB(119, 191, 254)
#define BLUE_COLOR		RGB(0, 0, 255)
#define ORANGE_COLOR	RGB(255, 128, 0)
#define YELLOW_COLOR	RGB(255, 255, 0)
#define PURPLE_COLOR	RGB(128, 0, 128)
#define PINK_COLOR		RGB(255, 0, 255)
#define LIGHT_GREEN_COLOR RGB(207, 255, 35)

class UTILITYCLASS CBitmapSupport
{
public:
	enum
	{
		CW = 0,
		CCW,
	};
	static BOOL WriteDIB(LPCTSTR szFile, HANDLE hDIB);
	static BOOL WriteBitmapToDIB(CDC * pDC, CBitmap& bitmap, LPCTSTR szFile);
	static HANDLE DDBToDIB(CBitmap& bitmap, DWORD dwCompression, CPalette* pPal);
	static HBITMAP DIBToDDB(HANDLE hDIB);

	static void DrawBitmap(CDC * pDC, CBitmap* pBitmap, CRect rect, BOOL bAutoScale = TRUE);
	static void DrawTransparent(CDC *pDC, CBitmap* pImage, CRect rc, COLORREF crMask);
	static void DrawTransparent(CDC *pDC, CBitmap& image, CBitmap& maskImage, int x, int y, COLORREF crColor);
	static void DrawTransparent(CDC *pDC, CBitmap& srcImage, CBitmap& maskImage, CRect rect, COLORREF crColor);

	static void RGB2HSI(double R, double G, double B,
							 double& H, double& S, double& V);
	static void HSI2RGB(double H, double S, double V,
							 double& R, double& G, double& B);
	static void HSI2RGB(double H, double S, double V, COLORREF& c);
	static void RGB2HSI(COLORREF c, double& H, double& S, double& V);
	static COLORREF ModifyHSI(COLORREF c , double H, double S, double V );

	static BOOL LoadBmpImage(LPCTSTR fileName, CBitmap &bitmap);
	static BOOL LoadBmpImage(LPCTSTR moduleName, UINT resourceID, CBitmap &bitmap);
	static HBITMAP GetBitmapFromIcon(HICON hIcon);
	static HICON GetIconFromBitmap(HBITMAP hBitmap);
	static COLORREF GetTransparentColor(CDC* pDC, HBITMAP hBitmap);
	static DWORD RGB2ARGB(COLORREF color);
	static HBITMAP GetGradientBlueImage();
	static HBITMAP GetGradientGrayImage();
	static HBITMAP GetGradientGreenImage();
	static HBITMAP GetGradientOrangeImage();
	static HBITMAP GetGradientRedImage();
	static HBITMAP GetPNGBitmap(HMODULE hModule, UINT nResourceID);
	static BOOL DCToBitmap(CDC* pDC, int nWidth, int nHeight, HBITMAP& hBitmap);
	// 컨트롤 크기에 따라서 적용할 아이콘 크기를 구한다.
	static CSize GetIconSize(CWnd* pWnd);

	static void SaveScreenCapture(CWnd* pWnd, LPCTSTR lpszSavePath);
	static void SaveWindowCapture(CWnd* pWnd, LPCTSTR lpszSavePath);

	static HBITMAP CreateAlphaTextBitmap(LPCTSTR inText, HFONT inFont, CRect rcText, COLORREF inColour);
	static void DrawAlphaBlendText(CDC* pDC, LPCTSTR str, CRect rcText, COLORREF color, DWORD dwAlign = DT_LEFT);
	static void DrawLineArrow(CDC* pDC, CPoint ptStart, CPoint ptEnd);
	static void DrawArcArrow(CDC* pDC, CPoint ptCenter, double lfRadius, double lfStartAngle, double lfEndAngle, int nDirection = CCW);
};

#define BOUND(x,min,max) ((x)>(max)?(max):((x)<(min)?(min):(x)))

#endif 

