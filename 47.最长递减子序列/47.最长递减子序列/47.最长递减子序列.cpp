// 47.��ݼ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
/*
��a[0...n-1]��������count[0...n-1]����¼��a[i]��β����ݼ������еĳ��ȣ���i��˵��j=0..i-1�������a[j]>a[i]����ôcount[i]=count[j]+1
ȡcount[i]=MAX(count[j]+1��������a[j]>a[i] && j=0....i-1)

���Ҫչʾ�Ÿ����еĻ������Ǵ����1��Ԫ�ؿ�ʼ��ǰ��������count[i]=max,��ô���Ԫ�ؾ�����ݼ������е����һ��Ԫ�أ�����ǰһ��Ԫ��Ӧ������a[j]>a[i] && count[j]==count[i]-1,һֱ��ǰ��֪��j<0Ϊֹ
*/

//��ӡ��ݼ������� 
void print(int* a,int *count,int n,int max)
{
	int i=n-1;
	while(count[i]!=max)
		--i;
	int j;
	for(j=i-1;j>=0;--j)
		if(count[j]+1==count[i] &&a[j]>a[i])
		{
			print(a,count,j+1,max-1);
				break;
		}
	cout<<a[i]<<" ";
}

void getmax(int* a,int* count,int n)
{
	//����a[0]��Ӧ��count[0]��1
	int i,j;
	int max=0;

	count[0]=1;
	for(i=1;i<n;i++)
	{
		count[i]=0;
		for(j=0;j<i;j++)
		{
			if(a[j]>a[i] && count[j]+1>count[i])
				count[i]=count[j]+1;
		}
		if(count[i]>max)
			max=count[i];
	}
	for(i=0;i<n;i++)
		cout<<count[i]<<" ";
	cout<<endl;

	print(a,count,n,max);
	cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={9,4,3,2,5,4,3,2};
	int count[8]={0};

	getmax(a,count,8);
	cout<<endl;

	system("pause");
	return 0;
}

