#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "������ �츮��";

	cout << s1 << endl;
	s1.replace(7, 4, "���ѹα�");
	cout << s1 << endl;
}