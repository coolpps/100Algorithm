// 58. ��β��ͷ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
ֵ����ͷ��㣬��β��ͷ������������Եݹ�
��p��p->next�����ȵݹ����p->next,Ȼ�����p��֪��p=NULL����ֹ
*/
#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}ListNode;

ListNode* head=NULL;

void init(int n)
{
	int i;
	ListNode* temp;
	ListNode* p=head;
	for(i=1;i<=n;++i)
	{
		temp=new ListNode;
		temp->data=i;
		temp->next=NULL;
		if(head==NULL)
			head=p=temp;
		else
		{
			p->next=temp;
			p=temp;
		}
	}
}

void reverse_print(ListNode* p)
{
	if(p==NULL)
		return ;
	reverse_print(p->next);
	cout<<p->data<<" ";
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;

	cin>>n;
	init(n);

	reverse_print(head);
	cout<<endl;

	system("pause");

	return 0;
}

