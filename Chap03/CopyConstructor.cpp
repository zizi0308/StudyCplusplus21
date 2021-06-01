#include <stdio.h>
#include <string.h>
//  ���������ȣ���� : 1. �Ű������� ��ü�� ������ �� 2. return���� ��ü�� �� 3. ��ü ���� ����������� ��
class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {		// ����Լ��ڸ��� ����� ���� Ŭ������ �̸����� �����ִ� >> ������
		pname = new char[strlen(aname) + 1];	// �����Ҵ�
		strcpy(pname, aname);
		age = aage;
	}

	Human(const Human &other) {	// ��������ڸ� �����ϸ鼭 ���� �޸� �����Ҵ��� ����
		// ����������� Ÿ���� ������ �����Ƿ� ���ѹݺ��� ���ϱ� ����(������ �Ⱦ��� ������ - ��������ڼ����� ����ȣ��) ������(&)������ �����
		// + ������ �ʱ갪 ���� ���۷����� ������ �� ������, �Լ������� �μ��� ���Ǿ����Ƿ� �ʱ�ȭ ���ص� ��(main�̳� �Լ��ȿ��� ������ �ʱ�ȭ �ʿ�).
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}

	~Human() { 
		delete[]pname;
	}

	void intro() {
		printf("�̸� = %s, ���� = %d\n", pname, age);
	}
};

void printHuman(Human who)
{
	who.intro();
}

int main()
{
	Human kang("������", 1424);
	Human boy = kang;

	printHuman(boy);
}