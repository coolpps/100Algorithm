// 约瑟夫链表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;


//对n个人，从第m个开始,第s个人出列
void hebing(int* a,int i,int n)
{
	for(int j=i+1;j<n;++j)
		a[j-1]=a[j];
}
void josephus(int n,int m,int s)
{
	int *a=new int[n];
	for(int i=0;i<n;++i)
		a[i]=i+1;

	//开始,第m个编号是m-1
	int begin=(m-1)%n;
	for(int i=n;i>0;--i)
	{
		begin=(begin+s-1)%i;

		cout<<a[begin]<<endl;
		//合并数组a[begin]之后的覆盖
		hebing(a,begin,i);
	}

	delete [] a;
}

//得到最后1个数
int LastRemainnong(unsigned int n,unsigned int m)
{
	if(n<1 || m<1)
		return -1;

	int last=0;
	for(int i=2;i<=n;++i)
		last=(last+m)%i;

	return last;
}
int _tmain(int argc, _TCHAR* argv[])
{
	josephus(10,1,3);

	cout<<endl<<LastRemainnong(10,4)<<endl;
	system("pause");
	return 0;
}

