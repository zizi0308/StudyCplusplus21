#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human
{	
private:
	char name[12];
	int age;

public:
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}

	/*void SetHuman(char n, int a) {
		name[12] = n;
		age = a;
	}*/

	void setName(const char* newName) {
		if (strlen(newName) < 12) {
			strcpy(name, newName);
		}
	}
};

int main()
{
	Human jo;
	
}


