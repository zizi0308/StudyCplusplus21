#include <iostream>
using namespace std;

class A
{
public:
	void AFunc() {
		cout << "A::AFunc()" << endl;
	}
};
class B : public A
{
public:
	void BFunc() {
		cout << "B::BFunc()" << endl;
	}
};
class C : public B
{
public:
	void CFunc() {
		cout << "C::CFunc()" << endl;
	}
};
// 부모 클래스는 자식을 가리킬 수 있다.
int main()
{
	A* pa = new C;		// A타입의 포인터 pa를 선언 기초클래스타입의 포인터가 파생객체의 데이터를 가리키고 있다.(자식객체를 부모가 가리키고 있음)
	pa->AFunc();		// A라는 포인터를 만들어서 C라는 포인터를 생성할 수 있지만 A의 범위까지만 사용할 수 있다.
	//C* pcc = new A;	// 자식포인터가 부모의 객체를 가리키면 안됨 (에러)
	B* pb = new C;		// 포인터를 통해 실질적으로 어떤 클래스를 사용할 수 있나? 
	pb->AFunc();		// >> 포인터가 가리키는 데이터값을 읽을 때(사용할 때)는 포인터의 자료형을 기준으로 접근해서 그 범위 안에서만 사용할 수 있다.
	pb->BFunc();		// 실질적으로 중요한 것은 '객체'인데 포인터의 자료형까지만 사용 할 수 있기 때문에 이것이 문제가 된다. 그래서 가상함수를 사용해야 한다
	C* pc = new C;
	pc->AFunc();
	pc->BFunc();
	pc->CFunc();

	return 0;
}
