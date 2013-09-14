// 16.树的层次遍历.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//树
typedef struct node
{
	int value;
	struct node* left;
	struct node* right;
}Tree;

//建树
Tree* create(void)
{
	Tree* t=NULL;
	int data;

	cin>>data;
	if(0==data)
		return NULL;
	else
	{
		t=new Tree;
		t->value=data;
		t->left=create();
		t->right=create();
	}
	return t;
}

//定义队列 
#define MAX 100
typedef struct
{
	Tree* data[MAX];
	int front;
	int tail;
}Queue;

Queue* init_queue(void)
{
	Queue* q=new Queue;
	if(q)
		q->front=q->tail=-1;
	return q;
}

bool empty_queue(Queue* q)
{
	if(q->front==q->tail)
		return true;
	return false;
}

bool full_queue(Queue* q)
{
	if((q->tail+1)%MAX==q->front)
		return true;
	return false;
}

void push(Queue* q,Tree* t)
{
	if(full_queue(q))
		return ;
	q->tail=(q->tail+1)%MAX;
	q->data[q->tail]=t;
}

void pop(Queue* q,Tree** t)
{
	if(empty_queue(q))
		return ;
	q->front=(q->front+1)%MAX;
	*t=q->data[q->front];
}

void cengci(Tree* t)
{
	Queue* q=NULL;
	Tree* p=t;

	q=init_queue();
	push(q,p);
	while(!empty_queue(q))
	{
		pop(q,&p);
		if(p)
		{
			cout<<p->value<<" ";
			if(p->left!=NULL)
				push(q,p->left);
			if(p->right!=NULL)
				push(q,p->right);
		}
	}
	cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Tree* t=NULL;

	t=create();
	cengci(t);

	system("pause");
	return 0;
}

