#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream f;		// 파일을 쓸 용도로 객체를 생성

	f.open("D:\\Sources\\Gitrepository\\StudyCplusplus21\\Chap12\\cpptest.txt");	// 파일오픈 경로설정
	if (f.is_open()) {	// 파일이 열렸는지 확인
		f << "String " << 1234 << endl;
		f.close();
	}
	else {
		cout << "파일열기 실패" << endl;
	}
}