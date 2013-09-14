// 求链表的中间节点.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


ListNode* FindMidNode(ListNode* phead)
{
	if(phead==NULL)
		return NULL;

	ListNode* slow=phead;
	ListNode* fast=phead;

	while(fast && fast->next!=NULL)//走早最后不要走了，走到
	{
		slow=slow->next;
		fast=fast->next->next;
		//判断是不是形成环
		if(slow==fast)
			return slow;
	}

	//要是没有环的话，最后fast走到尾节点或者NULL
	if(fast->next==NULL || fast==NULL)
		return 没环

}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

