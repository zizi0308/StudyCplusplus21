#include <stdio.h>

class MyClass
{
public:
	int i, j;
	double d;
};

int main()
{
	MyClass C;
	int MyClass::* pi;			// 소속클래스를 지정하고 그 소속의 포인터를 이용해 동일한 타입의 멤버변수를 이용해 주소를 저장
	double MyClass::* pd;
	int num;

	pi = &MyClass::i;
	pd = &MyClass::d;
	// pd = &MyClass::i;
	// pi = &MyClass::d;
	// pi=&num;
}