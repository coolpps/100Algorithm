// ������39 �ж��ǲ���ƽ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
���ú����ķ�ʽ�����ж����������ǲ��ǣ�������������ǵĻ����ڿ����ڵ��������㣬ͬʱ��Ҫ��¼���������ĸ߶�
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

