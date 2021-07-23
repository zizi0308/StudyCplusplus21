#include <stdio.h>

int main()
{
	int N = 0;
	int i;
	int j;
	scanf("%d", &N);

	for ( i = 1; i <= N; i++)
	{
		for ( j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}