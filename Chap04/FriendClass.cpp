#include <stdio.h>
// Date는 Time에 대한 친구지만, Time은 Date에 대한 친구가 아니다.(Time을 통해 Date클래스에 접근해서 사  용할 수 없다.)
class Time
{
	friend class Date;
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
};

class Date
{
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutToday(Time& t) {
		printf("오늘은 %d년 %d월 %d일이며, 지금 시간은 %d:%d:%d입니다.\n",
			year, month, day, t.hour, t.min, t.sec);
	}
};

int main()
{
	Date d(2018, 04, 24);
	Time t(12, 34, 52);
	d.OutToday(t);
}