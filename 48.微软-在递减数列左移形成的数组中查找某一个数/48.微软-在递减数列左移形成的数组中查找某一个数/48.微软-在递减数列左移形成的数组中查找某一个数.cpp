// 48.微软-在递减数列左移形成的数组中查找某一个数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

/*
对a[0....n-1],有a[0]>a[1]>a[2]>.....>a[n-1]，左移m位，则变为a[m],a[m+1],..a[n-1],a[0],...a[m-1],有a[m]>a[m+1]>...>a[n-1],a[0]>a[1]>a[2]>....>a[m-1]
另a[m] a[m+1] a[m+2] ....a[n-1] a[0] a[1]....a[m-1] 
-->
   0      1      2        n-m-1  n-m  n-m+1     n-1
   那么有  a[0]>a[2]>....>a[n-m-1],a[n-m]>a[n-m+2]>...>a[n-1]同时  a[n-m]是最大的数,a[n-m]>a[n-m-1] && a[n-m]>a[n-m+1],如果符合这个条件，那么a[n-m]就是分界点


   首先查找分界点，分界点就是上述a[n-m-1]和a[n-m],我么统一规定a[n-m]是分界点
   采用二分的方式查找,假设元素一定存在，元素是key
   low=0,high=n-1
   mid=(low+high);

   现在有以下几种可能
   1. min落在左边 ,有a[mid]<=a[0]
      如果key=a[mid]返回
	  如果key>a[mid] && key<=a[0]，那么继续在左边查找，这就是1个递减有序中查找数，明显二分
	  如果key>a[mid] && key>a[0]的话，我们要到分界点右面查找  low=分界点  high=n-2
	  如果key<a[mid],那么要在[mid,分界点]查找  low=mid+1,high=分界点
   2.min落在右边,有a[mid]>a[0]的话，
	  如果key=a[mid]
	  如果k<a[mid] && key>a[0],那么继续在[mid+1,high]查找
	  如果k<a[mid] && key<a[0]的话，在[0,分界点查找]
	  如果k>a[mid],在[分界点,mid-1]查找
*/

 void chazhao(int* a,int p,int r,int key)
{
	//1.首先查找分界点，两个分界点有如下特征，左边分界点a[i]<a[i-1] && a[i]<a[i+1],右边分界点  a[i]>a[i-1] && a[i]>a[i+1]
	//首先这是个左移的，肯定分界点不是在开始，有可能在结束 5 4 3 2 1 6,对1 6 5 4 3 2,若查找到1的话
	int pos=-1;
	int low=p;
	int high=r;

	while(low<=high)
	{
		int mid=(low+high)/2;
		if(mid==p && a[mid]<a[mid+1]) //那么1位置就是分界点
		{
			pos=p+1;
			break;
		}else if(mid==r && a[mid]>a[mid-1])//r处就是分界点
		{
			pos=r;break;
		}
		else//mid不在首尾 
		{
			if(a[mid]<a[mid-1] && a[mid]<a[mid+1])
			{
				pos=mid+1;break;
			}
			if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
			{
				pos=mid;break;
			}

			if(a[mid]>a[p])//现在是在右半部分，应该向左
				high=mid-1;
			else
				low=mid+1;
		}
	}

	//pos查找正确证明
	//cout<<a[pos]<<endl;

	//下面就该查找key了
	low=p;
	high=r;

	while(low<=high)
	{
		int mid=(low+high)/2;

		if(a[mid]==key)
		{
			cout<<"找到"<<key<<endl;
			break;
		}
		else if(a[mid]<key)
		{
			//>key有2种情况，因为key一定存在，现在看mid是落在左边还是右边了 
			if(a[mid]<=a[p])//落在左边 ,因为key>a[mid],所以key有可能在左边或者右边，比较key和a[0]
			{
				if(key<=a[p])//继续在左边
					high=high-1;
				else//在右边了 
				{
					low=pos;
					high=r;
				}
			}
			else //mid在右边的情况下
			{
				low=pos;
				high=mid-1;
			}
		}else //key<a[mid]
		{
			if(a[mid]<=a[p])//mid在左边,key<a[mid]
			{
				low=mid+1;
			}
			else//key<a[mid]并且mid在右边
			{
				if(key>a[p])//key>a[p]的话，还在右边
					low=mid+1;
				else
				{
					low=p;
					high=pos-1;
				}
			}
		}
	}

	
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={4,3,2,1,6,5};

	int b[]={1,6,5,4,3,2};

	int c[]={5,4,3,2,1,6};


	int i;

	cout<<boolalpha;
	for(i=0;i<6;i++)
		chazhao(c,0,5,c[i]);

	system("pause");
	return 0;
}

