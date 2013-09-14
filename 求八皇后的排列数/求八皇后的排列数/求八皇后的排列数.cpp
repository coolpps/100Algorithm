// ��˻ʺ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
������8*8��������ʾ8�ʺ��к��ж���1-8����ʾ,��(1,1)->(8,8),
�������еĵݹ飬��ÿ�����µݹ�1�У���ÿ����8������Է��ã��������������еĵ㲻��ͬһ�У�ͬһ�л�Խ��߾ʹ洢�����ŵݹ���һ�У������ǲ���
�洢��,������һ���ڵ�
*/

#include<iostream>
#include<utility>
#include<list>
using namespace std;

//ͬһ��
bool hang(std::list< pair<int,int> >& path,int row)
{
	//���path����Ԫ�ص�firstֵ��ͬ����ͬһ��
	for(std::list< pair<int,int> >::iterator iv=path.begin();iv!=path.end();++iv)
		if(iv->first==row)
			return true;

	return false;
}

//ͬһ��
bool lie(std::list< pair<int,int> >& path,int column)
{
	for(std::list< pair<int,int> >::iterator iv=path.begin();iv!=path.end();++iv)
		if(iv->second==column)	
			return true;
		
	return false;
}

//ͬһ �Խ���,ǰ���ǲ���ͬһ�в���ͬһ��
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
//�ݹ�̫�ർ�µ�ջ����������󲻳����������������һ�ַ���������
void EightQueen(int row,std::list< pair<int,int> >& path)//��row��
{
	//��,��
	if(row<=8)
	{
		++count;
		for(int column=1;column<=8;++column)
		{
			//��(row,column)
			if(!lie(path,column) && !duijiaoxian(path,row,column) )
			{
				path.push_back(make_pair(row,column));
				EightQueen(row+1,path);
				path.pop_back();
			}
		}
	}
	else//����9���ˣ�˵�������8�ж������ͬһ�С��кͶԽ��ߣ���ӡ
	{
		cout<<"��"<<++count<<"������";
		for(std::list< pair<int,int> >::iterator iv=path.begin();iv!=path.end();++iv)
			cout<<"("<<iv->first<<","<<iv->second<<")"<<"   ";
		cout<<"------------------------"<<endl;
	}
}


/*
������һ�ַ���,��Ϊ��ͬ�У����Ƕ���1������a[1-8]������Ϊ��ͬ�У���a[1-8]����1-8��ʾ�У����ھ��Ƕ�������ȫ���У����ÿ��ȫ��������
����һ���Խ����ϼ�a[i]-a[j]/(i-j)==-1,1����ô����һ�����з�ʽ
*/


bool duijiaoxian2(int* a)
{
	for(int i=1;i<=8;++i)//��
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
		//�ж����������㲻�ڶԽ�����
		//�ж�a[1-8]�ǲ���������������
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


//�κ��εĴ��� 
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

	//92�ֽⷨ 
	EightQueue2(a,1,8);
	//HeEightQueen();

	cout<<count<<endl;
	system("pause");
	return 0;
}

