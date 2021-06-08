#include <iostream>
using namespace std;

template <typename T>				// 일반화
T Add(T a, T b)
{
	return a + b;
}

template <>							// 자료타입을 비워둠 >> 템플릿 특수화(특정한 타입에 대해서 동작될 수 있도록 만들어 주는 것)
const char* Add(const char* lstr, const char* rstr)
{
	int llen = strlen(lstr);
	int rlen = strlen(rstr);
	int len = llen + rlen + 1;		// 전체문자열의 길이사용
	char* str = new char[len];		// 메모리 동적할당
	strcpy_s(str, llen + 1 , lstr);
	strcat_s(str, len, rstr);		// 문자열 붙이기
	return str;
}
int main()
{
	int res = Add<int>(3, 4);		// 5번행 실행
	cout << res << endl;
	const char* sres = Add<const char*>("Hello", "IoT");	// 11번행 실행 <const char*>생략가능
	cout << sres << endl;
	return 0;
}