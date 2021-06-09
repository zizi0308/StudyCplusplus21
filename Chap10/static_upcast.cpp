#include <iostream>
using namespace std;

class Base {
private:	
	int data;
public:
	Base() {};
	~Base() {};
	void setData(int adata) { data = adata;}
	int getData() { return data; }
};

class Derived : public Base {
public:
	void setData(int adata) {
		if (adata > 0) adata = 0;
		Base::setData(adata);
	}
	void PrintData() {
		cout << "PrintData() : " << getData() << endl;
	}
};

int main()
{
	Base* pb = new Derived;
	Derived* pd = NULL;
	
	pb->setData(10);			// 부모클래스의 setData()호출 
	//pb->PrintData();
	pd = static_cast<Derived*>(pb);	// 정적형변환(static_cast)
	pd->setData(20);			// 자식클래스의 setData()호출
	pd->PrintData();

	return 0;
}