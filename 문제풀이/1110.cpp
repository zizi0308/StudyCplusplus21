#include <stdio.h>

int main()
{
	int N = 0;
	int a = 0;
	int b = 0;
	int count = 1;
	int res = 0;
	
	scanf("%d", &N);
	a = N / 10;
	b = N % 10;
	if (a + b <= 10) res = a + b;
	else res = b * 10 + (a + b);
	while (1)
	{
		a = res / 10;
		if (a + b <= 10) res = a * 10;
		else
		{
			b = res % 10;
			res = b * 10 + (a + b) % 10;
		}
		count++;

		if (N == res) break;
	}
	printf("%d", count);
	
	return 0;
}