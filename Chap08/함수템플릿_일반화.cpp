/* �Լ� ���ø� */
#include <iostream>
using namespace std;

template <typename T>				// �Լ����ø� �Ϲ�ȭ�� ���� �ڷ��� ������� ������ �Լ� ������ �ϰ� ���ش�.
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(3.14, 4.5) << endl;
	return 0;
}
