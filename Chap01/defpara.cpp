#include <stdio.h>

// 초기값을 가진 매개변수 = 디폴트 매개변수, 맨뒤에서부터 역순으로 디폴트매개변수를 생성해야함
int GetSum(int from, int to, int step = 1, int base = 0);	 // 디폴트인수는 원형에만 지정함

int main()
{
	printf("%d\n", GetSum(1, 10));
	printf("%d\n", GetSum(1, 10, 2));
	printf("%d\n", GetSum(1, 10, 2, 10));
}

int GetSum(int from, int to, int step/* = 1*/, int base/* = 0*/)
{
	int sum = base;
	for (int i = from; i <= to; i+=step) {
		sum += i;
	}
	return sum;
}