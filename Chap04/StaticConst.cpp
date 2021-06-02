#include <stdio.h>

class MathCalc
{
private:
	static const double pie;		// 원래 static 멤버변수는 클래스 바깥에서 초기화 해야함 
	static const int sint = 3;		// const를 하면 안에서 초기화가 가능하다(단, 정수만)
public:
	MathCalc() {}
	void DoCalc(double r) {
		printf("반지름 %.2f인 원의 둘레 = %.2f\n", r, r * 2 * pie);
	}
};

const double MathCalc::pie = 3.1416;

int main()
{
	MathCalc m;
	m.DoCalc(5);
}