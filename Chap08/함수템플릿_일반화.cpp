/* 함수 템플릿 */
#include <iostream>
using namespace std;

template <typename T>				// 함수템플릿 일반화를 통해 자료형 상관없이 동일한 함수 연산을 하게 해준다.
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(3.14, 4.5) << endl;
	return 0;
}
