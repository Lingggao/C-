/*
	Day_2_3_20200212
	C++ �ڴ����
*/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	/* new,delete (Keywork �ؼ���) >= malloc,free (�⺯��) */

	/* ���ٵ������ռ� */

	//C
	int* p = (int*)malloc(sizeof(int));
	int* q = static_cast<int*>((int*)malloc(sizeof(int)));    //C++ǿ������ת��

	//C++
	//int
	int* m = new int(3);
	cout << *m << endl;
	*m = 5;
	cout << *m << endl;

	//string
	string* mm = new string("Hello ");
	cout << *mm;
	*mm = "World!";
	cout << *mm << endl;

	//struct
	struct Student {
		int age;
		string name;
	};
	Student* gkx = new Student{ 19,"Ling Gao" };
	cout << "\nStudent\nName:" << gkx->name << "\nAge:" << gkx->age << endl;

	/* ���ٶ�����ռ� */
	//char array
	char* ap = new char[20];
	/* 
	errno_t __cdecl strcpy_s(
        _Out_writes_z_(_SizeInBytes) char*       _Destination,
        _In_                         rsize_t     _SizeInBytes,
        _In_z_                       char const* _Source
        );
	*/
	strcpy_s(ap, 20, "ABCDEFG");    //strcpy_s() �� strcpy() ����ȫ
	cout << ap << endl;

	//int array
	int* ip = new int[3];
	memset(ip, 0, sizeof(int[3]));
	for (int i = 0; i < 3; i++)
		cout << ip[i] << endl;

	//ָ������
	int** pp = new int* [3];
	
	//int[][] ��ά����
	//int* p = new int[3][4];    Error E0144 "int (*)[4]" ���͵�ֵ�������ڳ�ʼ�� "int *" ���͵�ʵ��
	int(*ppa)[4] = new int[3][4]{ {0} };
	for (int i = 0; i < sizeof(int[3][4]) / sizeof(int[4]); i++)
		for (int j = 0; j < 4; j++)
			cout << ppa[i][j] << " ";


	/* �ͷ��ڴ�ռ� */
	int* dp = new int[100];
	delete []dp;    //����ʹ�� delete dp,����ֻ�ͷ������һ��Ԫ�ء���ά�����ͷ�ʱҲֻдһ��[]

	/* malloc ���ٵ��ڴ�ռ䲻Ҫʹ�� delete �ͷ�,new ���ٵĿռ䲻Ҫʹ�� free �ͷ� */

	/* �쳣 */
	try
	{
		int* f = new int[100];
		delete []f;
	}
	catch (const std::bad_alloc e) {
		cout << "new Error" << endl;
		cout << e.what() << endl;
		return -1;
	}

	//������ʹ�������� C++ �쳣����
	int* ff = new (std::nothrow) int[10];    //���׳��쳣
	if (ff == NULL)    //�������ʧ��,��ֹ���г���
		return -1;
	

	//�������н���ǰ���ͷŵ������ڴ�ռ�
	free(p);
	free(q);
	delete m;
	delete mm;
	delete gkx;
	delete []ap;
	delete []ip;
	delete []pp;
	delete []ppa;
	delete []ff;
	return 0;
}
