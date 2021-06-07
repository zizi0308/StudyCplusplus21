#include <stdio.h>

class Shape					// 과거에 만든 클래스
{
public:
	/*virtual*/void draw() { puts("도형 오브젝트입니다."); }	// virtual을 쓰면 draw를 가상으로 선언하는 것이므로 각 도형에 맞는 draw함수가 호출된다.
};

class Line : public Shape	// 과거에 만든 메서드와 클래스를 통해 새로운 클래스를 생성
{
public:
	void draw() { puts("선을 긋습니다."); }		// 부모클래스의 메서드를 상속받아 새롭게 재정의함
};

class Circle : public Shape
{
public:
	void draw() { puts("동그라미 그렸다 치고."); }
};

class Rect : public Shape
{
public:
	void draw() { puts("요건 사각형입니다."); }
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