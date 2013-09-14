// 打印1到最大的n位数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

/*第一种，用字符串来表示*/

bool increment(char* str)
{
	int length=strlen(str);
	int  takeover=0;
	int sum;

	bool isoverflow=false;

	for(int i=length-1;i>=0;--i)
	{
		sum=str[i]-'0'+takeover;
		if(i==length-1)
			sum++;

		if(sum>=10)
		{
			if(i==0)
				isoverflow=true;
			else
			{
				sum-=10;
				str[i]=sum+'0';
				takeover=1;
			}
		}
		else
		{
			str[i]=sum+'0';
			takeover=0;
			break;
		}
	}
	return isoverflow;
}

void printnumber(char* str)
{
	int notzero=0;
	int length=strlen(str);

	for(int i=0;i<length;++i)
		if(str[i]!='0')
		{
			notzero=i;
			break;
		}
	printf("%s\n",str[notzero]);
}
void Print(int n)
{
	if(n<=0)
		return ;

	char *str=new char[n+1];
	memset(str,'0',n+1);
	str[n]='\0';

	while(!increment(str))
		printnumber(str);
	delete []str;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int n;

	cin>>n;
	Print(n);

	system("pause");
	return 0;
}

