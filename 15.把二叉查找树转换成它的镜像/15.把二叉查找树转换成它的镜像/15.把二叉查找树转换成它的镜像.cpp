// 15.把二叉查找树转换成它的镜像.cpp : 定义控制台应用程序的入口点。
//

/*
镜像是左>=跟，右<=根，
*/
#include "stdafx.h"
#include<iostream>
using namespace  std;

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

//递归，左右孩子互换,这是明显的后续遍历
void zhuanzhi(Tree* t)
{
	if(t)
	{
		//先转置左
		zhuanzhi(t->left);
		//再转置右
		zhuanzhi(t->right);
		//然后左右孩子互换 
		Tree* temp=t->left;
		t->left=t->right;
		t->right=temp;
	}
}

//循环，采用后续遍历来转换
//定义后续遍历的栈
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

