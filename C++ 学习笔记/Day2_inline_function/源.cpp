/*
	Day_2_5_20200212
	C++ ��������
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define SQR(i) (i)*(i)    //�꺯��
/*
    �ŵ�:������Ƕ,������ú���
	ȱ��:���ײ������塢����ʹ���� text ��������󡢲���������ͼ��
*/

int Sqr(int i)    //����
{
	return i * i;
}
/*
    �ŵ�:������һ�θ߶ȳ�����߼������ײ������塢����text�����
	ȱ��:��������ʱ����ѹջ���ջ�Ŀ���
*/

inline int InlineSqr(int i)    //��������
{
	return i * i;
}
//���к꺯���뺯�����ŵ�

/*
    1.���ܽ����еĺ����趨Ϊ��������
	2.inline �������������Ľ���
	3.�� inline -> ���ܻ����� | ���� inline -> һ����������
	4.Google ��׼:������ 10 �л�����ʱ�ſ��Զ���Ϊ��������
	5.HUAWEI ��׼:5 ��
*/

int main()
{
	int i = 0;
	while (i < 5)
		cout << SQR(i++) << endl;

	cout << endl;

	i = 0;
	while (i < 5)
		cout << Sqr(i++) << endl;

	cout << endl;

	i = 0;
	while (i < 5)
		cout << InlineSqr(i++) << endl;

	return 0;
}
