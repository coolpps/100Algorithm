// 71.数值的整数次方.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
using namespace std;

double PowerWithAbsexp(double base,int exponent)
{
	//有exponent>0的
	double result=1.0;
	for(int i=1;i<=exponent;++i)
		result*=base;
	return result;
}

bool equalto0(double d)
{
	if(d>=-1E-6 && d<=1E-6)
		return true;
	else
		return false;
}
/*
判断double=0的问题

首先考虑exp<0的问题
当base=0 && exp>0时返回0
当base=0 && exp<=0时无意义
当base!=0 && exp=0时返回1
当base!=0 && exp!=0时返回...pow(base,|exp|)
*/

double Power(double base,int exponent)
{
	if(equalto0(base))
	{
		if(exponent>0)
			return 0.0;
		else
		{
			cout<<"Error"<<endl;
			return 0;
		}
	}
	else
	{
		if(exponent==0)
			return 1;
		else
		{
			int absexp=abs(exponent);

			return PowerWithAbsexp(base,absexp);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	double b;
	int exp;

	cin>>b>>exp;

	cout<<Power(b,exp)<<endl;

	system("pause");

	return 0;
}

