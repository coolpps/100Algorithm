// 14.在一个排好序的数组中查找2个数使和等于给定的数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//因为已经是排好序的了，定义两个指针，p和q,p=0,q=n-1,若a[p]+a[q]>key,则q--,若a[p]+a[q]<key ,p++,若a[p]+a[q]==key,break,若有p>=q，那么不存在
void print(int* a,int n,int key)
{
	int low=0;
	int high=n-1;

	while(low<high)
	{
		if(a[low]+a[high]==key)
		{
			cout<<a[low]<<"+"<<a[high]<<"="<<key<<endl;
			break;
		}
		else if(a[low]+a[high]>key)
			--high;
		else
			++low;
	}
	if(low>=high)
		cout<<"无"<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,2,4,7,11,15};
	int key;

	cin>>key;
	print(a,6,key);

	system("pause");
	return 0;
}

