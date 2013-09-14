// 52.���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

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

int height(Tree* t)
{
	if(!t)
		return 0;
	int left=height(t->left);
	int right=height(t->right);

	return (((left>=right)?left:right)+1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Tree* t=NULL;

	t=create();
	cout<<height(t)<<endl;

	system("pause");
	return 0;
}

