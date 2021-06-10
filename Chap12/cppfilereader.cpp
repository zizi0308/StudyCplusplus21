#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f;
	char str[128];
	int i;

	f.open("D:\\Sources\\Gitrepository\\StudyCplusplus21\\Chap12\\cpptest.txt");	// 파일오픈 경로설정(절대경로 << 다른곳에 있는 파일을 열때는 절대경로형태로 적어줘야함)
	if (f.is_open()) {	// 파일이 열렸는지 확인
		f >> str >> i;
		cout << str << i << endl;
		f.close();
	}
	else {
		cout << "파일열기 실패" << endl;
	}


}