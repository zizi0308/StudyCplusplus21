#include <stdio.h>
#include <string.h>

class Human
{
private:
	char name[12];
	int age;

public: 
	// ! ������ >> Ŭ������ �̸��� ������ return���� ���ٸ� �����ڰ� �ȴ� !
	Human(const char* aname, int aage) {// �μ��� �ַ� ����� �ʱ갪 >> ����� ������ �̸��� ����
		strcpy(name, aname);			// ������ �����̸��� ����� �� ����(��Ī�� �浹�ϸ� �������� �켱)
		age = aage;

	/*Human(const char* name, int age) {// ���� ���� �ڵ� �� �߿� ���Ѱ� ���� ��
		strcpy(this->name, name);		// �����ϰ� �ִ� ��ü�� ��������� ��(this->name, this->age)�� 
		this->age = age;*/				// �Ű����� name, age�� �����ض�� ��
	}
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	Human kim("�����", 29);
	kim.intro();
}