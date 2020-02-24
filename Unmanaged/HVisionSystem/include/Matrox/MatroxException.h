// MatroxException.h: interface for the MatroxException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATROXEXCEPTION_H__F891BC5E_9854_4BCB_9E62_BB1DC36E3732__INCLUDED_)
#define AFX_MATROXEXCEPTION_H__F891BC5E_9854_4BCB_9E62_BB1DC36E3732__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MatroxClass.h"
#include "Utility/UtilityException.h"

namespace Matrox
{
	enum
	{
		DriverInitFailed,
		GrabberInitFailed,
		CamFileLoadFailed,
		CreateGrabImageFailed,
		GrabFailed,
		NotAllocated,
		AlreadyAllocated,
		AllocFailed,
		InvalidCameraType,
		InvalidFrameSize,
		InvalidRect,
		InvalidBand,
		InvalidColorType,
		InvalidBandSize,
		InvalidParam,
		LoadFailed,
		NotCalibrated,
		InvalidImage,
		InvalidImageSize,
		TooManyGrabBuffer,
		PopImageTimeOut,
		EmptyBufPool,
		PoolSizeIsNotDefined,
		ImageFileNotFound,
		ImageFileLoadFailed,
		TooSmallImage,
		MemoryAllocFailed,
		FeatureNotAllocated,
		ResultNotAllocated,
		ResultOrFeatureNotAllocated,
		OutOfMemory,
		YUVImageAllocFailed,
		UnknownBufferAttribute,
		NotImplementedAttribute,
		UserMemoryNotAllocated,
		FileNameNotDefined,
		DisplayAllocFailed,
		InvalidDisplayType,
		ResultAllocFailed,
		CalibrationRestoreFaild,
		BlobAllocfailed,
		DigitizerAllocFailed,
		BufCountTooBig,
		NullPatModel,
		SourceNotAllocated,
		DestNotAllocated
	};

	CString GetErrorMessage(long code);
}

class MATROXCLASS MatroxException : public BaseException
{
public:
	MatroxException(long nCode) : BaseException(), m_nCode(nCode) {}
	virtual CString GetErrorMessage();

private:
	long m_nCode;
};

#endif // !defined(AFX_MATROXEXCEPTION_H__F891BC5E_9854_4BCB_9E62_BB1DC36E3732__INCLUDED_)
