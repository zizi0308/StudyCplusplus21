#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("C++ string");

	cout << s << "���ڿ��� ����= " << s.size() << endl;
	cout << s << "���ڿ��� ����= " << s.length() << endl;
	cout << s << "���ڿ��� �Ҵ�ũ��= " << s.capacity() << endl;	// ���������� �Ҵ���ִ� ������ ũ��
	cout << s << "���ڿ��� �ִ����= " << s.max_size() << endl;	// ��밡���� ������ ũ��

	s.resize(6);		// ���� ũ�⸦ 6���� ���Ҵ�
	cout << s << "����= " << s.size() << ", �Ҵ�ũ��= " << s.capacity() << endl;

	s.reserve(100);
	cout << s << "����= " << s.size() << ", �Ҵ�ũ��= " << s.capacity() << endl;
	s.at(0);
	cout << s.at(0) << endl;		// �ε��� ���� ã�ƺ���
	s.clear();						// �ʱ�ȭ ���ִ� ���ڿ��� ���� ��(but �Ҵ���� ������� �״����)
	cout << s << endl;
}