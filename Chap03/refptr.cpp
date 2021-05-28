#include <stdio.h>
#include <malloc.h>
#include <string.h>

// 형식매개변수로 사용할 때 레퍼런스를 쓴다(지역변수의 매개변수로 사용할 때<< 함수를 통해 지역변수 건드릴때)
// 같은 함수안에서 쓸 때는 레퍼런스함수를 쓸 필요가 없다.

void InputNameRef(char*& Name)				// 변수명을 통해 값을 받음
{
	Name = (char*)malloc(32);
	strcpy(Name, "kim sang hyung");
}

int main()
{
	//char* Name;							// Name을 포인터로 만듦

	//InputNameRef(Name);					// Input함수를 호출해 Name을 실인수로 전달
	//printf("이름은 %s입니다.", Name);
	//free(Name);
	int a = 10;
	int& ra = a;
	int* pa = &ra;	// 레퍼런스의 주소값을 취하면 실질적으로 레퍼런스의 주소값을 출력하는게 아닌 a의 주소값을 출력
	printf("%p %p %p\n", &a, &ra, pa);		// 동일하게 변수 a를 가리키는 형태를 취함(주소값 모두 동일)

}