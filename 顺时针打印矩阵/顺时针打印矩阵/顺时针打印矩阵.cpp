// ˳ʱ���ӡ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
ÿ�ο�ʼ
*/

 
void PrintMatrixClockwisely(int **a,int columns,int rows)
{
	if(a==NULL || columns<=0 || rows<=0)
		return ;

	int start=0;
	while(columns>start*2 && rows>start*2)
	{
		print(a,colums,rows,start);
		++start;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

