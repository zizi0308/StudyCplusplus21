#include <stdio.h>

class Parent {};
class Child : public Parent {};

int main()
{
	Parent P, * pP;
	Child C, * pC;
	int i = 1234;

	pP = static_cast<Parent*>(&C);
	pC = static_cast<Child*>(&P);			// 자식이 부모를 가리킴(다운캐스팅) 가능은 하지만 위험함
	// pP = static_cast<Parent*>(&i);		// 클래스와 기본형의 형변환은 지원하지 않는다.
	// pC = static_cast<Child*>(&i);		// 에러

}