#include <stdio.h>					// C에서 쓰는 헤더파일도 C++에서 지원이 된다

int main()
{
	int age = 25;
	bool isAdult = age > 19;		// 확장자명이 c이면 bool 지원X
	if (isAdult) {
		puts("성인입니다.");
	}
}