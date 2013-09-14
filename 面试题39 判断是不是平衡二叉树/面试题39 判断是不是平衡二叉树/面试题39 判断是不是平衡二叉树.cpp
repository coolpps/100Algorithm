// 面试题39 判断是不是平衡二叉树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
采用后续的方式，先判断左右子树是不是，如果左右子树是的话，在看根节点漫步满足，同时还要记录左右子树的高度
*/

bool IsBalancedTree(Tree* t,int* depth)
{
	if(t==NULL)
	{
		*depth=0;
		return true;
	}

	int left,right;
	if(IsBalancedTree(t->left,&left) && IsBalancedTree(t->right,&right))
	{
		int diff=left-right;
		if(diff<=1 || diff>=-1)
		{
			*depth=1+(left>right ? left: right);
			return true;
		}
	}

	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

