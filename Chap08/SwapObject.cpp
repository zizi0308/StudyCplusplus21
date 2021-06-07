#include <stdio.h>
#include <string.h>

template <typename T>
void swap(T& a, T& b)		// 2개의 타입을 템플릿 형태로 매개변수설정
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

	Human(const Human &other) {				// 복사생성자(매개변수가 참조형태),변환생성자(인수가 하나인)
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	age = other.age;
	}

	Human& operator =(const Human& other) {	// 연산자 오버로딩
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			age = other.age;
		}
		return *this;
	}

	~Human() {								// 소멸자
		delete[] name;
	}

	void intro() {							// 멤버함수
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human lee("이수만", 10);
	Human park("박진영", 20);
	lee.intro();
	park.intro();
	swap(lee, park);					// Human 자료형(클래스도 하나의 자료형임)
	lee.intro();
	park.intro();
}