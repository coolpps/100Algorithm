// ��C++дһ����������ӡ�����ļ������k��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
���⣬��������ͳ���ļ�һ�������У�Ȼ���Թ�ǰ��n-k�У�
����ϣ������ֻ���ļ�һ�Σ��Ϳ�������ļ��е����k�С� ���ǿ��Կ�һ����СΪk���ַ������飬Ȼ���ļ��е�ÿһ��ѭ�����롣
��ô��ѭ�������أ����ǽ�k���ַ������浽�ַ�������� �ڶ���k+1ʱ���������浽����ĵ�1��Ԫ�أ��������ơ�����һ���� ʵ�����ļ��е�i�е��ַ����ᱻ���浽����ĵ�i%k��λ�á�
����ļ�����ʱ�� ���鱣��ľ������k�е��ַ�������Ȼ�ˣ����Ŀ�ʼλ�ò���0������i%k��
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void printlastlines(ifstream &fin,int k)
{
	string *line=new string[k];

	int lines=0;
	string tmp;
	while(getline(fin,tmp))
	{
		line[lines%k]=tmp;
		++lines;
	}

	int start,cnt;
	if(lines<k)
	{
		start=0;
		cnt=lines;
	}
	else
	{
		start=lines%k;
		cnt=k;
	}

	for(int i=0;i<cnt;i++)
		cout<<line[(i+start)%k]<<endl;

	delete []line;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("13.1.in");

	int k=4;
	printlastlines(fin,k);
	fin.close();

	system("pause");
	return 0;
}

