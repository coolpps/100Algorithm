// 54.��������˳��ʹ����λ��ż��ǰ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;


//O(n)ʱ��
void tiaozheng(int* a,int p,int r)
{
	int i=p;
	int j=r;

	while(i<j)
	{
		while(a[i]%2==1)
			++i;
		while(a[j]%2==0)
			--j;

		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}

	for(i=p;i<=r;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={5,3,2,7,8,1};

	tiaozheng(a,0,5);

	system("pause");
	return 0;
}

