// 合并两个链表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

ListNode* merge(ListNode* phead1,ListNode* phead2)
{
	if(phead1==NULL)
		return phead2;
	if(phead2==NULL)
		return phead1;

	ListNode* mergenode=NULL;
	if(phead1->value<=phead2->value)
	{
		mergenode=phead1;
		mergenode->next=merge(phead1->next,phead2);
	}
	else
	{
		mergenode=phead2;
		mergenode->next=merge(phead1,phead2->next);
	}

	return mergenode;
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

