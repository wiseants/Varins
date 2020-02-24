// XmlArchive.h: interface for the CXList class.
//
//////////////////////////////////////////////////////////////////////

#define USE_XML_ARCHIVE

#ifdef USE_XML_ARCHIVE
#if !defined(AFX_XMLARCHIVE_H__89AC8467_B359_4478_8236_B51EA091371D__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_XMLARCHIVE_H__89AC8467_B359_4478_8236_B51EA091371D__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include <atlcoll.h>
#include "UtilityClass.h"

#include "msxml6.tlh"

#define TESTHR(hr) { if FAILED(hr) return FALSE; }
#pragma warning( disable : 4786 ) 

class CXmlArchive;
class CXmlNode;

typedef CAtlList<CXmlNode*> XmlNodeList;

class UTILITYCLASS CXmlNode : public CObject
{
private:
	CXmlNode* m_pParent;
	XmlNodeList m_nodeList;
	MSXML2::IXMLDOMDocumentPtr m_docPtr;
	MSXML2::IXMLDOMNodePtr m_nodePtr;
	CXmlArchive* m_pXmlArchive;
public:
	CXmlNode(MSXML2::IXMLDOMNodePtr nodePtr, MSXML2::IXMLDOMDocumentPtr& docPtr, CXmlArchive* pXmlArchive);
	virtual ~CXmlNode();

	CString GetNodeName();
	BOOL CheckNode(LPCTSTR nodeName);
	CXmlNode* AddNode(LPCTSTR nodeName);
	BOOL AddNode(CXmlNode* pChild);
	BOOL RemoveNode(LPCTSTR nodeName);
	BOOL RemoveNode(CXmlNode* pNode);
	void RemoveAllNodes();

	void AddBlank(MSXML2::IXMLDOMNodePtr parentNode);
	void EndNode();

	MSXML2::IXMLDOMNodePtr GetNodePtr();
	CXmlNode* GetChildNode(LPCTSTR nodeName, CXmlNode* pFindAfter = NULL);
	CXmlNode* GetChildNode(LPCTSTR name, LPCTSTR attr, LPCTSTR value);
	CXmlNode* GetFirstChildNode();
	CXmlNode* GetNextNode();
	CXmlArchive* GetXmlArchive();
	void GetChildNodeList(LPCTSTR name, XmlNodeList& nodeList);
	CXmlNode* GetParent();
	void SetParent(CXmlNode* pParent);

	CString GetText(LPCTSTR defaultValue = _T(""));
	CString GetValue(LPCTSTR name, LPCTSTR defaultValue = _T(""));
	void SetLong ( long value );
	void SetDouble ( double value );
	void SetString ( LPCTSTR value );
	void SetLong ( LPCTSTR nodeName , long value );
	void SetDouble ( LPCTSTR nodeName , double value );
	void SetString ( LPCTSTR nodeName , LPCTSTR value );

	BOOL GetBinary(LPBYTE lpByte, long size);
	void SetBinary(LPBYTE lpByte, long size);

	CXmlNode* SelectSingleNode(LPCTSTR queryString);
};

class CXmlNode;

class UTILITYCLASS CXmlArchive
{
	MSXML2::IXMLDOMDocumentPtr m_docPtr;
	CXmlNode* m_pRootNode;
public:
	CXmlArchive();
	virtual ~CXmlArchive();

	BOOL Create(LPCTSTR defaultData = NULL);
	BOOL Open(LPCTSTR lpszPathName);
	BOOL Save(LPCTSTR lpszPathName);
	CXmlNode* GetRootNode(LPCTSTR nodeName = NULL);
	CString GetXML();

	void ReportError();
	BOOL IsAvailable();
};

//#pragma warning( default : 4786 ) 

#endif // !defined(AFX_XLIST_H__89AC8467_B359_4478_8236_B51EA091371D__INCLUDED_)
#endif