#include <stdio.h>
// 가상함수가 있으면 프로그램이 실행되는 동안(런타임때)에 호출할 가상함수를 선택하게 된다. << 가상함수는 동적결합능력이 있다.
class Shape
{
public:							// 원래 가상함수는 재정의가 가능한 함수지만, 꼭 재정의가 필요한 것은 아님
	virtual void draw() = 0;	// 하지만, {}가 없는(몸체자체가 없는) '순수가상함수'는 꼭 미래의 설계자가 재정의를 해서 작성해야 한다. (클래스 전체를 미래에 위임해버림)
};								// 하나 이상의 순수 가상함수를 가지는 클래스를 "추상클래스"

class Line : public Shape
{
public: 
	virtual void draw() { puts("선을 긋습니다"); }
};

class Circle : public Shape
{
public:
	virtual void draw() { puts("동그라미를 그렸다 치고"); }
};

class Rect : public Shape
{
public:
	virtual void draw() { puts("요건 사각형이 됩니다."); }
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