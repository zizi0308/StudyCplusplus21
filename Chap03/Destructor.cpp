#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
		printf("%s ��ü�� �����ڰ� ȣ��Ǿ����ϴ�.\n", pname);
	}

	~Human() {			// ��ü�� �Ҹ�� �� ȣ��Ǵ� �ı��� : �Ű�����, ���X ��� ~�� ����
		printf("%s ��ü�� �ı��Ǿ����ϴ�.\n", pname);
		delete[] pname;	// �޸� �����Ҵ��� �ı�, �׻� �ı��� �ȿ��� �����Ҵ�� �޸𸮸� ��ȯ������� ��
	}

	void intro() {
		printf("�̸� = %s, ���� = %d\n", pname, age);
	}
};
// Human boy("����ѹ��ź��̿͵η��", 12); ���������� �ϸ� main�Լ��� ����Ǳ����� ȣ���
int main()
{
	Human boy("����ѹ��ź��̿͵η��", 12);
	boy.intro();
}