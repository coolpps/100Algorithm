/*
	5
	/ \
   2   6
    ����1����������������������2 5 6 ���������������Ҹ�����Ϊ��<��<��
	����Ǻ���������������������ǣ��������ǣ���������1�����ǾͲ��� 
*/
//��������Ԫ�ض���ͬ
#include<iostream>
using namespace std;

bool iis(int* a,int p,int r)  //a[p]--a[r]
{
	//�ȿ��������ǲ������� �� ��  ��
	//����������
	if(p==r)
		return true;
	
	int left,right;
	left=p;
	while(a[left]<a[r])
		left++;
	//���a[left]>a[r]
	right=left;

	while(a[right]>a[r])
		right++;
	if(right<r)
		return false;
	else if(right==r)//ò�������ˣ��������������ǲ�������
	{
		bool leftis=iis(a,p,left-1);
		bool rightis=iis(a,left,right-1);
		if(leftis && rightis)
			return true;
		else
			return false;
	}


}

int main(void)
{
	int a[]={5,7,6,9,11,10,8};
	int b[]={7,4,6,5};

	cout<<boolalpha;
	cout<<iis(a,0,6)<<endl;
	cout<<iis(b,0,3)<<endl;
	system("pause");
}