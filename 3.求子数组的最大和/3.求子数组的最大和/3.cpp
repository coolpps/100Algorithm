/*
	�����������������
	�����Ҫ����������,p��q,����ÿһ��pǰ��,qָ���ʱȡ�����ֵ�ĵط���sum��¼�ͣ���sum<0ʱҪ�ǵ���0
*/
#include<iostream>
#include<limits>
using namespace std;
void print(int* a,int n)
{
	int i,j,sum,temp_max;
	int begin,end;

	//sum������¼���ֵ��temp_max������¼��iλ�õ����ֵ,begin������¼���������Ŀ�ʼ,end������¼���� 
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
		else if(temp_max<0)//С��0��,ȫ����Ҫ
		{
			temp_max=0;
			begin=i+1;//��ʱj������¼���������ǰ���һ��Ԫ��
		}
		i++;
	}

	cout<<sum<<endl;
	

	//��ӡ���������
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