#include <stdio.h>

int main()
{
	enum origin {EAST, WEST, SOUTH, NORTH};
	enum origin mark = WEST;
	printf("%d����\n", mark);

	struct SHuman				// typedef ��������
	{
		char name[12];
		int age;
		double height;
	};							// �ڿ� �±׸� ��������
	struct SHuman kim = { "�����", 29, 181.4 };
	printf("�̸� = %s, ���� = %d\n", kim.name, kim.age);
}