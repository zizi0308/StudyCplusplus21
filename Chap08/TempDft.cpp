#include <iostream>
using namespace std;

template <typename T, int sz = 3>		// 디폴트 템플릿 인수 >> int sz = 3
class CTest
{
private:
	T ary[sz];
public:
	T& operator[](int idx) {		// 기존에 있던 연산자를 사용함
		if ((idx < 0) && (idx >= sz)) {
			cout << "에러" << endl;
			exit(1);
		}
		return ary[idx];			// 전달되는 타입을 가지고 return값을 만들어줘야핰
	}
	void getData() {
		for (int i = 0; i < sz; i++) {
			cout << ary[i] << endl;
		}
	}
};
int main()
{
	CTest<int, 3> arr;
	arr[0] = 10;					// CTest클래스 타입
	arr[1] = 20;
	arr[2] = 30;
	arr.getData();
	return 0;
}