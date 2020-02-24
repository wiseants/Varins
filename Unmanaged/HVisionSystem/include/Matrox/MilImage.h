// MilImage.h: interface for the CMilImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILIMAGE_H__22B9210C_517A_44AC_A54B_7A7F2A375D12__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_MILIMAGE_H__22B9210C_517A_44AC_A54B_7A7F2A375D12__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <mil.h>
#include <vector>
#include <atlstr.h>
#include "MilBuffer.h"
//#include "Utility/CDib.h"

#define M_OFFSET_LUMINANCE				0
#define M_OFFSET_SATURATION				1
#define M_OFFSET_HUE					2

enum EBandSize {
	ebsGRAY = 1,
	ebsRGB = 3
};

#include "MATROXCLASS.h"

#define HLS_IMAGE		0x0001
#define L_IMAGE			0x0002
#define RGB_IMAGE		0x0003
#define HLS_CONTAINER	0x0004
#define RGB_CONTAINER	0x0010

struct ModelOffsetInfo
{
	CPoint Offset;
	CPoint OffsetCenterPoint;  // Result Find Center
	CPoint AlignCenterPoint;   // Align ROI Center
	CRect FindRect;
	double angle;

	ModelOffsetInfo()
	{
		Offset = 0;
		OffsetCenterPoint = 0;
		AlignCenterPoint = 0;
		angle = 0;
		FindRect.SetRect(0, 0, 0, 0);
	}

	~ModelOffsetInfo()
	{
		Offset = NULL;
		OffsetCenterPoint = NULL;
		AlignCenterPoint = NULL;
		angle = NULL;
		FindRect = NULL;
	}
};


typedef void (*BayerToRGB)(MIL_ID SrcImageBufId, MIL_ID DestImageBufId, MIL_ID WhiteBalanceCoefficientsId, long ControlFlag);

class CMilSystem;

class MATROXCLASS CMilImage  : public CMilBuffer
{
// Constructor
public:
	CMilImage();
	virtual ~CMilImage();

	virtual void Free();

// Operators
public:
	static BOOL IsUseGreenBand();
	static void SetUseGreenBand(BOOL fUseGreenBand);

	void CopyToColor(CMilImage *DestImage, long Band);
	MIL_INT Inquire(long InquireType, void *UserVarPtr);
	void ControlNeighborhood(long OperationFlag, long OperationValue);
	void CopyFrom(CMilImage *SrcImage, BOOL bColor = FALSE);
	void CopyTo(CMilImage *DestImage, BOOL bColor=FALSE);

	//! MIL 지원 읽기/쓰기 함수 
	void Load(LPCTSTR FileName);
	BOOL Restore(LPCTSTR FileName);
	void Export(LPCTSTR FileName, MIL_ID FileFormatBufId = M_BMP) const;
	void ExportJPG(LPCTSTR FileName, MIL_ID FileFormatBufId = M_JPEG_LOSSY) const;
	void Import(LPCTSTR fileName, MIL_ID fileFormatBufID = M_BMP);
	// BMP : M_BMP / JPG : M_JPEG_LOSSY
	void DebugExport(LPCTSTR fileName, MIL_ID FileFormatBufId = M_BMP) const;
	
	void Get(void *UserArrayPtr);
	void GetColor(long DataFormat, long Band, void *UserArrayPtr);
	void GetColor2d(long OffX, long OffY, long SizeX, long SizeY, void *UserArrayPtr);
	void GetLine(CPoint Start, const CPoint End, long *NbPixelsPtr, void *UserArrayPtr);

	void Put(BYTE* pBuffer);
	void PutColor2d(long OffX, long OffY, long SizeX, long SizeY, void *UserArrayPtr);
	void PutColor(long dataFormat, long band, void* pUserArrayPtr);
	BOOL CopyColor2d(const CMilImage* pSrcImage, long srcBand, CPoint srcPt, long destBand, CPoint destPt,
					CSize size);

	CRect GetRect() const;

	void Alloc(EBandSize bandsize, long sizeX, long sizeY, long type, long attribute);
	void Alloc1d(long size, long bitSize);
	void Create2d(long sizeX, long sizeY, long type, long attribute, long controlFlag, long pitch, void* pDataPtr = (void *)NULL);
	void CreateColor(long sizeX, long sizeY, long type, long attribute, long controlFlag, long pitch, void** ppDataPtr = (void **)NULL);
		
	void AllocChild(CMilImage* pParentImage, long imageBand, const CRect& childRect = CRect(0,0,0,0));
	
	CMilImage* CreateClipImage(const CRect& _clipRect = CRect(0,0,0,0), long band = M_ALL_BAND , CMilImage* pClipImage = NULL) const;
	LPBYTE CreateColorBuffer(long* pBufSize);
	CMilImage* CreateRotateImage(double angle);
	CMilImage* CreateChild(long imageBand, const CRect& childRect = CRect(0,0,0,0));
	CMilImage* CreateResizeImage(double scaleFactorX, double scaleFactorY);
	CMilImage* CreateRotateImage(double angle, CSize internalSize);

	void BuildImage(BOOL fHLSImage, CMilImage* pBand1, CMilImage* pBand2, CMilImage* pBand3);

	void Attach(MIL_ID imageID, BOOL fHLSImage=FALSE);
	
	MIL_INT GetBandSize() const;
	
	void ChildColor(CMilImage* pParentImage, long Band);
	void ChildColor2d(CMilImage* pParentImage, long Band, long OffX, long OffY, long SizeX, long SizeY);
	void Convert(long type);

	BOOL HLStoRGB(BOOL fSelf = FALSE);
	BOOL IsHLSImage() const;
	BOOL IsOnlyLImage() const;

	CMilImage* GetHLSImage(BOOL fConvGray = TRUE, BOOL fOneBand = TRUE);

	void Inverse();
		
	void Rotate(double angle, long nInterpolationType = M_BICUBIC, CMilImage* pDestImage = NULL);
	void Rotate(double angle, CPoint offsetcenter, CPoint offset, long nInterpolationType = M_BICUBIC, CMilImage* pDestImage = NULL);  // Roi Align 만큼 image Rotate
	void Rotate180(CMilImage* pDestImage = NULL);

	void Projection(double projAngle, long* pResult);
	void Histogram(long* pResult);

	//! 해당 영역의 컬러 정보를 제거한다.
	void ClearColorData(const CRect& rect);
	BOOL ClearColorData();
	CString GetBandName(long imageBand) const;
	BOOL CheckBandAvailable(long imageBand) const;

	void SetImageType(long imageType);
	long GetImageType() const;

	void SetCompositeMade(BOOL fCompositeMade);
	BOOL IsCompositeMade() const;
	
	void SetRGBConverted(BOOL fRGBConverted);
	BOOL IsRGBConverted() const;

	void SetHLSConverted(BOOL fHLSConverted);

	void SetOnlyGreenAvailable(BOOL fOnlyGreenAvailable);
	BOOL IsOnlyGreenAvailable() const;
	BOOL GetAvgBrightness(long nDevCntWidth, long nDevCntHeight, std::vector<double>& vtrAvgBrightness);

	void Resize(double ScaleFactorX, double ScaleFactorY, long InterpolationType ,CMilImage* pDestImage);
	// 1 : Y축 반전, 2 : X축 반전
	void Flip(long direction, CMilImage* pDestImage);
	double CalcRGBMean(long nColorBand, CRect CalcRgn);
	double CalcRGBMean(long nColorBand);
	double CalcMean(CMilImage* pMilImage);

	double CalcHLSColorMean(long colorBand, CRect rectCalcRgn);
	void EmphasisCharacter(long removeNoiseSize, int filterSize);
	//jkk
	double CalcMaxPixelCount(long nColorBand, CRect CalcRgn, long minValue = 0);
	double CalcRBRatio(long nColorBand, CRect CalcRgn, long &totalColorCount, long refColorAngle, long minValue = 0);
	BOOL RGBtoHLS();
	
	float Statistics(long statType, long condition, double condLow, double condHigh);

	BOOL RGBtoL();
	BOOL RGBto0G0();
	BOOL RGBtoG();
	void CopyBuffer(BYTE* pBuffer, long nSize);
protected:
	long m_imageType;

	CMilImage* m_pHLSImage;
	BOOL	m_fCompositeMade;
	BOOL	m_fHLSConverted;
	BOOL	m_fRGBConverted;	// 평직에서만 사용

	BOOL	m_fOnlyGreenAvailable;
	static BOOL	m_fUseGreenBand;

	BOOL m_bUseHostAddress;
};

#endif // !defined(AFX_MILIMAGE_H__22B9210C_517A_44AC_A54B_7A7F2A375D12__INCLUDED_)
