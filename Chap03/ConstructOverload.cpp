#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	// 생성자 1(매개변수 3개)
	Time(int h, int m, int s) {		// 매개변수가 없는 생성자가 디폴트 생성자
		hour = h;					// 오버로딩을 하면 디폴트 생성자는 사라짐(디폴트생성자는 인수가 없다)
		min = m;
		sec = s;
	}
	// 생성자 2(매개변수 1개)
	Time(int abssec) {
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime() {
		printf("현재시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 30, 40);		// 12, 30, 40을 실인수로 전달(매개변수가 3개이므로 Time생성자 중 첫번째 생성자 호출)
	now.OutTime();
	Time noon(44000);			// 44000을 실인수로 전달(매개변수가 1개이므로 Time 생성자 중 두번째 생성자 호출)
	noon.OutTime();
}