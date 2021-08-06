#include <stdio.h>

int main()
{
	int A = 0;
	int B = 0;

	while (1)
	{
		A = 0;
		B = 0;
		scanf("%d %d", &A, &B);
		if (A + B == 0) break;
		printf("%d\n", A + B);
	}
	return 0;
}