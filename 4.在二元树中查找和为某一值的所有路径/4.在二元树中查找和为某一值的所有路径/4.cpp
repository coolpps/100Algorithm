/*
路径是定义从根节点到叶节点的，假设给定的值是value,那么和当前节点比较，若value-t->value>0，那么继续遍历它的左右几点，如果value-t->value<0的话，那么就终端，因为从这个节点不可能了，如果t->value=value,但是不是叶节点的话也终端，如果是叶节点就证明走了一个完整路径，打印

这个和寻找从根节点到当前节点的路径差不多 
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

bool findpath(Tree* t,std::list<Tree*>& path,int sum)
{

	if(t) //t!=NULL
	{
		if(sum<t->value)
			return false;
		if(sum==t->value)
		{
			if(t->left==NULL && t->right==NULL)
			{
				for(std::list<Tree*>::iterator iv=path.begin();iv!=path.end();iv++)
					cout<<(*iv)->value<<" ";
				cout<<t->value;
				cout<<endl;
				return true;
			}
			else
				return false;
		}

		if(sum>t->value)
		{
			path.push_back(t);
			//左右同时开工,t点找完就要弹出list了
			findpath(t->left,path,sum-t->value);
			findpath(t->right,path,sum-t->value);
			path.pop_back();
		}
	}
	else
		return false;
}
int main()
{
	Tree* t=NULL;
	int sum;

	cin>>sum;

	t=create();

	std::list<Tree*> path;
	findpath(t,path,sum);

	system("pause");
}