#include <stdio.h>
#include <stdlib.h>

inline int randfunc(int n)		// inline�� �Ǵ��ϴ� ���� �����Ϸ�
{
	return rand()%n;
}

int main()
{
	int i, j, k;
	i = randfunc(10);
	j = randfunc(100);
	k = randfunc(50);
	printf("���� = %d,%d,%d\n", i, j, k);

}