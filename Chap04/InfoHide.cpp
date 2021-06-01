#include <stdio.h>

class Time
{
private:
	int hour, min, sec;				// ��������� ��� ����(��������)

public:	// �ܺο����� public���� ������ִ� �Լ��� private�� �Ӽ��� �����Ѵ�.(�׼����Լ��� ����)
	Time(int h, int m, int s) {		// �μ� 3�� �޴� ������
		SetHour(h);					// SetHour��� �Լ��� ȣ���ϸ� h�� ����
		SetMinute(m);
		sec = s;
	}

	int GetHour() { return hour; }	// �׼����Լ� 1. : private���� hour�� ������ִ� �Ӽ��� ���Ͻ�Ű�� �ְ�,
	void SetHour(int h) {			// �׼����Լ� 2. 
		if (h >= 0 && h < 24) {		// ���ǿ� �´ٸ� Sethour�� ���޹��� ����
			hour = h;				// ��������� �����Ų��
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
		printf("����ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
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