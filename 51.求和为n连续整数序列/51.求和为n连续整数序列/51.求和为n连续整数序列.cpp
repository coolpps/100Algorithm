// 51.求和为n连续整数序列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
这题对于n,和最大的因子是n/2,因为n/2+(n/2+1)就大于n了，所以如果采用遍历的话，那么就从1-n/2，以每个元素开始
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

		if(sum==n)//得到1个序列了[i,j]
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

