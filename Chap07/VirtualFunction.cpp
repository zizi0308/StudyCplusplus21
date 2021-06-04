#include <iostream>
using namespace std;

class Base
{
public:
	virtual void func1() { cout << "B:func1()" << endl; }
	virtual void func2() { cout << "B:func2()" << endl; }
	void func3() { cout << "B:func3()" << endl; }
};
class Drived : public Base
{
public:
	void func1() { cout << "D:func1()" << endl; }
	void func3() { cout << "D:func3()" << endl; }
	void func4() { cout << "D:func4()" << endl; }
};

int main()
{
	Base b;
	Drived d;
	Base* pb = new Drived;

	pb->func1();	// B:func1() // 가상함수 선언후(virtual) D:func1()
	pb->func2();	// B:func2()
	pb->func3();	// 가상함수가 아닌것들은 포인터자료형을 따라간다

	return 0;
}