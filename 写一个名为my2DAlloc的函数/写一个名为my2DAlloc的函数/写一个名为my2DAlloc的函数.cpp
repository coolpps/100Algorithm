// дһ����Ϊmy2DAlloc�ĺ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

�����Ŀ��򵥵ķ��������ȿ�һ���������洢ָ��ÿһ�е�ָ�룬 Ȼ����Ϊÿһ�ж�̬�ط���ռ䡣���Ƿǳ������Ķ�̬�����ά����ռ�ķ�����

int** My2DAlloc(int rows, int cols){
    int **arr = (int**)malloc(rows*sizeof(int*));
    for(int i=0; i<rows; ++i)
        arr[i] = (int*)malloc(cols*sizeof(int));
    return arr;
}
��������ʹ����(rows+1)�ε�malloc��mallocʹ�ù����Ӱ����������Ч�ʣ� ��ô��û�а취����malloc��ʹ���ء�

��Ȼ�������������Ƕ�̬�����ά����ռ䣬����Щ����Ŀռ䱾������һά�� ֻ������Щ�ռ�洢�˵�ַ������Щ�ռ���洢�����ݡ���������ķ����� ������һ������Ϊrows��һά���飬�����ŵ���ָ��(int*)��ָ��ÿһ�еĵ�ַ�� Ȼ����������rows*cols��С�Ŀռ䣬�����ŵ�����������(int)����Ȼ��ˣ� ����һ���Խ���ô��Ŀռ�����������Ȼ���ڸô�ŵ�ַ�Ŀռ��ŵ�ַ�� �ڸô�����ݵĿռ������ݾ�OK�ˡ�

������Ҫ�洢ָ��ÿһ�еĵ�ַ����СΪ��

int header = rows * sizeof(int*);
ͬʱ��Ҫ�洢rows*cols���������ݣ���СΪ��

int data = rows * cols * sizeof(int);
����һ���Խ���Щ�ռ�����������

int **arr = (int**)malloc(header + data);
����ǰ��rows * sizeof(int*)�Ĵ�С��ŵ���ָ�룬���arr������int**�� �����rows����Ԫ�󣬺����ŵ����������ݣ������Ҫ��������תΪint*��

int *buf = (int*)(arr + rows);
��󣬴�bufָ��ĵ�ַ��ʼ��ÿcols����Ԫ���һ�У������׵�ַ��ŵ�arr ����Ӧλ�ü��ɡ�

for(int i=0; i<rows; ++i)
    arr[i] = buf + i * cols;
�������£�

int** My2DAlloc1(int rows, int cols){
    int header = rows * sizeof(int*);
    int data = rows * cols * sizeof(int);
    int **arr = (int**)malloc(header + data);
    int *buf = (int*)(arr + rows);
    for(int i=0; i<rows; ++i)
        arr[i] = buf + i * cols;
    return arr;
}
����һ��������ʹ��һ�ε�malloc�Ϳ��Զ�̬�������ά����ռ䣬 ���ҿ�����arr[i][j]������Ԫ�ؽ��з��ʡ�


int **My2DAlloc(int rows,int cols)
{
		int header=rows*sizeof(int*);
		int data=rows*cols*sizeof(int);
		int **arr=(int**)malloc(header+data);
		int* buf=(int*)(arr+rows);
		for(int i=0;i<rows;i++)
			arr[i]=buf+i*cols;
		return arr;
}