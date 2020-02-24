// List2.h: interface for the CList2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIST2_H__0C9EEA03_42EF_4CEB_B8B9_9C10F73E76B7__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_LIST2_H__0C9EEA03_42EF_4CEB_B8B9_9C10F73E76B7__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"


template<class TYPE, class ARG_TYPE>
class CList2 : public CList<TYPE,ARG_TYPE>
{
public:
	void RemoveAll();
};

template<class TYPE, class ARG_TYPE>
void CList2<TYPE, ARG_TYPE>::RemoveAll()
{
	ASSERT_VALID(this);

	POSITION pos = GetHeadPosition();
	while ( pos != NULL ) {
		delete GetNext(pos);
	}

	CList<TYPE,ARG_TYPE>::RemoveAll();
}

template <typename Type, typename List> 
class CopyList
{
public:
	void operator()(List& srcList, List& destList)
	{
		Type* pNode  = NULL;
		POSITION pos = srcList.GetHeadPosition();
		while (pos != NULL) {
			pNode = dynamic_cast<Type*>(srcList.GetNext(pos));
			if (pNode != NULL)
				destList.AddTail(pNode);
		}
	}
};

#endif // !defined(AFX_LIST2_H__0C9EEA03_42EF_4CEB_B8B9_9C10F73E76B7__INCLUDED_)
