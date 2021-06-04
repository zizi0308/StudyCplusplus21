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
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
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
	void intro() {
		printf("%d학번 %s입니다", stunum, name);
	}
	void study() {
		printf("이이는 사 이삼은 육 이사 팔\n");
	}
};

int main()
{
	Human h("김사람", 23);
	Student s("조사람", 14, 123456);
	Human* pH;
	Student* pS;

	pH = &h;	// 포인터자료형 = 객체자료형
	pS = &s;	// 포인터자료형 = 객체자료형
	pH = &s;	// 포인터가 부모자료형(Human) >> 부모는 자식을 가리킬 수 있다.	// 업캐스팅

	//pS = &h;			// 에러, 아래 Line50은 오류를 피하기 위해 형변환 해주고 있음

	pS = (Student*)&h;	// 자식자료형의 포인터로 부모객체를 가리키는 형태 >> 안됨 >> 그래서 형변환	// 다운캐스팅
	pS->intro();
}