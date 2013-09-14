// 67.所有和为n的m个筛子组合.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
输入n个骰子，和为S，求和，因为每个骰子有1-6共6个值，每个骰子都必须有值
*/

#include<iostream>
#include<list>
using namespace std;

void print(int n,int s,list<int> &data)
{
	if(n==0)
	{
		if(s==0)
		{
			for(std::list<int>::iterator iv=data.begin();iv!=data.end();++iv)
				cout<<*iv<<"+";
			cout<<endl;
			return ;
		}
		else
			return ;
	}
	else if(n>0)
	{
		if(s>0)
		{
			data.push_back(1);
			print(n-1,s-1,data);
			data.pop_back();

			data.push_back(2);
			print(n-1,s-2,data);
			data.pop_back();

			data.push_back(3);
			print(n-1,s-3,data);
			data.pop_back();

			data.push_back(4);
			print(n-1,s-4,data);
			data.pop_back();

			data.push_back(5);
			print(n-1,s-5,data);
			data.pop_back();

			data.push_back(6);
			print(n-1,s-6,data);
			data.pop_back();
		}else
			return ;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,s;

	cin>>n>>s;

	list<int> data;
	print(n,s,data);

	system("pause");
	return 0;
}

