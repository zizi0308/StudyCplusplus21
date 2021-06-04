#include <stdio.h>
#include <string.h>
// �������̵� >> ��Ӱ��迡�� �Լ��̸� �Ű����� ����� ��� ���ƾ� �Ѵ� "������"
// �����ε� >> �Լ��̸��� ������ �Ű������� ������ �ٸ��ų� Ÿ���� �ٸ� �� ��� "��������"
class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char *aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
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
	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��");
	}
	void intro() {	// 16��° �ٰ� ���� ���� >> "�������̵�" �θ𿡼� ����ϴ� ����Լ��� �ڽ�Ŭ�������� �״�� ������ ���(��ü�� �ٸ���)
		printf("%d�й� %s�Դϴ�.\n", stunum, name);
	}
};

int main()
{
	Human kim("�����", 29);
	kim.intro();			// �θ� �ִ� intro()
	Student han("���Ѱ�", 13, 12345);
	han.intro();			// �ڽĿ� �ִ� intro()
	han.Human::intro();		// �������̵� �� ��Ʈ�� ���� �θ� �ִ� ��Ʈ�θ� ���� ���� ��(�Ҽӵ��ִ� Ŭ������ �������� �����ڸ� �Ἥ �θ�Ŭ������ �Լ��� ������ ��)
}