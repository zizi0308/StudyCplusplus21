#include <stdio.h>
#include <string.h>
//  복사생성자호출요건 : 1. 매개변수로 객체를 선언할 때 2. return값이 객체일 때 3. 객체 값이 복사생성자일 때
class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {		// 멤버함수자리에 출력이 없고 클래스의 이름으로 무언가있다 >> 생성자
		pname = new char[strlen(aname) + 1];	// 동적할당
		strcpy(pname, aname);
		age = aage;
	}

	Human(const Human &other) {	// 복사생성자를 실행하면서 새로 메모리 동적할당을 받음
		// 복사생성자의 타입을 가지고 있으므로 무한반복을 피하기 위해(참조자 안쓰면 생성자 - 복사생성자순으로 무한호출) 참조자(&)연산을 사용함
		// + 원래는 초깃값 없이 레퍼런스를 선언할 수 없지만, 함수형식의 인수로 사용되었으므로 초기화 안해도 됨(main이나 함수안에서 쓰려면 초기화 필요).
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}

	~Human() { 
		delete[]pname;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

void printHuman(Human who)
{
	who.intro();
}

int main()
{
	Human kang("강감찬", 1424);
	Human boy = kang;

	printHuman(boy);
}