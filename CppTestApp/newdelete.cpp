#include <stdio.h>

int main()
{
	int* pi, *pj;

	pi = new int;
	pj = new int(10);		// 생성자를 호출하는 연산자이므로 바로 초기화 가능
	*pi = 123;
	printf("*pi = %d\n", *pi);
	printf("*pj = %d\n", *pj);
	delete pi;
	delete pj;
}