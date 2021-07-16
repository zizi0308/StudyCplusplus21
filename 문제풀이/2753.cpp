#include <stdio.h>

/*윤년을 판별하는 문제*/

int main()
{
	int year = 0;
	scanf("%d", &year);

	if ((year >= 1) && (year <= 4000))
	{
		if (year % 4 == 0)
		{
			if (year % 100 != 0)
			{
				printf("%d", 1);
			}
			else if (year % 400 == 0)
			{
				printf("%d", 1);
			}
		}
		else printf("%d", 0);
	}
	return 0;
}