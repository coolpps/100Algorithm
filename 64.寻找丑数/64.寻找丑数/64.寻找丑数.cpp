// 64.Ѱ�ҳ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<limits>
using namespace std;
/*
Ѱ�ҳ�����������ֻ��2,3,5�ĳɼ��Ϳ��Եõ���������n�ǳ���,n=2*2*2*....*3*3*....*5*5*5*....
�����������ľͲ��ǳ���
1,2,3,4,5���ǳ���
��տ�ʼ����Ϊ1
 1*2,1*3,1*5�õ�3��������������취����3���������ӵ�������,Ӧ�ð�2���---1,2
 1,2-->���ɵ�Ԫ���У�1,3,5,4,6,10,Ӧ�ð�>2����СԪ����ӵ���1,2,3
 1,2,3->���ɵ�Ԫ����1,3,5,4,6,10,6,9,15��Ӧ�ð�>3����С����ӽ�ȥ����1,2,3,4,
 ����ѭ����ȥ�����ܵõ���1500��Ԫ����
*/

//�ж�1�����ǲ��ǳ���
bool isUgly(int n)
{
	if(n>0)
	{
		while(n%2==0)
			n=n/2;
		while(n%3==0)
			n=n/3;
		while(n%5==0)
			n=n/5;
		if(n==1)
			return true;
		return false;
	}
	else
		return false;

}

#define MAX 1600
void print(int n)
{
	int a[MAX];
	int i,min,k,j;

	a[1]=1;

	int b[]={2,3,5};
	for(i=2;i<=1500;++i)
	{
		min=numeric_limits<int>::max();
		for(j=1;j<i;++j)
		{
			for(k=0;k<3;++k)
			{
				int temp=a[j]*b[k];
				if(temp>a[i-1] && temp<min)
					min=temp;
			}
		}
		a[i]=min;
	}
	
	cout<<a[1500]<<endl;
	cout<<boolalpha;
	cout<<isUgly(a[1500])<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	print(1500);

	system("pause");
	return 0;
}

