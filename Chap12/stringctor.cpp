#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1("test");				// �Ϲ������� ��ü����, �ʱ�ȭ ���
	string s2(s1);					// s1�� �����ؼ� ������ >> �� ����� �������� s1�� ������밡��
	string s3;
	string s4(10, 'S');				// S�� 10�� �ݺ��ؼ� ������(��������)
	string s5("very nice day", 8);	// ó������ 8���� ���ڸ� �ʱ�ȭ���Ѽ� ����ض�
	/*<13, 14��° ���� �Ѵ� ���� ����� ����>*/
	const char* str = "abcdefghijklmnopqrstuvwsyz";		// const �Ⱦ��� ���� >> ���ͷ� : ������ �Ұ�(�����ͷ� ����Ű�� �����Ƿ� ������ü�� �Ұ���)
	char str[] = "abcdefghijklmnopqrstuvwsyz";			// �� ���氡��(�迭�� ���� �ٲ��ָ� ��)					
	string s6(str + 5, str + 10);						// ���ڿ��� 5��°���� 10��°���� ���


	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;
	cout << "s3=" << s3 << endl;
	cout << "s4=" << s4 << endl;
	cout << "s5=" << s5 << endl;
	cout << "s6=" << s6 << endl;
}