/************************************************************************/
/*																		*/
/*	SYSTEM		:	Definition File to use Local Procedure Call			*/
/*	SUB SYSTEM	:	Dynamic DLL program of using LPC facility 			*/
/*	LANGUAGE	:	VC++ 2008											*/
/*																		*/
/*	FILE		:	LPCDef.h											*/
/*																		*/
/*	CAUTION		:	PRIVATE SOURCE FOR MIRTEC Co., Ltd.					*/
/*																		*/
/*	AUTHER		:	Lee, Hyuk Sang(mydos16@gmail.com)					*/
/*																		*/
/************************************************************************/

#pragma once

#define malloc_np(size)		HeapAlloc(GetProcessHeap(), 0, size);
#define free_np(ptr)		HeapFree(GetProcessHeap(), 0, ptr);

#define SPI_DEFECT_FILE_SAVE_LPC_NAME					"SPI_DEFECT_FILE_SAVE_LPC"
#define INSPECTOR_LOGMON_LPC_NAME						"INSPECTOR_LOGMANAGER_LPC"
#define INSPECTOR_RESULT_DATA_HTML_SAVE_LPC_NAME		"INSPECTOR_RESULT_DATA_HTML_SAVE_LPC"

#define LPC_LOG_SENDER				104

#define SPI_TIME_LEN				256
#define SPI_MACHINE_NAME_LEN		256
#define SPI_DEFECT_TYPE_LEN			10
#define SPI_OPERATOR_LEN			20

#define SPI_MAX_SYSTEMLOG			4096

#define SPI_DEFECTCODES_LEN			9

enum SPI_SAVETYPE 
{
	DEFECT_IMAGE,
	DEFECT_3D,
	IMAGE_LOG
};

enum SPI_MSGTYPE 
{
	SPI_DEFECT_IMAGE_SAVE_INFO = 30,
	SPI_DEFECT_3D_DATA_SAVE_INFO,
	SPI_INSPECTOR_LOGMAN_INIT,
	SPI_INSPECTOR_LOGMAN_SAVE,
	SPI_INSPECTOR_RESULT_DATA_HTML_SAVE_START,
	SPI_INSPECTOR_RESULT_DATA_HTML_SAVING,
	SPI_INSPECTOR_RESULT_DATA_HTML_SAVE_END,
	SPI_PROCESS_EXIT
};

// system log record tyep.
enum SPI_SYSTEMLOG_TYPE
{
	SPI_SYSTEMLOG_TYPE_DEBUG	= 0,
	SPI_SYSTEMLOG_TYPE_INFO		= 1,
	SPI_SYSTEMLOG_TYPE_WARNING	= 2,
	SPI_SYSTEMLOG_TYPE_ERROR	= 3,
	SPI_SYSTEMLOG_TYPE_FATAL	= 4,
	SPI_SYSTEMLOG_TYPE_COREINFO	= 5,
};

// system log file tyep.
enum SPI_SYSTEMLOG_FILE_TYPE
{
	SPI_SYSTEMLOG_FILE_TYPE_STARTUP	= 0,
	SPI_SYSTEMLOG_FILE_TYPE_OPERATION,
	SPI_SYSTEMLOG_FILE_TYPE_ERROR,
	SPI_SYSTEMLOG_FILE_TYPE_DEBUG,
	SPI_SYSTEMLOG_FILE_TYPE_EXCEPTION,
	SPI_SYSTEMLOG_FILE_TYPE_INSPECTION,
	SPI_SYSTEMLOG_FILE_TYPE_CLOSEDLOOP,
	SPI_SYSTEMLOG_FILE_TYPE_SAVE_MODEL,
	SPI_SYSTEMLOG_FILE_TYPE_LOAD_MODEL,
};

//////////////////////////////////////////////////////////////////////////////
// Defect Image Save Structure
typedef struct stSAVE_FILE_INFO
{	
	LONG		nbuf;					//image buffer size or save data size
	LONG		cx;						//image cx
	LONG		cy;						//image cy
	LONG		band;					//band size
	TCHAR		imagepath[MAX_PATH];	//file path
}SAVE_FILE_INFO, *LPSAVE_FILE_INFO;

//////////////////////////////////////////////////////////////////////////////
// Log Manager Data Structure
typedef struct stLOGMON_INFO
{
	SPI_SYSTEMLOG_FILE_TYPE		logfile;
	SPI_SYSTEMLOG_TYPE			LogLevel;
	TCHAR						szLog[SPI_MAX_SYSTEMLOG];
	TCHAR						szMutex[MAX_PATH];
}LOGMON_INFO, *LPLOGMON_INFO;

//////////////////////////////////////////////////////////////////////////////
// Inspect Result Data HTML Save Structure
typedef struct stRESULTDATA_INFO
{
	TCHAR szInspStartTime[SPI_TIME_LEN]; //yyyy/mm/dd hh/mm/ss format
	TCHAR szInspEndTime[SPI_TIME_LEN];	//yyyy/mm/dd hh/mm/ss format
	TCHAR szMachineName[SPI_MACHINE_NAME_LEN];
	TCHAR szModelName[SPI_MACHINE_NAME_LEN];

	TCHAR szRefID[SPI_MACHINE_NAME_LEN];
	double Height;
	double HeightPercent;
	double Area;
	double AreaPercent;
	double Volume;
	double VolumePercent;
	double OffsetX;
	double OffsetY;

	double Coplan_Height;
	double Coplan_Area;
	double Coplan_Volume;
	
	LONG   DefectCode[SPI_DEFECTCODES_LEN];

	BOOL   bStatus;		// if FALSE, status is NG, else REPASS
	
	TCHAR szSerialNo[SPI_MACHINE_NAME_LEN];
	TCHAR szLot_ID[SPI_MACHINE_NAME_LEN];
	TCHAR szBarcode[SPI_MACHINE_NAME_LEN]; 
	TCHAR szComponent[SPI_MACHINE_NAME_LEN];
	TCHAR szOperator[SPI_OPERATOR_LEN];

	TCHAR szSrcPath[MAX_PATH];  //szSrcPath is the defect image file path.
	TCHAR szDestPath[MAX_PATH];  //szDestPath is directory path to save the defect image file path.
	TCHAR szImageFile[MAX_PATH]; //szImageFile is filename to save the defect image file.
}RESULTDATA_INFO, *LPRESULTDATA_INFO;

typedef struct stLPC_SENDMSG
{
	SPI_MSGTYPE	dwMsg;
}LPC_SENDMSG, *LPLPC_SENDMSG;
