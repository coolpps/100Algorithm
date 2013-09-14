// 顺时针打印矩阵.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
每次开始
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

