#include <stdio.h>

class Parent {};
class Child : public Parent {};

int main()
{
	Parent P, * pP;
	Child C, * pC;
	int i = 1234;

	pP = static_cast<Parent*>(&C);
	pC = static_cast<Child*>(&P);			// �ڽ��� �θ� ����Ŵ(�ٿ�ĳ����) ������ ������ ������
	// pP = static_cast<Parent*>(&i);		// Ŭ������ �⺻���� ����ȯ�� �������� �ʴ´�.
	// pC = static_cast<Child*>(&i);		// ����

}