#include <cursor.h>
#include <iostream>
using namespace std;

template <typename T>
class PosValue
{
private:
	int x, y;
	T value;
public:
	PosValue() : x(0), y(0), value(0) {}
	PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av) {}
	void outvalue() {
		gotoxy(x, y);
		cout << value << endl;
	}
};

template <typename T>
class Wrapper
{
private:
	T member;
public:
	void set(T v) { member = v; }
	T get() { return member; }
};

int main()
{
	Wrapper<PosValue<char> > wrap;			// 템플릿중첩 할때는 두 괄호 사이에 띄어쓰기가 들어가야함(안하면 시프트연산자로 인식됨)
	wrap.set(PosValue<char>(10, 10, 'a'));
	PosValue<char>pc = wrap.get();
	pc.outvalue();
}