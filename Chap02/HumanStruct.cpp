#include <iostream>

struct Human {		// ����ü�� �⺻������ ������������ڰ� public������
	char name[20];
	float height;
	float weight;
	int age;
	char blood[10];

	void veiw();	// Ŭ���������� ����ü������ �������
};

void Human::veiw()		// �����Լ��ƴ� >> Ŭ������ �ִ� ����Լ���� ���� ��Ÿ���� �� >> �������� �����ڸ� ����� (Human::)
{						// �Լ� ������� �������� ������ ����� ��
	printf("���� �̸��� %s�̰� Ű�� %.1f �̰� �����Դ� %.1f �̰� ���̴� %d�̰� �������� %s �Դϴ�.", name, height, weight, age, blood);
}
int main()
{
	Human my = { "������", 168, 65, 26, "AB" };
	my.veiw();
	return 0;
}
