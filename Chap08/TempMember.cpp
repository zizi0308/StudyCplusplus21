#include <stdio.h>
// template <typename T>		// 클래스 템플릿(주석생략하고 22, 23 주석처리하면 실행됨)
class Util
{
public:
	template <typename T>		// 템플릿 멤버함수
	void swap(T& a, T& b)
	{
		T t;
		t = a; a = b; b = t;
	}
};

int main()
{
	Util/*<int>*/ u;
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	u.swap(a, b);
	u.swap(c, d);
	u.swap(e, f);
	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
	printf("e = %c, f = %c\n", e, f);
}