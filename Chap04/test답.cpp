#include <iostream>
using namespace std;

class Human {
private:
	char name[12];
	int age;

public:
	void SetName(char *name) {
		strcpy(this->name, name);
	}
	void GetName() {
		printf("%s", name);
	}
};

int main()
{
	Human i;
	char tempName[100];
	printf("이름을 입력하세요 : ");
	cin >> tempName;
	i.SetName(tempName);
	i.GetName();
	return 0;
}