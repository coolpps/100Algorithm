// Լɪ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;


//��n���ˣ��ӵ�m����ʼ,��s���˳���
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

	//��ʼ,��m�������m-1
	int begin=(m-1)%n;
	for(int i=n;i>0;--i)
	{
		begin=(begin+s-1)%i;

		cout<<a[begin]<<endl;
		//�ϲ�����a[begin]֮��ĸ���
		hebing(a,begin,i);
	}

	delete [] a;
}

//�õ����1����
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

