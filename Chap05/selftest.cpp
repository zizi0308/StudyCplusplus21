#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* name;
	int age;
public:
	Human() {}
	Human(const char* aname, int aage) {		// 생성자
		name = new char[strlen(aname) + 1];		// 동적할당
		strcpy(name, aname);
		age = aage;
	}
	Human(const Human& other) {					// 복사생성자 생성
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}
	~Human() {									// 동적할당 해제를 위한 소멸자
		delete[] name;
	}
	void PrintHuman() {							// 출력함수1
		printf("이름 : %s ,나이 : %d", name, age);
	}
	void PrintHuman2(Human who) {				// 출력함수2
		who.PrintHuman();
	}

	const Human operator =(const Human& other) {//	=연산자를 쓰기위한 operator함수 생성
		// Human obj
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;

		return *this;							// 자기자신 포인터로 리턴
		// return obj;
	}
};

int main()
{
	Human jo("조희지", 26);
	//jo.PrintHuman();
	//Human you(jo);
	//you.PrintHuman2(jo);
	Human Xman;
	Xman = jo;
	Xman.PrintHuman();
}