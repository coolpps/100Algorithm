/*
1.�жϵ������ǲ��л�
2.�ж��޻��Ļ��������������ǲ����ཻ
3.����л��Ļ��ҵ��뻷��
*/

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}Link;

//1.�ж����������ǲ����ཻ���������2�������޻�
bool �ཻ(Link* head1,Link* head2)
{
	//������1��β�ڵ�
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

//�ཻ�Ļ����ҵ��ཻ�ĵ�һ���ڵ�
Link*   ��һ���ڵ�(Link* head1,Link* head2)
{
	int len1;
	int len2; //����len2<len1

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
	//��Ҳ��O(n)��ʱ�䣬Ҫ��hash�������

}

//2.�ж��Ƿ��л�
bool �л�(Link* head)
{
	//����2��ָ��slow��fast,slowÿ��1����fastÿ��2������slow=fast��slowû����ȫ���أ���֤���л�
	//�л��Ļ������ջ�break�ģ�û���Ļ������fast�ߵ����1���ڵ����NULL
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

//�л��Ļ��ҵ��������
/*
�����ڵ�����ھ�����a,����ڵ������������b���������L
��ô����ʱ��fast�ߵ���slow�ߵ�2��,fast�Ѿ�����nȦ����,l-a�ǻ��ĳ�
slow�ߵ�=a+b
fast�ߵ� =a+b+n*(l-a)
�� 2(a+b)=a+b+n(l-a)
��a+b=n(l-a),��a=n*(l-a)-b,��p����ͷ��ʼ��q�������㿪ʼ�����Ƕ���һ��һ�����ߣ����ͻ�������������������ǻ�������� 

*/