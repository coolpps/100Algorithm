// 28.�����Ķ����Ʊ�ʾ��1�ĸ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int count(int n)
{
	int cnt=0;
	while(n!=0)
	{
		cnt+=1;
		n=n&(n-1);
	}
	return cnt;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin>>n;

	cout<<count(n)<<endl;

	system("pause");
	return 0;
}

