#include <iostream>
#include <memory>
using namespace std;

int main()
{
	auto_ptr<double> rate(new double);		// �޸𸮵����Ҵ�

	*rate = 3.1415;							// ���������
	cout << *rate << endl;					// ����ϰ� �������� �ؾ��ϴµ� ���ص� auto_ptr�̶�� ����Ʈ �����Ͱ� �ڵ����� ����
}