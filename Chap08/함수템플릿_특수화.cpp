#include <iostream>
using namespace std;

template <typename T>				// �Ϲ�ȭ
T Add(T a, T b)
{
	return a + b;
}

template <>							// �ڷ�Ÿ���� ����� >> ���ø� Ư��ȭ(Ư���� Ÿ�Կ� ���ؼ� ���۵� �� �ֵ��� ����� �ִ� ��)
const char* Add(const char* lstr, const char* rstr)
{
	int llen = strlen(lstr);
	int rlen = strlen(rstr);
	int len = llen + rlen + 1;		// ��ü���ڿ��� ���̻��
	char* str = new char[len];		// �޸� �����Ҵ�
	strcpy_s(str, llen + 1 , lstr);
	strcat_s(str, len, rstr);		// ���ڿ� ���̱�
	return str;
}
int main()
{
	int res = Add<int>(3, 4);		// 5���� ����
	cout << res << endl;
	const char* sres = Add<const char*>("Hello", "IoT");	// 11���� ���� <const char*>��������
	cout << sres << endl;
	return 0;
}