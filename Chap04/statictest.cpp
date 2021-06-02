#include <iostream>

class StaticTest {
public:
	int a;
	static int b;			// static ������� ����
	StaticTest() {
		a = 10;
		// b = 20;			// ���⿡�� �ʱ�ȭ �ȵ�(static ��������� Ŭ���� ���ο��� �ʱ�ȭ �Ұ���)
		b++;
	}
	void getData() {
		printf("a : %d, b : %d\n", a, b);
	}
};
int StaticTest::b = 20;		// �׳� ���� int b = 20�� ������, Ŭ���� �ٱ����� �� ���� �� �Ҽ�ǥ��
							// static ������� �ʱ�ȭ(�ܺο��� �ʱ�ȭ�ؾ� ��)-��ü���� �������� �ʴ´�.
int main()
{
	StaticTest s1;
	s1.getData(); 
	StaticTest s2;
	s2.getData();
	

	return 0;
}