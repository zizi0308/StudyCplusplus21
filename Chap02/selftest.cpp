#include <stdio.h>

class Date
{
private:
	int year, month, day;

public:
	void SetDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}

	void OutTime() {
		printf("현재날짜는 %d년 %d월 %d일입니다.\n", year, month, day);
	}
};

int main()
{
	Date now;

	now.SetDate(2021, 5, 31);
	now.OutTime();
}