// 33.实现1个挺高级的字符匹配算法.cpp : 定义控制台应用程序的入口点。
//
/*
给1个很长的字符串，找到符合要求的字符串
,这题的办法是，因为字符共256个，所有cnt[256]计数，同时假设模式串的个数是m个，用sum计数，当出现模式串中1个新的时候，就summ+1，
给定2个指针front,tail,开始front=tail=0,然后tail一直加，直到sum=m时为止，这时[front,tail]中有模式串的每一个字符，同时有1个字符只出现了1次，
其他字符可能出现多次，所以front++,知道有1个字符从1减到0时，我们知道这时这个字符只有这1个了，所以这时[front,tail]是符合要求的最小的子串，打印即可
下一个要匹配的串，tail=front+1开始匹配
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

