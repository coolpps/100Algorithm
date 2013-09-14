/*
	5
	/ \
   2   6
    这是1个二叉查找树，中序遍历是2 5 6 ，后续遍历是左右根，因为左<根<右
	如果是后续遍历结果则有左子树是，右子树是，若左右有1个不是就不是 
*/
//假设所有元素都不同
#include<iostream>
using namespace std;

bool iis(int* a,int p,int r)  //a[p]--a[r]
{
	//先看本序列是不是满足 左 右  根
	//先找左子树
	if(p==r)
		return true;
	
	int left,right;
	left=p;
	while(a[left]<a[r])
		left++;
	//最后a[left]>a[r]
	right=left;

	while(a[right]>a[r])
		right++;
	if(right<r)
		return false;
	else if(right==r)//貌似满足了，看看左右子树是不是满足
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