#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	// ������ 1(�Ű����� 3��)
	Time(int h, int m, int s) {		// �Ű������� ���� �����ڰ� ����Ʈ ������
		hour = h;					// �����ε��� �ϸ� ����Ʈ �����ڴ� �����(����Ʈ�����ڴ� �μ��� ����)
		min = m;
		sec = s;
	}
	// ������ 2(�Ű����� 1��)
	Time(int abssec) {
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime() {
		printf("����ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 30, 40);		// 12, 30, 40�� ���μ��� ����(�Ű������� 3���̹Ƿ� Time������ �� ù��° ������ ȣ��)
	now.OutTime();
	Time noon(44000);			// 44000�� ���μ��� ����(�Ű������� 1���̹Ƿ� Time ������ �� �ι�° ������ ȣ��)
	noon.OutTime();
}