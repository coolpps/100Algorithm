// 61.找出数组中只出现1次的两个数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<list>
#include<iostream>
using namespace std;
/*
假设数组中只有1个出现1次的数，通过所以元素异或^运算能得到
有2个出现1次的元素，那么最后异或结果就是这2个数的异或，根据异或的性质，相同位为0，不相同位为1，
我们结果的最低为1的位置找到，那么可以肯定，这2个数中1个是0,1个是1，其他的都出现2次的数，肯定都是0或者1，
这样根据这一位，就把原来n哥元素分成两组n1和n2,他们都只包含1个只出现1次的数，
*/

void erjinzhi(int n,list<int> &data)
{
	while(n!=0)
	{
		data.push_back(n%2);
		n=n/2;
	}
}

bool is(int n,int pos)//看pos位是不是为1
{
	list<int> data;
	erjinzhi(n,data);

	int count=0;


	while(!data.empty() && count<pos)
	{
		data.pop_front();
		count++;
	}
	if(!data.empty() && data.front()==1)
		return true;
	else
		return false;
}
void print(int* a,int p,int r)
{
	int result=0;
	int i;
	
	for(i=p;i<=r;++i)
		result^=a[i];

	//求result得2进制表示中最低位为1的位置
	int pos=0;
	while(is(result,pos)==false)
		pos++;
	//cout<<pos<<endl;

	int result_left=0;
	int result_right=0;;

	
	for(i=p;i<=r;i++)
	{
		if(is(a[i],pos)) //是1
			result_left^=a[i];
		else  //是0
			result_right^=a[i];
	}
	
	cout<<result_left<<endl;
	cout<<result_right<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={1,2,3,4,5,7,2,1,4,3};

	print(a,0,9);

	system("pause");
	return 0;
}

