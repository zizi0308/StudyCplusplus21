#include <iostream>
using namespace std;

class CTest {
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "~CTest()" << endl; }
	void func() { cout << "func()" << endl; }
};

int main()
{
	shared_ptr<CTest> ptr1(new CTest);
	ptr1->func();
	cout << "count : " << ptr1.use_count() << endl;
	{
		shared_ptr<CTest> ptr2(ptr1);				// ptr1�� �����ؼ� ����
		cout << "count : " << ptr1.use_count() << endl;
		ptr2->func();		// �����Ҵ� �� �������� Ƚ���� ���
	}
	cout << "count : " << ptr1.use_count() << endl; // count 1 ����
	// ���� �ڵ����� �޸� �����Ҵ��� ������ >> ptr2->func(); // ����
	ptr1->func();

	unique_ptr<CTest> ptr1(new CTest);	// �ϳ��� ��󿡸� �������� ������ (auti_ptr�� �����)
	return 0;
}