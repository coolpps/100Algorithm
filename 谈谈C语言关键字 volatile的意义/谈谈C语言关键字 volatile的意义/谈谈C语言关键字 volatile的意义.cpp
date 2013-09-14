// 谈谈C语言关键字 volatile的意义.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

volatile的意思是"易变的"，因为访问寄存器比访问内存要快得多， 所以编译器一般都会做减少存取内存的优化。volatile 这个关键字会提醒编译器，它声明的变量随时可能发生变化(在外部被修改)， 因此，与该变量相关的代码不要进行编译优化，以免出错