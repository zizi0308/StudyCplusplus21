#include <stdio.h>

int main()
{
	int T = 0;	// 테스트 케이스를 입력받을 갯수
	int A = 0;
	int B = 0;
	int i;

	scanf("%d", &T);

	for ( i = 1; i < (T + 1); i++)
	{
		scanf("%d %d", &A, &B);

		printf("%d\n", A + B);
	}
	getchar();
	return 0;
}