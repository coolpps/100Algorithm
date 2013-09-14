// 旋转数组的最小数字.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
一般的情况----,有相同元素的情况
*/

int Min(int *numbers,int length)
{
	if(NULL==numbers || length<=0)
		throw new std::exception("ssssss");

	int index1=0;
	int index2=length-1;
	int indexmin=0;

	while(numbers[index1]>=numbers[index2])
	{
		if(index2==index1+1)
		{
			indexmid=index2;break;
		}

		indexmid=(index1+index2)/2;

		if(numbers[index1]==numbers[index2] && numbers[index1]==numbers[indexmid])
			return MinInorder(numbers,index1,index2);

		if(numbers[indexmid]>numbers[index1])
			index1=indexmid;
		else
			index2=indexmid;
	}

	return numbers[indexmid];
}

int _tmain(int argc, _TCHAR* argv[])
{


	return 0;
}

