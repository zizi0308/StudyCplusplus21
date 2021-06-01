#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	operator int() {	// 변환함수(리턴 타입이 없지만 리턴을 시켜준다.)
		return hour * 3600 + min * 60 + sec;
	}

	void OutTime() {
		printf("현재시간은 %d:%d:%d입니다.", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 45);
	int i = now;
	printf("i = %d\n", i);
}