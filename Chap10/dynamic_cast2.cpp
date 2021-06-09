#include <iostream>
using namespace std;

class A {
public:
	virtual void test() { printf("A::test()\n"); }
};

class B : public A {
public:
	virtual void test() { printf("B::test()\n"); }
	void test2() { printf("B::test2()\n"); }
};

class C : public B {
public:
	virtual void test() { printf("C::test()\n"); }
	void test2() { printf("C::test2()\n"); }
};

void GlobalFunc(A& a) {					// 전달받은 주소값을 부모의 주소값으로 던져줌
	try {
		C& c = dynamic_cast<C&>(a);		// 얘가 True를 던져줌
		printf("GlobalFunc()");
	}
	catch (std::bad_cast) {
		printf("casting error");
	}
}

int main()
{
	A* pa = new C;
	A* paa = new B;
	pa->test();
	B* pb = dynamic_cast<B*>(pa);		// 다운캐스팅 << 가능
	if (pb) pb->test2();
	C* pc = dynamic_cast<C*>(paa);		// 업캐스팅 << 가능은 하나 실질적으로 완벽한 형변환이 이루어지지 않음(자식포인터로 부모를 가리킴)
	//if (pc) pc->test2();				// 결과에서 에러남


	C c;
	GlobalFunc(c);						// 객체와 포인터의 타입이 같음(정상출력)
	B b;								// b라는 객체전달 b를 부모의 포인터로 가리키는 것은 가능
	GlobalFunc(b);						// c의 포인터가 b를 가리킴 >> 자식이 부모객체를 가리켰으므로 에러발생
	return 0;
}