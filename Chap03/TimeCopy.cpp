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
		printf("����ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 23, 56);	// now��� ��ü�� ���� �갡 �μ� 3������ �����ڸ� ȣ��
	Time then = now;		// now��ü�� ���ο� ��ü�� ���Խ�Ŵ(�����ؼ�) >> �⺻������ ��������ڸ� �����Ϸ��� ȣ����
	// Time then(now); �� ����

	then.OutTime();			// ���� ������ ���� ��½�Ŵ
}