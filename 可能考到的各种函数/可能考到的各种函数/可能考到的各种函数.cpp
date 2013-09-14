// 可能考到的各种函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
包括一些字符串的函数, strcpy,strcmp,strlen,strcat,strchr,strstr
*/
/*
内存的一些函数,memset,memmove,memcpy
*/

/*
字符串和数字转换的一些函数，atoi和itoa
*/

//1. char* strcpy(char* dest,const char* src)
char* strcpy(char* dest,const char* src)
{
	char* dst=dest;
	//先检查指针的有效性
	//1.最好不要使用!dest这样的，牵扯到char*到bool的类型转换
	//2.不要使用dest==0,缺少可维护性
	if((dest==NULL)|| (src==NULL))
		throw new std::exception("invalid parameter");

	while((*dst++=*src++)!='\0');
	return dest;
}

//2.int strcmp(const char* s1,const char* s2)
int strcmp(const char* s1,const char* s2)
{
	assert((s1!=NULL) && (s2!=NULL));

	while(*s1!='\0' && !s2!='\0' && *s1==*s2)
	{
		++s1; ++s2;
	}
	return *s1-*2;
}

//3. unsigned int strlen(const char* str)
{
	//要 #include<assert.h>
	//主要是strlen(NULL)是错误的
	assert(str!=NULL);

	int len=0;
	while(*str++!='\0')
		++len;
	return len;
}

//4. char* strcat(char* dest,char* src)
{
	//dest要有足够空间容纳src,这点函数不保证，程序猿保证，函数只是把s
	assert((dest!=NULL) && (src!=NULL));

	char* dst=dest;
	while(*dst++!='\0')；//首先找到dest的结束符
	while((*dst++=*src++)!='\0'); //然后把src复制进去，知道遇到结束符
	*dst='\0';//补齐结束符
	return dest;
}

//5. char* strchr(const char* str,char c) 查找str中c第一次出现的位置，如果没有返回NULL
char* strchr(const char* str,char c)
{
	assert(str!=NULL); //str不要是NULL
	while(*str!='\0' && *str!=c)
		++str;
	return (*str=='\0')?(NULL):(str);
}

//6. char* strstr(char* str1,char* str2)
char* strstr(const char* str1,char* str2)
{
	assert((str1!=NULL) && (str2!=NULL));

	int n;
	if(*str2!='\0')
	{
		while(*str1!='\0')
		{
			for(n=0;*(str1+n)==*(str2+n);++n)
				if(*(str2+n+1)=='\0')
					return (char*)str1;
			++str1;
		}
		return NULL;
	}
	else
		return (char*)str1;
}

//7. void* memset(void* s,char ch,size_t n)
{
	//1个字节1个字节的赋值
	unsigned int i=0;

	char* begin=(char*)s;
	while(i<n)
	{
		*(begin+i)=ch;
		++i;
	}
	return s;
}
//8. memmove函数
void* memmove(void* dest,void* src,size_t n)
{
	//主要是防止内存重叠
	//dest在src前或者dest在src整体后都不重叠,dest在src中时重叠的，要从后向前复制
	assert((dest!=NULL) && (src!=NULL));

	void* ret=dest;
	if(dest<=src && dest>=(src+n))//不重叠,从前往后赋值
	{
		char* chardest=(char*)dest;
		char* charsrc=(char*)src;

		while(n--)
		{
			*chardest=*charsrc;
			++chardest;
			++charsrc;
		}
	}
	else //有重叠
	{
		char* chardest=(char*)dest+n-1;
		char* charsrc=(char*)src+n-1;

		while(n--)
		{
			*chardest=*charsrc;
			--charsrc;
			--chardest;
		}
	}
	return ret;

}

//9 .memcpy函数
void* memcpy(void* dest,void* src,size_t n)
{
	assert((dest!=NULL) && (src!=NULL) && (n>0));

	void* ret=dest;

	char* chardest=(char*)dest;
	char* charsrc=(char*)src;
	while(n--)
		*chardest++=*charsrc++;
	return ret;
}

// 10. atoi函数
long long strtoint(const char* str,bool minus)
{
	long long num=0;

	while(*str!='\0')
	{
		if(*str>='0' && *str<='9')
		{
			int flag=minus?-1:1;
			num=10*num+flag*(*str-'0');

			if((minus==false && num>0X7FFFFFFFF) || (minus==true && num<(signed int)0X80000000))
			{
				num=0;break;
			}
			str++;
		}
		else
		{
			num=0;
			break;
		}
	}
	if(*str=='\0')
		g_invalid=false;
}
bool g_invalid=true;
int atoi(const char* str)
{
	long long num=0;

	assert((str!=NULL));
	if(*str!='\0')
	{
		bool minus=false;
		if(*str=='-')
		{
			minus=true;
			++str;
		}
		else if(*str=='+')
			++str;

		if(*str!='\0')
			num=strtoint(str,minus);
	}
	retutrn (int)num;
}

int myaotoi(const char* str)
{
	g_valid=false;;
	if(str==NULL || strlen(str)<=0)
	{
		g_valid=false;
		return 0;
	}

	//去掉前面空格
	const char* p=str;
	while(*p++==' ');

	//判断符号位 
	int sign=1;
	if(*p=='-')
	{
		sign=-1;
		++p;
	}
	else
	{
		sign=1;
		++p;
	}

	int num=0;
	while(*p!='\0')
	{
		if(*p>='0' && *p<='9')
		{
			num=num*10+(*p-'0'); //考虑正最大值和负最小值
			if(((sign==1) && (unsigned int)num>0x7FFFFFFF) ||  ((sign==-1) && num<0x80000000))
			{
				num=0;
				break;
			}
			++p;
		}
		else
		{
			num=0;
			break;
		}
	}

	if(*p=='\0')
		g_invalid=false;

	return (int)(sign*num);
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

