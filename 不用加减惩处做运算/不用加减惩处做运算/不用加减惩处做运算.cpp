// 不用加减惩处做运算.cpp : 定义控制台应用程序的入口点。
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
	}while(num2!=0);//其实就是carry有进位

	return num1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<Add(7,15)<<endl;

	system("pause");
	return 0;
}

