// 73.对称字符串的最大长度.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
首先给出判断字符串是不是对称的函数 bool isduicheng(char* a,int p,int r) O(n)的时间，
那么对给定的a[p->r],首先如果a[p->r]对称的话，那么就是最大的，如果不对称的话，就要考虑a[p->r-1]和a[p+1->r]了，返回两者最大值
*/
#include<iostream>
using namespace std;
bool isduicheng(char* a,int p,int r)
{
	if(p>r)
		return false;

	while(p<=r)
		if(a[p]!=a[r])
			return false;
		else
		{
			++p;
			--r;
		}
	return true;
}


int getmax(char* a,int p,int r,int& max,int& begin,int& end)
{
	if(p<r)
	{
		if(isduicheng(a,p,r))
		{
			if(r-p+1>max)
			{
				max=r-p+1;
				begin=p;
				end=r;
			}
			return r-p+1;
		}
		else
		{
			int left=getmax(a,p+1,r,max,begin,end);
			int right=getmax(a,p,r-1,max,begin,end);
			return (left>=right)?left:right;
		}
	}else
		return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[]="abcgoogleedaba";
	int max=-1;
	int begin=-1;
	int end=-1;

	cout<<getmax(a,0,13,max,begin,end)<<endl;
	for(int i=begin;i<=end;++i)
		cout<<a[i];
	cout<<endl;

	system("pause");
	return 0;
}

