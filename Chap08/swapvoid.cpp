#include <stdio.h>
#include <malloc.h>
#include <memory.h>
// void >> �ڷ����� �������� ���� ����
void swap(void* a, void* b, size_t len)	// void�� ����ϸ� �ڷ������� Ŭ������ ���� ������ �ʿ䰡 ����(Ŭ������ �Ϲ�ȭ)
{										// �Լ��� ȣ��� ��(��Ÿ���߿�) �Ű������� �����ִ� Ÿ�Կ� ���� ����
	void* t;							// void�� �����͸� ����Ͽ� ������ �����͸� ó����
	t = malloc(len);
	memcpy(t, a, len);					// memcpy >> �޸� ������ �״�� ī����
	memcpy(a, b, len);
	memcpy(b, t, len);
	free(t);
}

int main()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	swap(&a, &b, sizeof(int));
	swap(&c, &d, sizeof(double));
	printf("a = %d, b = %d\n", a, b);
	printf("c = %.f, d = %.f", c, d);

}