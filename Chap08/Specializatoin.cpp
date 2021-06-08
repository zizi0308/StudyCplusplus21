#include <stdio.h>
// �������üȭ ����(ȣ������ �ʾƵ� �̸� ����� ���� �Լ�)�� ���ø����𺸴� �ڿ� �;���
template <class T>
void swap(T& a, T& b)	
{
	T t;
	t = a, a = b, b = t;
}

template <> void swap<double>(double& a, double& b)		// Ư��ȭ�� �ϱ����� ����
{
	int i, j;

	i = (int)a;
	j = (int)b;
	a = a - i + j;
	b = b - j + i;
}

int main()
{
	double a = 1.2, b = 3.4;
	printf("a = %g, b = %g\n", a, b);
	swap(a, b);
	printf("a = %g, b = %g\n", a, b);
}