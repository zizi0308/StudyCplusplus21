#include <stdio.h>

int main()
{
	int a, b;

	try
	{
		printf("�������� ���� �Է��ϼ��� : ");
		scanf("%d", &a);
		if (a < 0) throw a;			// throw�� ���� ����1
		printf("������ ���� �Է��ϼ��� : ");
		scanf("%d", &b);			// throw�� ���� ����2
		if (b == 0) throw "0���� ���� ���� �����ϴ�.";
		printf("������ ����� %d�Դϴ�.\n", a / b);
	}
	catch (int a) {					// ���� ���ڸ� ����1(������ Ÿ���� ���� �� �ִ� �ڵ鷯�� ��������� ��)
		printf("%d�� �����̹Ƿ� ������ �ź�\n", a);
	}
	catch (const char *message)	{	// ���� ���ڿ��� ����2(������ Ÿ���� ���� �� �ִ� �ڵ鷯�� ��������� ��)
		puts(message);
	}
}