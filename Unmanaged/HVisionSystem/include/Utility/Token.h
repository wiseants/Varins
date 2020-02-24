#ifndef _TOKEN_H_

#ifndef DOXYGEN_EXCLUDE
#define _TOKEN_H_
#endif

#define NORMAL_SEP	0x0000
#define GROUP_SEP	0x0001
#define MERGE_SEP	0x0002
#define SKIP_TOKEN	0x0004

struct TOKEN_INFO
{
	CString delimiter;
	CString finder;
	int type;
};


#include "UtilityClass.h"
// Deprecate
class UTILITYCLASS CTokenizer
{
	CString original;
	CString tokenStr;
	CString trimChar;
	bool	moreTokenExist;

	//! �ϳ��� ��ū ǥ�������κ��� TOKEN_INFO�� �ʿ��� ������ ��� �´�.
	/*!
	��ū ǥ������ ��ū�� ������ ���� �����ϰ��ϱ� ���� ������ ���ڿ��̴�. 
	��ū ǥ������ ������ ���� ���¸� ������. 

		<i> [wild card string] ; [parsing function]</i>
		[wild card string] := literal include * and/or ?(*)
		[parsing function] := p([delimiter]) | g([delimiter]) 
		*;p(x)	N*;g(y)

		wild card string���� wild card ����(*,?)�̿��� ���ڰ� �����ϸ�
		�Ľ̽� ��ū�� ���¸� �����Ͽ� ��ū�� ��ȿ�� ���θ� �˻��ϰ�,
		��ȯ�Ǵ� ��ū�� �ش� ���ڸ� ������ �� ��ȯ�ȴ�.

		p - normal seperator. ��ȣ���� ������ �Ϻθ� ��ġ�ϸ� ������.
		g - group seperator. ��ȣ���� ���ڰ� ��� ��ġ�ؾ� ��.
		s - skip token. ������ �����ڷ� ��ū�� ������ ��ȯ���� �ʰ� �����Ѵ�.

		delimiter�� /�� ����� �� ����. /�� ����ؾ� �� ��� \\�� ���.
		Ư�� ��ȣ : \\ = \t , \\ = \\
	\param tokInfo [out] �Ľ� ������ ��ū ǥ�������� ���� ��� �´�.
	\param tokInfoStr ��ū ǥ���� 
	\return tokInfoStr�� �������̸� TRUE�� ��ȯ�Ѵ�. �� ������ ���� ǥ������ �����Ѵ�.
	*/
	BOOL GetTokenInfo(TOKEN_INFO& tokInfo, CString tokInfoStr);

	//! TOKEN_INFO�� ������ ��ū�� �ϳ� ��� �´�.
	BOOL GetNextToken(CString& token, TOKEN_INFO& tokInfo);

public:
	//! �⺻ ������
	CTokenizer();
//	virtual ~CTokenizer();
	//! ���޵� ���ڿ��� ������ ��ū�����⸦ �ʱ�ȭ �Ѵ�. 
	CTokenizer(LPCTSTR str);
	
	//! ��ū ������ ��ȯ�Ѵ�.
	int GetTokenCount(LPCTSTR delimiter);

	//! ��ū�� ��ȯ�Ѵ�.
	/*!
	�� �Լ��� ����� �����ϳ� Token�� �������� ���� ��� �� ���ڿ��� ��ȯ�ǹǷ� 
	Token�� ���� ������ Ȯ���ϴµ� �������� ���ϴ�. Token������ Ȯ���ϱ� ���ؼ��� 
	�ݵ�� IsTokenExist�� ���� ����ؾ� �Ѵ�. ���� �ٸ� ������ GetNextToken�� 
	����ϴ� ���� �ٶ����ϴ�.
	\deprecated ����Ǿ���.
	\param delimiter ���� ����
	\param offset nth token. �ݵ�� 0���� Ŀ�� �Ѵ�.
	*/
	CString GetNextToken(LPCTSTR, int offset = 1);
	//! ��ū ���� ���� ����
	/*!
	\deprecated GetNextToken����
	*/
	BOOL IsTokenExist ( void );

	//! ��ū�� ��ȯ�Ѵ�.
	/*!
	<code>
		CToken tokenizer = "1;2;3;4";
		CString tokenStr;
		while(tokenizer.GetNextToken(tokenStr,";")) {
			cout << tokenStr << "\n";
		}
	</code>
	\param tokenStr [out] ��ū�� ���� ����.
	\param delimiter ���� ����
	\param offset nth token. �ݵ�� 0���� Ŀ�� �Ѵ�. �⺻���� 1�̴�.
	\param type ��ū ���� ����� �����Ѵ�. GROUP_SEP �Ǵ� MERGE_SEP�� ������ �� �ִ�. �⺻���� NORMAL_SEP�̴�.
	\return ��ū ������ ���������� ����Ǿ����� TRUE�� ��ȯ�Ѵ�. 
	*/
	BOOL GetNextToken(CString& tokenStr, LPCTSTR delimiter, int offset = 1, int type = NORMAL_SEP);

	//! ��ū�迭�� ��ȯ�Ѵ�.
	/*!
	���޵� ���� ���ڸ� �̿��Ͽ� ����� ��ū�� �迭�� �����Ѵ�. 
	\param tokenList [out] ��ū�� ���� �迭 ����.
	\param delimiter ���� ����
	\return ��ū ������ ���������� ����Ǿ����� TRUE�� ��ȯ�Ѵ�. �׻�, TRUE�� ��ȯ.
	*/
	BOOL GetTokenList(CStringArray& tokenList, LPCTSTR delimiter);

	//! ��ū�迭�� ��ȯ�Ѵ�.
	/*!
	���޵� ��ū ǥ������ �̿��Ͽ� ��ū �����⳻�� ���ڿ��� �ϰ������� �迭�� �����Ѵ�. 
	\param tokenList [out] ��ū�� ���� �迭 ����.
	\param tokExp ��ū ǥ���� 
	\return ��ū ������ ���������� ����Ǿ����� TRUE�� ��ȯ�Ѵ�. 
	*/
	BOOL GetTokenListEx(CStringArray& tokenList, LPCTSTR tokExp);

	LPCTSTR PeekNextToken(TCHAR* delimiter);
	CString GetStringToken(TCHAR* delimiter);

	CString operator= ( LPCTSTR str );
	operator LPCTSTR() const;

	CString GetString ( void );
	
	//! �߶󳻱� ���ڿ� ����
	/*!
	\deprecated �̸� ���� SetTrimChar�� ���.
	*/
	void TrimChar ( LPCTSTR trimChar );
	//! �߶󳻱� ���ڿ� ����
	void SetTrimChar(LPCTSTR trimChar);

	void RemoveRemark( LPCTSTR startRemark );
};

// New Name
#define CToken CTokenizer

#endif  // _TOKEN_H_
