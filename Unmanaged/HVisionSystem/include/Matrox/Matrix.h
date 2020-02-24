#ifndef	__RASTER_MATRIX_OBJECT__
#define	__RASTER_MATRIX_OBJECT__

#include "Structures.h"

class AFX_EXT_CLASS CMatrix  
{
public:
	CMatrix();
	CMatrix(long row, long column, double *pInit = NULL);
	CMatrix(const CMatrix &src);
 
	void Dump(double pBuffer[], long &row, long &column);
	void SVDecomposition(CMatrix &U, CMatrix &W, CMatrix &V);

	CMatrix & Invert();
	CMatrix & Transpose();
	CMatrix & MakeIdentity();
	CMatrix & Clear(double lfVal);

	CMatrix &operator=(const CMatrix &src);
	CMatrix &operator=(const double src);
	CMatrix &operator+=(const CMatrix &add);
	CMatrix &operator-=(const CMatrix &sub);
	CMatrix &operator*=(const CMatrix &mul);

	const CMatrix operator+(const CMatrix &add) const;
	const CMatrix operator-(const CMatrix &sub) const;
	const CMatrix operator*(const CMatrix &mul) const;
	const CMatrix operator!() const;
	const CMatrix operator~() const;
	double *operator[](long idx) const;

	double **GetBuffer();
	long Row();
	long Column();

	~CMatrix();

	void Transform(SDoublePoint &out, SDoublePoint &in) const;

	CMatrix & Realloc(long row, long column);

	friend CArchive AFX_EXT_CLASS &operator<<(CArchive &ar, const CMatrix &src);
	friend CArchive AFX_EXT_CLASS &operator>>(CArchive &ar, CMatrix &dst);

protected:
	void Alloc(long row, long column);
	void Free();

	long m_row;
	long m_column;
	double **m_pBuffer;
//	static long m_nObject;
};


#endif