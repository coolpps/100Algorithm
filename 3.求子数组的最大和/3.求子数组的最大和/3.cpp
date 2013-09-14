/*
	求连续子数组的最大和
	这个主要是设置两个,p和q,其中每一次p前进,q指向此时取得最大值的地方，sum记录和，当sum<0时要记得清0
*/
#include<iostream>
#include<limits>
using namespace std;
void print(int* a,int n)
{
	int i,j,sum,temp_max;
	int begin,end;

	//sum用来记录最大值，temp_max用来记录到i位置的最大值,begin用来记录最大子数组的开始,end用来记录结束 
	sum=numeric_limits<int>::min();
	temp_max=0;
	i=0;
	begin=0;
	while(i<n)
	{
		temp_max+=a[i];
		if(temp_max>sum)
		{
			sum=temp_max;
			end=i;
		}
		else if(temp_max<0)//小于0了,全部不要
		{
			temp_max=0;
			begin=i+1;//此时j用来记录最大子数组前面的一个元素
		}
		i++;
	}

	cout<<sum<<endl;
	

	//打印最大子数组
	while((sum-a[end])!=0)
	{
		cout<<a[end]<<" ";
		
		sum-=a[end];
		end--;
	}
	cout<<a[end]<<endl;
	cout<<endl;
	
}

int main()
{
	int a[]={1,-2,3,10,-4,7,2,-5};
	int b[]={-1,22,-3,-4,-5,-6,-7,-8};

	print(b,8);
	system("pause");
}