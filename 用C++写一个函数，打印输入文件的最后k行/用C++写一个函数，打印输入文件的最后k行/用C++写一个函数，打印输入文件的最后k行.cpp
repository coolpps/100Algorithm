// 用C++写一个函数，打印输入文件的最后k行.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
这题，可以首先统计文件一共多少行，然后略过前面n-k行，
我们希望可以只打开文件一次，就可以输出文件中的最后k行。 我们可以开一个大小为k的字符串数组，然后将文件中的每一行循环读入。
怎么样循环读入呢？就是将k行字符串保存到字符串数组后， 在读第k+1时，将它保存到数组的第1个元素，依次类推。这样一来， 实际上文件中第i行的字符串会被保存到数组的第i%k的位置。
最后当文件读完时， 数组保存的就是最后k行的字符串。当然了，它的开始位置不是0，而是i%k。
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void printlastlines(ifstream &fin,int k)
{
	string *line=new string[k];

	int lines=0;
	string tmp;
	while(getline(fin,tmp))
	{
		line[lines%k]=tmp;
		++lines;
	}

	int start,cnt;
	if(lines<k)
	{
		start=0;
		cnt=lines;
	}
	else
	{
		start=lines%k;
		cnt=k;
	}

	for(int i=0;i<cnt;i++)
		cout<<line[(i+start)%k]<<endl;

	delete []line;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("13.1.in");

	int k=4;
	printlastlines(fin,k);
	fin.close();

	system("pause");
	return 0;
}

