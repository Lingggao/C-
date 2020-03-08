/*
	Day_2_6_20200212
	C++ ǿ������ת��
*/
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

void Function(int& a)
{
	cout << "Function: " << a << endl;
	return;
}

int main()
{
	/*
	    1.C ǿ������ת��: type val = (type)xxx;
		2.C++ ǿ������ת����
		    1) static_cast    ������ʽ����,���ô�ת��
			2) dynamic_cast    *��ʱ��ѧ* ��Ҫ�������μ������ת��������ת����������������֮��Ľ���ת��
			3) reinterpret_cast    ����ʽ������,�޷�ʹ�� static_cast,��Ҫʹ�ô�ת��
			4) const_cast    ���ڰ��ѳ���,ֻ��Ӧ����ָ�������
		3.����������ʹ��ǿ������ת��

	*/

	float a = 5.5;
	int b = 6;

	/* ��ʽ����ת�� */
	b = static_cast<int>(a);
	a = static_cast<float>(b);

	/* ���ת�������ʹ�� static_cast */
	void* p = NULL;
	int* q = NULL;
	p = q;
	//q = p;    Error 0513 ���ܽ� "void *" ���͵�ֵ���䵽 "int *" ���͵�ʵ��
	p = static_cast<void*>(q);    //Ok
	q = static_cast<int*>(p);    //Ok

	/* ʵ�� 1 */
	int x = 10;
	int y = 3;
	float z = x / y;    //����ֵΪ 3.333...,ʵ��Ϊ 3
	cout << "z = " << z << endl;
	cout << "z = " << static_cast<float>(x) / y << endl;    //Ok

	/* ʵ�� 2 */
	//char* c = malloc(100);    Error 0144 "void *" ���͵�ֵ�������ڳ�ʼ�� "char *" ���͵�ʵ��
	char* c = static_cast<char*>(malloc(100));    //Ok


	/* ����ʽ����ת�� */
	int s[5] = { 1,2,3,4,5 };
	//int* ip = (int*)((int)a + 1);    Error
	int* ip = reinterpret_cast<int*>((reinterpret_cast<int>(s) + 1));    //Ok


	/* ���ѳ��� */
	//const һ�����ɸ�
	const int co = 5;
	//int* cop = static_cast<int*>(&co);    Error 0694 static_cast �޷��������������������޶���

	//Function(co);    Error 0433 �� "int &" ���͵����ð󶨵� "const int" ���͵ĳ�ʼֵ�趨��ʱ���޶���������
	Function(const_cast<int&>(co));    //�ѳ�,Ok

	int& rco = const_cast<int&>(co);
	rco = 7;
	cout << "rco = " << rco << endl;    //rco ��Ϊ 7
	cout << "co = " << co << endl;    //co ��ȻΪ 5
	cout << "&rco = " << &rco << "\t&co = " << &co << endl;    //�� rco �� co ���ߵ�ַ��ͬ

	/*
	    Depending on the type of the referenced object,
		a write operation through the resulting pointer,
		reference, or pointer to data member might produce undefined behavior.
	*/
	
	return 0;
}
