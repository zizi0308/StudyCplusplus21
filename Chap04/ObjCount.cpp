#include <stdio.h>

int count = 0;			// 전역변수 할당 >> 근데 가급적이면 정적지역변수(static)사용, 전역변수는 아무나 건드릴수 있으므로 위험하다
class Simple
{
private:
	int value;

public:
	Simple() { count++; }
	~Simple() { count--; }
	void OutCount() {	// 호출한 객체의 this포인터를 받음
		printf("현재객체 개수 = %d\n", count);
	}
};

int main()
{
	Simple s, * ps;		// 둘 다 전역변수로 선언된 count를 가져다 쓸 수 있음
	s.OutCount();		// 함수를 호출함
	ps = new Simple;
	ps->OutCount();
	delete ps;
	s.OutCount();
	printf("크기 = %d\n", sizeof(s));	// int형 4바이트(객체의 크기는 멤버변수에만 영향을 받기때문에)
}