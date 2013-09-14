/*
假设共n个节点
倒数第0个是尾节点，即正数第n-0个节点
倒数第1个事整数第n-1个节点，倒数第k个事正数第n-k个节点
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