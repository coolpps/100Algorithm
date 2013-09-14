// 写一个名为my2DAlloc的函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

这道题目最简单的方法就是先开一个数组来存储指向每一行的指针， 然后再为每一行动态地分配空间。这是非常常见的动态申请二维数组空间的方法：

int** My2DAlloc(int rows, int cols){
    int **arr = (int**)malloc(rows*sizeof(int*));
    for(int i=0; i<rows; ++i)
        arr[i] = (int*)malloc(cols*sizeof(int));
    return arr;
}
上述方法使用了(rows+1)次的malloc，malloc使用过多会影响程序的运行效率， 那么有没有办法减少malloc的使用呢。

虽然我们做的事情是动态申请二维数组空间，但这些申请的空间本质上是一维， 只不过有些空间存储了地址，而有些空间则存储了数据。比如上面的方法， 申请了一个长度为rows的一维数组，里面存放的是指针(int*)，指向每一行的地址。 然后又申请了rows*cols大小的空间，里面存放的是整型数据(int)。既然如此， 我们一次性将这么多的空间申请下来，然后在该存放地址的空间存放地址， 在该存放数据的空间存放数据就OK了。

我们需要存储指向每一行的地址，大小为：

int header = rows * sizeof(int*);
同时需要存储rows*cols的整型数据，大小为：

int data = rows * cols * sizeof(int);
我们一次性将这些空间申请下来：

int **arr = (int**)malloc(header + data);
由于前面rows * sizeof(int*)的大小存放的是指针，因此arr类型是int**。 而跨过rows个单元后，后面存放的是整型数据，因此需要将其类型转为int*：

int *buf = (int*)(arr + rows);
最后，从buf指向的地址开始，每cols个单元组成一行，将行首地址存放到arr 的相应位置即可。

for(int i=0; i<rows; ++i)
    arr[i] = buf + i * cols;
代码如下：

int** My2DAlloc1(int rows, int cols){
    int header = rows * sizeof(int*);
    int data = rows * cols * sizeof(int);
    int **arr = (int**)malloc(header + data);
    int *buf = (int*)(arr + rows);
    for(int i=0; i<rows; ++i)
        arr[i] = buf + i * cols;
    return arr;
}
这样一来，我们使用一次的malloc就可以动态地申请二维数组空间， 并且可以用arr[i][j]对数组元素进行访问。


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