#include <iostream>

//int func(int a)
//{
//	return a;
//}
int func(int a, int b = 0)		// b�� ����Ʈ �Ű������� ��
{
	return a + b;				
}
int main()
{
	func(10);					// �Լ� �����ε��� ������ �ش�ȭ ��(�Լ� ȣ���� ��ȣ��)

	return 0;					// ������ default �Ű������� �����ε��� �Բ� �����ʵ��� �����ؾ� ��
}
