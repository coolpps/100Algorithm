// 17.在1个字符串中找到第一个只出现1次的字符.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

/*
ASCII字符是128个，从0到127，扩展的ASCII字符是
128-255这128个事扩展的ASCII字符，。  目前许多基于 x86 的系统都支持使用扩展（或“高”）ASCII。
 扩展 ASCII 码允许将每个字符的第 8 位用于确定附加的 128 个特殊符号字符、外来语字母和图形符号
ASCII字符是从共256个，所以可以设定count[256]=0的
*/

int _tmain(int argc, _TCHAR* argv[])
{
	int cnt[256]={0};
	int i;
	char *a="abaccdeff";
	for( i=0;i<strlen(a);++i)
		cnt[(int)a[i]]++;
	

	for(i=0;i<strlen(a);i++)
		if(cnt[(int)a[i]]==1)
		{
			cout<<a[i]<<endl;
			break;
		}


	//假如说只有1个出现1次的字母，那么可以用异或运算，因为它的结核性，有a^a=0
	char *b="abccdba";

	char ch=b[0];
	for(i=1;i<strlen(b);++i)
		ch^=b[i];

	cout<<ch<<endl;

	system("pause");
	return 0;
}

