#include <stdio.h>

class MathCalc
{
private:
	const double pie;						// ��� double �ڷ���(�������� ����� ���ÿ� �ʱ�ȭ�ؾ��� >> �����ھȿ��� �ʱ�ȭ�ؾ��Ѵ�)

public:
	MathCalc(double apie) : pie(apie) {}	// �������� �ʱ�ȭ ������, ��ü�� ���۵Ǳ� ��(�������ʱ�ȭ ��) �������� �Ӹ��� �ʱ�ȭ�� �����ش�.
	void DoCalc(double r) {
		printf("������ %.2f�� ���� �ѷ� = %.2f\n", r, r * 2 * pie);
	}
};

int main()
{
	MathCalc m(3.1416);
	m.DoCalc(5);
}