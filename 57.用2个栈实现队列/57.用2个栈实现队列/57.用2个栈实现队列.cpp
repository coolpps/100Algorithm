// 57.��2��ջʵ�ֶ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
*/

//ջ 
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

//��ʵ���У������������
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
	else//s2Ҫ�ǿյĻ�����Ҫ��s1�е�����
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

