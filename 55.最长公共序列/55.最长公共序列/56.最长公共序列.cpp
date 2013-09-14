// 55.���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//LCS���⣬�ȿ����õݹ������ֿ��Ե������
/*
�����ַ���
*/
#include<iostream>
#include<cstring>
using namespace std;


void print_LCS(const char* a,const char* b,char **flag,int la,int lb)
{
	//���la��lb�е�0�Ļ����ǽ���
	if(la==0 || lb==0)
		return ;
	else //�鿴flag[la][lb]
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

	//���� c[lena+1][lenb+1]
	int **c=new int*[lena+1];
	for(i=0;i<lena+1;++i)
		c[i]=new int[lenb+1];

	for(i=0;i<lenb+1;++i)
		c[0][i]=0;
	for(i=0;i<lena+1;++i)
		c[i][0]=0;

	//����flag[lena+1][lenb+1]������־����־a[i-1]��b[j-1]�ǲ���LCS��һԱ
	char** flag=new char*[lena+1];
	for(i=0;i<lena+1;++i)
		flag[i]=new char[lenb+1];

	for(i=0;i<lena+1;++i)
		for(j=0;j<lenb+1;++j)
			flag[i][j]='\0';

	//��Ӧ��a[i-1]��b[j-1]
	//c[i][j]��Ӧ��a[i-1]��b[j-1]
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

		//�ݹ��ӡ
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

