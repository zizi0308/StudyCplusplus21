#include <stdio.h>
// ���� : static_cast<��ȯ�� Ÿ��>(ĳ���� �� ���)
int main()
{
	const char* str = "korea";
	int* pi;
	double d = 123.456;
	int i;
	int ary[] = { 1, 2, 3, 4, 5 };
	int* ptr = static_cast<int*>(ary);	// �迭�� ��ȯ�� �����ϴ�(�迭�� ������ �ڷ����� ���)

	i = static_cast<int>(d);			// ����
	// pi = static_cast<int*>(str);		// ���� : static_cast�� �����ͳ����� ����ȯ�� ������� �ʴ´�.
	pi = (int*)str;						// ����
}