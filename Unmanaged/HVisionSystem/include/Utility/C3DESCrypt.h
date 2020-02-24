#pragma once
#ifndef _3DES_CRYPT_H_
#define _3DES_CRYPT_H_

#include "UtilityClass.h"
#include <wincrypt.h>

class UTILITYCLASS C3DESCrypt
{
public:
	C3DESCrypt(void);
	~C3DESCrypt(void);
	
	BOOL Init(LPCTSTR pszKey);

	LPCTSTR Encrypt(LPCTSTR pOrgData, int cbOrgData);
	LPCTSTR Decrypt(LPCTSTR pEncData, int cbEncData);

	int CharToHexa(BYTE bytearray[],int bytelen, char *hexstring);
	int HexaToChars(const char *dataset, unsigned char *bytearray);

	char* ANSIToUTF8(const char * pszCode);
	char* UTF8ToANSI(const char *pszCode);

	char* WideToUTF8(LPCWSTR pszwCode);
	LPCWSTR UTF8ToWide(const char *pszCode);

	CStringW AnsiToWideChar(CStringA str);
	CStringA WideToAnsiChar(CStringW str);

private:
	HCRYPTPROV m_hProv;
	HCRYPTKEY m_hKey;
};

#endif // _3DES_CRYPT_H_

