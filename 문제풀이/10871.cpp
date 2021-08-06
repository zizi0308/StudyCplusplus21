#include <stdio.h>
#include <stdlib.h>

int main()
{
	int X;
	int N;
	int i;
	int* ary;

	scanf("%d %d", &N, &X);
	
	ary = new int[N];

	for ( i = 0; i < N; i++)
	{
		scanf("%d", &ary[i]);
	}
	
	
	for ( i = 0; i < N; i++)
	{
		if (*(ary + i) < X )
		{
			printf("%d ", ary[i]);
		}
	}

	return 0;
}