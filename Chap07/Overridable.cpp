#include <stdio.h>
#include <string.h>

class Human					// C++은 클래스의 연결거리가 메서드 밖에없음 << 일반적인 객체지향언어보다 모호성이 있다.
{
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void eat() {
		puts("냠냠냠\n");
	}
	virtual void intro()	// 미래를 내다보고(나중에 사용하기 위해 미리) 부모클래스에 설계할 때 기존에 있었던 것에 추가(재정의)하여 사용하기 위함
	{
		printf("이름 : %s, 나이 : %d\n", name, age);
	}
};

class Student :public Human
{
protected:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void intro() {
		printf("%d학번 %s입니다.\n", stunum, name);
	}
};

int main()
{
	Human h("김사랑", 13);
	Student s("이사랑", 15, 12345);
	Human* pH;

	pH = &h;
	pH->intro();
	pH->eat();
	pH = &s;
	pH->intro();
	pH->eat();
}