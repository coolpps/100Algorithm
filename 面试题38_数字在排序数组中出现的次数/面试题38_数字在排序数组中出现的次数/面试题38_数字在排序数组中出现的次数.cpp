// 面试题38_数字在排序数组中出现的次数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
在数组1,2,3,3,3,3,4,5中查找 数字3的出现次数，现在O(n)时间的不行,现在思路是查找<3的最大的数的位置和>3的最小的位置，它们都有1个共同特点
<3的它右侧是3,大于3的它左侧是3,这样就能断定了，2个O(lgn)时间，把位置想相减
*/

#include<iostream>
using namespace std;
int getnums(int* a,int n,int key)
{
	if(a==NULL || n<=0)
		return -1;
	//首先用2分发查找左侧位置
	int low;
	int high;
	int mid;

	low=0;
	high=n-1;
	int left=-2;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]<key && a[mid+1]==key)//就是这个
		{
			left=mid;break;
		}
		else if(a[mid]>=key)//现在在右边，朝左去
			high=mid-1;
		else if(a[mid]<key)
			low=mid+1;
	}
	//left==-2有2种情况，1是真没有这个元素，2是这个元素是a[0]，没有比这小的元素了
	//---->left=-2表示没有这个元素key<a[0],left=-1表示这个元素是a[0]
	if(left==-2 && key==a[0])
		left=-1;
	if(left!=-2 && left!=-1)
		cout<<"left="<<a[left]<<endl;

	//寻找右侧的位置，右侧这个最小的>key
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
		else if(a[mid]<=key)//朝右
			low=mid+1;
		else if(a[mid]>key)
			high=mid-1;
	}
	//right==n+1有2种情况，1是真没有这个元素，2是这个元素在最右边，没有比它大的了 
	if(right==n+1 && key==a[n-1])
		right=n;
		

	if(right!=n+1 && right!=n)
		cout<<"right="<<a[right]<<endl;
	//如果存在这个元素的话，则至少有1个,left和right肯定之间有距离，即right>=left+2
	if(left==-2 || right==n+1)//没有这个元素
	{
		cout<<"没有这个元素"<<endl;
		return -1;
	}
	 //特殊情况
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

