// 面试题42 翻转单词顺序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void reverse(char* begin,char* end)
{
	if(begin==NULL || end==NULL)
		return ;
	while(begin<end)
	{
		char temp=*begin;
		*begin=*end;
		*end=temp;

		++begin;
		--end;
	}
}

char *ReverseSentence(char* data)
{
	if(data==NULL)
		return NULL;

	char* begin=data;
	char* end=data;

	while(*end!='\0')
		++end;
	--end;

	reverse(begin,end);

	begin=end=data;
	while(*end!='\0')
	{
		if(*end!=' '&& *end!='\0')
			++end;
		else if(*begin==' ')
		{
			begin++;
			end++;
		}else
		{
			reverse(begin,end-1);
			begin=end;
		}
	}
	return data;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[]="i am a student.";

	cout<<ReverseSentence(a)<<endl;

	system("pause");
	return 0;
}

