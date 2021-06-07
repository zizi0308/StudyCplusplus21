#include <stdio.h>
#include <string.h>

template <typename T>
void swap(T& a, T& b)		// 2���� Ÿ���� ���ø� ���·� �Ű���������
{
	T t;
	t = a; a = b; b = t;
}
class Human
{
private:
	char* name;
	int age;

public:
	Human() {
		name = new char[1];
		name[0] = NULL;
		age = 0;
	}
	Human(const char* aname, int aage) {
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		age = aage;
	}

	Human(const Human &other) {				// ���������(�Ű������� ��������),��ȯ������(�μ��� �ϳ���)
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	age = other.age;
	}

	Human& operator =(const Human& other) {	// ������ �����ε�
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			age = other.age;
		}
		return *this;
	}

	~Human() {								// �Ҹ���
		delete[] name;
	}

	void intro() {							// ����Լ�
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	Human lee("�̼���", 10);
	Human park("������", 20);
	lee.intro();
	park.intro();
	swap(lee, park);					// Human �ڷ���(Ŭ������ �ϳ��� �ڷ�����)
	lee.intro();
	park.intro();
}