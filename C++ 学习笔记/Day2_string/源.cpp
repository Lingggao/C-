/*
	Day_2_10_20200213
	C++ ϵͳ string ��
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

string operator- (string, string);

int main()
{
	/* string ���� C++ �ؼ��֣�����һ���� */
	string es;
	cout << es << "*" << endl;    //�� string ���Ϊ��,����������ո�

	/* ��ʼ������ */
	string str1("Microsoft");
	string str2 = "Google";

	string str3;
	str3 = "Apple";

	string str4(str3);    //== string str4 = str3;
	str4 = str3;    //����ֱ�� =,����ʹ�� strcpy()

	cout << str1 << "  " << str2 
		 << "  " << str3 << "  " << str4 << endl;

	/* �ֽ��� */
	cout << sizeof(string) << endl;    //64 λ:40��32 λ:28,ƽ̨��ͬ�ֽ������ܲ�ͬ,һ�� >= 4

	/* ���� string */
	string cinstr;
	cin >> cinstr;
	cout << cinstr << endl;

	/* string ���� */
	str4 = str3;    //�ַ�������
	str4 += str3;    //�ַ���׷��

	cout << str4.size() << endl;    //string.size() �ַ�������

	//string �Ƚ�
	if (str3 > str4)
		cout << "str3 > str4" << endl;
	else
		cout << "str3 <= str4" << endl;

	cout << str4[2] << endl;    //�±����

	str3.swap(str4);    //�ַ�������

	/* ���� C �ַ��� */
	char buffer[100];
	string bstr = "Microsoft";
	strcpy_s(buffer, 10, bstr.c_str());    //string.c_str() ���� C �ַ���
	cout << buffer << endl;

	/* string ���� */
	int n = str3.find('l', 0);
	cout << str3 << endl;
	cout << n << endl;

	/* ���� string ������������� */
	string test1 = "abcdefgh";
	string test2 = "cde";
	string test3 = test1 - test2;
	cout << test3 << endl;
	
	/*
	    C++ ֮������
		1.����Ҫʹ�ú�
		2.��Ҫ����ʱ������,������ʼ��
		3.��ʹ�� malloc,���� new
		4.����ʹ��ǿ��ת��
		5.����ʹ�������� C �ַ���,���� string �� vector
	*/

	/* ɾ���ַ���ͷβ�ո� */
	string deletee = "   abcde    ";
	cout << deletee << "*" << endl;
	deletee.erase(0, deletee.find_first_not_of(' '));
	cout << deletee << "*" << endl;
	deletee.erase(deletee.find_last_not_of(' '));
	cout << deletee << "*" << endl;


	return 0;
}

string operator- (string a, string b)
{
	string ans;

	if (a.find(b) == -1)    //����޷����,�����
		return a;

	bool flag = false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == b[0])
		{
			flag = true;    //�ж����� true
			for (int j = 0; j < b.size(); j++)
			{
				if (a[i + j] != b[j])
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
				i += (b.size() - 1);
		}
		else
			ans += a[i];
	}

	return ans;
}
