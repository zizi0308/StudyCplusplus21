#include <stdio.h>

class Time
{
private:
	int hour, min, sec;				// 멤버변수를 모두 숨김(정보은폐)

public:	// 외부에서는 public으로 선언되있는 함수로 private의 속성에 접근한다.(액세서함수를 통해)
	Time(int h, int m, int s) {		// 인수 3개 받는 생성자
		SetHour(h);					// SetHour라는 함수를 호출하며 h를 전달
		SetMinute(m);
		sec = s;
	}

	int GetHour() { return hour; }	// 액세서함수 1. : private안의 hour에 저장되있는 속성을 리턴시키고 있고,
	void SetHour(int h) {			// 액세서함수 2. 
		if (h >= 0 && h < 24) {		// 조건에 맞다면 Sethour에 전달받은 값을
			hour = h;				// 멤버변수에 저장시킨다
		}
	}

	int GetMinute() { return min; }
	void SetMinute(int m) {
		if (m >= 0 && m < 60) {
			min = m;
		}
	}
	int GetSecond() { return sec; }
	
	void OutTime() {
		printf("현재시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	now.SetHour(40);
	now.OutTime();
	now.SetHour(9);
	now.OutTime();
}