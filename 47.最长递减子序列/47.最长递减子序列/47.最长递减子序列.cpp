// 47.最长递减子序列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
/*
对a[0...n-1]，我们以count[0...n-1]来记录以a[i]结尾的最长递减子序列的长度，对i来说，j=0..i-1，如果有a[j]>a[i]，那么count[i]=count[j]+1
取count[i]=MAX(count[j]+1，其中有a[j]>a[i] && j=0....i-1)

如果要展示着个序列的话，我们从最后1个元素开始往前遍历，若count[i]=max,那么这个元素就是最长递减子序列的最后一个元素，它的前一个元素应该满足a[j]>a[i] && count[j]==count[i]-1,一直往前，知道j<0为止
*/

//打印最长递减子序列 
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
	//首先a[0]对应的count[0]是1
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

