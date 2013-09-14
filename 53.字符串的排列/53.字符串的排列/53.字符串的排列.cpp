// 53.字符串的排列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void pailie(char* a,int p,int r)
{
	
	if(p<r)
	{
		char temp;
		for(int i=p;i<=r;++i)
		{
			temp=a[p];
			a[p]=a[i];
			a[i]=temp;

			pailie(a,p+1,r);

			temp=a[p];
			a[p]=a[i];
			a[i]=temp;
		}
	}
	else if(p==r)//说明已经排序到最后1个元素了，那么这是1种新的排序
	{
		for(int i=0;i<=3;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		return ;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[]="abcd";

	pailie(a,0,3);

	system("pause");
	return 0;
}

