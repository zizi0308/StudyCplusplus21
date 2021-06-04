#include <iostream>
#include <string.h>
using namespace std;

class Human
{
private:
	char* name;
public:
	Human(const char* aname) {
		int len = strlen(aname) + 1;
		name = new char[len];
		strcpy_s(name, len, aname);
	}
	~Human() {
		delete[] name;
	}

	void PrintName() {
		cout << "My name is" << name << endl;
	}
};

class Student : public Human
{
private:
	char* major;
public: 
	Student(const char* aname, const char* amajor) : Human(aname) {
		
		int len = strlen(amajor) + 1;
		major = new char[len];
		strcpy_s(major, len, amajor);
	}
	~Student() {
		delete[] major;
	}
	void PrintMajor() {
		PrintName();		// �ڽ�Ŭ�������� �θ�Ŭ������ name�� �ǵ帮�� �ȵ� �׷��� �θ�Ŭ���� public�� �ִ� �Լ�ȣ���� ���� ���� �ٲ��ش�
		cout  << " My major is " << major << endl;
	}
};

int main()
{
	Human my("ȫ�浿");
	my.PrintName();
	Student s("������", "IoT");
	//s.PrintName();
	s.PrintMajor(); // My name is �̸� My major is IoT �Դϴ�.
	return 0;
}