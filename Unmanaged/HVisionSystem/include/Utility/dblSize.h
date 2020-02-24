// dblSize.h: interface for the CdblSize class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBLSIZE_H__0E9C9124_697E_4CD1_848C_1F0B9AF98ECD__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_DBLSIZE_H__0E9C9124_697E_4CD1_848C_1F0B9AF98ECD__INCLUDED_
#endif

#include <vector>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct tagdblSIZE {
	double cx;
	double cy;
} dblSIZE;

#include <atltypes.h>

#include "UtilityClass.h"

class CdblPoint;

class UTILITYCLASS CdblSize : public dblSIZE
{
public:
	CdblSize();
	CdblSize(double initCX, double initCY);
	CdblSize(const CdblPoint& point);
	CdblSize(const CSize& size);
	virtual ~CdblSize();

	void operator =(const CdblSize &srcSize);
	void operator =(const CdblPoint &srcPoint);
	BOOL operator!=(const CdblSize& size);
	BOOL operator==(const CdblSize& size);

	void operator/=( const CdblSize& size );
	void operator*=( const CdblSize& size );

	void operator-=(const CdblSize& size);
	void operator+=(const CdblSize& size);
	void operator-=(const CdblPoint& point);
	void operator+=(const CdblPoint& point);
	BOOL operator>(const CdblSize& size);
	BOOL operator<(const CdblSize& size);

	CdblSize operator-(const CdblSize& size) const;
	CdblSize operator-() const;
	CdblSize operator+(const CdblSize& size) const;
	CdblSize operator-(const CdblPoint& point) const;
	CdblSize operator+(const CdblPoint& point) const;

	CSize GetCSize() const {
		return CSize((long)(cx), (long)(cy));
	}
};

typedef std::vector<CSize> VecSize;
typedef VecSize* VecSizePtr;
typedef std::vector<CdblSize> VecDblSize;
typedef VecDblSize* VecDblSizePtr;

#endif // !defined(AFX_DBLSIZE_H__0E9C9124_697E_4CD1_848C_1F0B9AF98ECD__INCLUDED_)
