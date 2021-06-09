#include <stdio.h>
#include <typeinfo>

class Parent
{
public:
	virtual void PrintMe() { printf("I am Parent\n"); }
};

class Child : public Parent
{
private: 
	int num;
public:
	Child(int anum) : num(anum) {}
	virtual void PrintMe() { printf("I am Child\n"); }
	void PrintNum() { printf("Hello Child = %d\n", num); }
};
void func() {}		// 함수도 확인가능
int main()
{
	Parent P, * pP;
	Child C(123), * pC;
	pP = &P;
	pC = &C;
	int val;		// 변수도 확인가능
	printf("P = %s, pP=%s, *pP=%s\n",
		typeid(P).name(), typeid(pP).name(), typeid(*pP).name()); 
	printf("C = %s, pC=%s, *pC=%s\n",
		typeid(C).name(), typeid(pC).name(), typeid(*pC).name());

	pP = &C;
	printf("pP=%s, *pP=%s, value = %s\n",
		typeid(pP).name(), typeid(*pP).name(), typeid(val).name());	// 포인터의 타입 : 부모, 실질적으로 포인터가 접근해서 읽어오는 객체(virtual로 선언되었기 때문) : 자식
	printf("func = %s\n", typeid(func).name());
}