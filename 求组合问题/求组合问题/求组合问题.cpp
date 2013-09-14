// 求组合问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
对于由n个字符，那么组合共有=长度为1，长度为2.。。。长度为n的组合，这个和求筛子和差不多，
*/

#include<iostream>
#include<list>
using namespace std;

void zuhe(char* a,int n,int begin,int end,int length,std::list<char> &path) //有end-begin+1==n，即在n个字符里找length个字符
{
	//不满足的几种，end-begin+1<n，即没有那么多的字符肯定不满足
	if(n<length)
		return ;

	//正好满足条件 1.length=0没有继续寻找时，2. length=n即满足时
	if(length==0 || length==n)//刚好满足条件，像在剩下5个字符中找5个字符...
	{
		//打印path啊，还有a[begin]->a[end]
		for(std::list<char>::const_iterator iv=path.begin();iv!=path.end();++iv)
			cout<<*iv<<" ";
		if(length==n)
		{
			for(int i=begin;i<=end;++i)
				cout<<a[i]<<" ";
		}
		cout<<endl;
		return ;
	}

	
	//包含a[begin],那么就是在a[begin+1]->a[end]中找i-1个了
	path.push_back(a[begin]);
	zuhe(a,n-1,begin+1,end,length-1,path);
	path.pop_back();

	//不包含a[begin],那么就是在a[begin+1]->a[end]中找i个了，必须得满足end-(begin+1)+1=end-begin>=i的条件下，否则返回
	zuhe(a,n-1,begin+1,end,length,path);

}
int _tmain(int argc, _TCHAR* argv[])
{
	char a[]="abc";

	std::list<char> path;

	for(int i=1;i<=strlen(a);++i)
		zuhe(a,3,0,2,i,path);
	system("pause");
	return 0;
}

