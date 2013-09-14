// 58. 从尾到头输出链表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
值给定头结点，从尾到头输出，这题明显递归
对p和p->next，首先递归输出p->next,然后输出p，知道p=NULL是终止
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

