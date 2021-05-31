#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];	// 멤버변수를 동적할당받음 strlen(aname) + 1 >> 문자열 + NULL값
		strcpy(pname, aname);
		age = aage;
		printf("== <%s> 객체생성 ==\n", pname);
	}

	~Human() {
		printf("== <%s> 객체가 파괴 == \n", pname);
		delete[] pname;							// 멤버변수 동적할당해제
	}
	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

int main()
{
	Human boy("김수한무거북이와두루미", 12);
	boy.intro();

	Human* leo;		// new 연산자가 리턴하는 포인터를 Human 타입 포인터 leo로 받음
	leo = new Human("레오나르도디카프리오", 40);
	leo->intro();	// 실행 중에 생성한 객체가 포인터타입이므로 화살표연산자 사용
	delete leo;
}