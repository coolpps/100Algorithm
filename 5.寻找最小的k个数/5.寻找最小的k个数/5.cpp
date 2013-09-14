/*
这里用到partition算法，返回第k小的数，然后它前面的数都满足
*/
#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

int partition(int* a,int p,int r)
{
	/*
	srand((unsigned)(time(NULL)));
	int pos=rand()%(r-p)+p;

	int temp=a[pos];
	a[pos]=a[r];
	a[r]=temp;
	*/
	int i,j,key,temp;
	i=p-1;
	j=p;
	key=a[r];
	
	for(;j<r;j++)
	{
		if(a[j]<key)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return i+1;
}

int findk(int* a,int p,int r,int k)
{
	int q=partition(a,p,r);
	int i=q-p+1; // q是第i小的数在a[p]-a[r]中

	if(i==k)
		return q;
	else if(i>k)
		findk(a,p,q-1,k);
	else
		findk(a,q+1,r,k-i);
}
int main()
{
	int a[]={1,6,3,8,5,4,2,7};

	int k;
	cin>>k;

	int pos=findk(a,0,7,k);
	for(int i=0;i<=pos;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	system("pause");
}