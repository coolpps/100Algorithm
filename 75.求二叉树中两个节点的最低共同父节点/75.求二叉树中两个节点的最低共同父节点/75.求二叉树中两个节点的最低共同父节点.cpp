// 75.求二叉树中两个节点的最低共同父节点.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
1.按照我的想法，要从根节点开做，如果说t1和t2都属于t的左子树，那么继续递归左子树;如果t1和t2都属于右子树，那么递归右子树；如果他们分属于T的左右子树，那么T就是满足要求的最低父节点

2.按照何海涛的想法，首先求出这2个节点的路径，即从父节点到它的路径，然后求着两条路径的最后一个共同节点
*/



#include<iostream>
#include<list>
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


bool ischild(Tree* T,Tree* p)//判断p是不是以T为根的孩子节点
{
	if(T==NULL)
		return false;
	if(p==T->left || p==T->right)
		return true;

	bool leftis=ischild(T->left,p);
	bool rightis=ischild(T->right,p);

	return (leftis || rightis);
}

//1.我的想法
Tree* CommonParent(Tree* root,Tree* t1,Tree* t2)
{
	if(root==NULL)
		return NULL;
	if(ischild(root->left,t1) && ischild(root->left,t2))
		return CommonParent(root->left,t1,t2);
	else if(ischild(root->right,t1) && ischild(root->right,t2))
		return CommonParent(root->right,t1,t2);
	else
		return root;

}

Tree* findt(Tree* root,int data)
{
	if(!root)
		return NULL;
	if(data==root->value)
		return root;
	
	Tree* left=findt(root->left,data);
	if(left!=NULL)
		return findt(root->left,data);
	else
		return findt(root->right,data);

}


//2.何海涛的想法
bool getpath(Tree* root,Tree* p,list<Tree*> &path)
{
	if(p==root)
		return true;

	bool flag=false;
	path.push_back(root);
	if(root->left!=NULL)
		flag=getpath(root->left,p,path);

	if(flag==false && root->right!=NULL)
		flag=getpath(root->right,p,path);

	if(!flag)
		path.pop_back();
	return flag;
}

void getCommonParent(list<Tree*> &path1,list<Tree*> &path2)
{
	bool flag=false;
	for(list<Tree*>::reverse_iterator p1=path1.rbegin();p1!=path1.rend();++p1)
	{
		for(list<Tree*>::reverse_iterator p2=path2.rbegin();p2!=path2.rend();++p2)
			if(*p1==*p2)
			{
				cout<<(*p1)->value<<endl;
				return ;
			}
	}
	cout<<"没找到"<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Tree* t=NULL;

	t=create();

	int m,n;
	cin>>m>>n;

	Tree* p=findt(t,m);
	Tree* q=findt(t,n);

	//cout<<p->value<<endl<<q->value<<endl<<endl;
	Tree* temp=CommonParent(t,p,q);
	if(temp)
		cout<<temp->value<<endl;

	list<Tree*> path1;
	list<Tree*> path2;

	getpath(t,p,path1);
	getpath(t,q,path2);

	for(list<Tree*>::iterator i=path1.begin();i!=path1.end();++i)
		cout<<(*i)->value<<" ";
	cout<<endl;

	for(list<Tree*>::iterator i=path2.begin();i!=path2.end();++i)
		cout<<(*i)->value<<" ";
	cout<<endl;

	getCommonParent(path1,path2);



	system("pause");
	return 0;
}

