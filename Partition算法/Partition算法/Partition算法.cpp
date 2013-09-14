// Partition�㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/*
����С��k����
*/
#include<iostream>
#include<set>
using namespace std;
int partition(int* a,int begin,int end)
{
	if(a==NULL || begin>end)
		return 0;

	int x=a[end];

	int i,j;
	i=begin-1;
	for(j=begin;j<end;++j)
	{
		if(a[j]<x)
		{
			++i;
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	int temp=a[end];
	a[end]=a[i+1];
	a[i+1]=temp;

	return i+1; //i+1�Ƿֽ��
}

void getlastk(int* a,int begin,int end,int k)
{
	if(a==NULL || begin>end || k<=0)
		return ;

	int q=partition(a,begin,end);
	int pos=q-begin+1; //����a[begin,end]�е�pos��С��
	if(k==pos)//������������,��ʱa[begin]-a[end]��һ���ǿ�ʼ�����begin��end
	{
		cout<<a[q]<<endl;
		return ;
	}
	else if(pos<k)//�����ұ�
	{
		return getlastk(a,begin+1,end,k-pos);
	}else if(pos>k)//�������
	{
		return getlastk(a,begin,end-1,k);
	}
}

void getlastnumbers(int* input,int n,int* output,int k)
{
	if(input==NULL || output==NULL || k>n || k<=0 || n<=0)
		return ;

	int start=0;
	int end=n-1;

	int index=partition(input,start,end);
	while(index!=k-1)
	{
		if(index>k-1)//index���ң������ȥ
		{
			end=index-1;
			index=partition(input,start,end);
		}
		else
		{
			start=index+1;
			index=partition(input,start,end);
		}
	}

	for(int i=0;i<k;++i)
		output[i]=input[i];
}


//�����ú�k�����Ĵ��������
//������,��Ϊ�ѵĳ���ʼ����k
void heapify(int *a,int i,int length)
{
	int left=2*i+1;
	int right=2*i+2;

	int max=i;
	if(left<length && a[i]<a[left])
		max=left;

	if(right<length && a[max]<a[right])
		max=right;
	
	if(i!=max)
	{
		int temp=a[i];
		a[i]=a[max];
		a[max]=temp;

		 heapify(a,max,length);
	}
}

void heapgetlastk(int *a,int n,int k)
{
	//�жϷ�������
	if(a==NULL || n<=0 || k<=0)
		return ;

	//��������һ��������
	int *heap=new int[k];
	//�Ѵ�С 

	for(int i=0;i<k;++i)
		heap[i]=a[i];

	//������������
	for(int i=k/2;i>=0;--i)
		heapify(a,i,k);

	for(int i=k;i<n;i++)
	{
		//����heap����k��Ԫ���ˣ�Ҫ������		
		if(a[i]<heap[0])
		{
			heap[0]=a[i];
			heapify(heap,0,k);
		}	
	}

	//��������
	for(int i=0;i<k;++i)
		cout<<heap[i]<<" ";
	cout<<endl;

	delete [] heap;
}

/*setʹ�ú����ʵ�ֵ�,�п�������ȵ�Ԫ�أ�������multiset*/
void setgetlastk(int* a,int n,int k)
{
	multiset< int,greater<int> > lastnum;

	for(int i=0;i<k;++i)
		lastnum.insert(a[i]);

	for(int i=k;i<n;++i)
	{
		multiset< int,greater<int> >::iterator b=lastnum.begin();
		if(a[i]<*b)
		{
			lastnum.erase(b);
			lastnum.insert(a[i]);
		}
	}

	//������lastnum
	for(multiset<int,greater<int> >::iterator iv=lastnum.begin();iv!=lastnum.end();++iv)
		cout<<*iv<< " ";
	cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={8,7,6,5,4,3,2,1};
	int b[]={1,2,3,4,5,6,7,8};

	heapgetlastk(a,8,7);
	setgetlastk(a,8,7);
	//getlastk(b,0,7,4);
	system("pause");
	return 0;
}

