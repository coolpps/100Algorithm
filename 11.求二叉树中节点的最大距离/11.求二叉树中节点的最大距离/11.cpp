/*
以某1个节点为根的最大的是，它的左孩子最深和右孩子最深，这是最大的，然后求左孩子的最大距离和右孩子的最大距离，取3者最大值
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


int height(Tree* t)
{
	if(NULL==t)
		return 0;
	int left=height(t->left);
	int right=height(t->right);
	
	if(left>=right)
		return left+1;
	else
		return right+1;
}
int max3(int a,int b,int c)
{
	int max;
	if(a>=b)
		max=a;
	else
		max=b;
	if(c>=max)
		max=c;
	return max;
}

int maxdistance(Tree* t)
{
	if(t==NULL)
		return 0;
	int left=height(t->left);
	int right=height(t->right);

	int left_dis=maxdistance(t->left);
	int right_dis=maxdistance(t->right);

	//返回3者的最大值
	//if(left!=0) left+=1;
	//if(right!=0) right+=1;
	return max3(left+right,left_dis,right_dis);
}

int main()
{
	Tree* t=NULL;

	t=create();
	cout<<maxdistance(t)<<endl;


	system("pause");
}