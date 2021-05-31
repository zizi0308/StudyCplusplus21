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

	void OutTime() {
		printf("현재시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 23, 56);	// now라는 객체를 생성 얘가 인수 3개가진 생성자를 호출
	Time then = now;		// now객체를 새로운 객체에 대입시킴(복사해서) >> 기본적으로 복사생성자를 컴파일러가 호출함
	// Time then(now); 와 동일

	then.OutTime();			// 이후 복사한 것을 출력시킴
}