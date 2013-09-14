// 59.不能被继承的c++类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
/*
1.最直观的一种方法，因为累被继承的话，派生类构造函数会调用基类构造函数，当基类构造函数不能被调用时基类就不能被继承，所以可以把
	基类构造、析构都声明为private函数，但是这样一来，也不能创建这个类的对象了，这样这个类没有一点用处，
2.根据友元类可以访问它的私有成员的性质，可以这样定义
*/

//1.第一种
class Base1
{
private:
	Base1(){}
	~Base1(){}
};

//2.第2种，定义1个虚继承，如a->b,a->c, b,c->d，此时b和c都虚继承a,但是d中只有1份a，这是d不是通过b,c来调用a的构造函数，而是直接调用a的构造函数

//B类声明
class B;
class A
{
public:
	friend class B;

private:
	A(){cout<<"A"<<endl;}
	~A(){}
};

class B: public virtual A  //此时B是A的友元函数，所以B是可以的
{
public:
	B(){cout<<"B"<<endl;}
	~B(){}
};

/* B是不能被继承的
class C:public B
{

};
*/

/*
因为B是虚继承自A，并且B是A的友元函数，那么B在自己的成员函数中时可以访问A的私有成员的，即B的构造函数能调用A的构造函数
	但是因为A->B->C,因为虚继承的关系，那么C就要自己去分别调用A和B的构造函数，明显A的不行
	同时B也可以实例化
	*/

int _tmain(int argc, _TCHAR* argv[])
{
	B b;

	system("pause");
	return 0;
}

