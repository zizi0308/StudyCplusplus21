#include <stdio.h>
#include <malloc.h>
#include <memory.h>
// void >> 자료형이 결정되지 않은 상태
void swap(void* a, void* b, size_t len)	// void를 사용하면 자료형별로 클래스를 새로 생성할 필요가 없음(클래스의 일반화)
{										// 함수가 호출될 떄(런타임중에) 매개변수로 쓰여있는 타입에 따라 결정
	void* t;							// void형 포인터를 사용하여 임의의 데이터를 처리함
	t = malloc(len);
	memcpy(t, a, len);					// memcpy >> 메모리 영역을 그대로 카피함
	memcpy(a, b, len);
	memcpy(b, t, len);
	free(t);
}

int main()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	swap(&a, &b, sizeof(int));
	swap(&c, &d, sizeof(double));
	printf("a = %d, b = %d\n", a, b);
	printf("c = %.f, d = %.f", c, d);

}