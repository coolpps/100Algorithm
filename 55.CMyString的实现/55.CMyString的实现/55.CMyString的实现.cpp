// 55.CMyString��ʵ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char* pDatta=NULL);
	CMyString(const CMyString& str);
	~CMyString();
	CMyString& operator=(const CMyString& str);
private:
	char*m_pData;
};

//1.
CMyString& CMyString::operator=(const CMyString& str)
{
	char* p=this->m_pData;
	this->m_pData=new char[strlen(str.m_pData)+1];
	strcpy(m_pData,str.m_pData);
	delette p;
}

//���ַ����ȽϺ�
CMyString& CMyString::operator=(const CMyString& str)
{
	if(*this!==str)
	{
		CMyString temp(str);
		char* t=temp.m_pData;
		temp.m_pData=m_pData;
		m_pData=t;
	}
}





int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

