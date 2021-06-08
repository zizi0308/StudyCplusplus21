#include <stdio.h>
#include <string.h>

class Human					// C++�� Ŭ������ ����Ÿ��� �޼��� �ۿ����� << �Ϲ����� ��ü������� ��ȣ���� �ִ�.
{
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void eat() {
		puts("�ȳȳ�\n");
	}
	virtual void intro()	// �̷��� ���ٺ���(���߿� ����ϱ� ���� �̸�) �θ�Ŭ������ ������ �� ������ �־��� �Ϳ� �߰�(������)�Ͽ� ����ϱ� ����
	{
		printf("�̸� : %s, ���� : %d\n", name, age);
	}
};

class Student :public Human
{
protected:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void intro() {
		printf("%d�й� %s�Դϴ�.\n", stunum, name);
	}
};

int main()
{
	Human h("����", 13);
	Student s("�̻��", 15, 12345);
	Human* pH;

	pH = &h;
	pH->intro();
	pH->eat();
	pH = &s;
	pH->intro();
	pH->eat();
}