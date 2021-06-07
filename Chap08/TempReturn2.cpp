#include <stdio.h>

template <typename T>
T cast(int s)			// cast함수 사용 : 인수로 전달된 정수형의 s를 T타입으로 캐스팅
{
	return T(s);
}

int main()
{
	unsigned u = cast<unsigned>(1234);
	double d = cast<double>(5678);

	printf("u = %d, d = %f\n", u, d);
}