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
		printf("%s 객체의 생성자가 호출되었습니다.\n", pname);
	}

	~Human() {			// 객체가 소멸될 때 호출되는 파괴자 : 매개변수, 출력X 대신 ~가 붙음
		printf("%s 객체가 파괴되었습니다.\n", pname);
		delete[] pname;	// 메모리 동적할당을 파괴, 항상 파괴자 안에서 동적할당된 메모리를 반환시켜줘야 함
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};
// Human boy("김수한무거북이와두루미", 12); 전역변수로 하면 main함수가 실행되기전에 호출됨
int main()
{
	Human boy("김수한무거북이와두루미", 12);
	boy.intro();
}