// 57.用2个栈实现队列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
*/

//栈 
#define MAX 100
typedef struct
{
	int data[MAX];
	int top;
}Stack;

typedef struct 
{
	Stack s1;
	Stack s2;
}Queue;

//其实队列，假设满的情况
void queue_push(Queue* q,int value)
{
	if(full(q.s1))
		return ;

	stack_push(q.s1.value);
}

void queue_pop(Queue*q,int* value)
{
	if(!empty(q.s2))
	{
		stack_pop(q.s2,value);
	}
	else//s2要是空的话，就要从s1中弹出了
	{
		while(!empty(q.s1))
		{
			int temp;
			stack_pop(q.a1,&temp);
			stack_push(q.s2,*temp);
		}
		stack_pop(q.s2,value);
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

