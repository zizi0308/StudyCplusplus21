#include <iostream>
using namespace std;

void TestFunc1()
{
	cout << "TestFunc1() BEGIN" << endl;	// 5.
	throw 0;								// 6. catch문으로 이동
	cout << "TestFunc1() END" << endl;
}

void TestFunc2()
{
	cout << "TestFunc2() BEGIN" << endl;	// 3.
	TestFunc1();							// 4. TestFunc1()로 이동
	cout << "TestFunc2() END" << endl;
}

void TestFunc3()
{
	cout << "TestFunc3() BEGIN" << endl;	// 1.	
	TestFunc2();							// 2. TestFunc2()로 이동
	cout << "TestFunc3() END" << endl;
}


int main()
{
	try {
		TestFunc3();						// 여기부터시작
	}
	catch (...) {								// ... << 어떤 타입이든지 catch문에서 작성하는 형태를 받아줌
		cout << "Exception Handling" << endl;	// 이동되어서 Exception Handling 출력 후 강제종료
	}
	return 0;
}
/* 스택풀기 : 함수를 반환하지 않고 스택을 풀어버린다. */