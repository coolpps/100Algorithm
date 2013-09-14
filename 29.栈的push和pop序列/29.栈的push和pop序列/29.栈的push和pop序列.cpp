// 29.栈的push和pop序列.cpp : 定义控制台应用程序的入口点。
//
/*
和海涛的分析 
这道题的一个很直观的想法就是建立一个辅助栈，每次push的时候就把一个整数push进入这个辅助栈，同样需要pop的时候就把该栈的栈顶整数pop出来。

我们以前面的序列4、5、3、2、1为例。第一个希望被pop出来的数字是4，因此4需要先push到栈里面。由于push的顺序已经由push序列确定了，也就是在把4 push进栈之前，数字1，2，3都需要push到栈里面。此时栈里的包含4个数字，分别是1，2，3，4，其中4位于栈顶。把4 pop出栈后，剩下三个数字1，2，3。接下来希望被pop的是5，由于仍然不是栈顶数字，我们接着在push序列中4以后的数字中寻找。找到数字5后再一次push进栈，这个时候5就是位于栈顶，可以被pop出来。接下来希望被pop的三个数字是3，2，1。每次操作前都位于栈顶，直接pop即可。

再来看序列4、3、5、1、2。pop数字4的情况和前面一样。把4 pop出来之后，3位于栈顶，直接pop。接下来希望pop的数字是5，由于5不是栈顶数字，我们到push序列中没有被push进栈的数字中去搜索该数字，幸运的时候能够找到5，于是把5 push进入栈。此时pop 5之后，栈内包含两个数字1、2，其中2位于栈顶。这个时候希望pop的数字是1，由于不是栈顶数字，我们需要到push序列中还没有被push进栈的数字中去搜索该数字。但此时push序列中所有数字都已被push进入栈，因此该序列不可能是一个pop序列。

也就是说，如果我们希望pop的数字正好是栈顶数字，直接pop出栈即可；如果希望pop的数字目前不在栈顶，我们就到push序列中还没有被push到栈里的数字中去搜索这个数字，并把在它之前的所有数字都push进栈。如果所有的数字都被push进栈仍然没有找到这个数字，表明该序列不可能是一个pop序列。
*/
#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;


bool ispossible(const int* push,cost int* pop,int length)
{
	bool is=false;

	if(push && pop && length>0)
	{
		const int* pushnext=push;
		const int* popnext=pop;

		std::stack<int> data;
		while(popnext-pop<length)
		{
			while(data.empty() || data.top()!=*popnext)
			{
				if(!pushnext)
					break;

				data.push(*pushnext);
				if(pushnext-push==length-1)//pushnext到了最后了,pushnext是一直前进的，如果它保证之前的元素都压入栈了
					pushnext=NULL;
				else
					pushnex++;
			}

			if(data.top()!=*popnext)
				break;

			data.pop();
			popnext++;
		}

		if(data.empty() && popnext-pop==length)
			is=true;
	}

	return is;
}

//我的版本
bool ispossible(const int* push.const int* pop,int length)// 0-length-1
{
	bool possible=false;
	if(push && pop && length>0)
	{
		const int* pushnext=push;
		const int* popnext=pop;

		stack<int> data;
		while(popnext<=pop+length-1)
		{
			while(data.empty() || data.top()!=*popnext)
			{
				if(pushnext==NULL)
					break;

				data.push(*pushnext);
				if(pushnext-push==length-1)
					pushnext=NULL;
				else
					pushnext++;
			}

			if(data.top()!=*popnext)
				break;

			data.pop();
			popnext++;
		}
		if(data.empty() && popnext-pop==length)
			possible=true;
	}
	return possible;
}



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

