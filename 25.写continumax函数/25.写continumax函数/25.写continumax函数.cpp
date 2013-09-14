// 25.写continumax函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

int continumax(char* outputstr,char* inputstr)
{
	int i=0;
	int len=strlen(inputstr);

	int max=0;
	int begin=0;
	bool flag;

	int rebegin,reend;
	for(i=0;i<len;)
	{
		if(!(inputstr[i]>='0'&&inputstr[i]<='9'))
		{ 
			flag=false;
			i++;
		}else
		{
			int temp_max=0;
			if(flag==false)
				begin=i;
			while(inputstr[i]>='0'&&inputstr[i]<='9')
			{
				++i;
				++temp_max;
			}
			if(temp_max>max)
			{
				rebegin=begin;
				reend=i-1;
				max=temp_max;
			}
		}
	}

	for(i=rebegin;i<=reend;i++)
		outputstr[i-rebegin]=inputstr[i];
	outputstr[i-rebegin]='\0';
	return max;
}



int _tmain(int argc, _TCHAR* argv[])
{
	char in[]="abcd12345ed125ss123456789";
	char out[20];

	continumax(out,in);
	cout<<out<<endl;
	system("pause");
	return 0;
}

