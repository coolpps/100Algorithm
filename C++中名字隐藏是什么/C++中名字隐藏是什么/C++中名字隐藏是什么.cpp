// C++������������ʲô.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

������ͨ��һ������������C++�е��������ء���C++�У����һ��������һ�����صķ����� ������һ����ȥ�̳�������д(����)�Ǹ��������������д���е����ط����� ����δ����д�ķ�������Ϊ������ͬ�������أ��Ӷ�ʹ�����������в��ɼ���

�뿴���ӣ�

class FirstClass{
public:
    virtual void MethodA(int);
    virtual void MethodA(int, int);
};
void FirstClass::MethodA(int i){
    cout<<"ONE"<<endl;
}
void FirstClass::MethodA(int i, int j){
    cout<<"TWO"<<endl;
}
�������������������(���صķ���)���������������������дһ�������ĺ����� �������ô����

class SecondClass : public FirstClass{
public:
    void MethodA(int);
};
void SecondClass::MethodA(int i){
    cout<<"THREE"<<endl;
}

int main (){
    SecondClass a;
    a.MethodA(1);
    a.MethodA(1, 1);
    return 0;
}
�����main�����У���2��MethodA�ڱ���ʱ�ᱨ����ʾû����֮ƥ��ĺ����� ������Ϊ����������MethodA�����������ǲ��ɼ��ģ�������������ء�

�����������麯���޹ء����Բ��ܻ����������������ǲ����麯���� �����ﶼ�ᷢ���������ء������������������һ���ǽ�2��������MethodA��һ�����֣� ��ô�����������оͿɼ��ˡ������Ǽ�Ȼ������MethodA��˵������ֻ�ǲ�����ͬ�� ��ʵ����Ӧ����������ͬ�������Ƶ��µġ����Ի������ֲ����Ǹ��ð취����ˣ� ����һ����õڶ��ַ�����������������д���е����غ�����