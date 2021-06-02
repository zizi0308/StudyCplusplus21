#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time() {}
	Time(int h, int m, int s) { hour = h, min = m, sec = s; }
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}
	const Time operator +(const Time& other) const {	// const Time >> 출력값을 상수화, operator + 자체가 연산자 함수이름 (const Time& other) << 객체가 매개변수로 쓰일때는 레퍼런스 타입을 사용
		Time t;	// 함수안에서 선언되었으므로 적용안받음
		t.sec = sec + other.sec;		// t1의 sec, min, hour를 변경하지마라,,,
		t.min = min + other.min;
		t.hour = hour + other.hour;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		return t;
	}
};

int main()
{
	Time t1(1, 10, 30);
	Time t2(2, 20, 40);
	Time t3;

	t3 = t1 + t2;				// 일반적인 더하기 연산처럼 operator로 만든 객체도 +로 표현가능
	// t3 = t1.operator+(t2)	// 이것도 가능함
	t3.OutTime();

}

