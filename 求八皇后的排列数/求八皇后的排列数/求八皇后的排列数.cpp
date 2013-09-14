// 求八皇后的排列数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
我们以8*8矩阵来表示8皇后，行和列都用1-8来表示,即(1,1)->(8,8),
可以逐行的递归，即每次向下递归1行，最每行有8个点可以放置，如果满足和上面行的点不在同一行，同一列或对角线就存储，接着递归下一行，否则是不能
存储的,遍历下一个节点
*/

#include<iostream>
#include<utility>
#include<list>
using namespace std;

//同一行
bool hang(std::list< pair<int,int> >& path,int row)
{
	//如果path中有元素的first值相同就是同一行
	for(std::list< pair<int,int> >::iterator iv=path.begin();iv!=path.end();++iv)
		if(iv->first==row)
			return true;

	return false;
}

//同一列
bool lie(std::list< pair<int,int> >& path,int column)
{
	for(std::list< pair<int,int> >::iterator iv=path.begin();iv!=path.end();++iv)
		if(iv->second==column)	
			return true;
		
	return false;
}

//同一 对角线,前提是不再同一行不在同一列
bool duijiaoxian(std::list< pair<int,int> >& path,int x,int y)
{
	for(std::list< pair<int,int> >::iterator iv=path.begin();iv!=path.end();++iv)
	{
		int temp=(iv->first-x)/(iv->second-y);
		if(temp==1 || temp==-1)
			return true;
	}
	return false;
}

int count=0;
//递归太多导致的栈溢出。。。求不出来结果，不过这是一种方法。。。
void EightQueen(int row,std::list< pair<int,int> >& path)//第row行
{
	//行,列
	if(row<=8)
	{
		++count;
		for(int column=1;column<=8;++column)
		{
			//对(row,column)
			if(!lie(path,column) && !duijiaoxian(path,row,column) )
			{
				path.push_back(make_pair(row,column));
				EightQueen(row+1,path);
				path.pop_back();
			}
		}
	}
	else//到第9行了，说明上面的8行都满足非同一行、列和对角线，打印
	{
		cout<<"第"<<++count<<"种排列";
		for(std::list< pair<int,int> >::iterator iv=path.begin();iv!=path.end();++iv)
			cout<<"("<<iv->first<<","<<iv->second<<")"<<"   ";
		cout<<"------------------------"<<endl;
	}
}


/*
给出的一种方法,因为不同行，我们定义1个数组a[1-8]，又因为不同列，给a[1-8]分配1-8表示列，现在就是对它进行全排列，如果每个全排列满足
不在一个对角线上即a[i]-a[j]/(i-j)==-1,1，那么就是一种排列方式
*/


bool duijiaoxian2(int* a)
{
	for(int i=1;i<=8;++i)//行
	{
		for(int j=i+1;j<=8;j++)
			if( (i-j==a[i]-a[j])  || (i-j==a[j]-a[i]) )
				return true;
	}
	return false;
}

void EightQueue2(int *a,int begin,int end)
{
	if(begin==end)
	{
		//判断漫步满足足不在对角线上
		//判断a[1-8]是不是满足上述条件
		if(!duijiaoxian2(a))
		{
			count++;
			for(int i=1;i<=8;i++)
				cout<<"("<<i<<","<<a[i]<<")"<<" ";
			cout<<endl;
			return ;
		}

	}
	else if(begin<end)
	{
		for(int i=begin;i<=end;++i)
		{
			int temp=a[begin];
			a[begin]=a[i];
			a[i]=temp;

			EightQueue2(a,begin+1,end);

			temp=a[begin];
			a[begin]=a[i];
			a[i]=temp;
		}
	}

}


//何海涛的代码 
int g_number = 0;
 
void PrintQueen(int ColumnIndex[], int length)
{
    printf("Solution %d\n", g_number);
 
    for(int i = 0; i < length; ++i)
        printf("%d\t", ColumnIndex[i]);
   
    printf("\n");
}
bool Check(int ColumnIndex[], int length)
{
    for(int i = 0; i < length; ++ i)
    {
        for(int j = i + 1; j < length; ++ j)
        {
            if((i - j == ColumnIndex[i] - ColumnIndex[j])
                || (j - i == ColumnIndex[i] - ColumnIndex[j]))
            return false;
        }
    }
 
    return true;
}
void Permutation(int ColumnIndex[], int length, int index)
{
    if(index == length)
    {
        if(Check(ColumnIndex, length))
        {
            ++ g_number;
            PrintQueen(ColumnIndex, length);
        }
    }
    else
    {
        for(int i = index; i < length; ++ i)
        {
            int temp = ColumnIndex[i];
            ColumnIndex[i] = ColumnIndex[index];
            ColumnIndex[index] = temp;
 
            Permutation(ColumnIndex, length, index + 1);
 
            temp = ColumnIndex[index];
            ColumnIndex[index] = ColumnIndex[i];
            ColumnIndex[i] = temp;
        }
    }
}
 

void HeEightQueen()
{
    const int queens = 8;
    int ColumnIndex[queens];
    for(int i = 0; i < queens; ++ i)
        ColumnIndex[i] = i;
 
    Permutation(ColumnIndex, queens, 0);
}
 

 

int _tmain(int argc, _TCHAR* argv[])
{
	std::list< pair<int,int> > path;

	int a[9];
	for(int i=1;i<=8;i++)
		a[i]=i;

	//92种解法 
	EightQueue2(a,1,8);
	//HeEightQueen();

	cout<<count<<endl;
	system("pause");
	return 0;
}

