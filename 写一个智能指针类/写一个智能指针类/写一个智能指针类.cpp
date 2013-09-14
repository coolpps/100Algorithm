// 写一个智能指针类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


template<typename T>
class SmartPointer
{
public:
	SmartPointer(T* ptr)
	{
		ref=ptr;
		ref_count=new unsigned int;
		*ref_count=1;
	}

	SmartPointer(const SmartPointer<T>& sptr)
	{
		ref=sptr.ref;
		ref_count=sptr.ref_count;
		++*ref_count;
	}

	SmartPointer& operator=(const SmartPointer<T>& sptr)
	{
		if(this!=&sptr)
		{
			if(--*ref_count==0)
			{
				clear();
			}

			ref=sptr.ref;
			ref_count=sptr.ref_count;
			++*ref_count;
		}
	}

	~SmartPointer()
	{
		if(--*ref_count==0)
			clear();
	}

	T getValue(){return *ref;}

private:
	T* ref;
	unsigned int *ref_count;

private:
	void clear()
	{
		delete ref;
		delete ref_count;
		ref=NULL;
		ref_count=NULL;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

