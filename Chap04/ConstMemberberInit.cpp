#include <stdio.h>

class Enemy
{
private:
	const int Speed;

public:
	Enemy(int aSpeed) :Speed(aSpeed) {}		// 매개변수가 하나이므로 변환생성자역할을 함, 머리에서 상수초기화 
	void Move() {
		printf("%d의 속도로 움직입니다.\n", Speed);
	}
};

int main()
{
	Enemy e1(10), e2(20);
	e1.Move();
	e2.Move();
}