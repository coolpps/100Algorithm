// 71.��ֵ�������η�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
using namespace std;

double PowerWithAbsexp(double base,int exponent)
{
	//��exponent>0��
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
�ж�double=0������

���ȿ���exp<0������
��base=0 && exp>0ʱ����0
��base=0 && exp<=0ʱ������
��base!=0 && exp=0ʱ����1
��base!=0 && exp!=0ʱ����...pow(base,|exp|)
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

