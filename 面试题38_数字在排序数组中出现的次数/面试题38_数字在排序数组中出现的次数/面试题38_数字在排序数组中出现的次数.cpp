// ������38_���������������г��ֵĴ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
������1,2,3,3,3,3,4,5�в��� ����3�ĳ��ִ���������O(n)ʱ��Ĳ���,����˼·�ǲ���<3����������λ�ú�>3����С��λ�ã����Ƕ���1����ͬ�ص�
<3�����Ҳ���3,����3���������3,�������ܶ϶��ˣ�2��O(lgn)ʱ�䣬��λ�������
*/

#include<iostream>
using namespace std;
int getnums(int* a,int n,int key)
{
	if(a==NULL || n<=0)
		return -1;
	//������2�ַ��������λ��
	int low;
	int high;
	int mid;

	low=0;
	high=n-1;
	int left=-2;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]<key && a[mid+1]==key)//�������
		{
			left=mid;break;
		}
		else if(a[mid]>=key)//�������ұߣ�����ȥ
			high=mid-1;
		else if(a[mid]<key)
			low=mid+1;
	}
	//left==-2��2�������1����û�����Ԫ�أ�2�����Ԫ����a[0]��û�б���С��Ԫ����
	//---->left=-2��ʾû�����Ԫ��key<a[0],left=-1��ʾ���Ԫ����a[0]
	if(left==-2 && key==a[0])
		left=-1;
	if(left!=-2 && left!=-1)
		cout<<"left="<<a[left]<<endl;

	//Ѱ���Ҳ��λ�ã��Ҳ������С��>key
	low=left+1;
	high=n-1;
	int right=n+1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]>key && a[mid-1]==key)
		{
			right=mid;break;
		}
		else if(a[mid]<=key)//����
			low=mid+1;
		else if(a[mid]>key)
			high=mid-1;
	}
	//right==n+1��2�������1����û�����Ԫ�أ�2�����Ԫ�������ұߣ�û�б�������� 
	if(right==n+1 && key==a[n-1])
		right=n;
		

	if(right!=n+1 && right!=n)
		cout<<"right="<<a[right]<<endl;
	//����������Ԫ�صĻ�����������1��,left��right�϶�֮���о��룬��right>=left+2
	if(left==-2 || right==n+1)//û�����Ԫ��
	{
		cout<<"û�����Ԫ��"<<endl;
		return -1;
	}
	 //�������
	else	if(left==-1)
		return right;
	else    if(right==n)
		return (n-1-left);
	else    
		return (right-left-1);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,2,3,3,3,3,4,5};

	cout<<getnums(a,8,0)<<endl;

	system("pause");

	return 0;
}

