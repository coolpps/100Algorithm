// ���Ϊ��������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
������ָ��small��big,��ʼsmall=1,big=2,big����sum���ӣ���sum=s���ӡ����sum<s,��big���ӣ���sum>s����small����
*/
void FindContinuousSequence(int sum)
{
	if(sum<3)
		return ;

	int small=1;
	int big=2;
	int mid=(1+sum)/2;
	int cursum=small+big;

	while(small<mid)
	{
		if(sum==cursum)
			print(small,sum);
		
		while(sum<cursum && small<mid)
		{
			cursum-=small;
			small++;

			if(sum==cursum)
				print(small,big);
		}
		big++;
		cursum+=big;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

