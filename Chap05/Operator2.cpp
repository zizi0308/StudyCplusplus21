#include <stdio.h>

class MyTest
{
private:
	int x;
	int y;

public:
	MyTest() {};
	MyTest(int ax, int ay) {
		x = ax, y = ay;
		printf("인수 2개 생성자\n");
	}

	void printData() {
		printf("%d , %d\n", x, y);
	}
	MyTest(MyTest& rhs) : x(rhs.x), y(rhs.y) {
		printf("복사생성자 호출!\n");
	}

	const MyTest& operator +(const MyTest& other) const {	// const MyTest& << 출력타입을 참조자형태로 만들어줌 >> 불필요한 복사생성자의 호출을 방지하기 위해
		MyTest obj;
		obj.x = x + other.x;
		obj.y = y + other.y;

		return obj;	// 마지막 리턴때문에 임시객체가 만들어져서 obj의 값인 x, y를 복사하기때문에 복사생성자가 생성됨 
	}

	friend const MyTest operator-(const MyTest& rhs1, const MyTest& rhs2); // 클래스 내에 접근하기 위해 프렌드 함수추가

	/*const MyTest& operator -(const MyTest& other) const {
		MyTest obj;
		obj.x = x - other.x;
		obj.y = y - other.y;

		return obj;
	}*/

	const MyTest operator =(const MyTest& other) {	// 출력타입을 참조형태로 하고 *this를 return하면 결국 참조의 참조가 되므로 정확한 값이 안나옴 때문에 참조연산자를 빼줌 (const MyTest만 씀)
		//MyTest res;
		x = other.x;
		y = other.y;
		return *this;	// 매개변수를 참조형태로 받기 때문에 포인터를 써야함
	}

};
const MyTest operator-(const MyTest& rhs1, const MyTest& rhs2) {	// 전역으로 만든 연산자함수
	MyTest res;
	res.x = rhs1.x - rhs2.x;
	res.y = rhs1.y - rhs2.y;
	return res;

}

int main()
{
	MyTest o1(20, 10);	// int a = 10 >> int a(10) >> MyTset o1(20, 10)
	//o1.printData();
	MyTest o2(30, 50);
	//o2.printData();
	MyTest res;
	o1.operator+(o2);
	//res = o1 + o2;
	//res = o1.operator=(o2);
	//res.printData();
	res = operator-(o2, o1);
	res.printData();
	//MyTest res2;		// MyTest자료형의 res2라는 변수선언 >> int c와 같은의미
	//res2 = o2 - o1;		// int c = b - a
	//res2.printData();	// 구조체에서 하던 것과 같은형태로 출력

}