// 18. 约瑟夫链表问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//用数组做和用链表做

void del(int *a,int n,int w)
{
	int i;
	for(i=w+1;i<n;i++)
		a[i-1]=a[i];
}

void shuzu(int n,int m)
{
	int* an=new int[n];
	int i,j;
	for(i=0;i<n;i++)
		an[i]=i;

	//开始从0数
	int w=0;
	for(j=n;j>=1;--j)
	{
		w=(w+m-1)%j;
		cout<<an[w]<<endl;

		//把w位置删除
		del(an,j,w);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,m;

	cin>>n>>m;
	shuzu(n,m);
	system("pause");
	return 0;
}

