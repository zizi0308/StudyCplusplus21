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

void GlobalFunc(A& a) {					// ���޹��� �ּҰ��� �θ��� �ּҰ����� ������
	try {
		C& c = dynamic_cast<C&>(a);		// �갡 True�� ������
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
	B* pb = dynamic_cast<B*>(pa);		// �ٿ�ĳ���� << ����
	if (pb) pb->test2();
	C* pc = dynamic_cast<C*>(paa);		// ��ĳ���� << ������ �ϳ� ���������� �Ϻ��� ����ȯ�� �̷������ ����(�ڽ������ͷ� �θ� ����Ŵ)
	//if (pc) pc->test2();				// ������� ������


	C c;
	GlobalFunc(c);						// ��ü�� �������� Ÿ���� ����(�������)
	B b;								// b��� ��ü���� b�� �θ��� �����ͷ� ����Ű�� ���� ����
	GlobalFunc(b);						// c�� �����Ͱ� b�� ����Ŵ >> �ڽ��� �θ�ü�� ���������Ƿ� �����߻�
	return 0;
}