#include <stdio.h>

int count = 0;			// �������� �Ҵ� >> �ٵ� �������̸� ������������(static)���, ���������� �ƹ��� �ǵ帱�� �����Ƿ� �����ϴ�
class Simple
{
private:
	int value;

public:
	Simple() { count++; }
	~Simple() { count--; }
	void OutCount() {	// ȣ���� ��ü�� this�����͸� ����
		printf("���簴ü ���� = %d\n", count);
	}
};

int main()
{
	Simple s, * ps;		// �� �� ���������� ����� count�� ������ �� �� ����
	s.OutCount();		// �Լ��� ȣ����
	ps = new Simple;
	ps->OutCount();
	delete ps;
	s.OutCount();
	printf("ũ�� = %d\n", sizeof(s));	// int�� 4����Ʈ(��ü�� ũ��� ����������� ������ �ޱ⶧����)
}