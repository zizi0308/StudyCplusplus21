#include <stdio.h>

int main()
{
	enum origin {EAST, WEST, SOUTH, NORTH};
	enum origin mark = WEST;
	printf("%d방향\n", mark);

	struct SHuman				// typedef 생략가능
	{
		char name[12];
		int age;
		double height;
	};							// 뒤에 태그명 생략가능
	struct SHuman kim = { "김상형", 29, 181.4 };
	printf("이름 = %s, 나이 = %d\n", kim.name, kim.age);
}