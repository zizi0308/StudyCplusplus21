#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int anum) {
		num = anum; 
		cout << num << "CTest constructor" << endl;
	}
	virtual ~CTest() {		// 메모리 동적할당으로 sub클래스(자식)의 파괴자가 호출되지 않는 문제를 막기위한 파괴자의 가상화(없애고 한번 더 실행해보기)
		cout << num << "CTest destructor" << endl;
	}
	virtual void func() {	// 상속받은 sub클래스(자식)의 함수를 호출시키기 위한 가상화
		cout << "CTest function()" << endl;
	}
};

class CTestSub : public CTest
{
private:
	int subN;
public:
	CTestSub(int anum, int asubN) : CTest(anum) {
		subN = asubN; 
		cout << subN << "CTestSub constructor" << endl;
	}
	~CTestSub() {
		cout << subN << "CTestSub destructor" << endl;
	}
	void func() {
	cout << "CTestSub function()" << endl;
	}

};

int main()
{
	CTest b(10);
	b.func();
	CTestSub c(20, 26);						// 상속받은 부모클래스의 생성자가 호출
	c.func();

	CTest* pb = new CTestSub(30, 24);		// 추상자료형으로 자식객체를 가리키게 함, (Line 13 virtual생략시)24에 해당하는 파괴자가 없음, 스택에 만들어지기 때문에 파괴되는 구조 : 제일 늦게만들어지는 객체부터 파괴된다. 
	pb->func();								// 부모의 메서드가 호출 >> 자식메서드를 호출 시키기 위해서는 virtual호출해야 함

	delete pb;

	return 0;
}