#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("char array");
	string s2("C++ string");

	cout << s.data() << endl;
	cout << s.c_str() << endl;		// string타입 문자열을 char타입으로 바꿔줌(문자열 끝에 null을 생성해서 변형시켜줌)

	char str[128];
	strcpy(str, s.c_str());
	printf("str = %s\n", str);

	swap(s, s2);
	cout << s << endl;

}