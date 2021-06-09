#include <stdio.h>
// 문법 : static_cast<변환할 타입>(캐스팅 할 대상)
int main()
{
	const char* str = "korea";
	int* pi;
	double d = 123.456;
	int i;
	int ary[] = { 1, 2, 3, 4, 5 };
	int* ptr = static_cast<int*>(ary);	// 배열은 변환이 가능하다(배열이 동일한 자료형인 경우)

	i = static_cast<int>(d);			// 가능
	// pi = static_cast<int*>(str);		// 에러 : static_cast는 포인터끼리의 형변환은 허용하지 않는다.
	pi = (int*)str;						// 가능
}