// 52.求树的深度.cpp : 定义控制台应用程序的入口点。
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

