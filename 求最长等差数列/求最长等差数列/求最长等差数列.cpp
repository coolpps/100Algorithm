// ����Ȳ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<set>
using namespace std;

/*
���ȶ��ö����н�������
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


/*����Ԫ�ض���һ��
��һ��ö�ٷ�����a[i]��a[j],ʹ�������ڣ�Ȼ������Ȳ�d=a[j]-a[i]���ݹ��������a[i]-d����ģ����Ҳ���a[j]+d�����
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

	//����������O(n*n*n*lgn),ʱ�临�Ӷ�̫�� 
	for(i=p;i<=r;++i)
	{
		for(j=i+1;j<=r;++j)
		{
			int length=2;
			int d=a[j]-a[i];
			//���ݹ����
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
��̬�滮
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
	
	//O(n*n*n)��ʱ��
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
ö�ٵȲ�����в���ͬ�����ԣ�a,b)���ֱ���a,��b��Ϊkey����һ����Ϊֵ��
���뵽����map֮�У�Ȼ����Ȼ��ĳһ��map֮�ڡ�
���ǣ�ö��ÿһ��map������ɾ��������
����(a,b)��ô��һ��ֵΪb+(b-a)��ǰһ��ֵΪa-(b-a)��
�ֱ�����map��ȥ���ң�����֮�����Ӷ�O(n^2logn)
*/

/*
����һ��O(n*n)ʱ�䣬O(n*n)�ռ���㷨,
����f[i,j]Ϊ��a[i]������2��a[j]������1����ݼ������г���

����DP�Լ�˫ָ�룬DP[i,j]��ʾ�Ե�i����Ϊ������2���j����Ϊ���1�������ɵĵȲ����еĳ��ȣ�
Ϊ�˱�����⣬�Ȼ�Ϊ��ֵ���⣬����DP[4, 6] = 4��Ҳ����˵ǰ�滹��0��2����DP[6,8] = 5��
�����ﲻ�ö������ң�������2��ָ��ֱ��������ƶ����������a[j] + a[k] = 2 * a[i]��
��f(i,k) = f(j,i) + 1��f(i , j)��ʾ��a[j],a[i]Ϊ�������ĵȲ����еĳ��ȡ�
ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n^2)���Ƿ����ù��������Ż��ռ临�ӶȻ�û��ϸ�����
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

