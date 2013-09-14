/*
借鉴了中序线索二叉树的概念，在中序线索树中，如果有左孩子，则指向左孩子，如果没有左孩子，则指向前去，这里都指向前去
如果有右孩子，则指向右孩子，否则指向后继，这里都指向后继
*/

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



//中序线索二叉树
/*
ltag=0时有左孩子;ltag=1时指向前驱
rtag=0是有右孩子;rtag=1时指向后继
pre始终是t的前驱

Tree* pre=NULL;
void inthread(Tree* t)
{
	if(t)
	{
		inthread(t->left);

		if(t->left==NULL)
		{
			t->left=pre;
			t->ltag=1;
		}

		if(t->right==NULL)
			t->rtag=1;

		if(pre!=NULL && pre->ltag==1)
			pre->left=t;

		pre=t;

		inthread(t->right);
	}
}
*/

//下面把儿茶搜索树转换成双向链表，遵循left始终指向前驱，right始终指向后继
Tree* pre=NULL;
void zhuanhuan(Tree* t)
{
	if(t)
	{
		zhuanhuan(t->left);
		t->left=pre;

		if(pre!=NULL)
			pre->right=t;

		pre=t;
		zhuanhuan(t->right);
	}
}

//找到二叉查找树的最小值节点
Tree* mintree(Tree* t)
{
	Tree* p=t;
	while(p->left!=NULL)
		p=p->left;
	return p;
}
//打印转换后的树
void print(Tree* t)
{
	while(t!=NULL)
	{
		cout<<t->value<<" ";
		t=t->right;
	}
}
int main(void)
{
	Tree* root=NULL;

	root=create();

	Tree* minnode=mintree(root);

	zhuanhuan(root);
	print(minnode);


	system("pause");
}
