// 33.ʵ��1��ͦ�߼����ַ�ƥ���㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
��1���ܳ����ַ������ҵ�����Ҫ����ַ���
,����İ취�ǣ���Ϊ�ַ���256��������cnt[256]������ͬʱ����ģʽ���ĸ�����m������sum������������ģʽ����1���µ�ʱ�򣬾�summ+1��
����2��ָ��front,tail,��ʼfront=tail=0,Ȼ��tailһֱ�ӣ�ֱ��sum=mʱΪֹ����ʱ[front,tail]����ģʽ����ÿһ���ַ���ͬʱ��1���ַ�ֻ������1�Σ�
�����ַ����ܳ��ֶ�Σ�����front++,֪����1���ַ���1����0ʱ������֪����ʱ����ַ�ֻ����1���ˣ�������ʱ[front,tail]�Ƿ���Ҫ�����С���Ӵ�����ӡ����
��һ��Ҫƥ��Ĵ���tail=front+1��ʼƥ��
*/

#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

void pipei(const char* s,const char* p)
{
	int front,tail;

	int cnt[256]={0};
	int sum=0;

	int n=strlen(s);
	int m=strlen(p);


}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s="dugdugwdeh1ihi2ihihi3hihihih4ihihi3ihihi2hiiih1hih1i1122h3iii2";
	char *p="123";

	pipei(s,p);
	return 0;
}

