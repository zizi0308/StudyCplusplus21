#include <stdio.h>

class MyClass
{
public:
	int i, j;
	double d;
};

int main()
{
	MyClass C;
	int MyClass::* pi;			// �Ҽ�Ŭ������ �����ϰ� �� �Ҽ��� �����͸� �̿��� ������ Ÿ���� ��������� �̿��� �ּҸ� ����
	double MyClass::* pd;
	int num;

	pi = &MyClass::i;
	pd = &MyClass::d;
	// pd = &MyClass::i;
	// pi = &MyClass::d;
	// pi=&num;
}