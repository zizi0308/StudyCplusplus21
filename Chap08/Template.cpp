#include <iostream>
using namespace std;

template <typename T>					// Ŭ���� ���ø��� �Ϲ�ȭ
class CTest {
private:
	T num;
public:
	//CTest(T anum) : num(anum) {};		// 15��° �� ���ʿ��� �����ϰ� �ٱ��� ���
	CTest(T);							// ����
	void printData() {
		cout << "num : " << num << endl;
	}
};
template <typename T>					// �ѹ� �� ���ø� ��������
CTest<T>::CTest(T anum) {				// Ŭ������ �Ҽ��� ���� Ŭ���� �Ҽӵڿ� Ÿ�Գ����� ����� �Ѵ�.

}
int main()
{
	//CTest obj(10);					// �Լ����ø������� typename������ �� ������ Ŭ������ typename�����Ұ�
	CTest<int> obj(10);
	obj.printData();

	return 0;
}