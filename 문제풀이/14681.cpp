
/*점 (x, y)의 사분면 번호(1, 2, 3, 4 중 하나)를 출력한다.*/
#include <stdio.h>

int main()
{
	int x = 0;
	int y = 0;

	scanf("%d %d", &x, &y);

	if ((x > 0) && (y > 0))
	{
		printf("%d", 1);
	}
	if ((x > 0) && (y < 0))
	{
		printf("%d", 4);
	}
	if ((x < 0) && (y < 0))
	{
		printf("%d", 3);
	}
	if ((x < 0) && (y > 0))
	{
		printf("%d", 2);
	}

	return 0;
}