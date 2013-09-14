// 66.颠倒栈.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;

/*
对栈点到也是1个递归的过程，首先把栈顶元素弹出来，然后递归点到剩下的栈，这是应该把栈顶元素压倒栈底，在把剩下的元素压入栈
*/
void tiaozheng(stack<int> &s,int top)
{
	//应该把top元素放在栈底
	stack<int> temp;
	while(!s.empty()){
		temp.push(s.top());
		s.pop();
	}
	s.push(top);
	while(!temp.empty()){
		s.push(temp.top());
		temp.pop();
	}
}

void diandao(stack<int> &s)
{
	if(!s.empty())
	{
		int top=s.top();
		s.pop();
		diandao(s);
		tiaozheng(s,top);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	stack<int> s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	diandao(s);

	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	system("pause");
	return 0;
}

