#include <stdio.h>

int main()
{
	int T = 0;
	int A = 0;
	int B = 0;
	int i;

	scanf("%d", &T);

	for ( i = 1; i <= T; i++)
	{
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d + %d = %d\n", i, A, B, A + B);
	}

	return 0;
}