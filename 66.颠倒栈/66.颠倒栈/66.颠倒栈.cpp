// 66.�ߵ�ջ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;

/*
��ջ�㵽Ҳ��1���ݹ�Ĺ��̣����Ȱ�ջ��Ԫ�ص�������Ȼ��ݹ�㵽ʣ�µ�ջ������Ӧ�ð�ջ��Ԫ��ѹ��ջ�ף��ڰ�ʣ�µ�Ԫ��ѹ��ջ
*/
void tiaozheng(stack<int> &s,int top)
{
	//Ӧ�ð�topԪ�ط���ջ��
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

