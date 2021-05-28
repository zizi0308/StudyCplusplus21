#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int& i, int& j);

int main()
{
	int i;
	int j;
	printf("정수값 입력 : ");
	scanf("%x %x", &i, &j);
	swap(i, j);
	printf("i = %d j = %d", i, j);
}

void swap(int& i, int& j)
{
	int temp;
	
	temp = i;
	i = j;
	j = temp;
}