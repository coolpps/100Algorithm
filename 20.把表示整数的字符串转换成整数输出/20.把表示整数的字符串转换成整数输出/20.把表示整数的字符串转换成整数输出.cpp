// 20.把表示整数的字符串转换成整数输出.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int myatoi(char* s)
{
	int sign=1,num=0;
	if(*s=='-')
	{
		sign=-1;s++;
	}
	while(*s!='\0')
	{
		if(*s>='0' && *s<='9')
		{
			num=num*10+(*s-'0');
			s++;
		}
		else
		{
			break;
			cout<<"Error"<<endl;
		}
	}
	return sign*num;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//就是atoi
	return 0;
}

