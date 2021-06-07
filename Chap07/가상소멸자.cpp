#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int anum) {
		num = anum; 
		cout << num << "CTest constructor" << endl;
	}
	virtual ~CTest() {		// �޸� �����Ҵ����� subŬ����(�ڽ�)�� �ı��ڰ� ȣ����� �ʴ� ������ �������� �ı����� ����ȭ(���ְ� �ѹ� �� �����غ���)
		cout << num << "CTest destructor" << endl;
	}
	virtual void func() {	// ��ӹ��� subŬ����(�ڽ�)�� �Լ��� ȣ���Ű�� ���� ����ȭ
		cout << "CTest function()" << endl;
	}
};

class CTestSub : public CTest
{
private:
	int subN;
public:
	CTestSub(int anum, int asubN) : CTest(anum) {
		subN = asubN; 
		cout << subN << "CTestSub constructor" << endl;
	}
	~CTestSub() {
		cout << subN << "CTestSub destructor" << endl;
	}
	void func() {
	cout << "CTestSub function()" << endl;
	}

};

int main()
{
	CTest b(10);
	b.func();
	CTestSub c(20, 26);						// ��ӹ��� �θ�Ŭ������ �����ڰ� ȣ��
	c.func();

	CTest* pb = new CTestSub(30, 24);		// �߻��ڷ������� �ڽİ�ü�� ����Ű�� ��, (Line 13 virtual������)24�� �ش��ϴ� �ı��ڰ� ����, ���ÿ� ��������� ������ �ı��Ǵ� ���� : ���� �ʰԸ�������� ��ü���� �ı��ȴ�. 
	pb->func();								// �θ��� �޼��尡 ȣ�� >> �ڽĸ޼��带 ȣ�� ��Ű�� ���ؼ��� virtualȣ���ؾ� ��

	delete pb;

	return 0;
}