#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f;
	char str[128];
	int i;

	f.open("D:\\Sources\\Gitrepository\\StudyCplusplus21\\Chap12\\cpptest.txt");	// ���Ͽ��� ��μ���(������ << �ٸ����� �ִ� ������ ������ ���������·� ���������)
	if (f.is_open()) {	// ������ ���ȴ��� Ȯ��
		f >> str >> i;
		cout << str << i << endl;
		f.close();
	}
	else {
		cout << "���Ͽ��� ����" << endl;
	}


}