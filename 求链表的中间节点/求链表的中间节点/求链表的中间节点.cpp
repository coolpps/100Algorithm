// ��������м�ڵ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


ListNode* FindMidNode(ListNode* phead)
{
	if(phead==NULL)
		return NULL;

	ListNode* slow=phead;
	ListNode* fast=phead;

	while(fast && fast->next!=NULL)//�������Ҫ���ˣ��ߵ�
	{
		slow=slow->next;
		fast=fast->next->next;
		//�ж��ǲ����γɻ�
		if(slow==fast)
			return slow;
	}

	//Ҫ��û�л��Ļ������fast�ߵ�β�ڵ����NULL
	if(fast->next==NULL || fast==NULL)
		return û��

}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

