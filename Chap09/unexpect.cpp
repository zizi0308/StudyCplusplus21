#include <stdio.h>
#include <exception>
using namespace std;

void myunex()
{
	puts("�߻��ؼ��� �� �Ǵ� ���� �߻�");
	exit(-2);
}

void calc() throw(int)
{
	throw "string";		// �������ܷ� �����ߴµ� ���ڿ��� ������. 
}

int main()
{
	set_unexpected(myunex);
	try {
		calc();
	}
	catch (int) {		// ����ó���� �� �� �ִ� ���� �ڷ����� �ڵ鷯�� ���� ������ �����߻�
		puts("������ ���ܹ߻�");
	}
	puts("���α׷� ����");
}