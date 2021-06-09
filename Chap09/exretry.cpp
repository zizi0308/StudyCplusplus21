#include <stdio.h>

int main()
{
	int num;

	try {
		printf("1에서 100사이의 정수를 입력하세요 : ");
		scanf("%d", &num);
		if (num < 1 || num > 100) throw num;
		printf("입력한 수 = %d\n", num);
	}
	catch (int num) {
		printf("%d는 1에서 100사이의 정수가 아닙니다.\n", num);
	}
}