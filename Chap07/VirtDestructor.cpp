#include <stdio.h>
// 
class Base
{
private:
	char* B_buf;
public:
	Base() { B_buf = new char[10]; puts("Base 생성"); }
	virtual ~Base() { delete[] B_buf; puts("Base 파괴"); }
};

class Derived : public Base
{
private:
	int* D_buf;
public:
	Derived() { D_buf = new int[32]; puts("Derived 생성"); }
	virtual ~Derived() {
		delete[] D_buf; puts("Derived 파괴");
	}
};

int main()
{
	Base* pB;

	pB = new Derived;	// 부모가 자식을 가리킬 수 있으므로 객체생성하여 자식을 가리키는 것 가능(Derived객체 생성)
	delete pB;			// new 연산자가 객체를 생성하면서 부모와 자식생성자 차례로 호출 >> 두 개의 버퍼 동적할당
}						// But, 객체 동적할당 해제할 때는 포인터의 타입을 따르므로 pB의 파괴자만 호출(정적결합)
						// 파괴자가 동적결합(virtual)을 하면 할당된 두 개의 버퍼를 해제할 수 있음