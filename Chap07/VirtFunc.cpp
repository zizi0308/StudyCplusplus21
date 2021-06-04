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
	virtual void intro() {	// �������̺� �����Լ��� ��ϵǾ� ���������� �����ϴ� ����
		printf("�̸� : %s, ���� : %d\n", name, age);
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
	virtual void intro() {		// �������̵��� �ڽ�Ŭ������ �ڵ����� virtual�� ��Ÿ����(virtual ��������)
		printf("%d�й� %s�Դϴ�.\n", stunum, name);
	}
	virtual void study() {
		printf("���̴� �� �̻��� �� �̻� ��\n");
	}
};

//void IntroSomeBody(Human* pH) {
//	pH->intro();
//}

int main()
{
	Human h("����", 13);
	Student s("���л�", 15, 12345);
	Human* pH;

	pH = &h;
	pH->intro();
	pH = &s;
	pH->intro();	// �θ�Ŭ������ �ִ� ��Ʈ�ΰ� ȣ���

	/*IntroSomeBody(&h);
	IntroSomeBody(&s);*/

}