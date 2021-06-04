#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* name;
	int age;
public:
	Human() {}
	Human(const char* aname, int aage) {		// ������
		name = new char[strlen(aname) + 1];		// �����Ҵ�
		strcpy(name, aname);
		age = aage;
	}
	Human(const Human& other) {					// ��������� ����
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}
	~Human() {									// �����Ҵ� ������ ���� �Ҹ���
		delete[] name;
	}
	void PrintHuman() {							// ����Լ�1
		printf("�̸� : %s ,���� : %d", name, age);
	}
	void PrintHuman2(Human who) {				// ����Լ�2
		who.PrintHuman();
	}

	const Human operator =(const Human& other) {//	=�����ڸ� �������� operator�Լ� ����
		// Human obj
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;

		return *this;							// �ڱ��ڽ� �����ͷ� ����
		// return obj;
	}
};

int main()
{
	Human jo("������", 26);
	//jo.PrintHuman();
	//Human you(jo);
	//you.PrintHuman2(jo);
	Human Xman;
	Xman = jo;
	Xman.PrintHuman();
}