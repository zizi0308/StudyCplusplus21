#include <stdio.h>
#include <string.h>

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
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	// Human momo;				// 에러 >> 인수가 없는 생성자를 필요로 하기때문
	// Human arFriend[3];		// 에러

	Human arFriend[3] = {
		{ Human("문동욱", 49) },
		{ Human("김유진", 49) },
		{ Human("박상만", 49) },
	};

	arFriend[2].intro();
}