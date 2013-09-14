// 19.쳲���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

/*
�ó˷�������쳲���������
����1��2*2�ľ���
*/

class ttmatrix
{
public:
	ttmatrix(int lefttop=1,int righttop=1,int leftbottom=1,int rightbottom=0):
	  m_00(lefttop),m_01(righttop),m_10(leftbottom),m_11(rightbottom)
	  {

	  }

	int m_00;
	int m_01;
	int m_10;
	int m_11;
};

//�������ĳ˷�
ttmatrix matrixmultiply(ttmatrix& t1,ttmatrix& t2)
{
	return ttmatrix(t1.m_00*t2.m_00+t1.m_01*t2.m_10,
					t1.m_00*t2.m_01+t1.m_01*t2.m_11,
					t1.m_10*t2.m_00+t1.m_11*t2.m_10,
					t1.m_10*t2.m_01+t1.m_11*t2.m_11);
}

ttmatrix fib(int n)
{
	if(n<=1)
		return ttmatrix(1,1,1,0);
	if(n%2==0)
		return matrixmultiply(fib(n/2),fib(n/2));
	else
		return matrixmultiply(ttmatrix(1,1,1,0),matrixmultiply(fib((n-1)/2),fib((n-1)/2)));
}


int _tmain(int argc, _TCHAR* argv[])
{
	ttmatrix t;
	int n;

	cin>>n;

	t=fib(n-1);
	cout<<t.m_00<<endl;

	system("pause");
	return 0;
}

