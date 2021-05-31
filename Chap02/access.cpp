#include <stdio.h>

struct SHuman
{
private:	// 정보은닉 (객체지향언어의 특징1)			속성은 대부분 private으로 설계
	char name[12];
	int age;

public:		// 캡슐화, 추상화 (객체지향언어의 특징2)	멤버는 대부분 public으로 설계
	void intro() {
		printf("이름 = %s, 나이 = %d", name, age);
	}
};

int main()
{
	SHuman kim;
	// kim.age = 286; age를 private으로 선언했으므로 주석풀면 에러남
	kim.intro();		// 멤버함수 : 객체들마다 공유
}