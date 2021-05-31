#include <iostream>

//int func(int a)
//{
//	return a;
//}
int func(int a, int b = 0)		// b에 디폴트 매개변수를 줌
{
	return a + b;				
}
int main()
{
	func(10);					// 함수 오버로딩의 문제가 극대화 됨(함수 호출의 모호성)

	return 0;					// 때문에 default 매개변수와 오버로딩을 함께 쓰지않도록 주의해야 함
}
