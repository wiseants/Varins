// Heighter.h: interface for the CHeighter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HEIGHTER_H__AFD99754_161B_4ED8_8FB4_844A95ACD938__INCLUDED_)
#define AFX_HEIGHTER_H__AFD99754_161B_4ED8_8FB4_844A95ACD938__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <map>
#include <list>

class CHeighter  
{
public:
	CHeighter();
	virtual ~CHeighter();

	void InsertValue(const float& _fZ);
	float Calculation(const float& _fAveHeight, const float& _fAveBottomHeight);

protected:
	typedef std::vector<float> HeightVec, *LpHeightVec;
	typedef std::map<int, HeightVec> HeightMap, *LpHeightMap;
	typedef std::list<HeightVec> HeightVecList, *LpHeightVecList;

	int FindRange(const float& _fUpper, const float& _fLower, const float& _fGap, const float& _fZ);
	void AddRangeElement(const int& _iKey, const float& _fZ);
	void FindMaxCountHeightVec(LpHeightVecList _lpListHeight);
	void AddHeightList(const LpHeightVec _lpVecHeight, const size_t& _nCount, LpHeightVecList _lpListHeight);
	float CalcAveHeight(LpHeightVecList _lpListHeight);
	float CalcAveHeight(LpHeightVec _lpVecHeight);

private:
	HeightVec m_vecHeight;
	HeightMap m_mapHeight;
};

#endif // !defined(AFX_HEIGHTER_H__AFD99754_161B_4ED8_8FB4_844A95ACD938__INCLUDED_)
