#include <iostream>
#include <memory>
using namespace std;

int main()
{
	auto_ptr<double> rate(new double);		// 메모리동적할당

	*rate = 3.1415;							// 값집어넣음
	cout << *rate << endl;					// 출력하고 동적해제 해야하는데 안해도 auto_ptr이라는 스마트 포인터가 자동으로 해제
}