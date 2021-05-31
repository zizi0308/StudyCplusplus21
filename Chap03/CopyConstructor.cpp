#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
	}

	Human(const Human &other) {	// 복사생성자를 실행하면서 새로 메모리 동적할당을 받음
		// 복사생성자의 타입을 가지고 있으므로 무한반복을 피하기 위해(참조자 안쓰면 생성자 - 복사생성자순으로 무한호출) 참조자(&)연산을 사용함
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