#include <stdio.h>
#include <string.h>

class Human
{
private:
	char *pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
	}

	~Human() { // 객체가 삭제되면서 메모리 동적할당을 해제 결국 없는(해제된) 주소를 가리키고 있기때문에 런타임오류 발생
		delete[]pname;		
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

int main()
{
	Human kang("강감찬", 1424);
	Human boy = kang;

	boy.intro();
}
