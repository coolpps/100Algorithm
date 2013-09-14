// 28.整数的二进制表示中1的个数.cpp : 定义控制台应用程序的入口点。
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

