#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;		// �迭�� ����� ����(�迭���� �����)
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<int> v2[5];

	v.push_back(10);	// ������ ������� ���Ϳ� �� �߰��� ��
	vector<int>::iterator iter = v.begin();	// ::iterator << �����Ͱ��� ��ü iter�� ������ v�� ���ٰ��� ��
	iter = v.insert(iter, 2);		// insert

	v.pop_back();		// �� �������� �ִ� ���Ұ� �ڵ����� ����
	v.erase(v.begin() + 10);
	v.clear();

	return 0;
}

