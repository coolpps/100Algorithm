// 61.�ҳ�������ֻ����1�ε�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<list>
#include<iostream>
using namespace std;
/*
����������ֻ��1������1�ε�����ͨ������Ԫ�����^�����ܵõ�
��2������1�ε�Ԫ�أ���ô��������������2��������򣬸����������ʣ���ͬλΪ0������ͬλΪ1��
���ǽ�������Ϊ1��λ���ҵ�����ô���Կ϶�����2������1����0,1����1�������Ķ�����2�ε������϶�����0����1��
����������һλ���Ͱ�ԭ��n��Ԫ�طֳ�����n1��n2,���Ƕ�ֻ����1��ֻ����1�ε�����
*/

void erjinzhi(int n,list<int> &data)
{
	while(n!=0)
	{
		data.push_back(n%2);
		n=n/2;
	}
}

bool is(int n,int pos)//��posλ�ǲ���Ϊ1
{
	list<int> data;
	erjinzhi(n,data);

	int count=0;


	while(!data.empty() && count<pos)
	{
		data.pop_front();
		count++;
	}
	if(!data.empty() && data.front()==1)
		return true;
	else
		return false;
}
void print(int* a,int p,int r)
{
	int result=0;
	int i;
	
	for(i=p;i<=r;++i)
		result^=a[i];

	//��result��2���Ʊ�ʾ�����λΪ1��λ��
	int pos=0;
	while(is(result,pos)==false)
		pos++;
	//cout<<pos<<endl;

	int result_left=0;
	int result_right=0;;

	
	for(i=p;i<=r;i++)
	{
		if(is(a[i],pos)) //��1
			result_left^=a[i];
		else  //��0
			result_right^=a[i];
	}
	
	cout<<result_left<<endl;
	cout<<result_right<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,2,3,4,5,7,2,1,4,3};

	print(a,0,9);

	system("pause");
	return 0;
}

