// Young氏矩阵的题目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
在Young氏矩阵中查找某1元素，或者找某元素合适的插入位置
a[m][n]
*/
#include<iostream>
using namespace std;
bool found(int a[],int m,int n,int x)
{
	// 最左下角是a[m-1][0],从它开始，因为向上是减小的，向右是增大的，向上的话是a[m-2][0],向右的话是a[m-1][[1]
	//用一维数组时 ，刚开始是a[m-1][0]=第a[n*(m-1)+0],当向右的时候,a[n*(m-1)+1],当向上的时候是,a[n*(m-1-1)+1],
	//当向右的时候，
	int row=m-1;
	int col=0;
	
	bool flag=false;

	while(row>=0 && col<n && flag==false)
	{
		if(x==a[row*n+col])
			flag=true;
		else if(x>a[row*n+col])//要向右
			col++;
		else
			row--;
	}

	return flag;
}

int _tmain(int argc, _TCHAR* argv[])
{

	/*
	从a[m][n]到int**的转换是错误的，怎么g++没提示??
	*/
	int a[]={1,2,8,9,
			  2,4,9,12,
				 4,7,10,13,
				 6,8,11,15
				};

	int x;
	cin>>x;

	cout<<boolalpha<<found(a,4,4,x)<<endl;

	system("pause");
	return 0;
}

