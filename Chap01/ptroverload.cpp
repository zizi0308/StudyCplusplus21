#include <stdio.h>

void sub(int a) { printf("int : %d\n", a); }
void sub(int* a) { printf("pointer: %p\n", a); }

int main()
{
	int i = 1234, * pi = &i;

	sub(i);
	sub(pi);
	sub(NULL);			// 원래 이렇게 쓰면 NULL포인터를 호출하는데 3행 때문에 NULL을 정수취급 함
	sub((int*)NULL);	// 포인터인 것을 나타내려면 강제로 형변환을 해야 한다(사실 이렇게는 안쓴다)
}						// 때문에 가급적이면 중복정의를 사용하지 말자,,,