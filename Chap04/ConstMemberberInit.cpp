#include <stdio.h>

class Enemy
{
private:
	const int Speed;

public:
	Enemy(int aSpeed) :Speed(aSpeed) {}		// �Ű������� �ϳ��̹Ƿ� ��ȯ�����ڿ����� ��, �Ӹ����� ����ʱ�ȭ 
	void Move() {
		printf("%d�� �ӵ��� �����Դϴ�.\n", Speed);
	}
};

int main()
{
	Enemy e1(10), e2(20);
	e1.Move();
	e2.Move();
}