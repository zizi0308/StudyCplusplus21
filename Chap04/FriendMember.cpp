#include <stdio.h>

class Time;
class Date
{
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutToday(Time& t);
};

class Time
{
	friend void Date::OutToday(Time& t);	// 항상 범위지정연산자를 사용해야함
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
};

void Date::OutToday(Time& t)				// 매개변수는 참조형태로 써줘야 복사생성자가 호출된다
{
	printf("오늘은 %d년 %d월 %d일이며, 지금 시간은 %d:%d:%d 입니다.\n",
		year, month, day, t.hour, t.min, t.sec);
}

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 45);
	d.OutToday(t);
}