#include <stdio.h>
#include <malloc.h>
#include <string.h>

// ���ĸŰ������� ����� �� ���۷����� ����(���������� �Ű������� ����� ��<< �Լ��� ���� �������� �ǵ帱��)
// ���� �Լ��ȿ��� �� ���� ���۷����Լ��� �� �ʿ䰡 ����.

void InputNameRef(char*& Name)				// �������� ���� ���� ����
{
	Name = (char*)malloc(32);
	strcpy(Name, "kim sang hyung");
}

int main()
{
	//char* Name;							// Name�� �����ͷ� ����

	//InputNameRef(Name);					// Input�Լ��� ȣ���� Name�� ���μ��� ����
	//printf("�̸��� %s�Դϴ�.", Name);
	//free(Name);
	int a = 10;
	int& ra = a;
	int* pa = &ra;	// ���۷����� �ּҰ��� ���ϸ� ���������� ���۷����� �ּҰ��� ����ϴ°� �ƴ� a�� �ּҰ��� ���
	printf("%p %p %p\n", &a, &ra, pa);		// �����ϰ� ���� a�� ����Ű�� ���¸� ����(�ּҰ� ��� ����)

}