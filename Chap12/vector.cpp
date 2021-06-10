#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;		// 배열과 비슷한 형태(배열같이 사용함)
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<int> v2[5];

	v.push_back(10);	// 기존에 만들어진 벡터에 값 추가할 떄
	vector<int>::iterator iter = v.begin();	// ::iterator << 포인터같은 객체 iter를 가지고 v에 접근가능 함
	iter = v.insert(iter, 2);		// insert

	v.pop_back();		// 맨 마지막에 있는 원소가 자동으로 삭제
	v.erase(v.begin() + 10);
	v.clear();

	return 0;
}

