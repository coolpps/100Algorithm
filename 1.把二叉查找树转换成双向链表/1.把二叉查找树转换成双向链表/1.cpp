/*
��������������������ĸ���������������У���������ӣ���ָ�����ӣ����û�����ӣ���ָ��ǰȥ�����ﶼָ��ǰȥ
������Һ��ӣ���ָ���Һ��ӣ�����ָ���̣����ﶼָ����
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



//��������������
/*
ltag=0ʱ������;ltag=1ʱָ��ǰ��
rtag=0�����Һ���;rtag=1ʱָ����
preʼ����t��ǰ��

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

//����Ѷ���������ת����˫��������ѭleftʼ��ָ��ǰ����rightʼ��ָ����
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

//�ҵ��������������Сֵ�ڵ�
Tree* mintree(Tree* t)
{
	Tree* p=t;
	while(p->left!=NULL)
		p=p->left;
	return p;
}
//��ӡת�������
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
