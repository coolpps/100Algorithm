// 64.寻找丑数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<limits>
using namespace std;
/*
寻找丑数。丑数是只用2,3,5的成绩就可以得到的数，即n是丑数,n=2*2*2*....*3*3*....*5*5*5*....
不满足上述的就不是丑数
1,2,3,4,5都是丑数
令刚开始数组为1
 1*2,1*3,1*5得到3个丑数，现在想办法把这3个丑数增加到数组中,应该把2添加---1,2
 1,2-->生成的元素有，1,3,5,4,6,10,应该把>2的最小元素添加到，1,2,3
 1,2,3->生成的元素有1,3,5,4,6,10,6,9,15，应该把>3的最小数添加进去，是1,2,3,4,
 这样循环下去，就能得到第1500个元素了
*/

//判断1个数是不是丑数
bool isUgly(int n)
{
	if(n>0)
	{
		while(n%2==0)
			n=n/2;
		while(n%3==0)
			n=n/3;
		while(n%5==0)
			n=n/5;
		if(n==1)
			return true;
		return false;
	}
	else
		return false;

}

#define MAX 1600
void print(int n)
{
	int a[MAX];
	int i,min,k,j;

	a[1]=1;

	int b[]={2,3,5};
	for(i=2;i<=1500;++i)
	{
		min=numeric_limits<int>::max();
		for(j=1;j<i;++j)
		{
			for(k=0;k<3;++k)
			{
				int temp=a[j]*b[k];
				if(temp>a[i-1] && temp<min)
					min=temp;
			}
		}
		a[i]=min;
	}
	
	cout<<a[1500]<<endl;
	cout<<boolalpha;
	cout<<isUgly(a[1500])<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	print(1500);

	system("pause");
	return 0;
}

