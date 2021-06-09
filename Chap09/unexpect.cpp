#include <stdio.h>
#include <exception>
using namespace std;

void myunex()
{
	puts("발생해서는 안 되는 에러 발생");
	exit(-2);
}

void calc() throw(int)
{
	throw "string";		// 정수예외로 설정했는데 문자열을 던진다. 
}

int main()
{
	set_unexpected(myunex);
	try {
		calc();
	}
	catch (int) {		// 예외처리를 할 수 있는 같은 자료형의 핸들러가 없기 때문에 에러발생
		puts("정수형 예외발생");
	}
	puts("프로그램 종료");
}