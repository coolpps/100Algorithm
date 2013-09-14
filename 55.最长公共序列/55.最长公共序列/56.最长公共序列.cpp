// 55.最长公共序列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//LCS问题，既可以用递归解决，又可以迭代解决
/*
假设字符串
*/
#include<iostream>
#include<cstring>
using namespace std;


void print_LCS(const char* a,const char* b,char **flag,int la,int lb)
{
	//如果la和lb有到0的话就是结束
	if(la==0 || lb==0)
		return ;
	else //查看flag[la][lb]
	{
		if(flag[la][lb]=='y')
		{
			print_LCS(a,b,flag,la-1,lb-1);
			cout<<a[la-1]<<" ";
		}
		else if(flag[la][lb]=='<')
			print_LCS(a,b,flag,la-1,lb);
		else if(flag[la][lb]=='>')
			print_LCS(a,b,flag,la,lb-1);
	}
}

void LCS(const char* a,const char* b)
{
	int lena=strlen(a);
	int lenb=strlen(b);
	int i,j;

	//定义 c[lena+1][lenb+1]
	int **c=new int*[lena+1];
	for(i=0;i<lena+1;++i)
		c[i]=new int[lenb+1];

	for(i=0;i<lenb+1;++i)
		c[0][i]=0;
	for(i=0;i<lena+1;++i)
		c[i][0]=0;

	//定义flag[lena+1][lenb+1]存贮标志，标志a[i-1]和b[j-1]是不是LCS的一员
	char** flag=new char*[lena+1];
	for(i=0;i<lena+1;++i)
		flag[i]=new char[lenb+1];

	for(i=0;i<lena+1;++i)
		for(j=0;j<lenb+1;++j)
			flag[i][j]='\0';

	//对应于a[i-1]和b[j-1]
	//c[i][j]对应于a[i-1]和b[j-1]
	int max=-1;
	for(i=1;i<=lena;++i)
		for(j=1;j<=lenb;++j)
		{
			if(a[i-1]==b[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				flag[i][j]='y';
			}
			else
			{
				if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					flag[i][j]='<';
				}
				else
				{
					c[i][j]=c[i][j-1];
					flag[i][j]='>';
				}
			}

			if(c[i][j]>max)
				max=c[i][j];
		}

		cout<<max<<endl;

		//递归打印
		print_LCS(a,b,flag,lena,lenb);
		cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const char* a="ABCBDAB";
	const char* b="BDCABA";

	LCS(a,b);

	system("pause");
	return 0;
}

