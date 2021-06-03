#include <stdio.h>

class Time
{
	friend const Time operator +(const Time& me, const Time& other);	// 매개변수 2개의 전역연산자 함수, 클래스 내부에서 쓸 수 있게 friend함수 사용
private:
	int hour, min, sec;

public:
	Time() {}
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}
};

const Time operator +(const Time& me, const Time& other) {	// 피연산자 2개, 클래스 외부에서 선언
	Time t;
	t.sec = me.sec + other.sec;
	t.min = me.min + other.min;
	t.hour = me.hour + other.hour;

	t.min += t.sec / 60;
	t.sec %= 60;
	t.hour += t.min / 60;
	t.min %= 60;
	return t;
}

int main()
{
	Time t1(1, 10, 30);
	Time t2(2, 20, 40);
	Time t3;

	t3 = t1 + t2;	// t3.operator+(t1, t2);와 동일함
	t3.OutTime();
}