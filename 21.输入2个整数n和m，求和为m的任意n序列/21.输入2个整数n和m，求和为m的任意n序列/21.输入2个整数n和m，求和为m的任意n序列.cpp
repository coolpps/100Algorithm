// 21.����2������n��m�����Ϊm������n����.cpp : �������̨Ӧ�ó������ڵ㡣
//����n��m��������1,2,...n������ȡ��������ʹ��͵���m��Ҫ���������еĿ�������г���

#include "stdafx.h"
#include<iostream>
#include<list>
using namespace std;

//�����ǿ��е�
void print(int n,int m,list<int>& path)
{
	if(n<1)
		return ;
	if(m<0)
		return  ;
	if(m==0)
	{
		for(list<int>::iterator iv=path.begin();iv!=path.end();++iv)
			cout<<*iv<<" ";
		cout<<endl;
		return ;
	}
	else //m>0
	{
		//n���n���㶼��
		//1.n��
		bool flag=false;
		path.push_back(n);
		print(n-1,m-n,path);
		path.pop_back();

		print(n-1,m,path);//n����
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,m;
	list<int> path;
	cin>>n>>m;


	print(n,m,path);

	system("pause");
	return 0;
}

