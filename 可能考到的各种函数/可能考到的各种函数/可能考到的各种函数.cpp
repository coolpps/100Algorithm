// ���ܿ����ĸ��ֺ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
����һЩ�ַ����ĺ���, strcpy,strcmp,strlen,strcat,strchr,strstr
*/
/*
�ڴ��һЩ����,memset,memmove,memcpy
*/

/*
�ַ���������ת����һЩ������atoi��itoa
*/

//1. char* strcpy(char* dest,const char* src)
char* strcpy(char* dest,const char* src)
{
	char* dst=dest;
	//�ȼ��ָ�����Ч��
	//1.��ò�Ҫʹ��!dest�����ģ�ǣ����char*��bool������ת��
	//2.��Ҫʹ��dest==0,ȱ�ٿ�ά����
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
	//Ҫ #include<assert.h>
	//��Ҫ��strlen(NULL)�Ǵ����
	assert(str!=NULL);

	int len=0;
	while(*str++!='\0')
		++len;
	return len;
}

//4. char* strcat(char* dest,char* src)
{
	//destҪ���㹻�ռ�����src,��㺯������֤������Գ��֤������ֻ�ǰ�s
	assert((dest!=NULL) && (src!=NULL));

	char* dst=dest;
	while(*dst++!='\0')��//�����ҵ�dest�Ľ�����
	while((*dst++=*src++)!='\0'); //Ȼ���src���ƽ�ȥ��֪������������
	*dst='\0';//���������
	return dest;
}

//5. char* strchr(const char* str,char c) ����str��c��һ�γ��ֵ�λ�ã����û�з���NULL
char* strchr(const char* str,char c)
{
	assert(str!=NULL); //str��Ҫ��NULL
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
	//1���ֽ�1���ֽڵĸ�ֵ
	unsigned int i=0;

	char* begin=(char*)s;
	while(i<n)
	{
		*(begin+i)=ch;
		++i;
	}
	return s;
}
//8. memmove����
void* memmove(void* dest,void* src,size_t n)
{
	//��Ҫ�Ƿ�ֹ�ڴ��ص�
	//dest��srcǰ����dest��src����󶼲��ص�,dest��src��ʱ�ص��ģ�Ҫ�Ӻ���ǰ����
	assert((dest!=NULL) && (src!=NULL));

	void* ret=dest;
	if(dest<=src && dest>=(src+n))//���ص�,��ǰ����ֵ
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
	else //���ص�
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

//9 .memcpy����
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

// 10. atoi����
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

	//ȥ��ǰ��ո�
	const char* p=str;
	while(*p++==' ');

	//�жϷ���λ 
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
			num=num*10+(*p-'0'); //���������ֵ�͸���Сֵ
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

