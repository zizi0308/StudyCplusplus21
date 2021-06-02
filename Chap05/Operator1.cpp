#include <iostream>

class MyTest {
private:
	int x;
	int y;

public:
	MyTest() {}					// 디폴트 생성자
	MyTest(int ax, int ay) { x = ax, y = ay; }	// 인수 2개를 받는 생성자
	
	void printData() {
		printf("x = %d , y = %d", x, y);
	}

	const MyTest sum(const MyTest& other) const {
		MyTest obj;				// x,y의 값을 가질 수 있는 변수를 선언
		obj.x = x + other.x;
		obj.y = y + other.y;
		return obj;				// return값이 바뀌면 안됨
	}
	
};

int main()
{
	MyTest obj1(10, 20);
	MyTest obj2(20, 10);
	MyTest obj;
	obj = obj1.sum(obj2);
	obj.printData();
	return 0;
}