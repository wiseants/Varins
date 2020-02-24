// CSerialPort.h: interface for the CSerialPort class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CSerialPort_H__2602632E_C4EC_410E_A6EC_77752AD02E00__INCLUDED_)
#define AFX_CSerialPort_H__2602632E_C4EC_410E_A6EC_77752AD02E00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UtilityClass.h"
#include "UtilityException.h"
#include "xmlParser.h"
#include <exception>

class UTILITYCLASS SerialException : public BaseException
{
public:
	SerialException(long nCode) : BaseException(), m_nCode(nCode) {}
	virtual CString GetErrorMessage();

protected:
	long m_nCode;
};

struct UTILITYCLASS CCommInfo 
{
	long portNo;
	long baudRate;
	long parity;
	long dataBits;
	long stopBits;

	CCommInfo() {
		portNo		= -1;
		baudRate	= CBR_9600;
		dataBits	= 8;
		parity		= NOPARITY;
		stopBits	= ONESTOPBIT;
	}

	CString GetInfoStr() {
		CString parityBitsStr[] = {
			_T("NO"),
			_T("ODD"),
			_T("EVEN"),
			_T("MARK"),
			_T("SPACE")
		};

		CString stopBitsStr[] = {
			_T("1"),
			_T("1.5"),
			_T("2") };

		CString infoStr = _T("");
		if (portNo > -1)
		{
			infoStr.Format(_T("COM%d/%dbps/%s/%d/%s"), 
				portNo, 
				baudRate, 
				parityBitsStr[parity], 
				dataBits,
				stopBitsStr[stopBits]);
		}
		return infoStr;
	}

	bool operator==(CCommInfo& commInfo)
	{
		return commInfo.portNo == portNo && commInfo.baudRate == baudRate && commInfo.dataBits == dataBits && 
				commInfo.parity == parity && commInfo.stopBits == stopBits;
	}

	void operator=(CCommInfo commInfo)
	{
		portNo = commInfo.portNo;
		baudRate = commInfo.baudRate;
		dataBits = commInfo.dataBits;
		parity = commInfo.parity;
		stopBits = commInfo.stopBits;
	}

	void Save(XMLNode& xmlSettings, LPCTSTR section)
	{
		xmlSettings.SetValueLong(section, _T("PortNo"), portNo);
		xmlSettings.SetValueLong(section, _T("BaudRate"), baudRate);
		xmlSettings.SetValueLong(section, _T("ByteSize"), dataBits);
		xmlSettings.SetValueLong(section, _T("Parity"), parity);
		xmlSettings.SetValueLong(section, _T("StopBits"), stopBits);
	}

	void Load(XMLNode& xmlSettings, LPCTSTR section)
	{
		portNo = xmlSettings.GetValueLong(section, _T("PortNo"), -1);
		baudRate = xmlSettings.GetValueLong(section, _T("BaudRate"), 9600);
		dataBits = xmlSettings.GetValueLong(section, _T("ByteSize"), 8);
		parity = xmlSettings.GetValueLong(section, _T("Parity"), 0);
		stopBits = xmlSettings.GetValueLong(section, _T("StopBits"), 0);
	}

	void CopyFrom(CCommInfo* pDstCommInfo)
	{
		portNo = pDstCommInfo->portNo;
		baudRate = pDstCommInfo->baudRate;
		parity = pDstCommInfo->parity;
		dataBits = pDstCommInfo->dataBits;
		stopBits = pDstCommInfo->stopBits;
	}
};

////// Serial port class ////////////////////////////////////////////
enum FlowControl
{
	NoFlowControl,
	CtsRtsFlowControl,
	CtsDtrFlowControl,
	DsrRtsFlowControl,
	DsrDtrFlowControl,
	RtsDtrForcedEnable,
	XonXoffFlowControl
};

enum Parity
{    
	EvenParity = EVENPARITY,
	MarkParity = MARKPARITY,
	NoParity = NOPARITY,
	OddParity = ODDPARITY,
	SpaceParity = SPACEPARITY
};

enum StopBits
{
	OneStopBit = ONESTOPBIT,
	OnePointFiveStopBits = ONE5STOPBITS,
	TwoStopBits = TWOSTOPBITS
};

//// The actual serial port class /////////////////////////////////////////////

class UTILITYCLASS CSerialPort
{
public:
	//Constructors / Destructors
	CSerialPort();
	~CSerialPort();

	//General Methods
	BOOL Open2(const CCommInfo& info);
	BOOL Open2(int nPort, DWORD dwBaud, Parity parity = NoParity, BYTE DataBits = 8, 
			StopBits stopbits = OneStopBit, FlowControl fc = NoFlowControl, BOOL bOverlapped = FALSE);
	void Open(const CCommInfo& info);
	void Open(int nPort, DWORD dwBaud, Parity parity = NoParity, BYTE DataBits = 8, 
			StopBits stopbits = OneStopBit, FlowControl fc = NoFlowControl, BOOL bOverlapped = FALSE);
	void Close();

	void Attach(HANDLE hComm);
	HANDLE Detach();
	operator HANDLE() const { return m_hComm; };
	BOOL IsOpen() const { return m_hComm != INVALID_HANDLE_VALUE; }

	static BOOL IsUnusablePort(int nPort);
	
	#ifdef _DEBUG
	void CSerialPort::Dump(CDumpContext& dc) const;
	#endif

	//Reading / Writing Methods
	DWORD Read(void* lpBuf, DWORD dwCount);
	BOOL Read(void* lpBuf, DWORD dwCount, OVERLAPPED& overlapped);
	void ReadEx(void* lpBuf, DWORD dwCount);
	DWORD Write(const void* lpBuf, DWORD dwCount);
	BOOL Write(const void* lpBuf, DWORD dwCount, OVERLAPPED& overlapped);
	void WriteEx(const void* lpBuf, DWORD dwCount);
	void TransmitChar(char cChar);
	void GetOverlappedResult(OVERLAPPED& overlapped, DWORD& dwBytesTransferred, BOOL bWait);
	void CancelIo();

	//Configuration Methods
	void GetConfig(COMMCONFIG& config);
	static void GetDefaultConfig(int nPort, COMMCONFIG& config);
	void SetConfig(COMMCONFIG& Config);
	static void SetDefaultConfig(int nPort, COMMCONFIG& config);

	//Misc RS232 Methods
	void ClearBreak();
	void SetBreak();
	void ClearError(DWORD& dwErrors);
	void GetStatus(COMSTAT& stat);
	void GetState(DCB& dcb);
	void SetState(DCB& dcb);
	void Escape(DWORD dwFunc);
	void ClearDTR();
	void ClearRTS();
	void SetDTR();
	void SetRTS();
	void SetXOFF();
	void SetXON();
	void GetProperties(COMMPROP& properties);
	void GetModemStatus(DWORD& dwModemStatus); 

	//Timeouts
	void SetTimeouts(COMMTIMEOUTS& timeouts);
	void GetTimeouts(COMMTIMEOUTS& timeouts);
	void SetTimeout();
	void SetWriteTimeout();
	void SetReadTimeout();

	//Event Methods
	void SetMask(DWORD dwMask);
	void GetMask(DWORD& dwMask);
	void WaitEvent(DWORD& dwMask);
	void WaitEvent(DWORD& dwMask, OVERLAPPED& overlapped);

	//Queue Methods
	void Flush();
	void Purge(DWORD dwFlags);
	void TerminateOutstandingWrites();
	void TerminateOutstandingReads();
	void ClearWriteBuffer();
	void ClearReadBuffer();
	void Setup(DWORD dwInQueue, DWORD dwOutQueue);

	int CheckReceiveBuffer(DWORD timeout = 0, ULONG dwSize = 0);

	//Overridables
	virtual void OnCompletion(DWORD dwErrorCode, DWORD dwCount, LPOVERLAPPED lpOverlapped);

	int GetPortNo() const { return m_nPortNo; }
	static CList<CSerialPort*, CSerialPort*>& GetPortList() { return s_CommList; }

protected:
	HANDLE m_hComm;       //Handle to the comms port
	BOOL   m_bOverlapped; //Is the port open in overlapped IO

	int m_nPortNo;
	CString m_strPortName;

	static CList<CSerialPort*, CSerialPort*> s_CommList; // Do we really need this?

	static void WINAPI _OnCompletion(DWORD dwErrorCode, DWORD dwCount, LPOVERLAPPED lpOverlapped);

private:
	BOOL m_bAttach;
	CSerialPort(const CSerialPort& CSerialPort);
	CSerialPort& operator=(const CSerialPort& CSerialPort);
};

#endif // !defined(AFX_CSerialPort_H__2602632E_C4EC_410E_A6EC_77752AD02E00__INCLUDED_)
