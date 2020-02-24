// ProbeSource_OCX.h: interface for the CProbeSource_Mirtec2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROBESOURCE_MIRTEC2_H__71E202D1_A5EC_4FA2_B85F_87B0A71DBF3F__INCLUDED_)
#define AFX_PROBESOURCE_MIRTEC2_H__71E202D1_A5EC_4FA2_B85F_87B0A71DBF3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "./spi/SPIMirTec_Basic.h"
#include "xspimirtec.h"	
#include "ProbeSource.h"

class MATROXCLASS CProbeSource_Mirtec2 : public CProbeSource
{
public:
	CProbeSource_Mirtec2(CMilDigitizer* pMilDigitizer);
	virtual ~CProbeSource_Mirtec2();

	static void InitDIO(void *pDioCtrl, VOID (*pFunction)(void*, void*, int, BOOL));

	// CDigitizerSource Interface
	virtual BOOL Initialize(long digitizerType, long cameraType, BOOL fUseDualProbe, long conveyorType, PortList ProbPortList);
	virtual void Release();
	virtual BOOL Grab3D(CMilImage* pMilImage, long _lGrabBuffer);
	virtual BOOL Grab(CMilImage* pMilImage);

#if defined(_SPI_PROBE_THREAD)
	virtual void SetNumThread4Inspect(const BYTE& _byThreadCount);
	virtual void SetUseHeightCal(const short& _shUse);
#endif

	virtual void Measure(LpSPIResultVec _lpVecResult);
	virtual BOOL Measure(const CSpiRect& spiRect, CSPIResult& spiResult);

	virtual void EnableLane(int laneEnable);
	virtual void SetProbeMode(short probeMode);

	virtual long* GetHeightCalibResult() { return m_pInfoSPI->plnSum; }

	virtual VOID StartBBTMode();
	virtual VOID FinishBBTMode();
	virtual BOOL IsBBTMode() CONST;
	virtual VOID SetGrabMode(CONST SHORT& _grabMode);

	virtual void ConvertImage();

	virtual BOOL IsCalibrationOK(short nStep);
	
	virtual void InitializePztCalibration();
	virtual void ReleasePztCalibration();
	
	virtual BOOL SaveRefPhase();

	virtual BOOL PztCalib(short step);
	
	virtual void SetHeightCalibParameters(float fHeight, short nRow, short nColumn, short nNumRepeat, float fOffsetHeight);
	virtual BOOL HeightCalibMeasure(CRect rcCalibRect, CSPIResult& spiResult);
	virtual void HeightCalib();
	virtual VOID Change3DBrightness(short _shrtBrightness);
	virtual BOOL HeightCalib2();
	virtual void ConfirmHeightCalib() { }

	virtual BOOL IsCalibrationDone();

	virtual BOOL CheckScanMode();
	virtual void ScanMode(short mode);
	virtual BOOL Grating(CMilImage* pMilImage);

	virtual BOOL ShowRef(CMilImage* pMilImage, int probeType = 0);

	//////////////////////////////////////////////////////////////////////////

	// Probe Hooking Function
	static void On3DGrabDone(void* pOwner);
	static void On2DGrabDone(void* pOwner);
	static void OnCalculationDone(void* pOwner);
	static void OnCalibrationDone(void* pOwner, short nWhat);

	float* GetReferencePhase(short probeMode);

	virtual BOOL GetUseFunctionProfile();
	virtual void SetUseFunctionProfile(BOOL bNewValue);
	virtual BOOL GetExportGratingImage();
	virtual void SetExportGratingImage(BOOL bNewValue);
	virtual void SaveFunctionProfile(LPCTSTR fileName);

protected:
	void SetCalculationDone();
	void ResetCalculationDone();
	
	void SetCalibrationDone(short calibStep);
	void ResetCalibrationDone();
	
	void Set3DMeasurementDone();
	void Reset3DMeasurementDone();

	virtual void SPIBufferToMilImage(CMilImage* _pMilImage);
	virtual CSize GetCameraResolution(long cameraType);

private:
	_SingleChannelInfo* m_pInfoSingleChannel;
	_SPIInfo* m_pInfoSPI; //이것은 그냥 Containter 이고, 실제 데이터는 CSolderBuffer안에 있다... 

private:
	CWnd m_parentWnd; // CXSPIMirTec의 parent 윈도우로 만듬.
	CXSPIMirTec	m_xSPICtrl;

	short m_probeMode;
	short m_calibStep;
	HANDLE m_hCalculationDone;
	HANDLE m_hCalibrationDone;
	HANDLE m_h3DMesurementDone;
	SHORT m_grabMode;

	double *m_pDouble;
};

#endif // !defined(AFX_PROBESOURCE_MIRTEC2_H__71E202D1_A5EC_4FA2_B85F_87B0A71DBF3F__INCLUDED_)
