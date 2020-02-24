// MultiArray.h: interface for the ImageArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIARRAY_H__275D46AC_B5DF_4D69_8589_85AA1A418317__INCLUDED_)
#define AFX_MULTIARRAY_H__275D46AC_B5DF_4D69_8589_85AA1A418317__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityException.h"
#include "UtilityClass.h"

/** This is basically 2 dimensional array class.

Usage : 
1.Create a object with concrete template parameter.
MultiArray<double> darray;

2.You can specifiy initial dimension when you create array.
MultiArray<double> darray(640, 480);

or you can change the dimension after the creation.
darray.SetSize(100, 100);

3.MultiArray overloads () operator and index operator[) for easy access to elements.
darray(24, 58) = 4.04;
double dd = darray(34, 12);

4.Iterator can be used like STL (Randome access iterator)
*/
template<class T>
class MultiArray
{
public:
	/** Default Constructor. Dimension is set to (0, 0).*/
	MultiArray() throw() : m_nCol(0), m_nRow(0), m_pArray(NULL) {}
	/** Constructor. Dimension is set to (nCol, nRow) and initialized to 0. */
	MultiArray(int nCol, int nRow) throw();
	/** Constructor. Dimension is set to (nCol, nRow) and initialized with data pData. */
	MultiArray(int nCol, int nRow, T* pData) throw();
	/** Copy Constructor. Copies dimension and elements from rhs. */
	MultiArray(const MultiArray& rhs) throw();
	/** Destructor */
	virtual ~MultiArray();
	/** Change the dimension to (nCol, nRow) and initialize all elements to 0. */
	void SetSize(int nCol, int nRow) throw();
	/** Initialize all elements to 0. */
	void ZeroAll() throw();
	/** Deallocate memory and set dimension to (0, 0) */
	void Clean() throw();
	/** overloaded operator. Copies dimension and elements from rhs. */
	const MultiArray& operator=(const MultiArray& rhs) throw();
	/** overloaded operator. add each elements from the value of rhs. If dimension is different throws UtilityException. */
	void operator+=(const MultiArray& rhs) throw(UtilityException);
	/** overloaded operator. subtract each elements from the value of rhs. If dimension is different throws UtilityException. */
	void operator-=(const MultiArray& rhs) throw(UtilityException);
	/** overloaded operator. Returns true if 2 arrays are same. */
	bool operator==(const MultiArray& rhs) throw();
	/** overloaded operator. Returns true if 2 arrays are different. */
	bool operator!=(const MultiArray& rhs) throw();
	/** overloaded operator. Set elements with max value of 2 arrays. If dimension is different throws UtilityException. */
	void PriorityAdd(const MultiArray& rhs) throw(UtilityException);
	/** inline overloaded operator. Get elements using index operator. Throws Exception only in Debug mode. */
	T& operator[](int nIndex) throw(UtilityException);
	/** inline overloaded operator. Set elements using index operator. Throws Exception only in Debug mode. */
	const T& operator[](int nIndex) const throw(UtilityException);
	/** inline overloaded operator. Get elements using () operator. Throws Exception only in Debug mode. */
	T& operator()(int nRow, int nCol) throw(UtilityException);
	/** inline overloaded operator. Set elements using () operator. Throws Exception only in Debug mode. */
	const T& operator()(int nRow, int nCol) const throw(UtilityException);
	/** Get the current width of array */
	int GetNoOfCol() const throw() { return m_nCol; }
	/** Get the current height of array */
	int GetNoOfRow() const throw() { return m_nRow; }
	/** Get the pointer of starting element of specified row. */
	T* GetRow(int nIndex) throw(UtilityException);
	/** Get the pointer of internal array. */
	T* GetArray() throw();
	/** Check if 2 arrays have same dimension. */
	bool IsSameSize(const MultiArray& rhs) const throw();
	/** Make output's dimension to this array's dimension and initialize all elements to 0. */
	void MakeSameSize(MultiArray& output) const throw(UtilityException);

	typedef T*			iterator;
	typedef const T*	const_iterator;
	iterator begin() { return &m_pArray[0]; }
	iterator end() { return &m_pArray[m_nCol * m_nRow]; }
	const_iterator begin() const { return &m_pArray[0]; }
	const_iterator end() const { return &m_pArray[m_nCol * m_nRow]; }

protected:
	T* m_pArray;
	int m_nCol;
	int m_nRow;
};

template<class T>
MultiArray<T>::MultiArray(int nCol, int nRow) throw() : m_nCol(nCol), m_nRow(nRow)
{
	int nTotalSize = nCol * nRow;
	m_pArray = new T[nTotalSize];
}

template<class T>
MultiArray<T>::MultiArray(int nCol, int nRow, T* pByte) throw() : m_nCol(nCol), m_nRow(nRow)
{
	int nTotalSize = nCol * nRow;
	m_pArray = new T[nTotalSize];
	::memcpy(m_pArray, pByte, sizeof(T) * nTotalSize);
}

template<class T>
MultiArray<T>::MultiArray(const MultiArray<T>& rhs) throw()
{
	m_nCol = rhs.m_nCol;
	m_nRow = rhs.m_nRow;
	int nTotalSize = m_nCol * m_nRow;
	m_pArray = new T[nTotalSize];
	::memcpy(m_pArray, rhs.m_pArray, sizeof(T) * nTotalSize);
}

template<class T>
MultiArray<T>::~MultiArray()
{
	Clean();
}

template<class T>
void MultiArray<T>::SetSize(int nCol, int nRow) throw()
{
	Clean();
	m_nCol = nCol;
	m_nRow = nRow;
	int nTotalSize = m_nCol * m_nRow;
	m_pArray = new T[nTotalSize];
	::memset(m_pArray, 0, sizeof(T) * nTotalSize);
}

template<class T>
void MultiArray<T>::ZeroAll() throw()
{
	::memset(m_pArray, 0, sizeof(T) * m_nCol * m_nRow);
}

template<class T>
void MultiArray<T>::Clean() throw()
{
	m_nCol = 0;
	m_nRow = 0;
	if(m_pArray) {
		delete[] m_pArray;
		m_pArray = NULL;
	}
}

template<class T>
const MultiArray<T>& MultiArray<T>::operator=(const MultiArray<T>& rhs) throw()
{
	if(&rhs == this)
		return *this;

	if(!IsSameSize(rhs)) {
		m_nCol = rhs.m_nCol;
		m_nRow = rhs.m_nRow;
		if(m_pArray)
			delete[] m_pArray;

		int nTotalSize = m_nCol * m_nRow;
		m_pArray = new T[nTotalSize];
	}

	::memcpy(m_pArray, rhs.m_pArray, sizeof(T) * m_nCol * m_nRow);

	return *this;
}

template<class T>
inline T& MultiArray<T>::operator[](int nIndex) throw(UtilityException)
{
#ifdef _DEBUG
	if(nIndex < 0 || nIndex >= m_nCol * m_nRow)
		throw UtilityException(0);
#endif
	return m_pArray[nIndex];
}

/*
template<class T>
inline T MultiArray<T>::operator[](int nIndex) const throw(UtilityException)
{
#ifdef _DEBUG
	if(nIndex < 0 || nIndex >= m_nCol * m_nRow)
		throw UtilityException(0);
#endif
	return m_pArray[nIndex];
}
*/

template<class T>
inline T& MultiArray<T>::operator()(int nRow, int nCol) throw(UtilityException)
{
#ifdef _DEBUG
	if(nCol <0 || nCol >= m_nCol || nRow < 0 || nRow >= m_nRow)
		throw UtilityException(0);
#endif
	return m_pArray[nCol + nRow * m_nCol];
}
/*
template<class T>
inline const T& MultiArray<T>::operator()(int nRow, int nCol) const throw(UtilityException)
{
#ifdef _DEBUG
	if(nCol <0 || nCol >= m_nCol || nRow < 0 || nRow >= m_nRow)
		throw UtilityException(0);
#endif
	return m_pArray[nCol + nRow * m_nCol];
}
*/
template<class T>
void MultiArray<T>::operator+=(const MultiArray<T>& rhs) throw()
{
	if(!IsSameSize(rhs))
		throw UtilityException(0);

	int nTotalByte = m_nCol * m_nRow;
	for(int i=0; i<nTotalByte; i++)
		m_pArray[i] += rhs[i];
}

template<class T>
void MultiArray<T>::operator-=(const MultiArray<T>& rhs) throw()
{
	if(!IsSameSize(rhs))
		throw UtilityException(0);

	int nTotalByte = m_nCol * m_nRow;
	for(int i=0; i<nTotalByte; i++)
		m_pArray[i] = abs(m_pArray[i] - rhs[i]);
}

template<class T>
bool MultiArray<T>::operator==(const MultiArray& rhs) throw()
{
	if(m_nCol != rhs.m_nCol)
		return false;
	if(m_nRow != rhs.m_nRow)
		return false;
	int nTotalByte = m_nCol * m_nRow;
	for(int i=0; i<nTotalByte; i++)
		if(m_pArray[i] != rhs.m_pArray[i])
			return false;

	return true;
}

template<class T>
bool MultiArray<T>::operator!=(const MultiArray& rhs) throw()
{
	if(m_nCol != rhs.m_nCol)
		return true;
	if(m_nRow != rhs.m_nRow)
		return true;
	int nTotalByte = m_nCol * m_nRow;
	for(int i=0; i<nTotalByte; i++)
		if(m_pArray[i] != rhs.m_pArray[i])
			return true;

	return false;
}

template<class T>
void MultiArray<T>::PriorityAdd(const MultiArray<T>& rhs) throw(UtilityException)
{
	if(!IsSameSize(rhs))
		throw UtilityException(0);

	int nTotalByte = m_nCol * m_nRow;
	for(int i=0; i<nTotalByte; i++)
		m_pArray[i] = max(m_pArray[i], rhs[i]);
}

template<class T>
T* MultiArray<T>::GetRow(int nIndex) throw(UtilityException)
{
	if(nIndex < 0 || nIndex >= m_nRow)
		throw UtilityException(0);

	T* pByte = m_pArray;
	pByte += m_nCol * nIndex * sizeof(T);
	return pByte;
}

template<class T>
T* MultiArray<T>::GetArray() throw()
{
	return m_pArray;
}

template<class T>
bool MultiArray<T>::IsSameSize(const MultiArray& rhs) const throw()
{
	if(m_nCol == rhs.m_nCol && m_nRow == rhs.m_nRow)
		return true;
	else
		return false;
}

template<class T>
void MultiArray<T>::MakeSameSize(MultiArray<T>& output) const throw()
{
	if(output.m_nRow != m_nRow || output.m_nCol != m_nCol) {
		output.Clean();
		output.m_nRow = m_nRow;
		output.m_nCol = m_nCol;
		output.m_pArray = new T[m_nCol * m_nRow];
		::memset(output.m_pArray, 0, sizeof(T) * m_nRow * m_nCol);
	}
}

#endif // !defined(AFX_MULTIARRAY_H__275D46AC_B5DF_4D69_8589_85AA1A418317__INCLUDED_)
