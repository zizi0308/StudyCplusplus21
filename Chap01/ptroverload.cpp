#include <stdio.h>

void sub(int a) { printf("int : %d\n", a); }
void sub(int* a) { printf("pointer: %p\n", a); }

int main()
{
	int i = 1234, * pi = &i;

	sub(i);
	sub(pi);
	sub(NULL);			// ���� �̷��� ���� NULL�����͸� ȣ���ϴµ� 3�� ������ NULL�� ������� ��
	sub((int*)NULL);	// �������� ���� ��Ÿ������ ������ ����ȯ�� �ؾ� �Ѵ�(��� �̷��Դ� �Ⱦ���)
}						// ������ �������̸� �ߺ����Ǹ� ������� ����,,,