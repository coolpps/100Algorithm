/*
��򵥵ķ�����ջԪ�ض�����������ɣ�ԭ����Ԫ�غ�ջ�׵����ڵ���Сֵ
*/

#include<iostream>
using namespace std;

//ջ����
#define MAX 100
struct node
{
	int value;
	int min;
};
typedef struct 
{
	struct node data[MAX];
	int top;
}Stack;

Stack* create(void)
{
	Stack* s=new Stack;
	if(s)
		s->top==-1;
}

bool empty(Stack* s)
{
	if(s->top==-1)
		return true;
	return false;
}

bool full(Stack* s)
{
	if(s->top==MAX-1)
		return true;
	return false;
}

void push(Stack* s,int value)
{
	if(full(s))
		return ;

	struct node temp;
	temp.value=value;
	
	int m=(s->data[s->top]).min;
	if(value<=m)
		temp.min=value;
	else
		temp.min=m;
	s->top++;
	(s->data[s->top]).value=value;
	(s->data[s->top]).min=temp.min;
}

void pop(Stack* s,int* value)
{
	if(empty(s))
		return ;
	*value=(s->data[s->top]).value;
	s->top--;
}

void stack_min(Stack* s,int *min)
{
	if(empty(s))
		return ;
	*min=(s->data[s->top]).min;
}

int main()
{

}