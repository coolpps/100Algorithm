// 63.���ַ�����ɾ���ض����ַ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

/*�����ַ���s��p��Ҫ��s��ɾ��p�г��ֵ��ַ�*/

void deletefroms(char* s,char* p)
{
	cout<<s<<endl;

	int lens=strlen(s);
	int lenp=strlen(p);
	int i;
	int cnt[256]={0};

	for(i=0;i<lenp;++i)
		cnt[p[i]]=1;

	char *k,*q;

	for(k=s,q=s;k<s+lens;++k)
	{
		if(cnt[*k]==0)
		{
			*q=*k;
			q++;
		}
	}
	*q='\0';
	cout<<s<<endl;

}


int _tmain(int argc, _TCHAR* argv[])
{
	char s[]="they are students";
	char p[]="aeiou";

	deletefroms(s,p);
	system("pause");
	return 0;
}


