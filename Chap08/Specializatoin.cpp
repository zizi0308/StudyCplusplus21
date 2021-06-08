#include <stdio.h>
// 명시적구체화 선언문(호출하지 않아도 미리 만들어 놓은 함수)은 템플릿선언보다 뒤에 와야함
template <class T>
void swap(T& a, T& b)	
{
	T t;
	t = a, a = b, b = t;
}

template <> void swap<double>(double& a, double& b)		// 특수화를 하기위한 형태
{
	int i, j;

	i = (int)a;
	j = (int)b;
	a = a - i + j;
	b = b - j + i;
}

int main()
{
	double a = 1.2, b = 3.4;
	printf("a = %g, b = %g\n", a, b);
	swap(a, b);
	printf("a = %g, b = %g\n", a, b);
}