// MilBlob.h: interface for the CMilBlob class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MILBLOB_H__D88A79C6_021E_4E3F_803E_FBC163E42CAF__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_MILBLOB_H__D88A79C6_021E_4E3F_803E_FBC163E42CAF__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <mil.h>
class CMilImage;
class CMilSystem;

#include "MATROXCLASS.h"
#include <vector>
#include "Utility/dblPoint.h"
#include "Utility/dblRect.h"

struct MATROXCLASS BlobBox : public CdblRect
{
	long label;
	long area;
	long totalArea;
	FLOAT length;
	FLOAT roughness;
	CdblPoint centerOfGravity;

	BlobBox() : CdblRect(0, 0, 0, 0)
	{
		area = 0;
		label = 0;
		length = 0;
		roughness = 0;
		centerOfGravity = CdblPoint(0, 0);
	}

	BlobBox(const BlobBox& bb) : CdblRect(bb)
	{
		area = bb.area;
		label = bb.label;
		length = bb.length;
		roughness = bb.roughness;
		centerOfGravity = bb.centerOfGravity;
	}

	BlobBox(long _left, long _top, long _right, long _bottom, long _area) : CdblRect(_left, _top, _right, _bottom)
	{
		area = _area;		
	}

	BlobBox& operator=(const BlobBox& blobBox)
	{
		left = blobBox.left;
		right = blobBox.right;
		top = blobBox.top;
		bottom = blobBox.bottom;
		area = blobBox.area;
		label = blobBox.label;
		length = blobBox.length;
		roughness = blobBox.roughness;
		centerOfGravity = blobBox.centerOfGravity;

		return *this;
	}
};

typedef CAtlArray<BlobBox> VecBlobBox;

class MATROXCLASS BlobUtil
{
public:
	static long GetMaxAreaIndex(VecBlobBox& vecBlobBox);
};

struct MATROXCLASS BlobFeature
{
	static long AREA;
	static long FERET_X;
	static long FERET_Y;
	static long FERET_MIN_ANGLE;
	static long FERET_MAX_ANGLE;
	static long FIRST_POINT_X;
	static long FIRST_POINT_Y;
	static long CHAIN_X;
	static long CHAIN_Y;
	static long BOX;
	static long BOX_X_MIN;
	static long BOX_Y_MIN;
	static long BOX_X_MAX;
	static long BOX_Y_MAX;
	static long COMPACTNESS;
	static long NUMBER_OF_HOLES;
	static long CENTER_OF_GRAVITY_X;
	static long CENTER_OF_GRAVITY_Y;

	static void Init();
};

class MATROXCLASS CMilBlob  
{
public:
	CMilBlob();
	virtual ~CMilBlob();

	void Alloc();
	BOOL IsAllocated();
	void Free();	

	void Control(long controlType, double controlValue);

	void SetSrcImage(CMilImage *pMilImage);
	void SetDestImage(CMilImage *pMilImage);
	void SetGrayImage(CMilImage *pMilImage);
	void FillHoles(long ProcMode);
	void ExtractHoles(long ProcMode);
	void EraseBorder(long ProcMode);
	void Fill(long Criterion, long Value);
	void Select(long Operation, long Feature, long Condition, double CondLow, double CondHigh);
	void GetResult(long Feature, float *TargetArrayPtr);
	void GetResult(long Feature, long *TargetArrayPtr);		
	void GetResult(long Feature, double *TargetArrayPtr);
	MIL_INT GetNumber();
	void Calculate();
	void SelectFeature(long featureList);
	void Label();
//Blob Control (instead of void Control(long controlBlob, double ControlValue));
	void SetIdentification(long identification); //ControlValue : M_INDIVIDUAL, M_LABELED, M_WHOLE_IMAGE
	void SetForegroundValueNonZero();
	void SetForegroundValueZero();
	void SetIdentifierTypeBinary();
	void SetIdentifierTypeGrayScale();
	void SetLattice4Connected();
	void SetLattice8Connected();
	void SetNumberOfFerets(long NumberOfFerets); //ControlValue : M_MAX_FERETS, M_MIN_FERETS, value
	void SetPixelAspectRatio(double PixelAspectRatio);
	void EnableSaveRuns(bool SaveRuns);

	void GetBlobBoxs(VecBlobBox& vecBlobBox);
	void Draw(CMilImage* pMilImage, long operation, long label);

	MIL_ID GetBlobResult() { return m_BlobResult; }
	MIL_ID GetFeatureList() { return m_FeatureList; }

	MIL_INT GetLabel(long xPos, long yPos);
	void Init();
private:
	MIL_ID m_BlobResult;
	MIL_ID m_FeatureList;

	CMilImage *m_pSrcImage;
	CMilImage *m_pDestImage;
	CMilImage *m_pGrayImage;

	BOOL m_fUseLabelFeature;
	BOOL m_fUseCenterOfGravityFeature;
	BOOL m_fUseLengthFeature;
	BOOL m_fUseRoughnessFeature;
};

#endif // !defined(AFX_MILBLOB_H__D88A79C6_021E_4E3F_803E_FBC163E42CAF__INCLUDED_)
