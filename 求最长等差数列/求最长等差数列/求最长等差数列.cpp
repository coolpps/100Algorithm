// 求最长等差数列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<set>
using namespace std;

/*
首先都得对序列进行排序
*/

int partition(int* a,int p,int r)
{
	int x=a[r];

	int i,j;

	for(i=p-1,j=p;j<r;++j)
	{
		if(a[j]<x)
		{
			++i;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}

	int temp=a[r];
	a[r]=a[i+1];
	a[i+1]=temp;

	return i+1;
}
void quicksort(int* a,int p,int r)  //a[p]-a[r]
{
	if(p<r)
	{
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}


/*假设元素都不一样
第一种枚举法，对a[i]和a[j],使他们相邻，然后求出等差d=a[j]-a[i]，递归在左侧找a[i]-d满足的，在右侧找a[j]+d满足的
*/
void meiju(int* a,int p,int r)
{
	int i,j;
	int dengcha;
	int left,right;
	std::set<int> sett;
	int max=0;
	int begin=-1;

	for(i=p;i<=r;++i)
		sett.insert(a[i]);

	//这种做法是O(n*n*n*lgn),时间复杂度太高 
	for(i=p;i<=r;++i)
	{
		for(j=i+1;j<=r;++j)
		{
			int length=2;
			int d=a[j]-a[i];
			//左侧递归查找
			left=a[i];
			while(sett.find(left-d)!=sett.end())
			{
				++length;
				left=left-d;
			}

			right=a[j];
			while(sett.find(right+d)!=sett.end())
			{
				++length;
				right=right+d;
			}

			if(length>max)
			{
				max=length;
				begin=left;
				dengcha=d;
			}
		}
	}

	cout<<"max="<<max<<endl;
	while(sett.find(begin)!=sett.end())
	{
		cout<<begin<<" ";
		begin+=dengcha;
	}
	cout<<endl;
}

/*
动态规划
*/
void dp(int* a,int p,int r)
{
	int f[6][6]={2};
	int max=0;

	int i,j;
	for(i=0;i<6;++i)
		for(j=0;j<6;j++)
			f[i][j]=2;
	for(i=0;i<6;++i)
		f[i][i]=1;
	
	//O(n*n*n)的时间
	for(int k=p;k<=r;++k)
		for(int i=k+1;i<=r;++i)
			for(int j=i+1;j<=r;++j)
				{
					if((a[k]+a[j]==2*a[i]) && (f[k][i]+1>f[i][j]))
						f[i][j]=f[k][i]+1;

					if(f[i][j]>max)
						max=f[i][j];
				}

	cout<<"max="<<max<<endl;
}


/*
枚举等差，将所有差相同的数对（a,b)，分别以a,以b作为key，另一个作为值，
插入到两个map之中，然后解必然在某一个map之内。
于是，枚举每一个map，进行删除操作，
比如(a,b)那么下一个值为b+(b-a)，前一个值为a-(b-a)，
分别到两个map中去查找，迭代之。复杂度O(n^2logn)
*/

/*
另外一种O(n*n)时间，O(n*n)空间的算法,
定义f[i,j]为以a[i]倒数第2，a[j]倒数第1的最长递减子序列长度

利用DP以及双指针，DP[i,j]表示以第i个数为倒数第2项，第j个数为最后1项，可以组成的等差数列的长度，
为了便于理解，先换为数值讲解，假设DP[4, 6] = 4，也就是说前面还有0，2。则DP[6,8] = 5。
在这里不用二分来找，而是用2个指针分别向左右移动，如果出现a[j] + a[k] = 2 * a[i]，
则f(i,k) = f(j,i) + 1，f(i , j)表示以a[j],a[i]为最后两项的等差数列的长度。
时间复杂度O(n^2)，空间复杂度O(n^2)，是否能用滚动数组优化空间复杂度还没仔细想过。
*/
void solve4(int* a,int n)
{
	int f[6][6];
	int i,j,k;
	int max=0;

	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			f[i][j]=0;
	//for(i=0;i<6;i++)
		//f[i][i]=1;

	for(i=1;i<n-1;i++)
	{
		j=i-1;
		k=i+1;
		while(j>=0 && k<n)
		{
			if(a[j]+a[k]>2*a[i])
				--j;
			else if(a[j]+a[k]<2*a[i])
				++k;
			else
			{
				f[i][k]=(f[j][i]==0)?3:(f[j][i]+1);
				if(f[i][k]>max)
				{
					max=f[i][k]; //

				}
				--j;
				++k;
			}
		}
	}

	cout<<max<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,3,0,5,-1,6};

	quicksort(a,0,5);
	meiju(a,0,5);

	dp(a,0,5);
	solve4(a,6);
	system("pause");
	return 0;
}

