#include <stdio.h>

struct SHuman {
	char name[12];
	int age;

	void intro();									// �Լ� ���� ����
};

void SHuman::intro()								// ��ü����
{
	printf("�̸� = %s, ���� = %d\n", name, age);
}

int main()
{
	SHuman jo = { "������", 29 };
	jo.intro();

}