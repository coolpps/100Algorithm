// 26.�����ַ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

//�õ�����
void nizhi(char* a,int p,int r)
{
	int i,j;
	char temp;

	i=p;j=r;
	while(i<=j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		++i;
		--j;
	}
}

void leftreverse(char* a,int n)
{
	nizhi(a,0,n-1);
	nizhi(a,n,strlen(a)-1);
	nizhi(a,0,strlen(a)-1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[]="abcdef";

	int n;
	cin>>n;
	leftreverse(a,n);

	cout<<a<<endl;

	system("pause");
	return 0;
}

