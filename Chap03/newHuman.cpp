#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];	// ��������� �����Ҵ���� strlen(aname) + 1 >> ���ڿ� + NULL��
		strcpy(pname, aname);
		age = aage;
		printf("== <%s> ��ü���� ==\n", pname);
	}

	~Human() {
		printf("== <%s> ��ü�� �ı� == \n", pname);
		delete[] pname;							// ������� �����Ҵ�����
	}
	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", pname, age);
	}
};

int main()
{
	Human boy("����ѹ��ź��̿͵η��", 12);
	boy.intro();

	Human* leo;		// new �����ڰ� �����ϴ� �����͸� Human Ÿ�� ������ leo�� ����
	leo = new Human("������������ī������", 40);
	leo->intro();	// ���� �߿� ������ ��ü�� ������Ÿ���̹Ƿ� ȭ��ǥ������ ���
	delete leo;
}