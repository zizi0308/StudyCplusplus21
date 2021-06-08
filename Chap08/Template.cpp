#include <iostream>
using namespace std;

template <typename T>					// 클래스 템플릿의 일반화
class CTest {
private:
	T num;
public:
	//CTest(T anum) : num(anum) {};		// 15번째 줄 안쪽에서 사용안하고 바깥에 사용
	CTest(T);							// 선언
	void printData() {
		cout << "num : " << num << endl;
	}
};
template <typename T>					// 한번 더 템플릿 선언해줌
CTest<T>::CTest(T anum) {				// 클래스의 소속을 쓰고 클래스 소속뒤에 타입네임을 써줘야 한다.

}
int main()
{
	//CTest obj(10);					// 함수템플릿에서는 typename생략할 수 있지만 클래스는 typename생략불가
	CTest<int> obj(10);
	obj.printData();

	return 0;
}