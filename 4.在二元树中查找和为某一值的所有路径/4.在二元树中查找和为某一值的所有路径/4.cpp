/*
·���Ƕ���Ӹ��ڵ㵽Ҷ�ڵ�ģ����������ֵ��value,��ô�͵�ǰ�ڵ�Ƚϣ���value-t->value>0����ô���������������Ҽ��㣬���value-t->value<0�Ļ�����ô���նˣ���Ϊ������ڵ㲻�����ˣ����t->value=value,���ǲ���Ҷ�ڵ�Ļ�Ҳ�նˣ������Ҷ�ڵ��֤������һ������·������ӡ

�����Ѱ�ҴӸ��ڵ㵽��ǰ�ڵ��·����� 
*/

#include<iostream>
#include<list>
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
			//����ͬʱ����,t�������Ҫ����list��
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