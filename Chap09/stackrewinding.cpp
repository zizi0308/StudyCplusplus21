#include <iostream>
using namespace std;

void TestFunc1()
{
	cout << "TestFunc1() BEGIN" << endl;	// 5.
	throw 0;								// 6. catch������ �̵�
	cout << "TestFunc1() END" << endl;
}

void TestFunc2()
{
	cout << "TestFunc2() BEGIN" << endl;	// 3.
	TestFunc1();							// 4. TestFunc1()�� �̵�
	cout << "TestFunc2() END" << endl;
}

void TestFunc3()
{
	cout << "TestFunc3() BEGIN" << endl;	// 1.	
	TestFunc2();							// 2. TestFunc2()�� �̵�
	cout << "TestFunc3() END" << endl;
}


int main()
{
	try {
		TestFunc3();						// ������ͽ���
	}
	catch (...) {								// ... << � Ÿ���̵��� catch������ �ۼ��ϴ� ���¸� �޾���
		cout << "Exception Handling" << endl;	// �̵��Ǿ Exception Handling ��� �� ��������
	}
	return 0;
}
/* ����Ǯ�� : �Լ��� ��ȯ���� �ʰ� ������ Ǯ�������. */