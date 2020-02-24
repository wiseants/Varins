// ClassMap.h: interface for the CClassMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLASSMAP_H__EF601101_A3FD_47A6_A8D6_723704B31F04__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_CLASSMAP_H__EF601101_A3FD_47A6_A8D6_723704B31F04__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"

class UTILITYCLASS CClassMap  
{
	static CMap<CString, LPCTSTR, CRuntimeClass*, CRuntimeClass*> m_classMap;

public:
	CClassMap();
	virtual ~CClassMap();

	static BOOL AddRuntimeClass(LPCTSTR className, CRuntimeClass* pRuntimeClass);
	static CObject* CreateObject(LPCTSTR className);
};

#define DECLARE_CLASSMAP(className) \
	className map##className

#define REGISTER_CLASSMAP(className) \
	CClassMap::AddRuntimeClass(_T(#className),RUNTIME_CLASS(className))

#define CREATE_OBJECT(className) \
	CClassMap::CreateObject(className)

#endif // !defined(AFX_CLASSMAP_H__EF601101_A3FD_47A6_A8D6_723704B31F04__INCLUDED_)
