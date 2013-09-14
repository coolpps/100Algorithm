// 83.memmove函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void* memmove(void* dest,const void* src,size_t n)
{
	//要看src和dest是不是内存重叠的
	void* ret=dest;
	//无重叠
	if( dest<src || (char*)dest>=((char*)src+n) )
	{
		while(n--)
		{
			*(char*)dest=*(char*)src;
			dest=(char*)dest+1;
			src=(char*)src+1;
		}
	}
	else//有重叠
	{
		dest=(char*)dest+n-1;
		src=(char*)ssrc+n-1;

		while(n--)
		{
			*(char*)dest=*(char*)src;
			dest=(char*)dest-1;
			src=(char*)src-1;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

