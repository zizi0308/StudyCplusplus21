#include <stdio.h>

int main()
{
	int N = 0;
	int i;
	int j;
	int k;
	scanf("%d", &N);

	for ( i = 1; i <= N; i++)
	{
		for ( j = N; j > i; j--)
		{
			printf(" ");
		}
		for ( k = 0; k < i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}