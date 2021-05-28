#include <iostream>
using namespace std;

int main()
{
	cout << "First C++ Program" << endl;	// 2행 생략시, std::cout << "First C++ Program" << std::endl;
											// std타입의 cout객체에 "First C++ Program"을 집어넣어라
	int i = 56;								// endl은 개행을 의미함
	char ch = 'S';
	double d = 2.414;

	cout << i << ch << endl;
}