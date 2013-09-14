/*
��ĳ1���ڵ�Ϊ���������ǣ���������������Һ�������������ģ�Ȼ�������ӵ���������Һ��ӵ������룬ȡ3�����ֵ
*/

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

	//����3�ߵ����ֵ
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