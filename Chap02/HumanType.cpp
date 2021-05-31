#include <stdio.h>

class Human
{
public:
	char name[12];
	int age;

	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human arFriend[10] = {
		{"문동욱", 49},
		{"김유진", 49},
		{"박상막", 49} };


	Human* pFriend;
	pFriend = &arFriend[1];
	pFriend->intro();
}
// 멤버변수는 각각의 메모리공간을 받아서 할당, 멤버함수는 인스턴스(객체)별로 생성하지 않음 
// Why? 멤버함수는 공유되기 때문 컴파일러가 멤버함수의 괄호안에 *this를 전달해주면서 멤버변수를 출력함 
// >> 각각 객체는 *this를 포함하고 있음(호출한 객체의 포인터를 전달하기 위한 *this)