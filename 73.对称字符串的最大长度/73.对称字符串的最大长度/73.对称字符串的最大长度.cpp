// 73.�Գ��ַ�������󳤶�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
���ȸ����ж��ַ����ǲ��ǶԳƵĺ��� bool isduicheng(char* a,int p,int r) O(n)��ʱ�䣬
��ô�Ը�����a[p->r],�������a[p->r]�ԳƵĻ�����ô�������ģ�������ԳƵĻ�����Ҫ����a[p->r-1]��a[p+1->r]�ˣ������������ֵ
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

