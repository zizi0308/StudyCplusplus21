#include <stdio.h>

int main()
{
	int A;
	int B;

	while (true)
	{
		scanf("%d %d", &A, &B);
		if ((A + B) == 0) break;
		printf("%d\n", A + B);
		
	}

	return 0;
}