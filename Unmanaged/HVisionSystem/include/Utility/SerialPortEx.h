// SerialPortEx.h: interface for the CSerialPortEx class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALPORTEX_H__561AF5DB_75AC_40D0_AE1B_CC1807488FCC__INCLUDED_)
#define AFX_SERIALPORTEX_H__561AF5DB_75AC_40D0_AE1B_CC1807488FCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SerialPort.h"
#include <afxmt.h>
#include "Thread.h"

#pragma warning (disable : 4290)

interface UTILITYCLASS ISerialListener
{
	virtual void ReceivedData(LPBYTE pBuf, int nSize) throw() = 0;
};

/** CSerialPortEx has additional functionality to the existing CSerialPort class.
	Notably, this class can start monitoring thread to wait incoming data from the Com Port.
	Incoming message is transfered to the listener registered.
	Overlapped IO is default here.
*/

class UTILITYCLASS CSerialPortEx : public CSerialPort  
{
public:
	CSerialPortEx() throw(UtilityException);
	~CSerialPortEx();

	BOOL Open2(int nPort, DWORD dwBaud = 9600, Parity parity = NoParity, BYTE DataBits = 8, 
			StopBits stopbits = OneStopBit, FlowControl fc = NoFlowControl) throw(SerialException);
	BOOL Open2(const CCommInfo& info, FlowControl fc = NoFlowControl);
	void Open(int nPort, DWORD dwBaud = 9600, Parity parity = NoParity, BYTE DataBits = 8, 
			StopBits stopbits = OneStopBit, FlowControl fc = NoFlowControl) throw(SerialException);
	void Open(const CCommInfo& info, FlowControl fc = NoFlowControl);

	DWORD ReadComm(LPBYTE pBuff, DWORD nToRead) throw(SerialException);
	void WriteComm(LPVOID lpBuf, DWORD dwCount) throw(SerialException);
	void WriteComm(LPCTSTR lpszMessage) throw(SerialException);

	void StartMonitoring() throw(SerialException);
	void StopMonitoring() throw();
	bool IsMonitoring() const throw() { return m_pThread != NULL; }
	
	void SetListener(ISerialListener* pListener) throw();

private:
	CSerialPortEx(const CSerialPortEx&) throw();
	const CSerialPortEx& operator=(const CSerialPort&) throw();

	ISerialListener* m_pListener;

	OVERLAPPED	m_osRead;
	OVERLAPPED	m_osWrite;

	Thread* m_pThread;

	friend class MonitoringThread;
};

inline void CSerialPortEx::SetListener(ISerialListener* pListener) throw()
{
	m_pListener = pListener;
}

#endif // !defined(AFX_SERIALPORTEX_H__561AF5DB_75AC_40D0_AE1B_CC1807488FCC__INCLUDED_)
