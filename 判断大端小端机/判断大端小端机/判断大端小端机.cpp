// �жϴ��С�˻�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
�����������жϣ�char��1�ֽڣ�int��4�ֽ�
*/

#include<iostream>
using namespace std;
union bigsmall
{
	char ch;
	int i;
};

int _tmain(int argc, _TCHAR* argv[])
{
	union bigsmall ooo;
	ooo.i=1;

	/*
	1�ı�ʾӦ���� 0X0001
	�������С�˻�,��ô
	��----->��  ��ַ
	0  0  0  1
	������ڴ�˻�

	��-----��
	1 0  0  0

	����ȡ��ʱ���Ǵӵ�ֵַȡch,����ch����0�Ļ����Ǵ�˻�������1�Ļ����ǵͶ˻�
	*/
	cout<<(int)(ooo.ch)<<endl;

	system("pause");
	return 0;
}

