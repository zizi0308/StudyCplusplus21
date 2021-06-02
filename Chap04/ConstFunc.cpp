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

	void SetTime(int h, int m, int s) {	// 일반적인 멤버함수 타입
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime() const {			// const가 멤버함수에 있다 >> 객체의 상태를 읽기만 하는 함수 : 상수멤버함수로 지정
		printf("현재시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
	// const int a() // 이런것도 있음, 출력되는 타입을 상수로(return되는 값을 상수로) 
};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 22, 33);
	now.OutTime();

	const Time meeting(16, 00, 00);	// meeting을 상수객체로 선언 후 값 할당 >> 이 할당 값은 변경불가
	// meeting.SetTime(17, 00, 00);	// 상수 객체로 지정했기 때문에 SetTime으로 값변경 할 수 없음, 객체를 상수화시키면 상수화된 멤버함수와 멤버변수만 사용가능
	meeting.OutTime();
}