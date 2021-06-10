#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("C++ string");

	cout << s << "문자열의 길이= " << s.size() << endl;
	cout << s << "문자열의 길이= " << s.length() << endl;
	cout << s << "문자열의 할당크기= " << s.capacity() << endl;	// 실질적으로 할당되있는 버퍼의 크기
	cout << s << "문자열의 최대길이= " << s.max_size() << endl;	// 사용가능한 버퍼의 크기

	s.resize(6);		// 버퍼 크기를 6개로 재할당
	cout << s << "길이= " << s.size() << ", 할당크기= " << s.capacity() << endl;

	s.reserve(100);
	cout << s << "길이= " << s.size() << ", 할당크기= " << s.capacity() << endl;
	s.at(0);
	cout << s.at(0) << endl;		// 인덱스 별로 찾아볼때
	s.clear();						// 초기화 되있는 문자열을 지울 때(but 할당받은 사이즈는 그대로임)
	cout << s << endl;
}