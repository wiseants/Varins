/****************************************************************************/
/*																			*/
/*	SYSTEM		:	Inspector system										*/
/*	SUB SYSTEM	:	CLPCResultData send Inspect Result to other process 	*/
/*	LANGUAGE	:	VC++ 2008												*/
/*																			*/
/*	FILE		:	LPCResultData.h											*/
/*																			*/
/*	CAUTION		:	PRIVATE SOURCE FOR MIRTEC Co., Ltd.						*/
/*																			*/
/*	AUTHER		:	Lee, Hyuk Sang(mydos16@gmail.com)						*/
/*																			*/
/****************************************************************************/

#ifndef _LPCRESULTDATA_H_
#define _LPCRESULTDATA_H_

#include "LPCDef.h"
#include "Utility/UtilityClass.h"
#include "LPC_Obj.h"

class UTILITYCLASS CLPCResultData
{
public:
	CLPCResultData();
	~CLPCResultData();

	CLPCObj* m_pLPCObj;

	BOOL Init();
	void Destroy();

	BOOL SPI_Send_ResultData(SPI_MSGTYPE dwMsg, LPRESULTDATA_INFO pSendData);

	BOOL SPI_Send_ProcessExit();
};

#endif //_LPCRESULTDATA_H_
