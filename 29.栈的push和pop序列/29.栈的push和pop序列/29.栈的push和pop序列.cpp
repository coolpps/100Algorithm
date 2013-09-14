// 29.ջ��push��pop����.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
�ͺ��εķ��� 
������һ����ֱ�۵��뷨���ǽ���һ������ջ��ÿ��push��ʱ��Ͱ�һ������push�����������ջ��ͬ����Ҫpop��ʱ��ͰѸ�ջ��ջ������pop������

������ǰ�������4��5��3��2��1Ϊ������һ��ϣ����pop������������4�����4��Ҫ��push��ջ���档����push��˳���Ѿ���push����ȷ���ˣ�Ҳ�����ڰ�4 push��ջ֮ǰ������1��2��3����Ҫpush��ջ���档��ʱջ��İ���4�����֣��ֱ���1��2��3��4������4λ��ջ������4 pop��ջ��ʣ����������1��2��3��������ϣ����pop����5��������Ȼ����ջ�����֣����ǽ�����push������4�Ժ��������Ѱ�ҡ��ҵ�����5����һ��push��ջ�����ʱ��5����λ��ջ�������Ա�pop������������ϣ����pop������������3��2��1��ÿ�β���ǰ��λ��ջ����ֱ��pop���ɡ�

����������4��3��5��1��2��pop����4�������ǰ��һ������4 pop����֮��3λ��ջ����ֱ��pop��������ϣ��pop��������5������5����ջ�����֣����ǵ�push������û�б�push��ջ��������ȥ���������֣����˵�ʱ���ܹ��ҵ�5�����ǰ�5 push����ջ����ʱpop 5֮��ջ�ڰ�����������1��2������2λ��ջ�������ʱ��ϣ��pop��������1�����ڲ���ջ�����֣�������Ҫ��push�����л�û�б�push��ջ��������ȥ���������֡�����ʱpush�������������ֶ��ѱ�push����ջ����˸����в�������һ��pop���С�

Ҳ����˵���������ϣ��pop������������ջ�����֣�ֱ��pop��ջ���ɣ����ϣ��pop������Ŀǰ����ջ�������Ǿ͵�push�����л�û�б�push��ջ���������ȥ����������֣���������֮ǰ���������ֶ�push��ջ��������е����ֶ���push��ջ��Ȼû���ҵ�������֣����������в�������һ��pop���С�
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
				if(pushnext-push==length-1)//pushnext���������,pushnext��һֱǰ���ģ��������֤֮ǰ��Ԫ�ض�ѹ��ջ��
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

//�ҵİ汾
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

