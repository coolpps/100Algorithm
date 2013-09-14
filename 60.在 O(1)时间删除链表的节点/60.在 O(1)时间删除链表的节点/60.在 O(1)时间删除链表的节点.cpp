// 60.在 O(1)时间删除链表的节点.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
给定链表头指针head和一个节点指针p，删除该节点
假设节点长度是n,那么对已1->n-1的节点来说，都有p->next,可以用p->data=p->next->data,然后删除p->next节点，都是O(1)时间，当p是
尾节点是，需要遍历找到p->pre,需要O(n)时间，即n-1的O(1)时间和1个O(N)时间，综合起来还是O（1）时间 (n-1)*1+1*n=n/n=O(1)
*/

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

