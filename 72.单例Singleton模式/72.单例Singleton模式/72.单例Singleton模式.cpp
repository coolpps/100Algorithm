// 72.����Singletonģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


class Singleton
{
public:
	//static Singleton* ptr;

	static Singleton* getInstance()
	{
		if(!ptr)
			ptr=new Singleton;
		return ptr;
	}

	sstatic void deleteInstance()
	{
		delete ptr;
	}
private:
	static Singleton* ptr;
	Singleton(){}
	~Singleton(){}
};

Singleton::Singleton *ptr=NULL;

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

