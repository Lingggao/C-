/*
	Day_2_8_20200213
	C++ �����ռ�
*/
#include <iostream>
#include <algorithm>
#include "Dog.h"
#include "Cat.h"
#include "Apple.h"
using std::cin;
using std::cout;
using std::endl;

//ȫ�����������ռ�
int vi = 5;    //ȫ�ֱ���

/* namespace �Ƕ�ȫ�������ռ���ٴλ��� */
namespace Ling
{
	int a;
	void function()
	{
		cout << "Ling::function();" << endl;
		return;
	}
	//�����ռ�֧��Ƕ��
	namespace Gaaooo
	{
		int a;
	}
}
namespace Gao
{
	int a;
	void function()
	{
		cout << "Gao::function();" << endl;
		return;
	}
}

/* ���������ռ�����ʱ�����Զ��ϲ�,ʹ�ô����Կ��Ժܷ���Ľ���Э������ */
namespace Hello
{
	int x;
	//int y;    �ȼ��ڴ����
}
namespace Hello
{
	int y;
}

int main()
{
	/* Ĭ�� namespace:global��function */
	int* vp = &vi;
	int vi = 55;    //�ֲ�����
	cout << vi << endl;    //�ֲ������Ḳ��ȫ�ֱ���
    cout << *vp << endl;    //���ǿ���ʹ��ָ�� "���׳�н" ������ȫ�ֱ���

	/* :: -> �����������,�����ǰ��Ҫ��������ռ� */
	cout << ::vi << endl;    //���������ռ�

	using Ling::a;
	using namespace Gao;
	a = 9;
	cout << "Ling::a = " << Ling::a << endl << "Gao::a = " << Gao::a << endl;

	/* �����ռ�֧��Ƕ�� */
	Ling::Gaaooo::a = 8;
	cout << Ling::Gaaooo::a;

	/* ���������ռ��Զ��ϲ�,����Э������ */
	Hello::x = 5;
	Hello::y = 6;

	/* Э������ */

	//Dog d;    Error 0020 δ�����ʶ�� "Dog"
	Animal::Dog dog;    //Ok
	Fruit::Apple apple;    //Ok

	return 0;
}
