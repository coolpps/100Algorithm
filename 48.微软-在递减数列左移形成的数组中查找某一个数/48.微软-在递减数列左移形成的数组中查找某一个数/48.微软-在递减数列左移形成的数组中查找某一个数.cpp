// 48.΢��-�ڵݼ����������γɵ������в���ĳһ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

/*
��a[0....n-1],��a[0]>a[1]>a[2]>.....>a[n-1]������mλ�����Ϊa[m],a[m+1],..a[n-1],a[0],...a[m-1],��a[m]>a[m+1]>...>a[n-1],a[0]>a[1]>a[2]>....>a[m-1]
��a[m] a[m+1] a[m+2] ....a[n-1] a[0] a[1]....a[m-1] 
-->
   0      1      2        n-m-1  n-m  n-m+1     n-1
   ��ô��  a[0]>a[2]>....>a[n-m-1],a[n-m]>a[n-m+2]>...>a[n-1]ͬʱ  a[n-m]��������,a[n-m]>a[n-m-1] && a[n-m]>a[n-m+1],������������������ôa[n-m]���Ƿֽ��


   ���Ȳ��ҷֽ�㣬�ֽ���������a[n-m-1]��a[n-m],��ôͳһ�涨a[n-m]�Ƿֽ��
   ���ö��ֵķ�ʽ����,����Ԫ��һ�����ڣ�Ԫ����key
   low=0,high=n-1
   mid=(low+high);

   ���������¼��ֿ���
   1. min������� ,��a[mid]<=a[0]
      ���key=a[mid]����
	  ���key>a[mid] && key<=a[0]����ô��������߲��ң������1���ݼ������в����������Զ���
	  ���key>a[mid] && key>a[0]�Ļ�������Ҫ���ֽ���������  low=�ֽ��  high=n-2
	  ���key<a[mid],��ôҪ��[mid,�ֽ��]����  low=mid+1,high=�ֽ��
   2.min�����ұ�,��a[mid]>a[0]�Ļ���
	  ���key=a[mid]
	  ���k<a[mid] && key>a[0],��ô������[mid+1,high]����
	  ���k<a[mid] && key<a[0]�Ļ�����[0,�ֽ�����]
	  ���k>a[mid],��[�ֽ��,mid-1]����
*/

 void chazhao(int* a,int p,int r,int key)
{
	//1.���Ȳ��ҷֽ�㣬�����ֽ����������������߷ֽ��a[i]<a[i-1] && a[i]<a[i+1],�ұ߷ֽ��  a[i]>a[i-1] && a[i]>a[i+1]
	//�������Ǹ����Ƶģ��϶��ֽ�㲻���ڿ�ʼ���п����ڽ��� 5 4 3 2 1 6,��1 6 5 4 3 2,�����ҵ�1�Ļ�
	int pos=-1;
	int low=p;
	int high=r;

	while(low<=high)
	{
		int mid=(low+high)/2;
		if(mid==p && a[mid]<a[mid+1]) //��ô1λ�þ��Ƿֽ��
		{
			pos=p+1;
			break;
		}else if(mid==r && a[mid]>a[mid-1])//r�����Ƿֽ��
		{
			pos=r;break;
		}
		else//mid������β 
		{
			if(a[mid]<a[mid-1] && a[mid]<a[mid+1])
			{
				pos=mid+1;break;
			}
			if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
			{
				pos=mid;break;
			}

			if(a[mid]>a[p])//���������Ұ벿�֣�Ӧ������
				high=mid-1;
			else
				low=mid+1;
		}
	}

	//pos������ȷ֤��
	//cout<<a[pos]<<endl;

	//����͸ò���key��
	low=p;
	high=r;

	while(low<=high)
	{
		int mid=(low+high)/2;

		if(a[mid]==key)
		{
			cout<<"�ҵ�"<<key<<endl;
			break;
		}
		else if(a[mid]<key)
		{
			//>key��2���������Ϊkeyһ�����ڣ����ڿ�mid��������߻����ұ��� 
			if(a[mid]<=a[p])//������� ,��Ϊkey>a[mid],����key�п�������߻����ұߣ��Ƚ�key��a[0]
			{
				if(key<=a[p])//���������
					high=high-1;
				else//���ұ��� 
				{
					low=pos;
					high=r;
				}
			}
			else //mid���ұߵ������
			{
				low=pos;
				high=mid-1;
			}
		}else //key<a[mid]
		{
			if(a[mid]<=a[p])//mid�����,key<a[mid]
			{
				low=mid+1;
			}
			else//key<a[mid]����mid���ұ�
			{
				if(key>a[p])//key>a[p]�Ļ��������ұ�
					low=mid+1;
				else
				{
					low=p;
					high=pos-1;
				}
			}
		}
	}

	
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={4,3,2,1,6,5};

	int b[]={1,6,5,4,3,2};

	int c[]={5,4,3,2,1,6};


	int i;

	cout<<boolalpha;
	for(i=0;i<6;i++)
		chazhao(c,0,5,c[i]);

	system("pause");
	return 0;
}

