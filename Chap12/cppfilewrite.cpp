#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream f;		// ������ �� �뵵�� ��ü�� ����

	f.open("D:\\Sources\\Gitrepository\\StudyCplusplus21\\Chap12\\cpptest.txt");	// ���Ͽ��� ��μ���
	if (f.is_open()) {	// ������ ���ȴ��� Ȯ��
		f << "String " << 1234 << endl;
		f.close();
	}
	else {
		cout << "���Ͽ��� ����" << endl;
	}
}