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

	operator int() {	// ��ȯ�Լ�(���� Ÿ���� ������ ������ �����ش�.)
		return hour * 3600 + min * 60 + sec;
	}

	void OutTime() {
		printf("����ð��� %d:%d:%d�Դϴ�.", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 45);
	int i = now;
	printf("i = %d\n", i);
}