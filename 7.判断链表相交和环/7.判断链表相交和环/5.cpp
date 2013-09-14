/*
1.判断单链表是不有环
2.判断无环的话，两个单链表是不是相交
3.如果有环的话找到入环口
*/

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}Link;

//1.判断连个链表是不是相交，这里假设2个链表都无环
bool 相交(Link* head1,Link* head2)
{
	//求链表1的尾节点
	Link* tail1=head1;
	while(tail1->next!=NULL)
		tail1=tail1->next;

	Link* tail2=head2;
	while(tail2->next!=NULL)
		tail2=tail2->next;

	if(tail1==tail2)
		return true;
	else
		return false;
}

//相交的话，找到相交的第一个节点
Link*   第一个节点(Link* head1,Link* head2)
{
	int len1;
	int len2; //假设len2<len1

	int i;
	Link *p,*q;
	p=head1;q=head2;
	for(i=0;i<(len1-len2);i++)
		p=p->next;

	while(p!=q)
	{
		p=p->next;
		q=q->next;
	}
	//这也是O(n)的时间，要比hash方便多了

}

//2.判断是否有环
bool 有环(Link* head)
{
	//设置2个指针slow和fast,slow每次1步，fast每次2步，若slow=fast，slow没走完全程呢，则证明有环
	//有环的话，最终会break的，没环的话，最后fast走到最后1个节点或者NULL
	Link* slow,*fast;

	slow=head;
	fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			return true;
	}
	
	return !(fast==NULL || fast->next==NULL);
}

//有环的话找到环的入口
/*
设链口到环入口距离是a,环入口到相遇点距离是b，真个链长L
那么相遇时，fast走的是slow走的2倍,fast已经走了n圈环了,l-a是环的长
slow走的=a+b
fast走的 =a+b+n*(l-a)
则 2(a+b)=a+b+n(l-a)
即a+b=n(l-a),即a=n*(l-a)-b,即p从链头开始，q从相遇点开始，他们都是一步一步的走，最后就会相遇，而再相遇点就是环的入口了 

*/