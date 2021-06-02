#include <iostream>

class StaticTest {
public:
	int a;
	static int b;			// static 멤버변수 선언
	StaticTest() {
		a = 10;
		// b = 20;			// 여기에서 초기화 안됨(static 멤버변수는 클래스 내부에서 초기화 불가능)
		b++;
	}
	void getData() {
		printf("a : %d, b : %d\n", a, b);
	}
};
int StaticTest::b = 20;		// 그냥 냅다 int b = 20은 오류남, 클래스 바깥에서 쓸 때는 꼭 소속표시
							// static 멤버변수 초기화(외부에서 초기화해야 함)-객체내에 존재하지 않는다.
int main()
{
	StaticTest s1;
	s1.getData(); 
	StaticTest s2;
	s2.getData();
	

	return 0;
}