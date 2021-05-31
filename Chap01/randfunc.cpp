#include <stdio.h>
#include <stdlib.h>

inline int randfunc(int n)		// inline을 판단하는 것은 컴파일러
{
	return rand()%n;
}

int main()
{
	int i, j, k;
	i = randfunc(10);
	j = randfunc(100);
	k = randfunc(50);
	printf("난수 = %d,%d,%d\n", i, j, k);

}