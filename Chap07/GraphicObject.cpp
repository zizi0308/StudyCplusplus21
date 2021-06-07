#include <stdio.h>

class Shape					// ���ſ� ���� Ŭ����
{
public:
	/*virtual*/void draw() { puts("���� ������Ʈ�Դϴ�."); }	// virtual�� ���� draw�� �������� �����ϴ� ���̹Ƿ� �� ������ �´� draw�Լ��� ȣ��ȴ�.
};

class Line : public Shape	// ���ſ� ���� �޼���� Ŭ������ ���� ���ο� Ŭ������ ����
{
public:
	void draw() { puts("���� �߽��ϴ�."); }		// �θ�Ŭ������ �޼��带 ��ӹ޾� ���Ӱ� ��������
};

class Circle : public Shape
{
public:
	void draw() { puts("���׶�� �׷ȴ� ġ��."); }
};

class Rect : public Shape
{
public:
	void draw() { puts("��� �簢���Դϴ�."); }
};

int main()
{
	Shape* ar[] = { new Shape(), new Rect(), new Circle(), new Rect(), new Line() };

	for (int i = 0; i < sizeof(ar)/sizeof(ar[0]); i++) {
		ar[i]->draw();
	}
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
		delete ar[i];
	}
}