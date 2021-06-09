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
	
	pb->setData(10);			// �θ�Ŭ������ setData()ȣ�� 
	//pb->PrintData();
	pd = static_cast<Derived*>(pb);	// ��������ȯ(static_cast)
	pd->setData(20);			// �ڽ�Ŭ������ setData()ȣ��
	pd->PrintData();

	return 0;
}