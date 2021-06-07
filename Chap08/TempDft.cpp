#include <iostream>
using namespace std;

template <typename T, int sz = 3>		// ����Ʈ ���ø� �μ� >> int sz = 3
class CTest
{
private:
	T ary[sz];
public:
	T& operator[](int idx) {		// ������ �ִ� �����ڸ� �����
		if ((idx < 0) && (idx >= sz)) {
			cout << "����" << endl;
			exit(1);
		}
		return ary[idx];			// ���޵Ǵ� Ÿ���� ������ return���� ���������H
	}
	void getData() {
		for (int i = 0; i < sz; i++) {
			cout << ary[i] << endl;
		}
	}
};
int main()
{
	CTest<int, 3> arr;
	arr[0] = 10;					// CTestŬ���� Ÿ��
	arr[1] = 20;
	arr[2] = 30;
	arr.getData();
	return 0;
}