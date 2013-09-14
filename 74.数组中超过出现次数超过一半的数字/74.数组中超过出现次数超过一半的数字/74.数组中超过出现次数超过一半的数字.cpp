// 74.数组中超过出现次数超过一半的数字.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
O(n*n)的时间，统计每个数字出现的次数，如果有1个出现次数>n/2，那么就可以停止了

可以每次从数组中删除2个不同的数字，如果数字相同，就接着统计。如果统计值=0的话，就意味着前面的偶数个字符都抵消掉了，即可以组成两两不同序列
这样到最后，因为有1个出现次数是>n/2的，最后统计值肯定不为0，此时剩下的就是要求的数字

*/

#include<iostream>
using namespace std;

//1.O(n*n)
int getnum(int* a,int n)
{
	for(int i=0;i<n;++i)
	{
		int sum=0;
		for(int j=0;j<n;j++)
			if(a[j]==a[i])
				sum++;
		if(sum>n/2) //肯定有，
			return a[i];
	}
}

//2. O(n)时间的 
/*
用指针i来遍历，用j来指明要和a[i]比对的数
首先如果sum=0,就表明i前面的0->i-1的都两两凑对了，此时j=i开始
如果a[i]==a[j]，就表明此时相同的，那么就sum++
如果a[i]!=a[j]，那么a[i]和a[j]就可以抵消掉了，此时j后面的数还可以抵消呢--->
如果sum=1的话，则表明a[j]和a[i]是相邻的，，如果sum>1的话，就是这样的 a[j] a[j+1] ..a[i]
此时呢，在j->i之间有多个a[j]没有被消掉，那么a[j]和a[i]消掉以后就得j++了
*/
int getnum2(int *a ,int n)
{
	int sum=1;
	int i=0,j;
	//从1开始统计
	i=1;j=0;
	while(i<n)
	{
		if(sum==0)
		{
			sum=1;
			j=i;
		}
		else
		{
			if(a[i]==a[j])
			{sum++;}
			else
			{	sum--;++j;}
		}
		++i;
	}

	return a[j];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,1,1,1,1,2,5,4,3};
	int b[]={1,5,4,1,2,3,1,1,1};

	cout<<getnum(b,9)<<endl<<getnum2(b,9)<<endl;

	system("pause");
	return 0;
}

