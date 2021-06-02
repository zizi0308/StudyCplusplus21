#include <stdio.h>

class MyTest
{
private:
	int x;
	int y;

public:
	MyTest() {};
	MyTest(int ax, int ay) {
		x = ax, y = ay;
		printf("�μ� 2�� ������\n");
	}

	void printData() {
		printf("%d , %d\n", x, y);
	}
	MyTest(MyTest& rhs) : x(rhs.x), y(rhs.y) {
		printf("��������� ȣ��!\n");
	}

	const MyTest& operator +(const MyTest& other) const {	// const MyTest& << ���Ÿ���� ���������·� ������� >> ���ʿ��� ����������� ȣ���� �����ϱ� ����
		MyTest obj;
		obj.x = x + other.x;
		obj.y = y + other.y;

		return obj;	// ������ ���϶����� �ӽð�ü�� ��������� obj�� ���� x, y�� �����ϱ⶧���� ��������ڰ� ������ 
	}

	const MyTest& operator -(const MyTest& other) const {
		MyTest obj;
		obj.x = x - other.x;
		obj.y = y - other.y;

		return obj;
	}

};

int main()
{
	MyTest o1(20, 10);	// int a = 10 >> int a(10) >> MyTset o1(20, 10)
	//o1.printData();
	MyTest o2(30, 50);
	//o2.printData();
	MyTest res;
	o1.operator+(o2);
	res = o1 + o2;
	res.printData();
	MyTest res2;		// MyTest�ڷ����� res2��� �������� >> int c�� �����ǹ�
	res2 = o2 - o1;		// int c = b - a
	res2.printData();	// ����ü���� �ϴ� �Ͱ� �������·� ���

}