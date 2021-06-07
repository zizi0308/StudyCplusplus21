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
	PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av) { }
	void outvalue() {
		gotoxy(x, y);
		cout << value << endl;
	}
};

int main()
{
	PosValue<int> iv(10, 10, 2);			// 명시적으로 타입을 표시 : 템블릿이름<자료형> => 클래스 (템플릿 이름은 템플릿value일 뿐 클래스가 아님)
	PosValue<char> cv(25, 5, 'C');
	PosValue<double> dv(30, 15, 3.14);
	iv.outvalue();
	cv.outvalue();
	dv.outvalue();
}