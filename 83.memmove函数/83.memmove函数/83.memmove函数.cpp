// 83.memmove����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void* memmove(void* dest,const void* src,size_t n)
{
	//Ҫ��src��dest�ǲ����ڴ��ص���
	void* ret=dest;
	//���ص�
	if( dest<src || (char*)dest>=((char*)src+n) )
	{
		while(n--)
		{
			*(char*)dest=*(char*)src;
			dest=(char*)dest+1;
			src=(char*)src+1;
		}
	}
	else//���ص�
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

