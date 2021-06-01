#include <stdio.h>
#include <string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		SetName(aname);
		SetAge(aage);
	}

	char* GetName() { return name; }
	void SetName(const char* aname) {
		if (strlen(aname) < 12) {
			strcpy(name, aname);
		}
		else { strcpy(name, ""); }
	}

	int GetAge() { return age; }
	void SetAge(int aage) {
		if (aage >= 0 && aage <= 120) {
			age = aage;
		}
		else {
			age = 0;
		}
	}

	void Out() {
		printf("이름 : %s, 나이 : %d", name, age);
	}

	void printHuman(Human who) {
		who.Out();
	}

};

int main()
{
	Human jo = { "조희지", 26 };
	jo.printHuman(jo);
}