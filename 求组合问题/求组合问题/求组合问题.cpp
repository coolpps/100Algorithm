// ���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
������n���ַ�����ô��Ϲ���=����Ϊ1������Ϊ2.����������Ϊn����ϣ��������ɸ�ӺͲ�࣬
*/

#include<iostream>
#include<list>
using namespace std;

void zuhe(char* a,int n,int begin,int end,int length,std::list<char> &path) //��end-begin+1==n������n���ַ�����length���ַ�
{
	//������ļ��֣�end-begin+1<n����û����ô����ַ��϶�������
	if(n<length)
		return ;

	//������������ 1.length=0û�м���Ѱ��ʱ��2. length=n������ʱ
	if(length==0 || length==n)//�պ���������������ʣ��5���ַ�����5���ַ�...
	{
		//��ӡpath��������a[begin]->a[end]
		for(std::list<char>::const_iterator iv=path.begin();iv!=path.end();++iv)
			cout<<*iv<<" ";
		if(length==n)
		{
			for(int i=begin;i<=end;++i)
				cout<<a[i]<<" ";
		}
		cout<<endl;
		return ;
	}

	
	//����a[begin],��ô������a[begin+1]->a[end]����i-1����
	path.push_back(a[begin]);
	zuhe(a,n-1,begin+1,end,length-1,path);
	path.pop_back();

	//������a[begin],��ô������a[begin+1]->a[end]����i���ˣ����������end-(begin+1)+1=end-begin>=i�������£����򷵻�
	zuhe(a,n-1,begin+1,end,length,path);

}
int _tmain(int argc, _TCHAR* argv[])
{
	char a[]="abc";

	std::list<char> path;

	for(int i=1;i<=strlen(a);++i)
		zuhe(a,3,0,2,i,path);
	system("pause");
	return 0;
}

