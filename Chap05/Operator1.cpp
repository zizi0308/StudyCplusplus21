#include <iostream>

class MyTest {
private:
	int x;
	int y;

public:
	MyTest() {}					// ����Ʈ ������
	MyTest(int ax, int ay) { x = ax, y = ay; }	// �μ� 2���� �޴� ������
	
	void printData() {
		printf("x = %d , y = %d", x, y);
	}

	const MyTest sum(const MyTest& other) const {
		MyTest obj;				// x,y�� ���� ���� �� �ִ� ������ ����
		obj.x = x + other.x;
		obj.y = y + other.y;
		return obj;				// return���� �ٲ�� �ȵ�
	}
	
};

int main()
{
	MyTest obj1(10, 20);
	MyTest obj2(20, 10);
	MyTest obj;
	obj = obj1.sum(obj2);
	obj.printData();
	return 0;
}