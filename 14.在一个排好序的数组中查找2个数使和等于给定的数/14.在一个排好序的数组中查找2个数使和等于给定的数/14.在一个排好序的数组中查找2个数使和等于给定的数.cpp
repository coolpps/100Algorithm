// 14.��һ���ź���������в���2����ʹ�͵��ڸ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//��Ϊ�Ѿ����ź�����ˣ���������ָ�룬p��q,p=0,q=n-1,��a[p]+a[q]>key,��q--,��a[p]+a[q]<key ,p++,��a[p]+a[q]==key,break,����p>=q����ô������
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
		cout<<"��"<<endl;
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

