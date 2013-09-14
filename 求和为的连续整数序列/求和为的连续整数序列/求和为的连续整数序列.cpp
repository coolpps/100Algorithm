// 求和为的连续整数序列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
用两个指针small和big,开始small=1,big=2,big增加sum增加，若sum=s则打印，若sum<s,则big增加，若sum>s，则small增加
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

