// 51.���Ϊn������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
�������n,������������n/2,��Ϊn/2+(n/2+1)�ʹ���n�ˣ�����������ñ����Ļ�����ô�ʹ�1-n/2����ÿ��Ԫ�ؿ�ʼ
*/
#include<iostream>
using namespace std;

void bianli(int n)
{
	int end=n/2;
	int i,j,k;

	int sum=0;
	for(i=1;i<=end;i++)
	{
		j=i;
		sum=0;
		sum+=j;
		while(sum<n)
		{
			++j;
			sum+=j;
		}

		if(sum==n)//�õ�1��������[i,j]
		{
			for(k=i;k<=j;++k)
				cout<<k<<" ";
			cout<<endl;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;

	cin>>n;
	bianli(n);

	system("pause");
	return 0;
}

