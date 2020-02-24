#pragma once

#include "UtilityClass.h"
#include "MemoryPool.h"
#include <vector>
#include <atlcoll.h>

class UTILITYCLASS CMemPoolMngr
{
public:
	static CMemPoolMngr* GetInstance();

public:
	VOID AddPointsSize(INT _iBytes);
	BOOL FreePoints();
	LPBYTE AllocPoints(INT _iBytes);
	BOOL FreePoints(INT _iBytes);

protected:
	CMemPoolMngr(void);
	CMemPoolMngr(const CMemPoolMngr&);
	friend class CMemPoolMngrDestroyer;
	virtual ~CMemPoolMngr(void);
	
private:
	static CMemPoolMngr* g_pInstance;
	static CMemPoolMngrDestroyer g_Destroyer;

	memorypool::CSerialPool m_PointPool;
	CAtlArray<INT> m_vecPointPool;
};

class CMemPoolMngrDestroyer
{
public:
	CMemPoolMngrDestroyer(CMemPoolMngr* = NULL);
	~CMemPoolMngrDestroyer();

	void SetDoomed(CMemPoolMngr* _pSingleton);
	CMemPoolMngr* GetDoomed();

private:
	CMemPoolMngr* m_pSingleton;
};
