#include <stdio.h>

struct SHuman
{
private:	// �������� (��ü�������� Ư¡1)			�Ӽ��� ��κ� private���� ����
	char name[12];
	int age;

public:		// ĸ��ȭ, �߻�ȭ (��ü�������� Ư¡2)	����� ��κ� public���� ����
	void intro() {
		printf("�̸� = %s, ���� = %d", name, age);
	}
};

int main()
{
	SHuman kim;
	// kim.age = 286; age�� private���� ���������Ƿ� �ּ�Ǯ�� ������
	kim.intro();		// ����Լ� : ��ü�鸶�� ����
}