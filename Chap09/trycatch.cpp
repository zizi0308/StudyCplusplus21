#include <stdio.h>

int main()
{
	int a, b;

	try
	{
		printf("나누어질 수를 입력하세요 : ");
		scanf("%d", &a);
		if (a < 0) throw a;			// throw를 통해 던짐1
		printf("나누는 수를 입력하세요 : ");
		scanf("%d", &b);			// throw를 통해 던짐2
		if (b == 0) throw "0으로 나눌 수는 없습니다.";
		printf("나누기 결과는 %d입니다.\n", a / b);
	}
	catch (int a) {					// 예외 숫자를 받음1(동일한 타입을 받을 수 있는 핸들러를 지정해줘야 함)
		printf("%d의 음수이므로 나누기 거부\n", a);
	}
	catch (const char *message)	{	// 예외 문자열을 받음2(동일한 타입을 받을 수 있는 핸들러를 지정해줘야 함)
		puts(message);
	}
}