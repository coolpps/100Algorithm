/*
不能使用乘除法，不能使用for while if else withc等，以及条件判断语句
*/
#include<iostream>
using namespace std;

int cal(int n,int& sum)
{
	(n>0) && cal(n-1,sum);
	return sum+=n;
}

int main()
{
	int sum=0;
	int n;
	
	cin>>n;
	cout<<cal(n,sum)<<endl;

	system("pause");
}