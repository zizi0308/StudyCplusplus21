#include <stdio.h>

class C
{
	int a;
public:
	C() { puts("������ ȣ��"); }		// ��ü�� �����Ϸ��� �ڵ������� ����/�Ҹ��� ȣ��
	~C() { puts("�Ҹ��� ȣ��"); }		// �ֱٿ� ���� �� ���� �Ҹ�
};

void divide(int a, int d)
{
	if (d == 0) throw "0���δ� ���� �� �����ϴ�.";	// throw���� ���� ������Ҵ� ���õ��� ��ȯ
	printf("������ ��� = %d�Դϴ�.", a / d);
}

void calc(int t, const char* m)						// ��ȯ�ϱ� ���� �긦 �ݾƹ���(�ı��� ȣ��) >> ���� throw�޼��� ������
{
	C c;
	divide(10, 0);
}

int main()
{
	try {
		calc(1, "���");
	}
	catch (const char* message) {
		puts(message);
	}
	puts("���α׷��� ����˴ϴ�");
}