#include <stdio.h>

void divide(int a, int d)
{
	if (d == 0) throw "0���� ���� ���� �����ϴ�.";
	printf("������ ��� = %d�Դϴ�.\n", a / d);
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