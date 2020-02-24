// Projection.h: interface for the CProjection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJECTION_H__96D49A41_6597_4655_8BE1_5F45A907F3AC__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_PROJECTION_H__96D49A41_6597_4655_8BE1_5F45A907F3AC__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMilImage;

#include "MATROXCLASS.h"
#include "MilObject.h"

class MATROXCLASS CProjection : public MilObject 
{
public:
	~CProjection();
	void Projection(CMilImage* pMilImage, double ProjAngle, long *UserArrayPtr, bool BinaryCount=false);

private:
	void Alloc(long nbEntries);
	void Free();
	void GetResult(long *UserArrayPtr);
};


class MATROXCLASS CMilMeas : public MilObject 
{
public:
	~CMilMeas();
	//	void Projection(CMilImage* pMilImage, double ProjAngle, long *UserArrayPtr, bool BinaryCount=false);

	void Alloc(long MarkerType);
	void Free();
	void SetMarker(long Parameter, double FirstValue, double SecondValue);
	void SetMarkerBox(CRect rect);
	void SetMarkerOrientation(double FirstValue, double SecondValue);
	void SetMarkerPolarity(double FirstValue, double SecondValue);
	void SetMarkerBoxAngle(double FirstValue, double SecondValue);
	void SetMarkerContrast(double FirstValue, double SecondValue);

public:
	void FindMarker(CMilImage* pMilImage, long MeasurementList);
	void GetResult(long ResultType, double *FirstResultPtr, double *SecondResultPtr);
	void GetPositionResult(double *FirstResultPtr, double* SecondResultPtr);
};

#endif // !defined(AFX_PROJECTION_H__96D49A41_6597_4655_8BE1_5F45A907F3AC__INCLUDED_)
