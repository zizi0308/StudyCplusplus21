#include <stdio.h>

class Date;
class Time
{
	friend void OutToday(Date&, Time&);
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
};

class Date
{
	friend void OutToday(Date&, Time&);
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
};

void OutToday(Date& d, Time& t)		// 함수의 매개변수로 들어갈 때 레퍼런스로 넣어야 함 + 정의부분에는 friend를 붙이면 안됨
{
	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.",
		d.year, d.month, d.day, t.hour, t.min, t.sec);	// friend로 선언하면 외부에서도 접근가능하기 때문에 값을 바꿀 수 있다.
}

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 23, 46);
	OutToday(d, t);
}