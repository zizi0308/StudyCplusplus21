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

	explicit Time(int abssec) {		// ��ȯ������ >> �ӽð�ü�� �����ؼ� ��ȯ�ϰ� ����� �����Ѵ�(��ü�� �⺻�����ڷ� �ٲ��� �� ���)
		hour = abssec / 3600;		// explicit�� �ǹ� : ������� ��ȯ�� ���(�⺻���¸� ����ϰ� �������� ����ϰڴ�.)
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void Outtime() {
		printf("����ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

void printTime(Time when)
{
	when.Outtime();
}

int main()
{
	Time noon(40000);	// TimeŬ���� noon��ü�� 40000�̶�� ���밪�� �ֱ⶧���� ��ȯ���
	noon.Outtime();
	//noon = 70000;		// ��Ȯ���� ���� ���� �������� ����(explicit ����) noon�� ����� ������ �� ������ Time�� 70000�� �� ������ ��ȣ��
	//Time now = 60000;	// ������� ȥ���� �����ϱ� ���� explicit�� ����Ѵ�. >> �����Ϸ��� ������ �Ǵ��� ������
	//now.Outtime();	// but, ������ȣ��, ĳ��Ʈ�����ڴ� �翵�ڰ� ��ȯ�ǻ縦 ���� ���̹Ƿ� ����
	//now = 70000;		
	//now.Outtime();

	//printTime(80000);
}
