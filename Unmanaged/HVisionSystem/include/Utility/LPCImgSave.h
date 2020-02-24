/****************************************************************************/
/*																			*/
/*	SYSTEM		:	Inspector system										*/
/*	SUB SYSTEM	:	CLPCImgSave  Image file to other process 				*/
/*	LANGUAGE	:	VC++ 2008												*/
/*																			*/
/*	FILE		:	LPCImgSave.h											*/
/*																			*/
/*	CAUTION		:	PRIVATE SOURCE FOR MIRTEC Co., Ltd.						*/
/*																			*/
/*	AUTHER		:	Lee, Hyuk Sang(mydos16@gmail.com)						*/
/*																			*/
/****************************************************************************/
#ifndef _LPCIMAGESAVE_H_
#define _LPCIMAGESAVE_H_

#include "LPCDef.h"
#include "Utility/UtilityClass.h"
#include "LPC_Obj.h"

class UTILITYCLASS CLPCImgSave
{
public:
	CLPCImgSave();
	~CLPCImgSave();

	BOOL Init();
	void Destroy();
	
	BOOL SPI_Send_DefectImage(LONG filetype, LPBYTE pImgData, LONG	nbuf, LONG cx, LONG cy, LONG band, LPCTSTR imagepath);

	BOOL SPI_Send_ProcessExit(LPCSTR pszIpcName);

protected:

	CLPCObj* m_pLPCObj;

	CRITICAL_SECTION	m_Crit;

	void LockInit();
	void LockClear();
	void Lock();
	void Unlock();
};

#endif //_LPCIMAGESAVE_H_
