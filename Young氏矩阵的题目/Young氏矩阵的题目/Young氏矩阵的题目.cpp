// Young�Ͼ������Ŀ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
��Young�Ͼ����в���ĳ1Ԫ�أ�������ĳԪ�غ��ʵĲ���λ��
a[m][n]
*/
#include<iostream>
using namespace std;
bool found(int a[],int m,int n,int x)
{
	// �����½���a[m-1][0],������ʼ����Ϊ�����Ǽ�С�ģ�����������ģ����ϵĻ���a[m-2][0],���ҵĻ���a[m-1][[1]
	//��һά����ʱ ���տ�ʼ��a[m-1][0]=��a[n*(m-1)+0],�����ҵ�ʱ��,a[n*(m-1)+1],�����ϵ�ʱ����,a[n*(m-1-1)+1],
	//�����ҵ�ʱ��
	int row=m-1;
	int col=0;
	
	bool flag=false;

	while(row>=0 && col<n && flag==false)
	{
		if(x==a[row*n+col])
			flag=true;
		else if(x>a[row*n+col])//Ҫ����
			col++;
		else
			row--;
	}

	return flag;
}

int _tmain(int argc, _TCHAR* argv[])
{

	/*
	��a[m][n]��int**��ת���Ǵ���ģ���ôg++û��ʾ??
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

