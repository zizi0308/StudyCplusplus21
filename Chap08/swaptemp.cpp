#include <stdio.h>
// template << 함수를 만드는 형틀 (함수에 대해 template이라는 기법을 적용한 것임)
template <typename T>		// template : 함수템플릿을 정의, <typename T> : 전달되는 자료형을 T로 통일해서 사용한다는 뜻
void swap(T& a, T& b)
{
	T t;
	t = a; a = b; b = temp;
}
// template <typename T>	// 에러 : 항상 템플릿을 선언한 다음에 템블릿이 적용된 코드가 와야한다.
int main()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	swap(a, b);
	swap(c, d);
	swap(e, f);
	printf("a = %d, b = %d", a, b);
	printf("c = %f, d = %f", c, d);
	printf("e = %c, f = %c", e, f);
}