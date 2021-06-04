#include <stdio.h>
#include <string.h>
// 오버라이딩 >> 상속관계에서 함수이름 매개변수 출력이 모두 같아야 한다 "재정의"
// 오버로딩 >> 함수이름은 같지만 매개변수의 개수가 다르거나 타입이 다를 때 사용 "다중정의"
class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char *aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
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
	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔");
	}
	void intro() {	// 16번째 줄과 같은 형태 >> "오버라이딩" 부모에서 사용하는 멤버함수를 자식클래스에서 그대로 가져와 사용(몸체만 다르다)
		printf("%d학번 %s입니다.\n", stunum, name);
	}
};

int main()
{
	Human kim("김상형", 29);
	kim.intro();			// 부모에 있는 intro()
	Student han("김한결", 13, 12345);
	han.intro();			// 자식에 있는 intro()
	han.Human::intro();		// 오버라이딩 된 인트로 말고 부모에 있는 인트로를 쓰고 싶을 때(소속되있는 클래스와 범위지정 연산자를 써서 부모클래스의 함수를 가져다 씀)
}