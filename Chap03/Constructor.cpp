#include <stdio.h>
#include <string.h>

class Human
{
private:
	char name[12];
	int age;

public: 
	// ! 생성자 >> 클래스와 이름이 같으며 return값이 없다면 생성자가 된다 !
	Human(const char* aname, int aage) {// 인수는 주로 멤버의 초깃값 >> 멤버와 유사한 이름을 붙임
		strcpy(name, aname);			// 하지만 같은이름을 사용할 수 없다(명칭이 충돌하면 좁은범위 우선)
		age = aage;

	/*Human(const char* name, int age) {// 위와 같은 코드 둘 중에 편한거 쓰면 됨
		strcpy(this->name, name);		// 전달하고 있는 객체의 멤버변수의 값(this->name, this->age)에 
		this->age = age;*/				// 매개변수 name, age을 대입해라는 뜻
	}
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human kim("김상형", 29);
	kim.intro();
}