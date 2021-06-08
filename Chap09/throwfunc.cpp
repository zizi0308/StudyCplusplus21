#include <stdio.h>

void divide(int a, int d)
{
	if (d == 0) throw "0으로 나눌 수는 없습니다.";
	printf("나누기 결과 = %d입니다.\n", a / d);
}

int main()
{
	try {
		divide(10, 0);
	}
	catch (const char *message) {
		puts(message);
	}
	divide(10, 5);
	return 0;
}