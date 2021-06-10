#include <iostream>
using namespace std;

class CTest {
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "~CTest()" << endl; }
	void func() { cout << "func()" << endl; }
};

int main()
{
	shared_ptr<CTest> ptr1(new CTest);
	ptr1->func();
	cout << "count : " << ptr1.use_count() << endl;
	{
		shared_ptr<CTest> ptr2(ptr1);				// ptr1을 복사해서 생성
		cout << "count : " << ptr1.use_count() << endl;
		ptr2->func();		// 동적할당 된 포인터의 횟수를 계산
	}
	cout << "count : " << ptr1.use_count() << endl; // count 1 감소
	// 이후 자동으로 메모리 동적할당을 해제함 >> ptr2->func(); // 에러
	ptr1->func();

	unique_ptr<CTest> ptr1(new CTest);	// 하나의 대상에만 포인팅이 가능함 (auti_ptr과 비슷함)
	return 0;
}