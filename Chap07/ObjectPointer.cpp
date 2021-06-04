#include <stdio.h>
#include <string.h>

class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

class Student : public Human
{
protected:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void intro() {
		printf("%d�й� %s�Դϴ�", stunum, name);
	}
	void study() {
		printf("���̴� �� �̻��� �� �̻� ��\n");
	}
};

int main()
{
	Human h("����", 23);
	Student s("�����", 14, 123456);
	Human* pH;
	Student* pS;

	pH = &h;	// �������ڷ��� = ��ü�ڷ���
	pS = &s;	// �������ڷ��� = ��ü�ڷ���
	pH = &s;	// �����Ͱ� �θ��ڷ���(Human) >> �θ�� �ڽ��� ����ų �� �ִ�.	// ��ĳ����

	//pS = &h;			// ����, �Ʒ� Line50�� ������ ���ϱ� ���� ����ȯ ���ְ� ����

	pS = (Student*)&h;	// �ڽ��ڷ����� �����ͷ� �θ�ü�� ����Ű�� ���� >> �ȵ� >> �׷��� ����ȯ	// �ٿ�ĳ����
	pS->intro();
}