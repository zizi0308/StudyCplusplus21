#include <stdio.h>
#include <string.h>
// 상속 >> 재사용의 개념
class Human
{
private:
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

class Student : public Human		// 클래스이름 : 클래스이름 (Human클래스를 public으로 상속받았다는 뜻)
{
private:
	int stunum;

	/*  <상속단계>
	1. 파생 클래스의 생성자가 호출  
	2. 부모클래스의 생성자 호출하면서 실행(머리에 콜론연산자 있으므로 먼저실행)  
	3. 파생클래스의 생성자 실행*/
public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {	// 부모의 멤버도 자식이 물려받았기 때문에 생성자로 초기화 해준다 + 콜론초기화(부모클래스의 인수 2개 초기화).
		stunum = astunum;	// 자식에 있는 멤버변수만 초기화시킨다(부모클래스는 이미 머리에서 초기화)
	}
	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

int main()
{
	Human kim("김상형", 34);
	kim.intro();
	Student han("한상형", 13, 123456);
	han.intro();
	han.study();
}