#include <stdio.h>

int ar[] = { 1, 2, 3, 4, 5 };

int& GetAr(int i)				// �����ؼ���
{
	return ar[i];				// 3���濡 �ִ� ��Ұ��� ������ ����(�迭 3���濡 �ִ� ���۷����� ���� ����)
}

int main()
{
	// int& ra = 10; ����� ������ �� �� ����. >> ������ ���� �ʱⰪ�� lvalue(����)���� ��
	GetAr(3) = 6;				// ��� �����ؼ� �� 5���� �ٸ� ����
	printf("ar[3] = %d\n", ar[3]);
}