#include <stdio.h>

class Simple
{
private:
	int value;
public:
	Simple(int avalue) : value(avalue) {}
	void Outvalue() {
		printf("value = %d\n", value);
	}
};

int main()
{
	Simple A(1), B(2);
	A.Outvalue();	// ����Լ��� �����ǹǷ� ����Լ��� ȣ���� �� �����Ϸ��� �˾Ƽ� this�����͸� �Ἥ ȣ���� ��ü�� �����Ѵ�.
	B.Outvalue();
}