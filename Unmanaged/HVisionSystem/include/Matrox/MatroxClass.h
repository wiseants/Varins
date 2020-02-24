#if !defined(AFX_MATROXCLASS_H__E03BEEAF_8186_4DCC_8C30_E0F8124E2063__INCLUDED_)

#ifndef DOXYGEN_EXCLUDE
#define AFX_MATROXCLASS_H__E03BEEAF_8186_4DCC_8C30_E0F8124E2063__INCLUDED_
#endif

#ifdef MATROX_DLL
   #define MATROXCLASS  _declspec(dllexport)
#else
   #define MATROXCLASS  _declspec(dllimport)
#endif

#ifdef _DEBUG
constexpr auto MATROX_MODULE_NAME = "Matrox.dll";
#else
constexpr auto MATROX_MODULE_NAME = "Matrox.dll";
#endif

#endif
