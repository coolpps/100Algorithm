// 17.��1���ַ������ҵ���һ��ֻ����1�ε��ַ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

/*
ASCII�ַ���128������0��127����չ��ASCII�ַ���
128-255��128������չ��ASCII�ַ�����  Ŀǰ������ x86 ��ϵͳ��֧��ʹ����չ���򡰸ߡ���ASCII��
 ��չ ASCII ������ÿ���ַ��ĵ� 8 λ����ȷ�����ӵ� 128 ����������ַ�����������ĸ��ͼ�η���
ASCII�ַ��Ǵӹ�256�������Կ����趨count[256]=0��
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


	//����˵ֻ��1������1�ε���ĸ����ô������������㣬��Ϊ���Ľ���ԣ���a^a=0
	char *b="abccdba";

	char ch=b[0];
	for(i=1;i<strlen(b);++i)
		ch^=b[i];

	cout<<ch<<endl;

	system("pause");
	return 0;
}

