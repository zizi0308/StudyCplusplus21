#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time() {}
	Time(int h, int m, int s) { hour = h, min = m, sec = s; }
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}
	const Time operator +(const Time& other) const {	// const Time >> ��°��� ���ȭ, operator + ��ü�� ������ �Լ��̸� (const Time& other) << ��ü�� �Ű������� ���϶��� ���۷��� Ÿ���� ���
		Time t;	// �Լ��ȿ��� ����Ǿ����Ƿ� ����ȹ���
		t.sec = sec + other.sec;		// t1�� sec, min, hour�� ������������,,,
		t.min = min + other.min;
		t.hour = hour + other.hour;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		return t;
	}
};

int main()
{
	Time t1(1, 10, 30);
	Time t2(2, 20, 40);
	Time t3;

	t3 = t1 + t2;				// �Ϲ����� ���ϱ� ����ó�� operator�� ���� ��ü�� +�� ǥ������
	// t3 = t1.operator+(t2)	// �̰͵� ������
	t3.OutTime();

}

