#include <stdio.h>

// �ʱⰪ�� ���� �Ű����� = ����Ʈ �Ű�����, �ǵڿ������� �������� ����Ʈ�Ű������� �����ؾ���
int GetSum(int from, int to, int step = 1, int base = 0);	 // ����Ʈ�μ��� �������� ������

int main()
{
	printf("%d\n", GetSum(1, 10));
	printf("%d\n", GetSum(1, 10, 2));
	printf("%d\n", GetSum(1, 10, 2, 10));
}

int GetSum(int from, int to, int step/* = 1*/, int base/* = 0*/)
{
	int sum = base;
	for (int i = from; i <= to; i+=step) {
		sum += i;
	}
	return sum;
}