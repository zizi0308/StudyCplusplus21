#include <stdio.h>

int Add(int a, int b); 
int Add(int a, int b, int c);			// 매개변수의 개수가 다르거나
double Add(double a, double b);			// 매개변수의 타입(자료형)이 다를 때 오버로딩 사용가능
										// 함수를 찾을 때 C:함수이름 C++:매개변수, 함수이름 둘 다
int Add(const int a, const int b)		// 이것도 오버로딩 가능

int main()
{
	printf("1 + 2 = %d\n", Add(1, 2));
	printf("3 + 4 + 5 = %d\n", Add(3, 4, 5));
	printf("1.414 + 2.54 = %f\n", Add(1.414, 2.54));
}

int Add(int a, int b)
{
	return a + b;
}

int Add(int a, int b, int c)
{
	return a + b + c;
}

double Add(double a, double b)
{
	return a + b;
}