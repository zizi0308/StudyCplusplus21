#include <stdio.h>

int ar[] = { 1, 2, 3, 4, 5 };

int& GetAr(int i)				// 복사해서씀
{
	return ar[i];				// 3번방에 있는 요소값을 변수로 전달(배열 3번방에 있는 레퍼런스의 값을 리턴)
}

int main()
{
	// int& ra = 10; 상수는 별명을 줄 수 없다. >> 참조에 대한 초기값은 lvalue(변수)여야 함
	GetAr(3) = 6;				// 얘와 복사해서 쓴 5번은 다른 것임
	printf("ar[3] = %d\n", ar[3]);
}