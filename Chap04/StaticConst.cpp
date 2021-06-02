#include <stdio.h>

class MathCalc
{
private:
	static const double pie;		// ���� static ��������� Ŭ���� �ٱ����� �ʱ�ȭ �ؾ��� 
	static const int sint = 3;		// const�� �ϸ� �ȿ��� �ʱ�ȭ�� �����ϴ�(��, ������)
public:
	MathCalc() {}
	void DoCalc(double r) {
		printf("������ %.2f�� ���� �ѷ� = %.2f\n", r, r * 2 * pie);
	}
};

const double MathCalc::pie = 3.1416;

int main()
{
	MathCalc m;
	m.DoCalc(5);
}