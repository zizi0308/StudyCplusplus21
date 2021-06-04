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
		PrintName();		// 자식클래스에서 부모클래스인 name을 건드리면 안됨 그래서 부모클래스 public에 있는 함수호출을 통해 값을 바꿔준다
		cout  << " My major is " << major << endl;
	}
};

int main()
{
	Human my("홍길동");
	my.PrintName();
	Student s("조희지", "IoT");
	//s.PrintName();
	s.PrintMajor(); // My name is 이름 My major is IoT 입니다.
	return 0;
}