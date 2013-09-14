// 81.求这样1个数组，左边的数都小于等于它，右边的数都大于等于它.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<limits>
using namespace std;

void print(int *a,int n)
{
	int* b=new int[n+2];
	//b[1,n]对应于a[0,n-1]

	b[0]=numeric_limits<int>::min();
	b[1]=numeric_limits<int>::min();

	

	//下面求最大值，a[i]对应的是b[i+1],即a[0,i-1]的最大值
	for(int i=1;i<n;i++)
		if(a[i-1]>=b[i])
			b[i+1]=a[i-1];
		else
			b[i+1]=b[i];

	//现在求最小值
	b[n+1]=numeric_limits<int>::max();


	for(int i=n-1;i>=0;i--)
	{
		if(a[i]>=b[i+1] && a[i]<=b[i+2])
			cout<<a[i]<<endl;
		//更新b[i+1]
		if(a[i]<=b[i+2])
			b[i+1]=a[i];
		else
			b[i+1]=b[i+2];
	}

	delete [] b;
			
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,2,3,5,9,7,6,4,10,12,15,14};

	print(a,12);

	system("pause");
	return 0;
}

