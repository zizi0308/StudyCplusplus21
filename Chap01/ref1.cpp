#include <stdio.h>

int main()
{
	int i = 3;
	int &ri = i;			// i�� ������ ������ �ִ� ri�̴�.
	int* pi = &i;

	printf("i = %d, ri = %d\n", i, ri);
	ri++;
	printf("i = %d, ri = %d\n", i, ri);
	*pi = i + 1;
	printf("i = %d, ri = %d\n", i, ri);
	printf("i���� = %x, ri���� = %x\n, pi = %x", &i, &ri, &pi);

}