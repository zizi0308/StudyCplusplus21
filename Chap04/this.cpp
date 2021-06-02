#include <stdio.h>

class Simple
{
private:
	int value;
public:
	Simple(int avalue) : value(avalue) {}
	void Outvalue() {
		printf("value = %d\n", value);
	}
};

int main()
{
	Simple A(1), B(2);
	A.Outvalue();	// 멤버함수는 공유되므로 멤버함수를 호출할 때 컴파일러가 알아서 this포인터를 써서 호출한 객체를 구분한다.
	B.Outvalue();
}