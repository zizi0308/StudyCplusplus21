#include <stdio.h>

class MathCalc
{
private:
	const double pie;						// 상수 double 자료형(상수멤버는 선언과 동시에 초기화해야함 >> 생성자안에서 초기화해야한다)

public:
	MathCalc(double apie) : pie(apie) {}	// 상수멤버의 초기화 생성자, 본체가 시작되기 전(생성자초기화 전) 생성자의 머리에 초기화를 시켜준다.
	void DoCalc(double r) {
		printf("반지름 %.2f인 원의 둘레 = %.2f\n", r, r * 2 * pie);
	}
};

int main()
{
	MathCalc m(3.1416);
	m.DoCalc(5);
}