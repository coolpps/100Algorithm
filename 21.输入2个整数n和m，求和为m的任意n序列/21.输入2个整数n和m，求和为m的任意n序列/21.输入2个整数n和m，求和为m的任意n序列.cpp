// 21.输入2个整数n和m，求和为m的任意n序列.cpp : 定义控制台应用程序的入口点。
//输入n和m，从数列1,2,...n中随意取几个数，使其和等于m，要求将其中所有的可能组合列出来

#include "stdafx.h"
#include<iostream>
#include<list>
using namespace std;

//方法是可行的
void print(int n,int m,list<int>& path)
{
	if(n<1)
		return ;
	if(m<0)
		return  ;
	if(m==0)
	{
		for(list<int>::iterator iv=path.begin();iv!=path.end();++iv)
			cout<<*iv<<" ";
		cout<<endl;
		return ;
	}
	else //m>0
	{
		//n算和n不算都是
		//1.n算
		bool flag=false;
		path.push_back(n);
		print(n-1,m-n,path);
		path.pop_back();

		print(n-1,m,path);//n不算
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,m;
	list<int> path;
	cin>>n>>m;


	print(n,m,path);

	system("pause");
	return 0;
}

