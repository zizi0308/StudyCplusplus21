#include <stdio.h>

int main()
{
	int* ar;

	ar = new int[5];				// C의 경우 : (int*)malloc(sizeof(int) * 5)
	for (int i = 0; i < 5; i++)
	{
		ar[i] = i;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d번째 = %d\n", i, ar[i]);
	}
	delete[] ar;					// 대괄호를 써서 전체요소를 한꺼번에 해제
}