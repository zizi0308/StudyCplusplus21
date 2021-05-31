#include <iostream>

struct Human {		// 구조체는 기본적으로 멤버접근지정자가 public형태임
	char name[20];
	float height;
	float weight;
	int age;
	char blood[10];

	void veiw();	// 클래스원형을 구조체안으로 집어넣음
};

void Human::veiw()		// 전역함수아님 >> 클래스에 있는 멤버함수라는 것을 나타내야 함 >> 범위지역 연산자를 써야함 (Human::)
{						// 함수 끄집어내고 범위지역 연산자 써줘야 함
	printf("나의 이름은 %s이고 키는 %.1f 이고 몸무게는 %.1f 이고 나이는 %d이고 혈액형은 %s 입니다.", name, height, weight, age, blood);
}
int main()
{
	Human my = { "조희지", 168, 65, 26, "AB" };
	my.veiw();
	return 0;
}
