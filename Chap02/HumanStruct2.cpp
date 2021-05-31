#include <stdio.h>

struct SHuman {
	char name[12];
	int age;

	void intro();									// 함수 원형 선언
};

void SHuman::intro()								// 본체정의
{
	printf("이름 = %s, 나이 = %d\n", name, age);
}

int main()
{
	SHuman jo = { "조희지", 29 };
	jo.intro();

}