#include <stdio.h>

int main()
{
	int T = 0;
	int i;
	int A = 0;
	int B = 0;
	scanf("%d", &T);
	for ( i = 0; i < T; i++)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A + B);
	}
	return 0;
}