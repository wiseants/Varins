#ifndef __MEMORYPOOL_H__
#define __MEMORYPOOL_H__

// ����		: �ܸ��� ������ ���� NEW/DELETE �������� ���Ͽ�
//			  �޸� ����ȭ�� ó���ӵ��� ���� ������带 
//			  ���̱� ���Ͽ� �������� Ǯ�� ��ɵ��� �����Ѵ�.
// �׽�Ʈ���:�޸� ����ȭ�� ���� �پ���. ���� Ƚ���� ������ �޸��� ����ȭ�� �Ͼ�� �ʴ´�.
//			  ���� ó�� �ӵ��� ���̴� �߻����� �ʴ´�.
//			  Page Pool		-> ������ ������ ����
//			  Serial Pool	-> ������� ����

namespace memorypool
{
	static const INT		g_PAGE_INDEX_SIZE	= 9;
	static const DWORD		g_K_BYTE			= 1024;
	static const INT		g_OFFSET_SIZE		= 4;

	class CPagePool 
	{
	public:
		CPagePool(): m_pPool(0), m_pPoolPtr(0), m_iUnUsedPool(0), m_bInternal(FALSE)
		{

		}

		virtual ~CPagePool()
		{
			Release();
		}

	protected:
		INT  PAGEDATA_SIZE;
		INT  PAGEDATA_NUM;

		BYTE *m_pPool;
		BYTE **m_pPoolPtr;
		INT	 *m_iUnUsedPool;
		INT	 m_iUnUsedEndIdx;
		BOOL m_bInternal;

	public:
		BYTE* Init(INT page_size, INT page_num)
		{
			return Init(NULL,page_size,page_num);
		}

		BYTE* Init(BYTE* pMemPool, INT page_size, INT page_num)
		{
			INT iSizeNum=0;
			PAGEDATA_SIZE = page_size + g_OFFSET_SIZE; //4 byte :index save
			PAGEDATA_NUM = page_num;

			if(!pMemPool)
			{
				m_pPool		= new BYTE[PAGEDATA_SIZE * PAGEDATA_NUM];
				m_pPoolPtr	= new BYTE*[PAGEDATA_NUM];
				m_iUnUsedPool = new INT[PAGEDATA_NUM];
				m_bInternal = TRUE;
			}
			else
			{
				m_pPool			= pMemPool; iSizeNum += PAGEDATA_SIZE * PAGEDATA_NUM;
				m_pPoolPtr		= (BYTE**)(pMemPool + iSizeNum); iSizeNum += sizeof(BYTE*) * PAGEDATA_NUM;
				m_iUnUsedPool	= (INT*)(pMemPool + iSizeNum); iSizeNum += sizeof(int) * PAGEDATA_NUM;
				m_bInternal		= FALSE;
			}

			for(INT i=0; i < PAGEDATA_NUM; ++i)
			{
				m_iUnUsedPool[i] = i;
				m_iUnUsedEndIdx = i;
				m_pPoolPtr[i] = &m_pPool[i * PAGEDATA_SIZE];
			}

			return pMemPool + iSizeNum;
		}

		void Release()
		{
			if(m_bInternal)
			{
				delete[] m_pPool,m_pPool = NULL;
				delete[] m_pPoolPtr,m_pPoolPtr = NULL;
				delete[] m_iUnUsedPool,m_iUnUsedPool=NULL;
			}

		}

		//void Clear();
		BYTE* Alloc()
		{
			// �Ҵ���н� ũ��Ƽ�� ����	
			if(m_iUnUsedEndIdx <0) return NULL;
			// �Ҵ�
			int nIndex = m_iUnUsedPool[m_iUnUsedEndIdx--];
			BYTE *pData	= m_pPoolPtr[nIndex];

			memcpy(pData,&nIndex,sizeof(int));

			//m_bUsedPageNode[nIndex] = TRUE;

			return pData + g_OFFSET_SIZE;
		}

		BOOL Free(BYTE* pData)
		{
			if(FALSE == m_pPool || pData < m_pPool || pData > m_pPool + (PAGEDATA_SIZE * PAGEDATA_NUM)) 
				return FALSE;
			// �߸��� �ε��� ���� ũ��Ƽ�� ����
			//m_iUnUsedPageNode[++ m_iUnUsedEndIdx] = (pData-PAGE_INDEX_SIZE)->nIndex;
			int nIdx = (int)(*(pData - g_OFFSET_SIZE));
			m_iUnUsedPool[++ m_iUnUsedEndIdx] = nIdx;

			return TRUE;
			//m_bUsedPageNode[pData->nIndex] = FALSE;
		}

	};

	class CSerialPool
	{
	public:
		CSerialPool() : m_pPool(0), m_iPoolSize(0), m_iUsedPool(0), m_bInternal(FALSE)
		{

		}
		
		~CSerialPool()
		{
			Release();
		}

	protected:
		BYTE* m_pPool;
		INT	m_iPoolSize;
		INT	m_iUsedPool;
		BOOL m_bInternal; 

	public:
		// Create Serial Pool
		BOOL  Init(INT bytes)
		{
			return Init(NULL, bytes);
		}

		BOOL  Init(BYTE* pPool, INT bytes)
		{
			Release();
			m_pPool = pPool;
			if(NULL == pPool)
			{
				m_pPool = new BYTE[bytes];
				m_bInternal = TRUE;
			}

			if(NULL == m_pPool)	
				m_iPoolSize =0;
			else				
				m_iPoolSize = bytes;
			
			return  m_iPoolSize > 0  ? TRUE : FALSE;
		}

		// Delete Serial Pool
		VOID  Release()	
		{ 
			if(m_pPool && m_bInternal) delete[] m_pPool, m_pPool =NULL;
			
			m_bInternal = FALSE;
			m_iPoolSize = 0;
			m_iUsedPool = 0;
		}

		VOID Clear(){ m_iUsedPool =0;}

		// Allocation From Serial Pool
		BYTE* Alloc(INT bytes)
		{
			BYTE* pResult = NULL;
			if(m_iUsedPool + bytes > m_iPoolSize) return NULL;
			pResult = (BYTE*)m_pPool + m_iUsedPool;
			m_iUsedPool += bytes;

			return pResult;
		}

		// Return to Serial Pool
		BOOL Free(INT bytes)
		{
			if(m_iUsedPool - bytes < 0) return FALSE;
			m_iUsedPool -= bytes;
			return TRUE;
		}

		BYTE* Get_PoolPtr(){return m_pPool;}
		int Get_Size(){return m_iPoolSize;}
		int Get_UsedSize(){return m_iUsedPool;}
	};
}

#endif