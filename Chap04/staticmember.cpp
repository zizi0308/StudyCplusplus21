#include <iostream>

class StaticTest {
	static int a;					// static �������
	int b;

public:
	StaticTest();
	static void setData(int);		// static ����Լ��� static ��������� �����
	void getData();
};
int StaticTest::a = 10;				// static ������� �ʱ�ȭ
StaticTest::StaticTest()
{
	b = 20;							// this->b = 20 �� ������
}
void StaticTest::getData()
{
	printf("a : %d ,b : %d\n", a, b);
}
void StaticTest::setData(int aa)	// static ����Լ��� ���� static ��������� ������
{
	a = aa;
	// a = aa;						// this�����͸� ����� �� ����. static��������� ��ü�� ���� �ƴϴ�.
}

int main()
{
	StaticTest s1;
	s1.getData();
	StaticTest s2;
	s2.getData();

	s1.setData(30);
	s1.getData();
	s2.getData();

	StaticTest::setData(40);		// Ŭ���� �Ҽ����� Ŭ������ ȣ���� �����ϴ�.
	s1.getData();
	s2.getData();

	return 0;
}