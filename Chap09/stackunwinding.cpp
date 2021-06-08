#include <stdio.h>

class C
{
	int a;
public:
	C() { puts("생성자 호출"); }		// 객체는 컴파일러가 자동적으로 생성/소멸자 호출
	~C() { puts("소멸자 호출"); }		// 최근에 들어온 것 부터 소멸
};

void divide(int a, int d)
{
	if (d == 0) throw "0으로는 나눌 수 없습니다.";	// throw실행 전에 열어놓았던 스택들을 반환
	printf("나누기 결과 = %d입니다.", a / d);
}

void calc(int t, const char* m)						// 반환하기 위해 얘를 닫아버림(파괴자 호출) >> 이후 throw메세지 보여줌
{
	C c;
	divide(10, 0);
}

int main()
{
	try {
		calc(1, "계산");
	}
	catch (const char* message) {
		puts(message);
	}
	puts("프로그램이 종료됩니다");
}