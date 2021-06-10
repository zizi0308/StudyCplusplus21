#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("test");				// 일반적으로 객체생성, 초기화 방법
	string s2(s1);					// s1을 복사해서 만들어라 >> 이 복사는 깊은복사 s1과 개별사용가능
	string s3;
	string s4(10, 'S');				// S를 10번 반복해서 만들어라(공백포함)
	string s5("very nice day", 8);	// 처음부터 8개의 문자만 초기화시켜서 사용해라
	/*<13, 14번째 줄은 둘다 같은 결과값 나옴>*/
	const char* str = "abcdefghijklmnopqrstuvwsyz";		// const 안쓰면 에러 >> 리터럴 : 값변경 불가(포인터로 가리키고 있으므로 변경자체가 불가함)
	char str[] = "abcdefghijklmnopqrstuvwsyz";			// 값 변경가능(배열의 방을 바꿔주면 됨)					
	string s6(str + 5, str + 10);						// 문자열의 5번째부터 10번째까지 사용


	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;
	cout << "s3=" << s3 << endl;
	cout << "s4=" << s4 << endl;
	cout << "s5=" << s5 << endl;
	cout << "s6=" << s6 << endl;
}