#include <stdio.h>
// template << �Լ��� ����� ��Ʋ (�Լ��� ���� template�̶�� ����� ������ ����)
template <typename T>		// template : �Լ����ø��� ����, <typename T> : ���޵Ǵ� �ڷ����� T�� �����ؼ� ����Ѵٴ� ��
void swap(T& a, T& b)
{
	T t;
	t = a; a = b; b = temp;
}
// template <typename T>	// ���� : �׻� ���ø��� ������ ������ �ۺ��� ����� �ڵ尡 �;��Ѵ�.
int main()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	swap(a, b);
	swap(c, d);
	swap(e, f);
	printf("a = %d, b = %d", a, b);
	printf("c = %f, d = %f", c, d);
	printf("e = %c, f = %c", e, f);
}