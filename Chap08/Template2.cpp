#include <iostream>
using namespace std;

template <typename T>
class CTest {
private:
	T data;
public:
	CTest(T adata) : data(adata) {};
	T getData() { return data; }
};

template <>									// 특수화
class CTest<char> {
private:
	char data;
public :
	CTest(char adata) : data(adata) {};
	char getData() { return data; }
};

int main()
{
	CTest<int> obj(10);					// 클래스는 객체생성할 때 명시적으로 타입을 지정해서 써야함
	cout << obj.getData() << endl;
	CTest<char> obj2('a');
	cout << obj2.getData() << endl;
	return 0;
}