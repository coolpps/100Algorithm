/*
���蹲n���ڵ�
������0����β�ڵ㣬��������n-0���ڵ�
������1����������n-1���ڵ㣬������k����������n-k���ڵ�
*/
#include<iostream>
using namespace std;

typedef struct node
{
	int key;
	struct node* next;
}ListNode;

ListNode* head=NULL;

int main()
{
	int i;
	int n;
	int k;

	cin>>n;
	ListNode* p=head;
	for(i=1;i<n;i++)
	{
		ListNode* temp=new ListNode;
		temp->key=i;
		temp->next=NULL;

		if(p==NULL)
			p=head=temp;
		else{
			p->next=temp;
			p=temp;
		}
	}

	cin>>k;

	p=head;
	for(i=1;i<n-k;i++)
		p=p->next;
	cout<<p->key<<endl;

	system("pause");
}