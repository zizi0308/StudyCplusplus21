#include <stdio.h>

int main()
{
	int n = 0;
	int i;
	int sum = 0;

	scanf("%d", &n);

	for (i = 0; i < n + 1; i++)
	{
		sum += i;
	}
	printf("%d", sum);
	
	return 0;
}