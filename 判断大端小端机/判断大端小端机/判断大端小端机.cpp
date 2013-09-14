// 判断大端小端机.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
用联合体来判断，char是1字节，int是4字节
*/

#include<iostream>
using namespace std;
union bigsmall
{
	char ch;
	int i;
};

int _tmain(int argc, _TCHAR* argv[])
{
	union bigsmall ooo;
	ooo.i=1;

	/*
	1的表示应该是 0X0001
	如果是在小端机,那么
	高----->低  地址
	0  0  0  1
	如果是在大端机

	高-----低
	1 0  0  0

	我们取得时候是从地址值取ch,所以ch若是0的话就是大端机，若是1的话就是低端机
	*/
	cout<<(int)(ooo.ch)<<endl;

	system("pause");
	return 0;
}

