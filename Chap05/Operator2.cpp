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

	friend const MyTest operator-(const MyTest& rhs1, const MyTest& rhs2); // Ŭ���� ���� �����ϱ� ���� ������ �Լ��߰�

	/*const MyTest& operator -(const MyTest& other) const {
		MyTest obj;
		obj.x = x - other.x;
		obj.y = y - other.y;

		return obj;
	}*/

	const MyTest operator =(const MyTest& other) {	// ���Ÿ���� �������·� �ϰ� *this�� return�ϸ� �ᱹ ������ ������ �ǹǷ� ��Ȯ�� ���� �ȳ��� ������ ���������ڸ� ���� (const MyTest�� ��)
		//MyTest res;
		x = other.x;
		y = other.y;
		return *this;	// �Ű������� �������·� �ޱ� ������ �����͸� �����
	}

};
const MyTest operator-(const MyTest& rhs1, const MyTest& rhs2) {	// �������� ���� �������Լ�
	MyTest res;
	res.x = rhs1.x - rhs2.x;
	res.y = rhs1.y - rhs2.y;
	return res;

}

int main()
{
	MyTest o1(20, 10);	// int a = 10 >> int a(10) >> MyTset o1(20, 10)
	//o1.printData();
	MyTest o2(30, 50);
	//o2.printData();
	MyTest res;
	o1.operator+(o2);
	//res = o1 + o2;
	//res = o1.operator=(o2);
	//res.printData();
	res = operator-(o2, o1);
	res.printData();
	//MyTest res2;		// MyTest�ڷ����� res2��� �������� >> int c�� �����ǹ�
	//res2 = o2 - o1;		// int c = b - a
	//res2.printData();	// ����ü���� �ϴ� �Ͱ� �������·� ���

}