#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v = { 10, 20, 30, 40, 50 };

	for (auto i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';		//  배열형태
	}
	cout << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << ' ';		// 포인터가 가리키는 곳에 데이터 값을 읽어와야 함
	}
	cout << endl;
	for (auto i = v.begin(); i != v.end(); i++) {	// auto 자동으로 자료형을 맞춰줌
		cout << *i << ' ';	
	}
	return 0;
}