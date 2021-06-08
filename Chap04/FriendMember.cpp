#include <stdio.h>

class Time;
class Date
{
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutToday(Time& t);
};

class Time
{
	friend void Date::OutToday(Time& t);	// Friend Ŭ������ ����� ������ �׻� �������� �����ڸ� ����ؾ� �� 
private:									// Line 15: DateŬ������ ����Լ��� OutToday�� Time�� ��� ����� ���� �� �ִ� ������ ������
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
};

void Date::OutToday(Time& t)				// �Ű������� �������·� ����� ��������ڰ� ȣ��ȴ�
{
	printf("������ %d�� %d�� %d���̸�, ���� �ð��� %d:%d:%d �Դϴ�.\n",
		year, month, day, t.hour, t.min, t.sec);
}

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 45);
	d.OutToday(t);
}