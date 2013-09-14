// 24.单链表的逆置.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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
	ListNode* p=head;
	for(i=1;i<=n;i++)
	{
		ListNode* temp=new ListNode;
		temp->data=i;
		temp->next=NULL;
		if(p==NULL)
			p=head=temp;
		else
		{
			p->next=temp;
			p=temp;
		}
	}
}

void reverse()
{
	ListNode* p=head;
	ListNode* temp;

	head=NULL;
	while(p!=NULL)
	{
		temp=p;
		p=p->next;

		temp->next=NULL;
		temp->next=head;
		head=temp;
		
	}
}

void print()
{
	ListNode* p=head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin>>n;

	init(n);
	print();
	reverse();
	print();

	system("pause");
	return 0;
}

