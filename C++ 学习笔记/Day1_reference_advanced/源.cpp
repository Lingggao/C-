/*
	Day_1_7_20200211
	C++ �߼�����֪ʶ
*/
#include <iostream>
using namespace std;

int main()
{
	/*1.���Զ���ָ�������,���ܶ������õ�����*/
	int a = 5;
	int* p = &a;
	int** pp = &p;
	int**& rp = pp;    //Ok
	cout << **rp << endl;
	//int*&& rrp = rp;    Error

	/*2.���Զ���ָ���ָ��,���ܶ������õ�ָ��*/
	int b = 4;
	int& rb = b;
	int* bp = &rb;    //Ok
	//int&* bpp = &rb;    Error
	//int &* -> Error # int *& -> Ok

	/*3.���Զ���ָ������,���ܶ�����������,���Զ�����������*/
	int m = 1, n = 2, t = 3;
	int* sp[] = { &m,&n,&t };    //Ok
	//int& rp[] = { m,n,t };    Error,ԭ��:int& �׵�ַΪ int&*
	int arr[5] = { 1,2,3,4,5 };
	//int*& rarr = arr;    Error,ԭ��:int* �� int[X] ����ȫ�ȼ�
	int(&rarr)[5] = arr;    //OK

	return 0;
}
