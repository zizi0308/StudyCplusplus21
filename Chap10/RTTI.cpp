#include <stdio.h>

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
	virtual void PrintMe() { printf("I am Child\n");}
	void PrintNum() {printf("Hello Child = %d\n", num);}
};

void func(Parent* p)
{
	p->PrintMe();
	((Child*)p)->PrintNum();		// 자식객체에 있는 포인터(형변환을 통해)가 자식을 가리킴 >> 근데 이거 쓰레기값나옴
}

int main()
{
	Parent p;
	Child c(5);

	func(&c);
	func(&p);
}