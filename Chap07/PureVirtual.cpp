#include <stdio.h>
// �����Լ��� ������ ���α׷��� ����Ǵ� ����(��Ÿ�Ӷ�)�� ȣ���� �����Լ��� �����ϰ� �ȴ�. << �����Լ��� �������մɷ��� �ִ�.
class Shape
{
public:							// ���� �����Լ��� �����ǰ� ������ �Լ�����, �� �����ǰ� �ʿ��� ���� �ƴ�
	virtual void draw() = 0;	// ������, {}�� ����(��ü��ü�� ����) '���������Լ�'�� �� �̷��� �����ڰ� �����Ǹ� �ؼ� �ۼ��ؾ� �Ѵ�. (Ŭ���� ��ü�� �̷��� �����ع���)
};								// �ϳ� �̻��� ���� �����Լ��� ������ Ŭ������ "�߻�Ŭ����"

class Line : public Shape
{
public: 
	virtual void draw() { puts("���� �߽��ϴ�"); }
};

class Circle : public Shape
{
public:
	virtual void draw() { puts("���׶�̸� �׷ȴ� ġ��"); }
};

class Rect : public Shape
{
public:
	virtual void draw() { puts("��� �簢���� �˴ϴ�."); }
};

int main()
{
	Shape* pS[3];
	
	// Shape s;
	pS[0] = new Line;
	pS[1] = new Circle;
	pS[2] = new Rect;

	for (int i = 0; i < 3; i++)
	{
		pS[i]->draw();
	}
	for (int i = 0; i < 3; i++)
	{
		delete pS[i];
	}
}