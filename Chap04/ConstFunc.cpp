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

	void SetTime(int h, int m, int s) {	// �Ϲ����� ����Լ� Ÿ��
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime() const {			// const�� ����Լ��� �ִ� >> ��ü�� ���¸� �б⸸ �ϴ� �Լ� : �������Լ��� ����
		printf("����ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
	// const int a() // �̷��͵� ����, ��µǴ� Ÿ���� �����(return�Ǵ� ���� �����) 
};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 22, 33);
	now.OutTime();

	const Time meeting(16, 00, 00);	// meeting�� �����ü�� ���� �� �� �Ҵ� >> �� �Ҵ� ���� ����Ұ�
	// meeting.SetTime(17, 00, 00);	// ��� ��ü�� �����߱� ������ SetTime���� ������ �� �� ����, ��ü�� ���ȭ��Ű�� ���ȭ�� ����Լ��� ��������� ��밡��
	meeting.OutTime();
}