#include <cursor.h>
#include <iostream>
using namespace std;

template <typename T>					// 템플릿의 일반화
class PosValue
{
private:
	int x, y;
	T value;
public:
	PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av) {}
	void outvalue() {
		gotoxy(x, y);
		cout << value << endl;
	}
};

template <> class PosValue<double>		// typename이 비워져있음 >> 클래스 템플릿특수화
{
private:
	int x, y;
	double value;
public:
	PosValue(int ax, int ay, double av) : x(ax), y(ay), value(av) {}
	void outvalue() {
		gotoxy(x, y);
		cout << "[" << value << "]" << endl;
	}
};

int main()
{
	PosValue<int> iv(10, 10, 2);		// 템플릿은 메모리에 할당된 형태가 아니기때문에 <>안에 타입을 지정해 메모리를 할당시킨다.
	PosValue<char> cv(25, 5, 'C');
	PosValue<double> dv(30, 15, 3.14);
	iv.outvalue();
	cv.outvalue();
	dv.outvalue();
}
