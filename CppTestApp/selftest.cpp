#include <stdio.h>

int main()
{
	double* ar;

	ar = new double[100];

	ar[50] = 3.14;

	printf("50번째 배열 : %.2f", ar[50]);

	delete[] ar;

}