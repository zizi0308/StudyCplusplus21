#include <stdio.h>
#include <string.h>
// ��� >> ������ ����
class Human
{
private:
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

class Student : public Human		// Ŭ�����̸� : Ŭ�����̸� (HumanŬ������ public���� ��ӹ޾Ҵٴ� ��)
{
private:
	int stunum;

	/*  <��Ӵܰ�>
	1. �Ļ� Ŭ������ �����ڰ� ȣ��  
	2. �θ�Ŭ������ ������ ȣ���ϸ鼭 ����(�Ӹ��� �ݷп����� �����Ƿ� ��������)  
	3. �Ļ�Ŭ������ ������ ����*/
public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {	// �θ��� ����� �ڽ��� �����޾ұ� ������ �����ڷ� �ʱ�ȭ ���ش� + �ݷ��ʱ�ȭ(�θ�Ŭ������ �μ� 2�� �ʱ�ȭ).
		stunum = astunum;	// �ڽĿ� �ִ� ��������� �ʱ�ȭ��Ų��(�θ�Ŭ������ �̹� �Ӹ����� �ʱ�ȭ)
	}
	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};

int main()
{
	Human kim("�����", 34);
	kim.intro();
	Student han("�ѻ���", 13, 123456);
	han.intro();
	han.study();
}