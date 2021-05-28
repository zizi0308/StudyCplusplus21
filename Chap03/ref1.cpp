#include <stdio.h>

int main()
{
	int i = 3;
	int &ri = i;			// i의 별명을 가지고 있는 ri이다.
	int* pi = &i;

	printf("i = %d, ri = %d\n", i, ri);
	ri++;
	printf("i = %d, ri = %d\n", i, ri);
	*pi = i + 1;
	printf("i = %d, ri = %d\n", i, ri);
	printf("i번지 = %x, ri번지 = %x\n, pi = %x", &i, &ri, &pi);

}