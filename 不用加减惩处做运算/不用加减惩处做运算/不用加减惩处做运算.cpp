// ���üӼ��ʹ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
using namespace std;
int Add(int num1,int num2)
{
	int sum,carry;
	do
	{
		sum=num1 ^ num2;
		carry=(num1 & num2)<<1;

		num1=sum;
		num2=carry;
	}while(num2!=0);//��ʵ����carry�н�λ

	return num1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<Add(7,15)<<endl;

	system("pause");
	return 0;
}

