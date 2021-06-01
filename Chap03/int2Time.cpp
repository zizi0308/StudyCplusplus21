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

	explicit Time(int abssec) {		// 변환생성자 >> 임시객체를 생성해서 변환하고 멤버에 대입한다(객체를 기본생성자로 바꿔줄 때 사용)
		hour = abssec / 3600;		// explicit의 의미 : 명시적인 변환만 허용(기본형태만 허용하고 나머지는 허용하겠다.)
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void Outtime() {
		printf("현재시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

void printTime(Time when)
{
	when.Outtime();
}

int main()
{
	Time noon(40000);	// Time클래스 noon객체에 40000이라는 절대값을 주기때문에 변환허용
	noon.Outtime();
	//noon = 70000;		// 명확하지 않은 값은 실행하지 않음(explicit 때문) noon에 상수를 대입을 한 것인지 Time에 70000을 준 것인지 모호함
	//Time now = 60000;	// 사용자의 혼란을 방지하기 위해 explicit를 사용한다. >> 컴파일러의 임의적 판단을 방지함
	//now.Outtime();	// but, 생성자호출, 캐스트연산자는 사영자가 변환의사를 밝힌 것이므로 허용됨
	//now = 70000;		
	//now.Outtime();

	//printTime(80000);
}
