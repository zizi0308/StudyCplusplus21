#include <stdio.h>

class Human
{
public:
	char name[12];
	int age;

	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	Human arFriend[10] = {
		{"������", 49},
		{"������", 49},
		{"�ڻ�", 49} };


	Human* pFriend;
	pFriend = &arFriend[1];
	pFriend->intro();
}
// ��������� ������ �޸𸮰����� �޾Ƽ� �Ҵ�, ����Լ��� �ν��Ͻ�(��ü)���� �������� ���� 
// Why? ����Լ��� �����Ǳ� ���� �����Ϸ��� ����Լ��� ��ȣ�ȿ� *this�� �������ָ鼭 ��������� ����� 
// >> ���� ��ü�� *this�� �����ϰ� ����(ȣ���� ��ü�� �����͸� �����ϱ� ���� *this)