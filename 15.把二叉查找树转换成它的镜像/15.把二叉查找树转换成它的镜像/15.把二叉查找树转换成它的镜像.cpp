// 15.�Ѷ��������ת�������ľ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
��������>=������<=����
*/
#include "stdafx.h"
#include<iostream>
using namespace  std;

//��
typedef struct node
{
	int value;
	struct node* left;
	struct node* right;
}Tree;

//����
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

//�ݹ飬���Һ��ӻ���,�������Եĺ�������
void zhuanzhi(Tree* t)
{
	if(t)
	{
		//��ת����
		zhuanzhi(t->left);
		//��ת����
		zhuanzhi(t->right);
		//Ȼ�����Һ��ӻ��� 
		Tree* temp=t->left;
		t->left=t->right;
		t->right=temp;
	}
}

//ѭ�������ú���������ת��
//�������������ջ
#define MAX 100
struct datanode
{
	Tree* t;
	int count;
};

typedef struct 
{
	struct datanode data[MAX];
	int top;
}Stack;

Stack* init_stack(void)
{
	Stack* s=new Stack;
	if(s)
		s->top=-1;
	return s;
}

bool empty_stack(Stack* s)
{
	if(s->top==-1)
		return true;
	return false;
}

bool full_stack(Stack* s)
{
	if(s->top==MAX-1)
		return true;
	return false;
}

void push(Stack* s,struct datanode dn)
{
	if(full_stack(s))
		return ;
	++s->top;
	(s->data[s->top]).t=dn.t;
	(s->data[s->top]).count=dn.count;
}

void pop(Stack* s,struct datanode* dn)
{
	if(empty_stack(s))
		return ;
	dn->t=(s->data[s->top]).t;
	dn->count=(s->data[s->top]).count;
	--s->top;
}

void zhuanzhi_houxu(Tree* t)
{
	Tree* p=t;
	Stack* s=NULL;
	struct datanode temp;

	s=init_stack();
	while(p!=NULL || !empty_stack(s))
	{
		if(p)
		{
			temp.t=p;
			temp.count=0;
			push(s,temp);
			p=p->left;
		}
		else
		{
			pop(s,&temp);
			p=temp.t;

			if(temp.count==0)
			{
				temp.count=1;
				push(s,temp);
				p=p->right;
			}
			else
			{
				Tree* q=p->left;
				p->left=p->right;
				p->right=q;
				p=NULL;
			}

		}
	}
}


void inorder(Tree* t)
{
	if(t)
	{
		inorder(t->left);
		cout<<t->value<<" ";
		inorder(t->right);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Tree* t=NULL;

	t=create();
	inorder(t);
	cout<<endl;

	zhuanzhi(t);
	inorder(t);
	cout<<endl;

	zhuanzhi_houxu(t);
	inorder(t);
	cout<<endl;
	system("pause");

	return 0;
}

