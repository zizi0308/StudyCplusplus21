#include <stdio.h>
#include <string.h>

class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	virtual void intro() {	// 가상테이블에 가상함수가 등록되어 내부적으로 동작하는 형태
		printf("이름 : %s, 나이 : %d\n", name, age);
	}
	
};
class Student : public Human
{
protected:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	virtual void intro() {		// 오버라이딩된 자식클래스는 자동으로 virtual로 나타내짐(virtual 생략가능)
		printf("%d학번 %s입니다.\n", stunum, name);
	}
	virtual void study() {
		printf("이이는 사 이삼은 육 이사 팔\n");
	}
};

//void IntroSomeBody(Human* pH) {
//	pH->intro();
//}

int main()
{
	Human h("김사람", 13);
	Student s("이학생", 15, 12345);
	Human* pH;

	pH = &h;
	pH->intro();
	pH = &s;
	pH->intro();	// 부모클래스에 있는 인트로가 호출됨

	/*IntroSomeBody(&h);
	IntroSomeBody(&s);*/

}