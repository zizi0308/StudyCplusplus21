#include <stdio.h>

int main()
{
	int T = 0;
	int i;
	int A = 0;
	int B = 0;

	scanf("%d", &T);

	for ( i = 1; i < (T+1); i++)
	{
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d\n", i, A + B);
	}


	return 0;
}