#include <iostream>

class StaticTest {
	static int a;					// static 멤버변수
	int b;

public:
	StaticTest();
	static void setData(int);		// static 멤버함수는 static 멤버변수에 사용함
	void getData();
};
int StaticTest::a = 10;				// static 멤버변수 초기화
StaticTest::StaticTest()
{
	b = 20;							// this->b = 20 도 가능함
}
void StaticTest::getData()
{
	printf("a : %d ,b : %d\n", a, b);
}
void StaticTest::setData(int aa)	// static 멤버함수를 통해 static 멤버변수에 접근함
{
	a = aa;
	// a = aa;						// this포인터를 사용할 수 없다. static멤버변수는 객체의 것이 아니다.
}

int main()
{
	StaticTest s1;
	s1.getData();
	StaticTest s2;
	s2.getData();

	s1.setData(30);
	s1.getData();
	s2.getData();

	StaticTest::setData(40);		// 클래스 소속으로 클래스로 호출이 가능하다.
	s1.getData();
	s2.getData();

	return 0;
}